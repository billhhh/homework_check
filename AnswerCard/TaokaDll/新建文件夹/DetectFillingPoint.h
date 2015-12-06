#include"ACStructs.h"
#include"MarkersBoundaryTable.h"
//ʶ��Id��
bool DetectIdPoint(Mat img,vector<cv::Rect> idPInfo,double areaThresh);
//ʶ���Ծ����͡�ѡ����
int DetectPaperType(Mat Img,bool istype2,ItemPos fPInfo,MarkersBoundaryTable &mbt,double sensibilityThresh,double areaThreshold,FillingPointsResult &fpr);
int DetectPaperType(Mat,FillingpointItemPos fPInfo,cv::Point originalPoint,double sensibilityThresh,double areaThreshold,FillingPointsResult &fpr);   //������
//ʶ��ȱ����Ǻ�Υ����Ϳ��
int DetectAbsent(Mat Img,bool istype2,ItemPos fPInfo,MarkersBoundaryTable &mbt,double areaThreshold,FillingPointsResult &fpr);
int DetectAbsent(Mat,FillingpointItemPos fPInfo,cv::Point originalPoint,double areaThreshold,FillingPointsResult &fpr);		//������
//ʶ�������͵���Ϳ��
int DetectNumericPoint(Mat Img,bool istype2,FillingPoints_info fPInfo,MarkersBoundaryTable &mbt,double sensibilityThresh,double areaThreshold,FillingPointsResult &fpr);
int DetectNumericPoint(Mat,FillingPoints_info3 fPInfo,cv::Point originalPoint,double sensibilityThresh,double areaThreshold,FillingPointsResult &fpr);		//������
//��Ϳ�����Ϳ���ʶ��
int DetectPreFillingPoint( Mat roi,bool istype2,ItemPos fPPos,MarkersBoundaryTable &mbt,Point rectPos,double sensibilityThresh,double areaThreshold,PerFPResult &result);
//������
int DetectPreFillingPoint( Mat img,vector<Rect> pos,bool isSingleChoice,cv::Point originalPoint,double sensibilityThresh,double areaThreshold,PerFPResult &result);