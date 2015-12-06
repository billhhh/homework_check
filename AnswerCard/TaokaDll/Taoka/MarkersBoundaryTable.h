#pragma once
#include"ACStructs.h"
#include <cv.h>
using namespace cv;
#include <vector>
using namespace std;
class MarkersBoundaryTable
{
public:
	//���캯��
	MarkersBoundaryTable(void);
	~MarkersBoundaryTable(void);
	//����߽���ұ�
	//boundaryBuffRate=�߽绺�����Ĵ�С/��ǵ��С
	int InitMarkersBoundaryTable(vector<cv::Rect> hMarkers,vector<cv::Rect> vMarkers,double boundaryBuffRate = 0.5,bool merge = true);
	//�ϲ�����߽�
	int MergeCloseBoundary();
protected:
	//ˮƽ����ֱ�����ǵ�����
	int hMarkersNum,vMarkersNum;
	//ˮƽ�����ǵ����
	int* pHmarkersLBoundary;
	//ˮƽ�����ǵ��ҽ�
	int* pHmarkersRBoundary;
	//��ֱ�����ǵ��Ͻ�
	int* pVmarkersTBoundary;
	//��ֱ�����ǵ��½�
	int* pVmarkersBBoundary;
	//�ϲ���ֵ
	double mergeThreshold;

public:
	// ���ˮƽ��ǵ����
	int GetLBoundary(int hmarker_idx);
	// ���ˮƽ��ǵ��ҽ�
	int GetRBoundary(int hmarker_idx);
	// ��ô�ֱ��ǵ��Ͻ�
	int GetTBoundary(int vmarker_idx);
	// ��ô�ֱ��ǵ��½�
	int GetBBoundary(int vmarker_idx);
	// ���ˮƽ��ǵ�����
	int GetXmarkerNum(void);
	// ��ô�ֱ��ǵ�����
	int GetYmarkerNum(void);
	// ��ͼ���л��Ʊ߽�
	int DrawBoundary(cv::Mat &img,Scalar color,int thickness);
	// ���Ʊ��
	int DrawMarkersNum(Mat & img, Scalar color, int thickness);
	// ��ȡ�����õ�������߽�
	int GetNearestLBoundary(int x);
	// ��ȡ��С�ұ߽�
	int GetNearestRBoundary(int x);
	// ��ȡ����ϱ߽�
	int GetNearestTBoundary(int y);
	// ��ȡ��С�±߽�
	int GetNearestBBoundary(int y);
	//�����Ŀ����
	cv::Rect GetQuestionBoundry(ItemPos pos);
	void printMBT();
};
