#include"ACStructs.h"
#include <cv.h>
using namespace cv;

#define Marker_ERR_BASE_OVERNUM	1
#define XMarker_ERR_OVERNUM 2
#define XMarker_ERR_QUANTITYSHORTAGE 3
#define XMarker_ERR_OVERMAXDIFFRATE 4
#define YMarker_ERR_OVERNUM 2
#define YMarker_ERR_QUANTITYSHORTAGE 3
#define YMarker_ERR_OVERMAXDIFFRATE 4
//��ǵ�����������
const float marker_width_max_diff_rate = 0.3f;
const float marker_height_max_diff_rate = 0.35f;

extern void PreprocesRoi(Mat &RoiImage,cv::Size Markersize);
extern void PreprocesAnchorRoi(Mat &RoiImage,cv::Size Markersize);
//ͬ��ͷ�쳣���
int DetectXMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo );
int DetectXMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo ,Size anchorSize);
int DetectYMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo);
int DetectYMarkersERR(vector<cv::Rect> &DetectedRect,Marker_info TemMakerInfo ,Size anchorSize);
//���ο���
extern vector<cv::Rect> DetectRectangle(Mat roi_img,Size rectSize);
vector<cv::Rect> DetectRectangle(Mat roi_img,Size markSize,Size anchorSize);
//����ͬ��ͷ���
int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & xMarkers);
int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & xMarkers,double xRangeScale,double yRangeScale);
int DetectXMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,Size anchorSize,vector<cv::Rect> & xMarkers,double xRangeScale,double yRangeScale);
//����ͬ��ͷ���
int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & yMarkers);
int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,vector<cv::Rect> & yMarkers,double xRangeScale,double yRangeScale);
int DetectYMarkers(Mat srcimg,Marker_info markerInfo,cv::Point originalPt,Size anchorSize,vector<cv::Rect> & yMarkers,double xRangeScale,double yRangeScale);
//��Rect����
void SortRects(vector<cv::Rect>& rects,bool isSortByX = true);