#include "stdafx.h"
#include "DetectMarkers.h"
#include<highgui.h>


/************************************************************************/
/*								�������ǵ�
������
	srcimg��		���⿨ͼ��
	markerInfo��	����ı�ǵ���Ϣ
	xMarkers��		���ڴ�������к�����������м����ľ��Σ����õ��ı�ǵ��ʵ��λ��ͨ���ò�������

����ֵ��
	0��		����
	!0��	�쳣
*/
/************************************************************************/
int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & xMarkers){  //�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.xMarker;
	roiRect.x += originalPt.x;
	roiRect.y += originalPt.y;
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
	PreprocesRoi(RoiImage,markerInfo.xSize);
// 	imshow("test",RoiImage);
// 	cvWaitKey(0);
	vector<cv::Rect> DetectedXRect;			//������Ȥ�����ھ���
	DetectedXRect=DetectRectangle(RoiImage,markerInfo.xSize);
	int X_err_ID=DetectXMarkersERR(DetectedXRect,markerInfo);
	if (!X_err_ID)
	{
		for (i=0;i<DetectedXRect.size();i++)
		{	
			DetectedXRect[i].x += roiRect.x;
			DetectedXRect[i].y += roiRect.y;
			xMarkers.push_back( DetectedXRect[i]);
		}
	}
	else
	{
		return 	Marker_ERR_BASE_OVERNUM +X_err_ID;
	}
	SortRects(xMarkers);
	return 0;
} 


int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & xMarkers,double xRangeScale,double yRangeScale)
{  //�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.xMarker;
	roiRect.x += originalPt.x-((int)(xRangeScale*markerInfo.xSize.width)>>1);
	roiRect.y += originalPt.y-((int)(yRangeScale*markerInfo.xSize.height)>>1);
	
	//���ݲ�������roiλ����ߴ�
	roiRect.width += (int)(xRangeScale*markerInfo.xSize.width);
	roiRect.height += (int)(yRangeScale*markerInfo.xSize.height);
	roiRect.width=MIN(roiRect.width,srcimg.cols);
	roiRect.height=MIN(roiRect.height,srcimg.rows);
	roiRect.x = MIN(MAX(roiRect.x,0),srcimg.cols-roiRect.width);
	roiRect.y = MIN(MAX(roiRect.y,0),srcimg.rows-roiRect.height);
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
	PreprocesRoi(RoiImage,markerInfo.xSize);
  	//imshow("xMarker",RoiImage);
  	//cvWaitKey(0);
	vector<cv::Rect> DetectedXRect;			//������Ȥ�����ھ���
	DetectedXRect=DetectRectangle(RoiImage,markerInfo.xSize);
	int X_err_ID=DetectXMarkersERR(DetectedXRect,markerInfo);

	if (!X_err_ID)
	{
		for (i=0;i<DetectedXRect.size();i++)
		{	
			DetectedXRect[i].x += roiRect.x;
			DetectedXRect[i].y += roiRect.y;
			xMarkers.push_back( DetectedXRect[i]);
		}
	}
	else
	{
		return 	Marker_ERR_BASE_OVERNUM +X_err_ID;
	}
	SortRects(xMarkers);
	return 0;
} 
int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,Size anchorSize, vector<cv::Rect> & xMarkers,double xRangeScale,double yRangeScale)
{  //�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.xMarker;
	roiRect.x += originalPt.x-((int)(xRangeScale*markerInfo.xSize.width)>>1);
	roiRect.y += originalPt.y-((int)(yRangeScale*markerInfo.xSize.height)>>1);

	//���ݲ�������roiλ����ߴ�
	roiRect.width += (int)(xRangeScale*markerInfo.xSize.width);
	roiRect.height += (int)(yRangeScale*markerInfo.xSize.height);
	roiRect.width=MIN(roiRect.width,srcimg.cols);
	roiRect.height=MIN(roiRect.height,srcimg.rows);
	roiRect.x = MIN(MAX(roiRect.x,0),srcimg.cols-roiRect.width);
	roiRect.y = MIN(MAX(roiRect.y,0),srcimg.rows-roiRect.height);
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
	PreprocesRoi(RoiImage,markerInfo.xSize);
// 	imwrite("I:\\aa.jpg",RoiImage);
// 	imshow("xMarker",RoiImage);
// 	waitKey(0);
	
	vector<cv::Rect> DetectedXRect;			//������Ȥ�����ھ���
	DetectedXRect=DetectRectangle(RoiImage,markerInfo.xSize,anchorSize);
	if (DetectedXRect.size()==0)
	{
		return 	Marker_ERR_BASE_OVERNUM;
	}
	int X_err_ID=DetectXMarkersERR(DetectedXRect,markerInfo,anchorSize);

	if (!X_err_ID)
	{
		for (i=0;i<DetectedXRect.size();i++)
		{	
			DetectedXRect[i].x += roiRect.x;
			DetectedXRect[i].y += roiRect.y;
			xMarkers.push_back( DetectedXRect[i]);
		}
	}
	else
	{
		return 	X_err_ID;
	}
	SortRects(xMarkers);
	return 0;
} 

/************************************************************************/
/*								��������ǵ�
������
	srcimg��		���⿨ͼ��
	markerInfo��	����ı�ǵ���Ϣ
	yMarkers��		���ڴ��������������������м����ľ��Σ����õ��ı�ǵ��ʵ��λ��ͨ���ò�������

����ֵ��
	0��		����
	!0��	�쳣
*/
/************************************************************************/
int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & yMarkers){	//�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.yMarker;
	roiRect.x += originalPt.x;
	roiRect.y += originalPt.y;
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
	PreprocesRoi(RoiImage,markerInfo.ySize);
// 	imwrite("yMarker.jpg",RoiImage);
// 	imshow("test",RoiImage);
// 	cvWaitKey(0);
	vector<cv::Rect> DetectedYRect;			//������Ȥ�����ھ���
	DetectedYRect=DetectRectangle(RoiImage,markerInfo.ySize);
	int Y_err_ID=DetectYMarkersERR(DetectedYRect,markerInfo);
	if (!Y_err_ID)
	{
		for (i=0;i<DetectedYRect.size();i++)
		{	
			DetectedYRect[i].x += roiRect.x;
			DetectedYRect[i].y += roiRect.y;
			yMarkers.push_back( DetectedYRect[i]);
		}	
	}
	else
	{
		return 	Marker_ERR_BASE_OVERNUM +Y_err_ID;
	}
	SortRects(yMarkers,false);
	return 0;
} 

int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & yMarkers,double xRangeScale,double yRangeScale){	//�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.yMarker;

	roiRect.x += originalPt.x-((int)xRangeScale*markerInfo.ySize.width>>1);
	roiRect.y += originalPt.y-((int)yRangeScale*markerInfo.ySize.height>>1);

	//���ݲ�������roiλ����ߴ�
	roiRect.width += (int)(xRangeScale*markerInfo.ySize.width);
	roiRect.height += (int)(yRangeScale*markerInfo.ySize.height);
	roiRect.width=MIN(roiRect.width,srcimg.cols);
	roiRect.height=MIN(roiRect.height,srcimg.rows);
	roiRect.x = MIN(MAX(roiRect.x,0),srcimg.cols-roiRect.width);
	roiRect.y = MIN(MAX(roiRect.y,0),srcimg.rows-roiRect.height);
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
// 	imshow("ymarker",RoiImage);
// 	cvWaitKey(0);
	PreprocesRoi(RoiImage,markerInfo.ySize);
	/*imwrite("yMarker.jpg",RoiImage);
 	imshow("ymarker",RoiImage);
 	cvWaitKey(0);*/
	vector<cv::Rect> DetectedYRect;			//������Ȥ�����ھ���
	DetectedYRect=DetectRectangle(RoiImage,markerInfo.ySize);
	int Y_err_ID=DetectYMarkersERR(DetectedYRect,markerInfo);
	if (!Y_err_ID)
	{
		for (i=0;i<DetectedYRect.size();i++)
		{	
			DetectedYRect[i].x += roiRect.x;
			DetectedYRect[i].y += roiRect.y;
			yMarkers.push_back( DetectedYRect[i]);
		}	
	}
	else
	{
		
		return 	Marker_ERR_BASE_OVERNUM +Y_err_ID;
	}
	SortRects(yMarkers,false);
	return 0;
} 
//��Ӷ�λ����Ϣ �Ա��ⶨλ���ͬ��ͷʶ��ĸ���
int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,Size anchorSize,vector<cv::Rect> & yMarkers,double xRangeScale,double yRangeScale){	//�����ǵ���
	unsigned int i;
	cv::Rect  roiRect;
	roiRect = markerInfo.yMarker;

	roiRect.x += originalPt.x-((int)xRangeScale*markerInfo.ySize.width>>1);
	roiRect.y += originalPt.y-((int)yRangeScale*markerInfo.ySize.height>>1);
	//���ݲ�������roiλ����ߴ�
	roiRect.width += (int)(xRangeScale*markerInfo.ySize.width);
	roiRect.height += (int)(yRangeScale*markerInfo.ySize.height);
	roiRect.width=MIN(roiRect.width,srcimg.cols);
	roiRect.height=MIN(roiRect.height,srcimg.rows);
	roiRect.x = MIN(MAX(roiRect.x,0),srcimg.cols-roiRect.width);
	roiRect.y = MIN(MAX(roiRect.y,0),srcimg.rows-roiRect.height);
	Mat RoiImage;
	RoiImage=srcimg(roiRect);				//�ü�����Ȥ����
 	//imshow("ymarker",RoiImage);
 	//cvWaitKey(0);
	PreprocesRoi(RoiImage,markerInfo.ySize);

// 	imwrite("G:\\yMarker.jpg",RoiImage);
// 	imshow("ymarker",RoiImage);
// 	cvWaitKey(0);

	vector<cv::Rect> DetectedYRect;			//������Ȥ�����ھ���
	DetectedYRect=DetectRectangle(RoiImage,markerInfo.ySize,anchorSize);
	if (DetectedYRect.size()==0)
	{
		return 	Marker_ERR_BASE_OVERNUM;
	}
	int Y_err_ID=DetectYMarkersERR(DetectedYRect,markerInfo,anchorSize);
	if (!Y_err_ID)
	{
		for (i=0;i<DetectedYRect.size();i++)
		{	
			DetectedYRect[i].x += roiRect.x;
			DetectedYRect[i].y += roiRect.y;
			yMarkers.push_back( DetectedYRect[i]);
		}	
	}
	else
	{
		
		return 	Y_err_ID;
	}
	SortRects(yMarkers,false);
	return 0;
} 

//vector�ȽϷ���,��������
bool RectWidthCompare(cv::Rect rt1,cv::Rect rt2)
{
	return rt1.width<rt2.width;
}
//vector�ȽϷ���,��������
bool RectHeightCompare(cv::Rect rt1,cv::Rect rt2)
{
	return rt1.height<rt2.height;
}

/*�������ǵ���ε��쳣*/
int DetectXMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo ){       
	if(DetectedRect.size()>TemMakerInfo.xNum)
	{
		//ȥ���쳣
		SortRects(DetectedRect,false);				//��y����
		Rect standardRect = DetectedRect.at(DetectedRect.size()/2);	//ȡ��λ��
		for(vector<cv::Rect>::iterator it  = DetectedRect.begin(); it != DetectedRect.end(); )  
		{  
			if (abs(it->y-standardRect.y)>standardRect.height)
			{
				it = DetectedRect.erase(it);
			}else
				it++;			
		} 
		if (DetectedRect.size()>TemMakerInfo.xNum)
		{
			return XMarker_ERR_OVERNUM;
		}else if (DetectedRect.size()<TemMakerInfo.xNum)
		{
			return XMarker_ERR_QUANTITYSHORTAGE;
		}
	}
	else if(DetectedRect.size()<TemMakerInfo.xNum)
		return XMarker_ERR_QUANTITYSHORTAGE ;
	//����Ȳ����
	auto cmpResult = std::minmax_element(DetectedRect.begin(),DetectedRect.end(),RectWidthCompare);
	Rect minWidthRect = *cmpResult.first;
	Rect maxWidthRect = *cmpResult.second;
 	int widthMaxDiff = maxWidthRect.width - minWidthRect.width;
	if (widthMaxDiff>marker_width_max_diff_rate*maxWidthRect.width)
	{
		return XMarker_ERR_OVERMAXDIFFRATE;
	}
	return 0;
}
/*�������ǵ���ε��쳣*/
//��Ӷ�λ���С
int DetectXMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo ,Size anchorSize){ 
	SortRects(DetectedRect,false);				//��y����
	Rect standardRect = DetectedRect.at(DetectedRect.size()/2);	//ȡ��λ��
	standardRect.y+=standardRect.height>>1;
	if(DetectedRect.size()/*>TemMakerInfo.xNum*/)
	{
		//ȥ���쳣

		for(vector<cv::Rect>::iterator it  = DetectedRect.begin(); it != DetectedRect.end(); )  
		{  
			if (abs(it->y + (it->height>>1) - standardRect.y) > standardRect.height)
			{
				it = DetectedRect.erase(it);
			}else
				it++;			
		} 
		if (DetectedRect.size()>TemMakerInfo.xNum)
		{
			return XMarker_ERR_OVERNUM;
		}else if (DetectedRect.size()<TemMakerInfo.xNum)
		{
			return XMarker_ERR_QUANTITYSHORTAGE;
		}
	}
  if(DetectedRect.size()<TemMakerInfo.xNum)
		return XMarker_ERR_QUANTITYSHORTAGE ;
	//����Ȳ����
  /*auto cmpResult = std::minmax_element(DetectedRect.begin(),DetectedRect.end(),RectWidthCompare);
  Rect minWidthRect = *cmpResult.first;
  Rect maxWidthRect = *cmpResult.second;
  int widthMaxDiff = maxWidthRect.width - minWidthRect.width;
  if (widthMaxDiff>(abs(anchorSize.width-standardRect.width)*(1+marker_width_max_diff_rate*2))&&widthMaxDiff>marker_width_max_diff_rate*maxWidthRect.width)
  {
  return XMarker_ERR_OVERMAXDIFFRATE;
  }*/
	return 0;
}


/*��������ǵ���ε��쳣*/
int DetectYMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo){
	if(DetectedRect.size()/*>TemMakerInfo.yNum*/)
	{
		//ȥ���쳣
		SortRects(DetectedRect);
		Rect standardRect = DetectedRect.at(DetectedRect.size()/2);
		for(vector<cv::Rect>::iterator it  = DetectedRect.begin(); it != DetectedRect.end(); )  
		{  
			if (abs(it->x-standardRect.x)>standardRect.height)
			{
				it = DetectedRect.erase(it);
			}else
				it++;			
		} 
		if (DetectedRect.size()>TemMakerInfo.yNum)
		{
			return YMarker_ERR_OVERNUM;
		}else if (DetectedRect.size()<TemMakerInfo.yNum)
		{
			return YMarker_ERR_QUANTITYSHORTAGE;
		}
	}
	 if(DetectedRect.size()<TemMakerInfo.yNum)
		return YMarker_ERR_QUANTITYSHORTAGE ;
	//����Ȳ����
	auto cmpResult = std::minmax_element(DetectedRect.begin(),DetectedRect.end(),RectHeightCompare);
	Rect minHeightRect = *cmpResult.first;
	Rect maxHeightRect = *cmpResult.second;
	int heightMaxDiff = maxHeightRect.height - minHeightRect.height;
	if (heightMaxDiff>marker_height_max_diff_rate*minHeightRect.height)
	{
		return YMarker_ERR_OVERMAXDIFFRATE;
	}
	return 0;
}
int DetectYMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo,Size anchorSize){
	SortRects(DetectedRect);
	Rect standardRect = DetectedRect.at(DetectedRect.size()/2);
	standardRect.x+=standardRect.width>>1;
	if(DetectedRect.size()/*>=TemMakerInfo.yNum*/)
	{
		//ȥ���쳣
		
		for(vector<cv::Rect>::iterator it  = DetectedRect.begin(); it != DetectedRect.end(); )  
		{  
			int b=abs(it->width/2+it->x-standardRect.x);
			if ((abs((it->width>>1)+it->x-standardRect.x)>standardRect.width>>1))
			{
				it = DetectedRect.erase(it);
			}else
				it++;			
		} 
		if (DetectedRect.size()>TemMakerInfo.yNum)
		{
			return YMarker_ERR_OVERNUM;
		}else if (DetectedRect.size()<TemMakerInfo.yNum)
		{
			return YMarker_ERR_QUANTITYSHORTAGE;
		}
	}
	else if(DetectedRect.size()<TemMakerInfo.yNum)
		return YMarker_ERR_QUANTITYSHORTAGE ;
	//����Ȳ����
	/*auto cmpResult = std::minmax_element(DetectedRect.begin(),DetectedRect.end(),RectHeightCompare);
	Rect minHeightRect = *cmpResult.first;
	Rect maxHeightRect = *cmpResult.second;
	int heightMaxDiff = maxHeightRect.height - minHeightRect.height;*/
// 	if (heightMaxDiff>(abs(anchorSize.height-standardRect.height)*(1+marker_height_max_diff_rate*2))&&heightMaxDiff>marker_height_max_diff_rate*minHeightRect.height)
// 	{
// 		return YMarker_ERR_OVERMAXDIFFRATE;
// 	}
	return 0;
}

//vector�Ƚ��㷨,��x��������
bool RectXCompare(cv::Rect& rt1,cv::Rect& rt2)
{
	return rt1.x<rt2.x;
}
//vector�Ƚ��㷨,��y��������
bool RectYCompare(cv::Rect& rt1,cv::Rect& rt2)
{
	return rt1.y<rt2.y;
}

void SortRects(vector<cv::Rect>& rects,bool isSortByX)
{
	if (isSortByX)
	{
		sort(rects.begin(),rects.end(),RectXCompare);
	}else
		sort(rects.begin(),rects.end(),RectYCompare);
}

/*������Ȥ�����ڵľ���*/ 
//Ϊ�˶�λ�������ڱ�ǵ�����

vector<cv::Rect> DetectRectangle(Mat roi_img,Size rectSize,Size anchorSize){


	vector<vector<Point> > contours;    //�������飨�Ǿ������飩��ÿ��������һ��Point�͵�vector
	findContours(roi_img,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );
	vector<cv::Rect> boundRect;                           //��Χ�㼯����С����vector @if contours.size()>2
	Rect bRect;
	double diff_threashold = 0.8;
	Size maxDiffSize(rectSize.width*diff_threashold*.5+0.5,rectSize.height*diff_threashold*.8+0.5);
	Size maxDiffSize2(rectSize.width*diff_threashold*.5+0.5,MAX(maxDiffSize.height,anchorSize.height*diff_threashold*.8+0.5));
	for(int i = contours.size()-1;i>=0; i-- )
	{
		bRect = boundingRect(contours[i]);
		double area=contourArea(contours[i]);
		if(area/bRect.area()<0.55)     //�ж������Ƿ��Ǿ���
			continue;
		//������
		if ((abs(1-(float)rectSize.area()/bRect.area())<diff_threashold)||(abs(1-(float)anchorSize.area()/bRect.area())<diff_threashold))
		{
			cv::Size sizeDiff(abs(rectSize.width-bRect.width),abs(rectSize.height-bRect.height));
			cv::Size sizeDiff2(abs(anchorSize.width-bRect.width),(bRect.height-anchorSize.height));
			if ((sizeDiff.width<=maxDiffSize.width&&sizeDiff.height<=maxDiffSize.height)||(sizeDiff2.width<=maxDiffSize2.width&&sizeDiff2.height<=maxDiffSize2.height&&sizeDiff2.height>= - maxDiffSize.height))
			{
				boundRect.push_back(bRect);    //���㲢���ذ�Χ�����㼯����С����
			}
			else
			{
		/*		cout<<bRect<<endl;*/
			}
			// 			float aspectRatioDiff = abs((float)rectSize.width/rectSize.height-(float)bRect.width/bRect.height);
			// 			//��߱ȼ��
			// 			if (aspectRatioDiff*aspectRatioDiff<diff_threashold)
			// 			{
			// 				boundRect.push_back(bRect);    //���㲢���ذ�Χ�����㼯����С����
			// 			}
		}
		else
		{
	/*		cout<<bRect<<endl;*/
		}

	}
	return boundRect;
}