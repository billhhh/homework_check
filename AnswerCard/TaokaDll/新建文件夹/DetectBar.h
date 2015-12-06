#ifndef _ACALGORITHM_H
#define _ACALGORITHM_H
#include<string>
#include "ACStructs.h"
#include<cv.h>
#include<zbar.h>
using namespace cv;
using namespace zbar;
//extern AC_info acinfo;  //�⿨��Ϣ�ṹ��
bool GetBar(Mat bar,string &str);//�������� MatΪ���������������ͼ���,strΪʶ������Mat����Ϊ�Ҷ�ͼƬ������ʶ�𲻳������
bool GetBar(Mat src,Rect rect,string &str);//�������⣻srcΪԴͼ��RectΪ��������������strΪ����ַ�����
int GetBar(Mat src,vector<Bar_info> barGroup,vector<BarResult> &barResult,double xRangeScale,double yRangeScale);//�������⣬bargroupΪ�������������������Ϣ��barresultΪʶ����
int GetBar(Mat src,vector<Bar_info> barGroup,vector<BarResult> &barResult);     //�������������⣬û��Ҫ������������
#endif