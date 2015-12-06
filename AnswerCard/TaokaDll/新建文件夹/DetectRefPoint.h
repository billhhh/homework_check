#include "ACStructs.h"
#include <cv.h>
using namespace cv;
//ʶ��ο���
 int DetectRefPoint(Mat srcImg,vector<Rect> srcYMarker,vector<Rect> yMarker,vector<Rect> & refPoint,Rect & refMarkerPos,Point posRevise,double &angle);
//Ԥ����
void PreprocesrefPointRoi(Mat &RoiImage,cv::Size refSize);
extern vector<cv::Rect> DetectRectangle(Mat roi_img,Size rectSize);

extern void SortRects(vector<cv::Rect>& rects,bool isSortByX);
//����ʶ��ο���Ͷ�Ӧ��ǵ�֮��ĽǶ�
void GetrefMarkerAngle(const Rect &yMarker,const Rect &refPoint,double &angle);
//����ʶ��ο����Ӧ�ı�ǵ�
int GetMarker(const vector<Rect> &srcYMarker,Rect refPoint);





