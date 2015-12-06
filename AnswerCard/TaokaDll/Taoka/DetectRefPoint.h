#include "ACStructs.h"
#include <cv.h>
using namespace cv;
//ʶ��ο���
 int DetectRefPoint(Mat srcImg,vector<Rect> srcXMarker,vector<Rect> xMarker,vector<Rect> srcYMarker,vector<Rect> yMarker,vector<Rect> & refPoint,Rect & refMarkerPos,Point posRevise,double &angle);
//Ԥ����
void PreprocesrefPointRoi(Mat &RoiImage,cv::Size refSize);
extern vector<cv::Rect> DetectRectangle(Mat roi_img,Size rectSize);

extern void SortRects(vector<cv::Rect>& rects,bool isSortByX);
//����ʶ��ο���Ͷ�Ӧ��ǵ�֮��ĽǶ�
void GetrefMarkerAngle(const Rect &yMarker,const Rect &refPoint,double &angle);
//����ʶ��ο����Ӧ��x�����ǵ�
int GetXMarker(const vector<Rect> &srcXMarker,Rect refPoint);
//����ʶ��ο����Ӧ��y�����ǵ�
int GetYMarker(const vector<Rect> &srcYMarker,Rect refPoint);





