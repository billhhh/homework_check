#include <math.h>
#include <cv.h>

using namespace cv;
//��бУ��
//���в���rtΪ4����λ�����Ӿ�����	1|2
//����������ͼ						-+-
//									3|4
int TiltCorrection(Mat src,Mat &dst,cv::Rect* rt,double &angle);
int TiltCorrection(Mat src,Mat &dst,vector<cv::Rect> &anchorPt,short anchorType,double &angle);
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* �������޶�λ�� ����б�����붨λ���κͲο���Ļ�ȡ                    */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////

//srcΪԴͼ��dstΪ��б�������ͼ��anchorRectΪ��λ��������originalPointΪ��λ��׼�㣬angleΪ��б�Ƕ�
int TiltCorrection(Mat src,Mat &dst,Rect &anchorRect,Point &originalPoint, double &angle);
//��ȡ������ͼ��ľ��ο�λ�����С
int GetOriginalPoint(Mat src,Rect &anchorRect,Point &originalPoint);
void SortPoint(vector<cv::Point>& points,bool isSortByX=true);
//������
bool DetectFold(vector<Rect> anchorPoints,vector<Rect> anchorPoints2);
//��λ�����λ����ֵ����Զ�λ��߶ȵı���
const double anchor_point_max_shift = 1.0f;