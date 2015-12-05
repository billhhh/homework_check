#pragma once
#ifndef ANSWERCARD_H
#define ANSWERCARD_H

#include <cv.h>
#include <highgui.h>
#include "qpoint.h"
#include "qstring.h"
#include "qsettings.h"
#include "AnswerCardProcessing.h"
#include "MarkersBoundaryTable.h"
#include "..\XmlIO\XmlIO.h"

using namespace cv;

struct FillPoint
{
	ushort type;
	cv::Rect rect;
	int interval;
	bool isCrossWise;
	short num;
};

struct Questions
{
	short num;
	int interval;
	cv::Rect rect;
	bool isCrossWise;
};

//��״̬
enum GroupState
{
	InitialState,   //��ʼ״̬
	AnchorState,   //��λ��
	MarkerState,    //��ǵ�
	BarCodeState,//������
	FillPointState,//��Ϳ��
	ClipState,//����
	QuestionState,//����Ϳ
	MarkerMakeState,
	WhiteLineState,//�׼��
	BlackLineState,//�ڼ��
	AnchorRectState,
	IdPointState,//id��
	PagePointState
};

enum AnchorSubState
{
	AnchorInitial,
	LTBegin,
	LTEnd,
	RTBegin,
	RTEnd,
	LBBegin,
	LBEnd,
	RBBegin,
	RBEnd
};

enum MarkerSubState
{
	MarkerInitial,
	RowBegin,
	RowPress,
	RowRelease,
	ColBegin,
	ColPress,
	ColRelease
};

enum BaseSubState
{
	BaseInitial,
	BaseBegin,
	BasePress,
	BaseRelease,
	BaseEnd
};

enum QuestionSubState
{
	QuestionInitial,
	SingleBegin,
	SinglePress,
	SingleRelease,
	SingleEnd,
	MultiBegin,
	MultiPress,
	MultiRelease,
	MultiEnd
};

double GetEmptyRate(Mat gray);
PerFillingPtBackground_info  GetPerFillingPtBackground_info(Mat img2,
	int num,int interval,bool isCrosswise,FillingPointsType type);
PerQuestionBackground_info  GetPerQuestionBackground_info(Mat img2,int num,bool isCrosswise);

class CAnswerCardApp
{
public:
	CAnswerCardApp();

	bool m_hasQuestions;
	///////////////////////////////////�洢����///////////////////////////////////////
	// ��״̬
	unsigned short m_group_state;
	// ��״̬
	unsigned short m_state;
	// ��λ��ֲ�����
	int anchor_type;
	//��λ����
	cv::Rect anchorPoints[4];
	//ˮƽ����ֱ��ǵ�����
	cv::Rect markersRect[2];
	//ˮƽ��ǵ���
	vector<cv::Rect> hmarkers;
	//��ֱ��ǵ���
	vector<cv::Rect> vmarkers;
	//��Ŀ��Ϣ
	vector<ItemPos> questionInfo;
	//��ǵ�߽��
	MarkersBoundaryTable markerBT;
	//�Զ�����Ϳ��
	vector<FillingPoints_info> cfp_group;
	cv::Rect cfp_tmpRect;
	//��������
	vector<CropArea_info> cropAreas;
	//����������
	vector<Bar_info> barGroup;
	//ID��
	vector<ItemPos> idGroup;
	//
	cv::Rect whiteLineRect;
	cv::Rect blackLineRect;
	//ʶ��ο���
	vector<cv::Rect> referPoint;

	int questionType;

	void clear();
	vector<FillPoint> CountFillPointsBackground();
	vector<Questions> CountQuestionsBackground();

	////////////////////////////////��������/////////////////////////////////////////
	//opencv
	Mat img_raw;
	Mat img_gray;
	Mat img_bw;
	Mat img_show;
	Mat img_bk;
	// ��λ����ɫ���߿�
	Scalar anchor_point_color;
	unsigned short anchor_point_thickness;
	//��ǵ�������ɫ���߿�
	Scalar markers_point_color;
	unsigned short markers_point_thickness;
	//������������ɫ�߿�
	Scalar barcode_color;
	unsigned short barcode_thickness;
	Scalar barcodeClicked_color;
	unsigned short barcodeClicked_thickness;
	//����Ϳ����ɫ�߿�
	Scalar answer_color;
	Scalar answer_multi_color;
	unsigned short answer_single_thickness;
	unsigned short answer_multi_thickness;
	Scalar answerClicked_color;
	Scalar answerClicked_multi_color;
	unsigned short answerClicked_single_thickness;
	unsigned short answerClicked_multi_thickness;
	//�û��Զ�����Ϳ��������ɫ���߿�
	Scalar cfp_color;
	unsigned short cfp_thickness;
	Scalar cfpClicked_color;
	unsigned short cfpClicked_thickness;
	//����������ɫ���߿�
	Scalar cropArea_color;
	unsigned short cropArea_thickness;
	Scalar cropAreaClicked_color;
	unsigned short cropAreaClicked_thickness;
	//�׼������ɫ���߿�
	Scalar whiteLine_color;
	unsigned short whiteLine_thickness;
	//�ڼ������ɫ���߿�
	Scalar blackLine_color;
	unsigned short blackLine_thickness;
	//�����ǵ���ɫ
	Scalar marker_color;
	Scalar markerClicked_color;
	unsigned short markerClicked_thickness;
	//id����ɫ�߿�
	Scalar idPoint_color;
	unsigned short idPoint_thickness;
	Scalar idPointClicked_color;
	unsigned short idPointClicked_thickness;
	//��ȡ�����ļ������ø����߿���ɫ�����
	void readConfig();

	///////////////////////////////////�������///////////////////////////////////////
public:
	AC_info acinfo;

public:
	// ��������ڵ���ͨ����Ӿ��Σ�������
	bool GetArchorPointRect(QPoint pt, int ap_idx, bool is_draw= true);
	// ���»���
	int Redraw(void);
	// ����ʾͼ���������Ƿ�ͬ��
	bool is_synchronous;
	// �����ǵ�����
	vector<cv::Rect> GetMarkersNum(Mat roi);
	//�Ա�ǵ�����
	void SortMarkers(bool is_hmarkers);
	// ��ǵ���С���
	int min_markers_area;
	// ���ļ��ж�ȡͼ��
	int LoadImg(const QString &path);
	// ת��������ṹ��
	int TransToOutputStruct();
	// �¼�һ����
	void AddQuestion(int id, bool isCrosswise, bool isSingleChoice, ushort interval,
		ushort markerIdx0, ushort markerIdx1, ushort markerIdx2);
	void AddFillPoint(string name, FillingPointsType type, bool isCrosswise, 
		int cspace, int rspace, int idx_l, int idx_r, int idx_t, int idx_b);
	void AddIdPoint(int id, ushort markerIdx0, ushort markerIdx1, ushort markerIdx2);
	//���������Ϣ
	void clearACInfo();
};

extern CAnswerCardApp theApp;

#endif