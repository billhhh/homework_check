#pragma once

#include "ACStructs.h"
 #include <libxml/parser.h>
 #include <libxml/tree.h>
#include "DataTypeConversion.h"
#ifdef _DLL_XMLIO
#define DLL_XMLIO_API __declspec(dllexport)
#else
#define DLL_XMLIO_API __declspec(dllimport)
#endif
class DLL_XMLIO_API XmlIo
{
public:
// 	XmlIo(void);
// 	~XmlIo(void);
	//��д�ӿ�
	int Read(string filename,AC_info &acInfo);
	int Read(string filename,AC_info3 &acInfo);
	int Read(string filename,TK_info  &tkInfo);
	int Read(string filename,TK_info3  &tkInfo);
	int GetACType(string filename,int &acType);
	int Write(string filename,AC_info acInfo);
	int Write(string filename,AC_info3 acInfo);
	int Write(string filename,TK_info tkInfo);
	int Write(string filename,TK_info3 tkInfo);
protected:
	/////////////////////////////////////дģ��/////////////////////////////////////
	//AC_info3�ṹ��
	int WriteACInfo3(xmlNodePtr root_node,AC_info3 acInfo);
	//AC_info�ṹ��
	int WriteACInfo(xmlNodePtr root_node,AC_info acInfo);
	//ҳ���ʶ��ģ��
	int WritePageMarkerInfo(xmlNodePtr root_node,vector<cv::Rect> pageMarker);
	//��λ��ģ��
	int WriteAnchorPointInfo(xmlNodePtr root_node,AnchorPoint_info anchorPointInfo);
	// ��ǵ�ģ��
	int WriteMarkerInfo(xmlNodePtr root_node, Marker_info markerInfo);
	// ��ǵ�ģ��
	int WriteMarkerInfo3(xmlNodePtr root_node, vector<Marker_info3> markerGroupInfo);
	//id����Ϣ
	int WriteIdPointInfo(xmlNodePtr root_node,vector<ItemPos> idPoint);
	//������Ϣ
	int WriteBarInfo(xmlNodePtr root_node,vector<Bar_info> barGroup);
	//Ԥ������Ϳ����
	int WriteFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info> fillingPointGroup);
	//Ԥ������Ϳ����
	int WriteFillingPointsInfo3(xmlNodePtr root_node,vector<FillingPoints_info3> fillingPointGroup);
	//ѡ����Ϣ�ṹ��
	int WriteItemPosInfo(xmlNodePtr partent_node,ItemPos itemPos);
	//ѡ����Ϣ�ṹ��
	int WriteFillingpointItemPos(xmlNodePtr partent_node,FillingpointItemPos itemPos);
	//��Ϳ�㱳����Ϣ
	int WriteFillingPointBackgroundInfo(xmlNodePtr root_node,vector<PerFillingPtBackground_info> fillingPointBackgroundInfo);
	//��Ŀ��Ϣ
	int WriteQuestionInfo(xmlNodePtr root_node,vector<ItemPos> questionInfo);
	//��Ŀ������Ϣ
	int WriteQuestionBackgroundInfo(xmlNodePtr root_node,vector<PerQuestionBackground_info> questionBackgroundInfo);
	//��������
	int WriteCropAreaInfo(xmlNodePtr root_node,vector<CropArea_info> cropAreaInfo);
	//�ڰ׼����
	int WriteBlackWhiteLine(xmlNodePtr root_node,Rect blackLine,Rect whiteLine);
	//ʶ��ο���
	int WriteRefPoint(xmlNodePtr root_node,vector<Rect> refPoint);
	//����ͬ��ͷ
	int WriteMarker(xmlNodePtr root_node,vector<PerMarker_info> marker);
	/////////////////////////////////////��ģ��/////////////////////////////////////
	//����һ��
	int ReadACInfo(xmlNodePtr root_node,AC_info &acInfo);
	//������
	int ReadACInfo3(xmlNodePtr root_node,AC_info3 &acInfo);
	//��λ��ģ��
	int ReadAnchorPointInfo(xmlNodePtr root_node,AnchorPoint_info &anchorPointInfo);
	//ҳ���ʶ��ģ��
	int ReadPageMakerInfo(xmlNodePtr root_node,vector<cv::Rect> &pageMarker);
	// ��ǵ�ģ��
	int ReadMarkerInfo(xmlNodePtr root_node, Marker_info &markerInfo);
	int ReadMarkerGroupInfo(xmlNodePtr root_node, vector<Marker_info3> &markerInfo);
	//id����Ϣ
	int ReadIdPointInfo(xmlNodePtr root_node,vector<ItemPos> &idPoint);
	//������Ϣ
	int ReadBarInfo(xmlNodePtr root_node,vector<Bar_info> &barGroup);
	//Ԥ������Ϳ����
	int ReadFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info> &fillingPointGroup);
	int ReadFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info3> &fillingPointGroup);
	//ѡ����Ϣ�ṹ��
	int ReadItemPosInfo(xmlNodePtr partent_node,ItemPos &itemPos);
	int ReadFillingpointItemPos(xmlNodePtr firstItemPosPtr,FillingpointItemPos & itemPos);
	//��Ϳ�㱳����Ϣ
	int ReadFillingPointBackgroundInfo(xmlNodePtr root_node,vector<PerFillingPtBackground_info> &fillingPointBackgroundInfo);
	//��Ŀ��Ϣ
	int ReadQuestionInfo(xmlNodePtr root_node,vector<ItemPos> &questionInfo);
	//��Ŀ������Ϣ
	int ReadQuestionBackgroundInfo(xmlNodePtr root_node,vector<PerQuestionBackground_info> &questionBackgroundInfo);
	//��������
	int ReadCropAreaInfo(xmlNodePtr root_node,vector<CropArea_info> &cropAreaInfo);
	//ʶ��ο���
	
	//����ͬ��ͷ

	//����ͬ��ͷ
	// �����һ����ЧԪ��
	int GetNextElement(string elementName, xmlNodePtr &cur_node);
	// ��ȡѡ��λ����Ϣ
	int ReadItemPos(xmlNodePtr firstItemPosPtr,ItemPos &itemPos);
	//ʶ��ο���
	int ReadRefPoint(xmlNodePtr root_node,vector<Rect> &refPoint);
	//����ͬ��ͷ
	int ReadMarker(xmlNodePtr root_node,vector<PerMarker_info> &marker);
};

