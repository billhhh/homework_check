
#include "AnswerCardProcessing.h"

#include <highgui.h>

#include <iostream>
using namespace std;
#pragma comment(lib,"atlsd.lib")
int TiltCorrection(Mat src,Mat &dst,cv::Rect* rt,double &angle)
{
	short effective_markers_count = 0;
	short effective_markers_mask = 0;
	for (int i=0;i<4;i++)
	{
		if (rt[i].width>0)
		{
			effective_markers_count++;
			effective_markers_mask+=1<<i;
		}
	}
	if (effective_markers_count==4)
	{
		//检查是否异常
		if (rt[2].y == rt[0].y)
			return -2;
		angle = atan(((double)(rt[2].x-rt[0].x))/(rt[2].y-rt[0].y))*180/CV_PI;
		/// 求得旋转变换矩阵
		Mat warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
		//计算旋转后的标记点
		Mat src_data(4,3,CV_64FC1);
		for (int i =0;i<4;i++)
		{
			src_data.at<double>(i,0) = rt[i].x;
			src_data.at<double>(i,1) = rt[i].y;
			src_data.at<double>(i,2) = 1;
		}	
		Mat dst_data = src_data *warp_mat.t();
		for (int i =0;i<4;i++)
		{
			rt[i].x = (int)dst_data.at<double>(i,0);
			rt[i].y = (int)dst_data.at<double>(i,1);
		}
		/// 对源图像应用上面求得的仿射变换
		warpAffine( src, dst, warp_mat, src.size(),1,0,Scalar(255,255,255));
		return effective_markers_mask;
	}else if (effective_markers_count==3)
	{
		Mat warp_mat;
		//计算旋转后的标记点
		Mat src_data(3,3,CV_64FC1);
		switch(effective_markers_mask)
		{
			//123缺4
		case 7:
			{
				//检查是否异常
				if (rt[2].y == rt[0].y)
					return -2;

				angle = atan(((double)(rt[2].x-rt[0].x))/(rt[2].y-rt[0].y))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
				//123缺4
				src_data.at<double>(0,0) = rt[0].x;	src_data.at<double>(0,1) = rt[0].y;
				src_data.at<double>(1,0) = rt[1].x;	src_data.at<double>(1,1) = rt[1].y;
				src_data.at<double>(2,0) = rt[2].x;	src_data.at<double>(2,1) = rt[2].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
				rt[2].x = (int)(dst_data.at<double>(2,0)+0.5);	rt[2].y = (int)(dst_data.at<double>(2,1)+0.5);
				break;
			}
			//124缺3
		case 11:
			{
				//检查是否异常
				if (rt[3].y == rt[1].y)
					return -2;
				//angle = atan(((double)(rt[3].x-rt[1].x))/(rt[3].y-rt[1].y))*180/CV_PI;
				angle = atan(((double)(rt[0].y-rt[1].y))/(rt[0].x-rt[1].x))*180/CV_PI;

				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),angle,1);
				//124缺3
				src_data.at<double>(0,0) = rt[0].x;	src_data.at<double>(0,1) = rt[0].y;
				src_data.at<double>(1,0) = rt[1].x;	src_data.at<double>(1,1) = rt[1].y;
				src_data.at<double>(2,0) = rt[3].x;	src_data.at<double>(2,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();

				rt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(2,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(2,1)+0.5);
				break;
			}
			//134缺2
		case 13:
			{
				//检查是否异常
				if (rt[2].y == rt[0].y)
					return -2;
				angle = atan(((double)(rt[2].x-rt[0].x))/(rt[2].y-rt[0].y))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
				//134缺2
				src_data.at<double>(0,0) = rt[0].x;	src_data.at<double>(0,1) = rt[0].y;
				src_data.at<double>(1,0) = rt[2].x;	src_data.at<double>(1,1) = rt[2].y;
				src_data.at<double>(2,0) = rt[3].x;	src_data.at<double>(2,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[2].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[2].y = (int)(dst_data.at<double>(1,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(2,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(2,1)+0.5);
				break;
			}
			//234缺1
		case 14:
			{
				//检查是否异常
				if (rt[3].y == rt[1].y)
					return -2;
				angle = atan(((double)(rt[3].x-rt[1].x))/(rt[3].y-rt[1].y))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
				//134缺2
				src_data.at<double>(0,0) = rt[1].x;	src_data.at<double>(0,1) = rt[1].y;
				src_data.at<double>(1,0) = rt[2].x;	src_data.at<double>(1,1) = rt[2].y;
				src_data.at<double>(2,0) = rt[3].x;	src_data.at<double>(2,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[1].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[1].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[2].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[2].y = (int)(dst_data.at<double>(1,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(2,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(2,1)+0.5);
				break;
			}
		}
		/// 对源图像应用上面求得的仿射变换
		warpAffine( src, dst, warp_mat, src.size(),1,0,Scalar(255,255,255));
		return effective_markers_mask;
	}else if (effective_markers_count==2)
	{
		Mat warp_mat;
		//计算旋转后的标记点
		Mat src_data(2,3,CV_64FC1);
		switch(effective_markers_mask)
		{
			//12缺34
		case 3:
			{
				//检查是否异常
				if (rt[1].x == rt[0].x)
					return -2;

				angle = atan(((double)(rt[1].y-rt[0].y))/(rt[1].x-rt[0].x))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),angle,1);
				//12缺34
				src_data.at<double>(0,0) = rt[0].x;	src_data.at<double>(0,1) = rt[0].y;
				src_data.at<double>(1,0) = rt[1].x;	src_data.at<double>(1,1) = rt[1].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
				break;
			}
			//24缺13
		case 10:
			{
				//检查是否异常
				if (rt[3].y == rt[1].y)
					return -2;
				angle = -atan(((double)(rt[3].x-rt[1].x))/(rt[3].y-rt[1].y))*180/CV_PI;
				//angle = atan(((double)(rt[0].y-rt[1].y))/(rt[0].x-rt[1].x))*180/CV_PI;

				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
				//24缺13
				src_data.at<double>(0,0) = rt[1].x;	src_data.at<double>(0,1) = rt[1].y;
				src_data.at<double>(1,0) = rt[3].x;	src_data.at<double>(1,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();

				rt[1].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[1].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(1,1)+0.5);
				break;
			}
			//13缺24
		case 5:
			{
				//检查是否异常
				if (rt[2].y == rt[0].y)
					return -2;
				angle = -atan(((double)(rt[2].x-rt[0].x))/(rt[2].y-rt[0].y))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),-angle,1);
				//134缺2
				src_data.at<double>(0,0) = rt[0].x;	src_data.at<double>(0,1) = rt[0].y;
				src_data.at<double>(1,0) = rt[3].x;	src_data.at<double>(1,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(1,1)+0.5);
				break;
			}
			//3 4缺1 2
		case 12:
			{
				//检查是否异常
				if (rt[3].x == rt[2].x)
					return -2;
				angle = atan(((double)(rt[3].y-rt[2].y))/(rt[3].x-rt[2].x))*180/CV_PI;
				/// 求得旋转变换矩阵
				warp_mat = getRotationMatrix2D(cv::Point2d(src.cols*0.5,src.rows*0.5),angle,1);
				//134缺2
				src_data.at<double>(0,0) = rt[2].x;	src_data.at<double>(0,1) = rt[2].y;
				src_data.at<double>(1,0) = rt[3].x;	src_data.at<double>(1,1) = rt[3].y;
				src_data.col(2) = 1;
				Mat dst_data = src_data *warp_mat.t();
				rt[2].x = (int)(dst_data.at<double>(0,0)+0.5);	rt[2].y = (int)(dst_data.at<double>(0,1)+0.5);
				rt[3].x = (int)(dst_data.at<double>(1,0)+0.5);	rt[3].y = (int)(dst_data.at<double>(1,1)+0.5);
				break;
			}
		}
		/// 对源图像应用上面求得的仿射变换
		warpAffine( src, dst, warp_mat, src.size(),1,0,Scalar(255,255,255));
		return effective_markers_mask;
	}else
		return -1;
}
/************************************************************************/
/* 倾斜校正
*/
/************************************************************************/

int TiltCorrection(Mat src,Mat &dst,vector<cv::Rect> &anchorPt,short anchorType,double &angle)
{
	Mat warp_mat;
	//计算旋转后的标记点
	Mat src_data(3,3,CV_64FC1);
	double xAngle,yAngle;
	if (anchorPt.size()<2)
	{
		//定位点数量不足
		return 1;
	}
	switch(anchorType)
	{
		//123缺4
	case 15:
	case 7:
		{
			//检查是否异常
			if (anchorPt[2].y == anchorPt[0].y)
				return -2;

			yAngle = -atan(((double)(anchorPt[2].x-anchorPt[0].x))/(anchorPt[2].y-anchorPt[0].y))*180/CV_PI;
			if (anchorPt[0].x == anchorPt[1].x)
				return -2;
			xAngle = atan(((double)(anchorPt[1].y-anchorPt[0].y))/(anchorPt[1].x-anchorPt[0].x))*180/CV_PI;
			angle=(xAngle+yAngle)/2;
			/// 求得旋转变换矩阵
			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//123缺4
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = anchorPt[2].x;	src_data.at<double>(2,1) = anchorPt[2].y;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			anchorPt[2].x = (int)(dst_data.at<double>(2,0)+0.5);	anchorPt[2].y = (int)(dst_data.at<double>(2,1)+0.5);
			break;
		}
		//124缺3
	case 11:
		{
			//检查是否异常
 			if (anchorPt[0].x == anchorPt[1].x)
 				return -2;
 			 angle = - atan(((double)(anchorPt[2].x-anchorPt[1].x))/(anchorPt[2].y-anchorPt[1].y))*180/CV_PI;
 			double angle2 = atan(((double)(anchorPt[1].y-anchorPt[0].y))/(anchorPt[1].x-anchorPt[0].x))*180/CV_PI;
 			angle=(angle+angle2)/2;
 			/// 求得旋转变换矩阵
 			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//124缺3
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = anchorPt[2].x;	src_data.at<double>(2,1) = anchorPt[2].y;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			anchorPt[2].x = (int)(dst_data.at<double>(2,0)+0.5);	anchorPt[2].y = (int)(dst_data.at<double>(2,1)+0.5);
			break;
		}
		//234缺1
	case 14:
		{
			//检查是否异常
			if (anchorPt[2].y == anchorPt[0].y)
				return -2;
			yAngle = -atan(((double)(anchorPt[2].x-anchorPt[0].x))/(anchorPt[2].y-anchorPt[0].y))*180/CV_PI;
			if (anchorPt[2].x == anchorPt[1].x)
				return -2;
			xAngle = atan(((double)(anchorPt[2].y-anchorPt[1].y))/(anchorPt[2].x-anchorPt[1].x))*180/CV_PI;
			/// 求得旋转变换矩阵
			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//134缺2
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = anchorPt[2].x;	src_data.at<double>(2,1) = anchorPt[2].y;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			anchorPt[2].x = (int)(dst_data.at<double>(2,0)+0.5);	anchorPt[2].y = (int)(dst_data.at<double>(2,1)+0.5);
			break;
		}
		//134缺2
	case 13:
		{
			//检查是否异常
			if (anchorPt[1].y == anchorPt[0].y)
				return -2;
			yAngle = -atan(((double)(anchorPt[1].x-anchorPt[0].x))/(anchorPt[1].y-anchorPt[0].y))*180/CV_PI;
			if (anchorPt[1].x == anchorPt[2].x)
				return -2;
			xAngle = atan(((double)(anchorPt[1].y-anchorPt[2].y))/(anchorPt[1].x-anchorPt[2].x))*180/CV_PI;
			angle=(xAngle+yAngle)/2;
			/// 求得旋转变换矩阵
			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//134缺2
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = anchorPt[2].x;	src_data.at<double>(2,1) = anchorPt[2].y;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			anchorPt[2].x = (int)(dst_data.at<double>(2,0)+0.5);	anchorPt[2].y = (int)(dst_data.at<double>(2,1)+0.5);
			break;
		}

		//仅1 2
	case 3:
	case 12:  //仅 3 4
		{
			//检查是否异常
			if (anchorPt[1].x == anchorPt[0].x)
				return -2;
			angle = atan(((double)(anchorPt[1].y-anchorPt[0].y))/(anchorPt[1].x-anchorPt[0].x))*180/CV_PI;
			/// 求得旋转变换矩阵
			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//134缺2
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = 0;	src_data.at<double>(2,1) = 0;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			break;
		}

	case 10: //仅2 4
	case 5:  //仅1 3
		{
			//检查是否异常
			if (anchorPt[0].y == anchorPt[1].y)
				return -2;
			angle = -atan(((double)(anchorPt[1].x-anchorPt[0].x))/(anchorPt[1].y-anchorPt[0].y))*180/CV_PI;
			/// 求得旋转变换矩阵
			warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
			//134缺2
			src_data.at<double>(0,0) = anchorPt[0].x;	src_data.at<double>(0,1) = anchorPt[0].y;
			src_data.at<double>(1,0) = anchorPt[1].x;	src_data.at<double>(1,1) = anchorPt[1].y;
			src_data.at<double>(2,0) = 0;	src_data.at<double>(2,1) = 0;
			src_data.col(2) = 1;
			Mat dst_data = src_data *warp_mat.t();
			anchorPt[0].x = (int)(dst_data.at<double>(0,0)+0.5);	anchorPt[0].y = (int)(dst_data.at<double>(0,1)+0.5);
			anchorPt[1].x = (int)(dst_data.at<double>(1,0)+0.5);	anchorPt[1].y = (int)(dst_data.at<double>(1,1)+0.5);
			break;
		}
	default:
		//未定义定位点分布类型
		return 2;
	}
	/// 对源图像应用上面求得的仿射变换
	warpAffine( src, dst, warp_mat, src.size());
// 	cout<<angle<<endl;
// 	imwrite("I:\\aa.jpg",dst);
// 	imshow("dst",dst);
// 	waitKey();
	return 0;
}

//褶皱检测
bool DetectFold(vector<Rect> anchorPoints,vector<Rect> anchorPoints2)
{
	if (anchorPoints.size() != anchorPoints2.size())
		return true;

	Point src_pt1,src_pt2,dst_pt1,dst_pt2,diff1,diff2;
	src_pt1.x = anchorPoints[1].x - anchorPoints[0].x;
	src_pt1.y = anchorPoints[1].y - anchorPoints[0].y;
	src_pt2.x = anchorPoints[2].x - anchorPoints[0].x;
	src_pt2.y = anchorPoints[2].y - anchorPoints[0].y;

	dst_pt1.x = anchorPoints2[1].x - anchorPoints2[0].x;
	dst_pt1.y = anchorPoints2[1].y - anchorPoints2[0].y;
	dst_pt2.x = anchorPoints2[2].x - anchorPoints2[0].x;
	dst_pt2.y = anchorPoints2[2].y - anchorPoints2[0].y;

	diff1.x = abs(src_pt1.x-dst_pt1.x);
	diff1.y = abs(src_pt1.y-dst_pt1.y);
	diff2.x = abs(src_pt2.x-dst_pt2.x);
	diff2.y = abs(src_pt2.y-dst_pt2.y);

	double t = anchor_point_max_shift*anchorPoints[0].height;
	if (diff1.x>t||diff1.y>t||diff2.x>t||diff2.y>t)
		return true;

	return false;
}
//类型三无定位点的倾斜矫正与定位矩形和参考点的获取
int TiltCorrection(Mat src,Mat &dst,Rect &anchorRect,Point &originalPoint, double &angle)
{
	Mat srcGray;
	if (src.channels()!=1)
	{
		cvtColor(src,srcGray,CV_BGR2GRAY);
	}else
		srcGray=src;

	dst=src.clone();
 	Rect roiRect;
 	double rectRange=0.5;
 	roiRect.width=MIN(anchorRect.width*(1+rectRange),src.cols);
 	roiRect.height=MIN(anchorRect.height*(1+rectRange),src.rows);
 	roiRect.x=MIN(MAX(anchorRect.x - ((roiRect.width-anchorRect.width)>>1),0),src.cols-roiRect.width);
 	roiRect.y = MIN(MAX(anchorRect.y - ((roiRect.height-anchorRect.height)>>1),0),src.rows-roiRect.height);
	Mat roi_img=srcGray(roiRect).clone();
	// 	imshow("src",src);
	// 	imshow("roi",roi_img);
	// 	waitKey();
	Mat bw,fillHole_img;
	double rectThresh=0.8;//去除干扰轮廓的阈值
	double thresh = threshold(roi_img,bw,100,255,THRESH_BINARY|THRESH_OTSU);
	threshold(roi_img,bw,thresh * 1.1,255,THRESH_BINARY);
	bw=255-bw;
	Size seSize;
	Mat se;
	se = getStructuringElement(MORPH_CROSS,Size(3,3));
	morphologyEx(bw,bw,cv::MORPH_DILATE,se);
	//imshow("roiimg",roi_img);
	//imshow("bw",bw);
	//cvWaitKey();
	//imwrite("I:\\aa.jpg",bw);
	vector<vector<Point> > contours;
	findContours(bw,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE );
	if (contours.size()>1)    //去除干扰轮廓
	{
		for (vector<vector<Point> >::iterator it=contours.begin();it!=contours.end();)
		{
			Rect rect=boundingRect(*it);
			if (rect.width<anchorRect.width*rectThresh||rect.height<rectThresh*anchorRect.height)
			{
				it=contours.erase(it);
			}
			else
				it++;

		}
	}
	//得到矩形轮廓
	if (contours.size()==1)
	{
		fillHole_img=roi_img.clone();
		fillHole_img = 255 - fillHole_img;
		drawContours(fillHole_img, contours, -1, CV_RGB(255,255,255), -1);

		Rect myrect=boundingRect(contours[0]);
		seSize.width = anchorRect.width >>2;
		seSize.height =MIN(anchorRect.height >>2,MAX(15,(anchorRect.height >>3)+5));
		se = getStructuringElement(MORPH_RECT,seSize);
		morphologyEx(fillHole_img,fillHole_img,cv::MORPH_OPEN,se);
		threshold(fillHole_img,bw,128,255,THRESH_BINARY);
		findContours(bw,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
 
  		/*imshow("srcimg",roi_img);
  		imshow("roiimg",fillHole_img);
  		imwrite("I:\\aa.jpg",fillHole_img);
  		waitKey();*/
		if (contours.size()>1)    //去除干扰轮廓
		{
			for (vector<vector<Point> >::iterator it=contours.begin();it!=contours.end();)
			{
				Rect rect=boundingRect(*it);
				if (rect.width<anchorRect.width*rectThresh||rect.height<rectThresh*anchorRect.height)
				{
					it=contours.erase(it);
				}
				else
					it++;

			}
		}
		if (contours.size()!=1)
		{
			return 2;
		}
		vector<Point> boundary=contours[0];
		Point minx(0,0),miny(0,0);
		miny=boundary[0];
		minx=boundary[2];
		Rect rect=boundingRect(boundary);
		if(abs(minx.x-miny.x)>abs(minx.y-miny.y))
		{
			int i=2;
			while(i<boundary.size())
			{
				if(abs(boundary[i+1].x-boundary[i].x)<abs(boundary[i+1].y-boundary[i].y))
					break;
				i++;
			}
			minx=boundary[i];
		}
		else
		{
			SortPoint(contours[0]);
			minx=contours[0][0];

		}
		double dist=sqrt((double)((minx.x-miny.x)*(minx.x-miny.x)+(minx.y-miny.y)*(minx.y-miny.y)));
		double dist_thresh=min(anchorRect.width,anchorRect.height)*0.3;
		int rectWDiff = abs(rect.width-anchorRect.width);
		int rectHDiff = (rect.height-anchorRect.height);
		//如果两个点x或y坐标相差较小 或者两个点距离较近 则不需要进行倾斜矫正
		if (min(abs(minx.x-miny.x),abs(minx.y-miny.y))<3||dist<dist_thresh||rectWDiff<4&&rectHDiff<3&&rectHDiff>-5)
		{
			angle=0;
			Rect rect=boundingRect(boundary);
			anchorRect.width=rect.width;
			anchorRect.height=rect.height;
			anchorRect.x=rect.x+roiRect.x;
			anchorRect.y=rect.y+roiRect.y;
			originalPoint.x=anchorRect.x/*+anchorRect.width>>1*/;
			originalPoint.y=anchorRect.y/*+anchorRect.height>>1*/;
			return 0;
		}
		angle=atan(((double)(miny.x-minx.x)/(minx.y-miny.y)))*180/CV_PI;
		if (angle>45)
		{
			angle=angle-90;
		}
		Mat warp_mat = getRotationMatrix2D(cv::Point2d(src.cols>>1,src.rows>>1),angle,1);
		warpAffine( src, dst, warp_mat, src.size(),1,0,Scalar(255,255,255));

//  		imshow("src",src);
//  		imshow("dst",dst);
//  		waitKey();
		if (GetOriginalPoint(dst,roiRect,originalPoint)==0)
		{
			anchorRect=roiRect;
			return 0;
		} 
		else
		{
			return 1;
		}

	} 
	else
	{
		return -1;     //未找到匹配矩形框
	}
	return 0;
}
 //获取矫正后图像的矩形框位置与大小
int GetOriginalPoint(Mat srcimg,Rect &anchorRect,Point &originalPoint)
{
	Mat src;
	if (srcimg.channels()!=1)
	{
		cvtColor(srcimg,src,CV_BGR2GRAY);
	}else
		src=srcimg.clone();
	//	cvtColor(srcimg,src,CV_BGR2GRAY);
	Mat roi=src(anchorRect).clone();
	Mat bw;

	double rectThresh=0.6;
	double thresh = threshold(roi,bw,100,255,THRESH_BINARY|THRESH_OTSU);
	//	imshow("roiimg",src);
	//imshow("roi",roi);
	//imshow("bw",bw);
	//cvWaitKey();
	bw=255-bw;
	vector<vector<Point> > contours;
	findContours(bw,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );
	if (contours.size()>1)    //去除干扰轮廓
	{
		for (vector<vector<Point> >::iterator it=contours.begin();it!=contours.end();)
		{
			Rect rect=boundingRect(*it);
			if (rect.width<anchorRect.width*rectThresh||rect.height<rectThresh*anchorRect.height)
			{
				it=contours.erase(it);
			}
			else
				it++;

		}
	}
	if (contours.size()==1)
	{
		Size seSize;
		Mat fillHole_img=roi.clone();
		fillHole_img = 255 - fillHole_img;
		drawContours(fillHole_img, contours, -1, CV_RGB(255,255,255), -1);
		seSize.width = anchorRect.width >>2;
		seSize.height = anchorRect.height >>2;
		Mat se = getStructuringElement(MORPH_RECT,seSize);
		morphologyEx(fillHole_img,fillHole_img,cv::MORPH_OPEN,se);
		threshold(fillHole_img,bw,128,255,THRESH_BINARY);
		findContours(bw,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
		if (contours.size()!=1)
		{
			return 1;
		}
		Rect rect=boundingRect(contours[0]);
		// 		imshow("rect",roi(rect));
		// 		waitKey();
		anchorRect.width=rect.width;
		anchorRect.height=rect.height;
		anchorRect.x+=rect.x;
		anchorRect.y+=rect.y;
		originalPoint.x=anchorRect.x/*+anchorRect.width>>1*/;
		originalPoint.y=anchorRect.y/*+anchorRect.height>>1*/;
		return 0;
	}
	else if (contours.size()==0)
	{
		return 1;
	} 
	else
	{
		return 2;
	}


}

//Point比较算法,按x坐标排序
bool PointXCompare(cv::Point& pt1,cv::Point& pt2)
{
	if (pt1.x==pt2.x)
	{
		return pt1.y<pt2.y;
	}
	else
		return pt1.x<pt2.x;
}
//Point比较算法,按y坐标排序
bool PointYCompare(cv::Point& pt1,cv::Point& pt2)
{
	return pt1.y<pt2.y;
}

void SortPoint(vector<cv::Point>& points,bool isSortByX)
{
	if (isSortByX)
	{
		sort(points.begin(),points.end(),PointXCompare);
	}else
		sort(points.begin(),points.end(),PointYCompare);
}