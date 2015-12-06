#include "StdAfx.h"
#include "XmlIo.h"
#include "ChineseCode.h"

// XmlIo::XmlIo(void)
// {
// }
// 
// 
// XmlIo::~XmlIo(void)
// {
// }
//////////////////////////////////д////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//�׿� ����һ��
int XmlIo::Write(string filename,TK_info tkInfo)
{
	xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
	xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"TaokaInfo");
	//���ø��ڵ�
	xmlDocSetRootElement(doc,root_node);
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_type", BAD_CAST (DataTypeConversion::Ushort2String(tkInfo.tkinfo[0].acinfo[0].ac_type).c_str()));
	for (unsigned int i=0;i<tkInfo.tkinfo.size();i++)
	{
		xmlNodePtr perACInfo_node = xmlNewNode(NULL,BAD_CAST"perACInfo");
		xmlAddChild(root_node,perACInfo_node);
		
		//�׿����
		xmlAddChild(perACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�׿����").c_str()) ));
		xmlNewTextChild(perACInfo_node, NULL, BAD_CAST "tkId", BAD_CAST (DataTypeConversion::Int2String(tkInfo.tkinfo[i].tkId).c_str()));
		//�Ծ���
		xmlAddChild(perACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ҳ��").c_str())));
		xmlNewTextChild(perACInfo_node, NULL, BAD_CAST "pageId", BAD_CAST (DataTypeConversion::Int2String(tkInfo.tkinfo[i].pageId).c_str()));
		for (unsigned int j=0;j<tkInfo.tkinfo[i].acinfo.size();j++)
		{
			WriteACInfo(perACInfo_node,tkInfo.tkinfo[i].acinfo[j]);
		}

	}
	int nRel = xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8",1);
	if (nRel != -1)
	{
		cout<<"һ��xml�ĵ�������,д��"<<nRel<<"���ֽ�"<<endl;
	}
	//�ͷ��ĵ��ڽڵ㶯̬������ڴ�
	xmlFreeDoc(doc);
	return 0;
}

//�׿� ������
int XmlIo::Write(string filename,TK_info3 tkInfo)
{
	xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
	xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"TaokaInfo");
	//���ø��ڵ�
	xmlDocSetRootElement(doc,root_node);
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_type", BAD_CAST (DataTypeConversion::Ushort2String(tkInfo.tkinfo[0].acinfo[0].ac_type).c_str()));
	for (unsigned int i=0;i<tkInfo.tkinfo.size();i++)
	{
		xmlNodePtr perACInfo_node = xmlNewNode(NULL,BAD_CAST"perACInfo");
		xmlAddChild(root_node,perACInfo_node);

		//�Ծ���
		xmlAddChild(perACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ҳ��").c_str())));
		xmlNewTextChild(perACInfo_node, NULL, BAD_CAST "pageId", BAD_CAST (DataTypeConversion::Int2String(tkInfo.tkinfo[i].pageId).c_str()));
		
		for (unsigned int j=0;j<tkInfo.tkinfo[i].acinfo.size();j++)
		{
			xmlAddChild(perACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨��Ϣ").c_str()) ));
			xmlNodePtr ACInfo_node = xmlNewNode(NULL,BAD_CAST"ACInfo");
			xmlAddChild(perACInfo_node,ACInfo_node);
			WriteACInfo3(ACInfo_node,tkInfo.tkinfo[i].acinfo[j]);
		}
		

	}
	int nRel = xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8",1);
	if (nRel != -1)
	{
		cout<<"һ��xml�ĵ�������,д��"<<nRel<<"���ֽ�"<<endl;
	}
	//�ͷ��ĵ��ڽڵ㶯̬������ڴ�
	xmlFreeDoc(doc);
	return 0;
}


//����һ�� AC_info�ṹ��
int XmlIo::Write(string filename,AC_info acInfo)
{

	xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
	xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"AnswerCardInfo");
	//���ø��ڵ�
	xmlDocSetRootElement(doc,root_node);

	WriteACInfo(root_node,acInfo);
	
	//��ʽ��������ļ�
	//int nRel = xmlSaveFile(filename.c_str(),doc);
	int nRel = xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8",1);
	if (nRel != -1)
	{
		cout<<"һ��xml�ĵ�������,д��"<<nRel<<"���ֽ�"<<endl;
	}
	//�ͷ��ĵ��ڽڵ㶯̬������ڴ�
	xmlFreeDoc(doc);
	return 0;
}
int XmlIo::Write(string filename,AC_info3 acInfo)
{

	xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
	xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"AnswerCardInfo");
	//���ø��ڵ�
	xmlDocSetRootElement(doc,root_node);
	
	WriteACInfo3(root_node,acInfo);

	//��ʽ��������ļ�
	//int nRel = xmlSaveFile(filename.c_str(),doc);
	int nRel = xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8",1);
	if (nRel != -1)
	{
		cout<<"һ��xml�ĵ�������,д��"<<nRel<<"���ֽ�"<<endl;
	}
	//�ͷ��ĵ��ڽڵ㶯̬������ڴ�
	xmlFreeDoc(doc);
	return 0;
}

////////////////////////////////PerAC_info�ṹ��ģ��////////////////////////////////////////
// int XmlIo::WritePerACInfo(xmlNodePtr root_node,PerAC_info perACInfo)
// {
// 	//�׿����
// 	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�׿����").c_str()) ));
// 	xmlNewTextChild(root_node, NULL, BAD_CAST "tkId", BAD_CAST (perACInfo.tkId.c_str()));
// 	//�Ծ���
// 	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ծ���").c_str()) ));
// 	xmlNewTextChild(root_node, NULL, BAD_CAST "acId", BAD_CAST (perACInfo.acId.c_str()));
// 
// }

//////////////////////////////////�⿨��Ϣ�ṹ��ģ��////////////////////////////////////////
//������
int XmlIo:: WriteACInfo3(xmlNodePtr root_node,AC_info3 acInfo)
{
	//���⿨����
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_type", BAD_CAST (DataTypeConversion::Ushort2String(acInfo.ac_type).c_str()));

	//�Ծ�����
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ծ�����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_id", BAD_CAST (acInfo.ac_id.c_str()));

	//�������־
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�������־").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "isFront", BAD_CAST (DataTypeConversion::Bool2String(acInfo.isFront).c_str()));

	//�ֱ���
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ֱ���").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "dpi", BAD_CAST (DataTypeConversion::Int2String(acInfo.dpi).c_str()));

	//ͼƬSize
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ͼƬ�ߴ�").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "imgSize", BAD_CAST (DataTypeConversion::Size2String(acInfo.imgSize).c_str()));

	//�Ƿ���ڶ�λ���־
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ���ڶ�λ��").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "isAnchorPointExist", BAD_CAST (DataTypeConversion::Bool2String(acInfo.isAnchorPointExist).c_str()));

	//�Ƿ���ڶ�λ���α�־
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ���ڶ�λ����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "isAnchorRectExist", BAD_CAST (DataTypeConversion::Bool2String(acInfo.isAnchorRectExist).c_str()));

	//��λ��������
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "anchorRect", BAD_CAST (DataTypeConversion::Rect2String(acInfo.anchorRect).c_str()));
	
 
 	//ѡ��������
 	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ѡ��������").c_str()) ));
 	xmlNewTextChild(root_node, NULL, BAD_CAST "questionType", BAD_CAST (DataTypeConversion::Int2String(acInfo.questionType).c_str()));

	//ҳ���ʶ����Ϣ
	WritePageMarkerInfo(root_node,acInfo.pageMarker);

	//��λ����Ϣ
	WriteAnchorPointInfo(root_node,acInfo.anchorPointInfo);

	//��ǵ���Ϣ
	WriteMarkerInfo3(root_node,acInfo.markerInfo);

	//������Ϣ
	WriteBarInfo(root_node,acInfo.barGroup);

	//Ԥ������Ϳ����
	WriteFillingPointsInfo3(root_node,acInfo.fillingPointGroup);

	//��Ŀ��Ϣ
	WriteQuestionInfo(root_node,acInfo.questioninfo);

	//��Ŀ������Ϣ
	WriteQuestionBackgroundInfo(root_node,acInfo.questionBackgroundInfo);

	//����������Ϣ
	WriteCropAreaInfo(root_node,acInfo.cropAreaInfo);

	//�ڰ׼����
	WriteBlackWhiteLine(root_node,acInfo.blackLine,acInfo.whiteLine);
	//ʶ��ο���
	WriteRefPoint(root_node,acInfo.refPoint);
	return 0;
}
//����һ��
int XmlIo:: WriteACInfo(xmlNodePtr root_node,AC_info acInfo)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨��Ϣ").c_str()) ));
	xmlNodePtr ACInfo_node = xmlNewNode(NULL,BAD_CAST"ACInfo");
	xmlAddChild(root_node,ACInfo_node);
	//���⿨����
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���⿨����").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "ac_type", BAD_CAST (DataTypeConversion::Ushort2String(acInfo.ac_type).c_str()));

	//�ֱ���
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ֱ���").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "dpi", BAD_CAST (DataTypeConversion::Int2String(acInfo.dpi).c_str()));
	
	//ͼƬSize
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ͼƬ�ߴ�").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "imgSize", BAD_CAST (DataTypeConversion::Size2String(acInfo.imgSize).c_str()));
	//��������
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�������־").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "isFront", BAD_CAST (DataTypeConversion::Bool2String(acInfo.isFront).c_str()));

	//�Ƿ���ڶ�λ���־
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ���־").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "isAnchorPointExist", BAD_CAST (DataTypeConversion::Bool2String(acInfo.isAnchorPointExist).c_str()));

// 
// 	//ѡ��������
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ѡ��������").c_str()) ));
	xmlNewTextChild(ACInfo_node, NULL, BAD_CAST "questionType", BAD_CAST (DataTypeConversion::Int2String(acInfo.questionType).c_str()));

	//��λ����Ϣ
	WriteAnchorPointInfo(ACInfo_node,acInfo.anchorPointInfo);

	//��ǵ���Ϣ
	WriteMarkerInfo(ACInfo_node,acInfo.markerInfo);

	//id����Ϣ
	WriteIdPointInfo(ACInfo_node,acInfo.idPoint);

	//������Ϣ
	WriteBarInfo(ACInfo_node,acInfo.barGroup);

	//Ԥ������Ϳ����
	WriteFillingPointsInfo(ACInfo_node,acInfo.fillingPointGroup);

	//��Ϳ�㱳����Ϣ
	WriteFillingPointBackgroundInfo(ACInfo_node,acInfo.fillingPointBackgroundInfo);

	//��Ŀ��Ϣ
	WriteQuestionInfo(ACInfo_node,acInfo.questioninfo);

	//��Ŀ������Ϣ
	WriteQuestionBackgroundInfo(ACInfo_node,acInfo.questionBackgroundInfo);

	//����������Ϣ
	WriteCropAreaInfo(ACInfo_node,acInfo.cropAreaInfo);
	//�ڰ׼����
	WriteBlackWhiteLine(ACInfo_node,acInfo.blackLine,acInfo.whiteLine);
	//ʶ��ο���
	WriteRefPoint(ACInfo_node,acInfo.refPoint);
	//����ͬ��ͷ
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����ͬ��ͷ��Ϣ").c_str()) ));
	xmlNodePtr XMarker_node = xmlNewNode(NULL,BAD_CAST"XMarkerInfo");
	xmlAddChild(ACInfo_node,XMarker_node);
	WriteMarker(XMarker_node,acInfo.xMarker);
	//����ͬ��ͷ
	xmlAddChild(ACInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����ͬ��ͷ��Ϣ").c_str()) ));
	xmlNodePtr YMarker_node = xmlNewNode(NULL,BAD_CAST"YMarkerInfo");
	xmlAddChild(ACInfo_node,YMarker_node);
	WriteMarker(YMarker_node,acInfo.yMarker);
	return 0;
}
//////////////////////////////////ҳ���ʶ��ģ��////////////////////////////////////////
int XmlIo::WritePageMarkerInfo(xmlNodePtr root_node,vector<cv::Rect> pageMarker)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ҳ���ʶ��").c_str()) ));
	xmlNodePtr pageMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"pageMarkerInfo");
	xmlAddChild(root_node,pageMarkerInfo_node);
	//��λ��λ����Ϣ
	xmlAddChild(pageMarkerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ҳ���ʶ��λ����Ϣ").c_str()) ));
	xmlNodePtr pmPosInfo_node = xmlNewNode(NULL,BAD_CAST"pmPosInfo");
	xmlAddChild(pageMarkerInfo_node,pmPosInfo_node);
	for (unsigned int i=0;i<pageMarker.size();i++)
	{
		xmlNewTextChild(pmPosInfo_node, NULL, BAD_CAST "pos", BAD_CAST(DataTypeConversion::Rect2String(pageMarker[i]).c_str()));
	}
	return 0;

}
//////////////////////////////////��λ��ģ��////////////////////////////////////////

int XmlIo::WriteAnchorPointInfo(xmlNodePtr root_node,AnchorPoint_info anchorPointInfo)
{
	//xmlNodePtr cur_node = xmlAddPrevSibling(root_node,xmlNewComment(BAD_CAST"��λ��"));
	//xmlAddPrevSibling( root_node, xmlNewComment( BAD_CAST "abc" ));
	//��λ��
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ��").c_str()) ));
	xmlNodePtr anchorPointInfo_node = xmlNewNode(NULL,BAD_CAST"anchorPointInfo");
	xmlAddChild(root_node,anchorPointInfo_node);

	//��λ������
	xmlAddChild(anchorPointInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ������").c_str()) ));
	xmlNewTextChild(anchorPointInfo_node, NULL, BAD_CAST "num", BAD_CAST(DataTypeConversion::Int2String(anchorPointInfo.num).c_str()));

	//��λ������
	xmlAddChild(anchorPointInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ������").c_str()) ));
	xmlNewTextChild(anchorPointInfo_node, NULL, BAD_CAST "anchorType", BAD_CAST(DataTypeConversion::Short2String(anchorPointInfo.anchorType).c_str()));

	//��λ��λ����Ϣ
	xmlAddChild(anchorPointInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ��λ����Ϣ").c_str()) ));
	xmlNodePtr anchorPtPosInfo_node = xmlNewNode(NULL,BAD_CAST"anchorPtPosInfo");
	xmlAddChild(anchorPointInfo_node,anchorPtPosInfo_node);
	for (unsigned int i=0;i<anchorPointInfo.anchorPt.size();i++)
	{
		xmlNewTextChild(anchorPtPosInfo_node, NULL, BAD_CAST "perAnchorPtPos", BAD_CAST(DataTypeConversion::Rect2String(anchorPointInfo.anchorPt[i]).c_str()));
	}

	return 0;
}

////////////////////////////////// ��ǵ�ģ��//////////////////////////////////////

int XmlIo::WriteMarkerInfo(xmlNodePtr root_node, Marker_info markerInfo)
{
	//��ǵ�
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��ǵ�").c_str()) ));
	xmlNodePtr markerInfo_node = xmlNewNode(NULL,BAD_CAST"markerInfo");
	xmlAddChild(root_node,markerInfo_node);

	//�����ǵ�����
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xNum", BAD_CAST(DataTypeConversion::Int2String(markerInfo.xNum).c_str()));

	//�����ǵ�����
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "yNum", BAD_CAST(DataTypeConversion::Int2String(markerInfo.yNum).c_str()));

	//�����ǵ�ߴ�
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�ߴ�").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xSize", BAD_CAST(DataTypeConversion::Size2String(markerInfo.xSize).c_str()));

	//�����ǵ�ߴ�
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�ߴ�").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "ySize", BAD_CAST(DataTypeConversion::Size2String(markerInfo.ySize).c_str()));

	//�����ǵ�����������
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����������").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xMarker", BAD_CAST(DataTypeConversion::Rect2String(markerInfo.xMarker).c_str()));

	//�����ǵ�����������
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����������").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "yMarker", BAD_CAST(DataTypeConversion::Rect2String(markerInfo.yMarker).c_str()));

	return 0;
}

int XmlIo::WriteMarkerInfo3(xmlNodePtr root_node, vector<Marker_info3> markerGroupInfo)
{
	//�����ǵ���
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ���").c_str()) ));
	xmlNodePtr MarkerGroupInfo_node = xmlNewNode(NULL,BAD_CAST"MarkerGroupInfo");
	xmlAddChild(root_node,MarkerGroupInfo_node);
	for (unsigned int i=0;i<markerGroupInfo.size();i++)
	{
		xmlNodePtr perMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"perMarkerInfo");
		xmlAddChild(MarkerGroupInfo_node,perMarkerInfo_node);
		xmlAddChild(perMarkerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ����").c_str()) ));
		xmlNewTextChild(perMarkerInfo_node, NULL, BAD_CAST "id", BAD_CAST(DataTypeConversion::Int2String(markerGroupInfo[i].id).c_str()));
		xmlNodePtr xMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"xMarkerInfo");
		xmlAddChild(perMarkerInfo_node,xMarkerInfo_node);
		for (int j=0;j<markerGroupInfo[i].xMarker.size();j++)
		{
			xmlNewTextChild(xMarkerInfo_node, NULL, BAD_CAST "perMarkerPos", BAD_CAST(DataTypeConversion::Rect2String(markerGroupInfo[i].xMarker[j]).c_str()));
		}
		xmlNodePtr yMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"yMarkerInfo");
		xmlAddChild(perMarkerInfo_node,yMarkerInfo_node);
		for (int j=0;j<markerGroupInfo[i].yMarker.size();j++)
		{
			xmlNewTextChild(yMarkerInfo_node, NULL, BAD_CAST "perMarkerPos", BAD_CAST(DataTypeConversion::Rect2String(markerGroupInfo[i].yMarker[j]).c_str()));
		}
	}
	return 0;
}
////////////////////////////////////////////Id����Ϣ//////////////////////////////
int XmlIo::WriteIdPointInfo(xmlNodePtr root_node,vector<ItemPos> idPoint)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("Id����Ϣ").c_str()) ));
	xmlNodePtr idPointInfo_node = xmlNewNode(NULL,BAD_CAST"idPointInfo");
	xmlAddChild(root_node,idPointInfo_node);
	for (unsigned int i=0;i<idPoint.size();i++)
	{
		xmlNodePtr perIdPoint_node = xmlNewNode(NULL,BAD_CAST"perIdPointInfo");
		xmlAddChild(idPointInfo_node,perIdPoint_node);
		WriteItemPosInfo(perIdPoint_node,idPoint[i]);
	}
	return 0;
}
////////////////////////////////////////////������Ϣ//////////////////////////////



int XmlIo::WriteBarInfo(xmlNodePtr root_node,vector<Bar_info> barGroup)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
	xmlNodePtr barInfo_node = xmlNewNode(NULL,BAD_CAST"barInfo");
	xmlAddChild(root_node,barInfo_node);
	for (unsigned int i=0;i<barGroup.size();i++)
	{
		xmlNodePtr perBarInfo_node = xmlNewNode(NULL,BAD_CAST"perBarInfo");
		xmlAddChild(barInfo_node,perBarInfo_node);
		xmlAddChild(perBarInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��������").c_str()) ));
		xmlNewTextChild(perBarInfo_node,NULL, BAD_CAST "barType", BAD_CAST (DataTypeConversion::Ushort2String(barGroup[i].barType).c_str()));
		xmlAddChild(perBarInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����λ��").c_str()) ));
		xmlNewTextChild(perBarInfo_node,NULL, BAD_CAST "pos", BAD_CAST (DataTypeConversion::Rect2String(barGroup[i].pos).c_str()));
	}
	return 0;
}

///////////////////////////////////////Ԥ������Ϳ����/////////////////////////////////////


int XmlIo::WriteFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info> fillingPointGroup)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("Ԥ������Ϳ����").c_str()) ));
	xmlNodePtr fillingPointGroup_node = xmlNewNode(NULL,BAD_CAST"fillingPointGroup");
	xmlAddChild(root_node,fillingPointGroup_node);
	for (unsigned int i=0;i<fillingPointGroup.size();i++)
	{
		xmlNodePtr perFillingPointGroup_node = xmlNewNode(NULL,BAD_CAST"perFillingPointInfo");
		xmlAddChild(fillingPointGroup_node,perFillingPointGroup_node);
		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ϳ����").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "name", BAD_CAST CChineseCode::GBKToUTF8(fillingPointGroup[i].name).c_str());

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ϳ������").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "type", BAD_CAST (DataTypeConversion::Ushort2String(fillingPointGroup[i].type).c_str()));

		for (unsigned int j=0;j<fillingPointGroup[i].fillingPoints.size();j++)
		{
			WriteItemPosInfo(perFillingPointGroup_node,fillingPointGroup[i].fillingPoints[j]);
		}
	}
	return 0;
}
//Ԥ������Ϳ����
int XmlIo::WriteFillingPointsInfo3(xmlNodePtr root_node,vector<FillingPoints_info3> fillingPointGroup)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("Ԥ������Ϳ����").c_str()) ));
	xmlNodePtr fillingPointGroup_node = xmlNewNode(NULL,BAD_CAST"fillingPointGroup");
	xmlAddChild(root_node,fillingPointGroup_node);
	for (unsigned int i=0;i<fillingPointGroup.size();i++)
	{
		xmlNodePtr perFillingPointGroup_node = xmlNewNode(NULL,BAD_CAST"perFillingPointInfo");
		xmlAddChild(fillingPointGroup_node,perFillingPointGroup_node);
		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ϳ����").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "name", BAD_CAST CChineseCode::GBKToUTF8(fillingPointGroup[i].name).c_str());

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ϳ������").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "type", BAD_CAST (DataTypeConversion::Ushort2String(fillingPointGroup[i].type).c_str()));

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ��Ǻ����").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "isCrosswise", BAD_CAST (DataTypeConversion::Bool2String(fillingPointGroup[i].isCrosswise).c_str()));

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "bgInfo", BAD_CAST (DataTypeConversion::Mat32s2String(fillingPointGroup[i].bgInfo).c_str()));

		for (unsigned int j=0;j<fillingPointGroup[i].fillingPoints.size();j++)
		{
			WriteFillingpointItemPos(perFillingPointGroup_node,fillingPointGroup[i].fillingPoints[j]);
		}
	}
	return 0;
}
///////////////////////////////////////ѡ����Ϣ�ṹ��/////////////////////////////////////

int XmlIo::WriteItemPosInfo(xmlNodePtr partent_node,ItemPos itemPos)
{
	xmlNodePtr itemPos_node = xmlNewNode(NULL,BAD_CAST"itemPos");
	xmlAddChild(partent_node,itemPos_node);
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "id", BAD_CAST (DataTypeConversion::Int2String(itemPos.id).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��ǵ����").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "mark_id", BAD_CAST (DataTypeConversion::Ushort2String(itemPos.mark_id).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ����").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isCrosswise", BAD_CAST (DataTypeConversion::Bool2String(itemPos.isCrosswise).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ�ѡ").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isSingleChoice", BAD_CAST (DataTypeConversion::Bool2String(itemPos.isSingleChoice).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����/����������ѡ���Ų�Ϊ������Ϊ������").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "interval", BAD_CAST (DataTypeConversion::Ushort2String(itemPos.interval).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ŀ��Ӧ��λ����������Ϊ������[0]Ϊˮƽ���������ţ�[1]Ϊ��ֱ�����Ӧ�ĵ�һ�������ţ�[2]Ϊ��ֱ�����Ӧ�����һ��������").c_str()) ));
	string tmpStr = DataTypeConversion::Ushort2String(itemPos.markerIdx[0]);
	tmpStr += ' '+DataTypeConversion::Ushort2String(itemPos.markerIdx[1]);
	tmpStr += ' '+DataTypeConversion::Ushort2String(itemPos.markerIdx[2]);
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "markerIdx", BAD_CAST (tmpStr.c_str()));
	return 0;

}
/////////////////////////////////////ÿλ��Ϳ����Ϣ/////////////////////////////////////
int XmlIo::WriteFillingpointItemPos(xmlNodePtr partent_node,FillingpointItemPos itemPos)
{
	xmlNodePtr itemPos_node = xmlNewNode(NULL,BAD_CAST"fillingpointItemPos");
	xmlAddChild(partent_node,itemPos_node);
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "id", BAD_CAST (DataTypeConversion::Int2String(itemPos.id).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ�ѡ").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isSingleChoice", BAD_CAST (DataTypeConversion::Bool2String(itemPos.isSingleChoice).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("λ��").c_str()) ));
	xmlNodePtr pos_node = xmlNewNode(NULL,BAD_CAST"pos");
	xmlAddChild(itemPos_node,pos_node);
	for (int i=0;i<itemPos.pos.size();i++)
	{
		xmlNewTextChild(pos_node,NULL, BAD_CAST "perFillingPointPos", BAD_CAST (DataTypeConversion::Rect2String(itemPos.pos[i]).c_str()));
	}
	return 0;
}
////////////////////////////////////��Ϳ�㱳����Ϣ//////////////////////////////////////
int XmlIo::WriteFillingPointBackgroundInfo(xmlNodePtr root_node,vector<PerFillingPtBackground_info> fillingPointBackgroundInfo)
{
	xmlNodePtr fillingPointBackgroundInfo_node = xmlNewNode(NULL,BAD_CAST"fillingPointBackgroundInfo");
	xmlAddChild(root_node,fillingPointBackgroundInfo_node);
	string matStr;
	for (unsigned int i=0;i<fillingPointBackgroundInfo.size();i++)
	{
		xmlNodePtr perFillingPointBackgroundInfo_node = xmlNewNode(NULL,BAD_CAST"perFillingPointBkInfo");
		xmlAddChild(fillingPointBackgroundInfo_node,perFillingPointBackgroundInfo_node);

		xmlAddChild(perFillingPointBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����").c_str()) ));
		xmlNewTextChild(perFillingPointBackgroundInfo_node,NULL, BAD_CAST "type", BAD_CAST (DataTypeConversion::Ushort2String(fillingPointBackgroundInfo[i].type).c_str()));

		xmlAddChild(perFillingPointBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		if ((matStr = DataTypeConversion::Mat32s2String(fillingPointBackgroundInfo[i].bkInfo))=="error")
		{
			return -1;
		}
		xmlNewTextChild(perFillingPointBackgroundInfo_node,NULL, BAD_CAST "bkInfo", BAD_CAST (matStr.c_str()));
	}
	return 0;
}

/////////////////////////////////////��Ŀ��Ϣ///////////////////////////////////////
int XmlIo::WriteQuestionInfo(xmlNodePtr root_node,vector<ItemPos> questionInfo)
{
	xmlNodePtr questionInfo_node = xmlNewNode(NULL,BAD_CAST"questionInfo");
	xmlAddChild(root_node,questionInfo_node);
	for (unsigned int i=0;i<questionInfo.size();i++)
	{
		WriteItemPosInfo(questionInfo_node,questionInfo[i]);
	}
	return 0;
}

/////////////////////////////////////��Ŀ������Ϣ///////////////////////////////////////

int XmlIo::WriteQuestionBackgroundInfo(xmlNodePtr root_node,vector<PerQuestionBackground_info> questionBackgroundInfo)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ŀ������Ϣ").c_str()) ));
	xmlNodePtr questionBackgroundInfo_node = xmlNewNode(NULL,BAD_CAST"questionBackgroundInfo");
	xmlAddChild(root_node,questionBackgroundInfo_node);
	string matStr;
	for (unsigned int i=0;i<questionBackgroundInfo.size();i++)
	{
		xmlNodePtr perQuestionBackgroundInfo_node = xmlNewNode(NULL,BAD_CAST"perQuestionBackgroundInfo");
		xmlAddChild(questionBackgroundInfo_node,perQuestionBackgroundInfo_node);

		xmlAddChild(perQuestionBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����").c_str()) ));
		xmlNewTextChild(perQuestionBackgroundInfo_node,NULL, BAD_CAST "type", BAD_CAST (DataTypeConversion::Ushort2String(questionBackgroundInfo[i].type).c_str()));

		xmlAddChild(perQuestionBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		if ((matStr = DataTypeConversion::Mat32s2String(questionBackgroundInfo[i].bkInfo))=="error")
		{
			return -1;
		}
		xmlNewTextChild(perQuestionBackgroundInfo_node,NULL, BAD_CAST "bkInfo", BAD_CAST (matStr.c_str()));
	}
	return 0;
}
////////////////////////////////////��������//////////////////////////////////////

int XmlIo::WriteCropAreaInfo(xmlNodePtr root_node,vector<CropArea_info> cropAreaInfo)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����������Ϣ").c_str()) ));
	xmlNodePtr cropAreaInfo_node = xmlNewNode(NULL,BAD_CAST"cropAreaInfo");
	xmlAddChild(root_node,cropAreaInfo_node);

	for (unsigned int i=0;i<cropAreaInfo.size();i++)
	{
		xmlNodePtr perCropAreaInfo_node = xmlNewNode(NULL,BAD_CAST"perCropAreaInfo");
		xmlAddChild(cropAreaInfo_node,perCropAreaInfo_node);

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������������").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "name", BAD_CAST (CChineseCode::GBKToUTF8(cropAreaInfo[i].name).c_str()));

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��������λ��").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "pos", BAD_CAST (DataTypeConversion::Rect2String(cropAreaInfo[i].pos).c_str()));

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ϲ����").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "groupNum", BAD_CAST (DataTypeConversion::Int2String(cropAreaInfo[i].groupNum).c_str()));

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��������").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "isSecret", BAD_CAST (DataTypeConversion::Bool2String(cropAreaInfo[i].isSecret).c_str()));

	}
	return 0;
}
///////////////////////////////�ڰ׼����/////////////////////////////////////////////

int XmlIo::WriteBlackWhiteLine(xmlNodePtr root_node,Rect blackLine,Rect whiteLine)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ڰ׼����").c_str()) ));
	xmlNewTextChild(root_node,NULL, BAD_CAST "blackLine", BAD_CAST (DataTypeConversion::Rect2String(blackLine).c_str()));
	xmlNewTextChild(root_node,NULL, BAD_CAST "whiteLine", BAD_CAST (DataTypeConversion::Rect2String(whiteLine).c_str()));
	return 0;
}

///////////////////////////////////ʶ��ο���///////////////////////////////////////

int XmlIo::WriteRefPoint(xmlNodePtr root_node,vector<Rect> refPoint)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("ʶ��ο���").c_str()) ));
	xmlNodePtr refPoint_node = xmlNewNode(NULL,BAD_CAST"refPointInfo");
	xmlAddChild(root_node,refPoint_node);
	for (unsigned int i=0;i<refPoint.size();i++)
	{
		xmlNewTextChild(refPoint_node, NULL, BAD_CAST "perrefPointPos", BAD_CAST(DataTypeConversion::Rect2String(refPoint[i]).c_str()));
	}

	return 0;
}
///////////////////////////////////����ͬ��ͷ///////////////////////////////////////
int XmlIo::WriteMarker(xmlNodePtr root_node,vector<PerMarker_info> marker)
{
	for (int i=0;i<marker.size();i++)
	{
		xmlNodePtr perMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"perMarkerInfo");
		xmlAddChild(root_node,perMarkerInfo_node);
		//������
		xmlAddChild(perMarkerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������").c_str()) ));
		xmlNewTextChild(perMarkerInfo_node,NULL, BAD_CAST "id", BAD_CAST (DataTypeConversion::Ushort2String(marker[i].id).c_str()));
		//ͬ��ͷλ��
		xmlAddChild(perMarkerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("λ��").c_str()) ));
		xmlNewTextChild(perMarkerInfo_node,NULL, BAD_CAST "pos", BAD_CAST (DataTypeConversion::Rect2String(marker[i].pos).c_str()));
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////��ģ��/////////////////////////////////////////


/////////////////////////////////�׿���ģ��/////////////////////////////////////////
//����һ��
int XmlIo::Read(string filename,TK_info &tkInfo)
{
	xmlDocPtr doc;
	xmlNodePtr root_node;
	// load an exist xml file.
	doc = xmlReadFile(filename.c_str(),"UTF-8",XML_PARSE_NOBLANKS); 
	if (doc == NULL ) 
	{ 
		return -1; 
	} 
	// get root
	root_node = xmlDocGetRootElement(doc);

	if (root_node == NULL) 
	{ 
		xmlFreeDoc(doc);
		return 1;
	}

	xmlNodePtr cur_node,perACInfo_node;      //������ָ��
	perACInfo_node = root_node->xmlChildrenNode->next; //�ӽڵ㼯������
	perACInfo_node=perACInfo_node->next;
/*	perACInfo_node=perACInfo_node->next;*/

	int nRel;
	string content;
	//��ʼ��ȡ����
	while((nRel = GetNextElement("perACInfo",perACInfo_node))==0)
	{
		PerAC_info perACInfo;
		cur_node=perACInfo_node->children;
		if ((nRel = GetNextElement("tkId",cur_node))!=0)
		{
			return nRel;
		}
		content=string((char * )cur_node->children->content);
		perACInfo.tkId = DataTypeConversion::String2Int(content);
		cur_node = cur_node->next;
		if ((nRel = GetNextElement("pageId",cur_node))!=0)
		{
			return nRel;
		}
		content=string((char * )cur_node->children->content);
		perACInfo.pageId =  DataTypeConversion::String2Int(content);
		cur_node = cur_node->next;
		while(cur_node)
		{
			cur_node=cur_node->next;
			AC_info acinfo;
			ReadACInfo(cur_node,acinfo);
			perACInfo.acinfo.push_back(acinfo);
			cur_node=cur_node->next;
		}
		tkInfo.tkinfo.push_back(perACInfo);
		perACInfo_node=perACInfo_node->next;
	}
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 0;

}


//������
int XmlIo::Read(string filename,TK_info3 &tkInfo)
{
	xmlDocPtr doc;
	xmlNodePtr root_node;
	// load an exist xml file.
	doc = xmlReadFile(filename.c_str(),"UTF-8",XML_PARSE_NOBLANKS); 
	if (doc == NULL ) 
	{ 
		return -1; 
	} 
	// get root
	root_node = xmlDocGetRootElement(doc);

	if (root_node == NULL) 
	{ 
		xmlFreeDoc(doc);
		return 1;
	}

	xmlNodePtr cur_node,perACInfo_node;      //������ָ��
	perACInfo_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	perACInfo_node=perACInfo_node->next;
	perACInfo_node=perACInfo_node->next;
	int nRel;
	string content;
	//��ʼ��ȡ����
	while((nRel = GetNextElement("perACInfo",perACInfo_node))==0)
	{
		PerAC_info3 perACInfo;
		cur_node=perACInfo_node->children;
		if ((nRel = GetNextElement("pageId",cur_node))!=0)
		{
			return nRel;
		}
		content=string((char * )cur_node->children->content);
		perACInfo.pageId = DataTypeConversion::String2Int(content);
		cur_node = cur_node->next;
		while(cur_node)
		{
			cur_node=cur_node->next;
			AC_info3 acinfo;
			ReadACInfo3(cur_node,acinfo);
			perACInfo.acinfo.push_back(acinfo);
			cur_node=cur_node->next;
		}
		tkInfo.tkinfo.push_back(perACInfo);
		perACInfo_node=perACInfo_node->next;
	}

	//while(perACInfo_node)
	//{
	//	AC_info3 acinfo;
	//	perACInfo_node=perACInfo_node->next;
	//	ReadACInfo3(perACInfo_node,acinfo);
	//	tkInfo.tkinfo.push_back(acinfo);
	//	perACInfo_node=perACInfo_node->next;
	//}
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 0;

}
//��ȡ�⿨����
int XmlIo::GetACType(string filename,int &acType)
{
	xmlDocPtr doc;
	xmlNodePtr root_node;
	// load an exist xml file.
	doc = xmlReadFile(filename.c_str(),"UTF-8",XML_PARSE_NOBLANKS); 
	if (doc == NULL ) 
	{ 
		return -1; 
	} 
	// get root
	root_node = xmlDocGetRootElement(doc);

	if (root_node == NULL) 
	{ 
		xmlFreeDoc(doc);
		return 1;
	}
	string content;
	int nRel;
	xmlNodePtr cur_node;      //������ָ��
	cur_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	if ((nRel = GetNextElement("ac_type",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acType= DataTypeConversion::String2Ushort(content);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 0;

}
/////////////////////////////////����һ�����Ͷ���ģ��/////////////////////////////////////////

int XmlIo::Read(string filename,AC_info &acInfo)
{
	xmlDocPtr doc;
	xmlNodePtr root_node;
	// load an exist xml file.
	doc = xmlReadFile(filename.c_str(),"UTF-8",XML_PARSE_NOBLANKS); 
	if (doc == NULL ) 
	{ 
		return -1; 
	} 
	// get root
	root_node = xmlDocGetRootElement(doc);

	if (root_node == NULL) 
	{ 
		xmlFreeDoc(doc);
		return 1;
	}
	ReadACInfo(root_node,acInfo);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 0;
}
/////////////////////////////////��������ģ��/////////////////////////////////////////
int XmlIo::Read(string filename,AC_info3  &acInfo){
// 	 AC_info3 *acInfo= new AC_info3;
// 	 *ppAcInfo=acInfo;
	//AC_info3 *acInfo=&acinfo;
	xmlDocPtr doc;
	xmlNodePtr root_node;
	// load an exist xml file.
	doc = xmlReadFile(filename.c_str(),"UTF-8",XML_PARSE_NOBLANKS); 
	if (doc == NULL ) 
	{ 
		return -1; 
	} 
	// get root
	root_node = xmlDocGetRootElement(doc);

	if (root_node == NULL) 
	{ 
		xmlFreeDoc(doc);
		return 1;
	}
	ReadACInfo3(root_node,acInfo);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 0;
}
//���⿨ģ�� ������
int XmlIo::ReadACInfo3(xmlNodePtr root_node,AC_info3 &acInfo)
{
	xmlNodePtr cur_node;      //������ָ��
	cur_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	int nRel;
	string content;
	//��ʼ��ȡ����

	//���⿨����
	if ((nRel = GetNextElement("ac_type",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.ac_type= DataTypeConversion::String2Ushort(content);
	cur_node = cur_node->next;

	//�Ծ�����
	if ((nRel = GetNextElement("ac_id",cur_node))!=0)
	{
		return nRel;
	}
	acInfo.ac_id = string((char * )cur_node->children->content);
	cur_node = cur_node->next;

	//�������־
	if ((nRel = GetNextElement("isFront",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.isFront= DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//�ֱ���
	if ((nRel = GetNextElement("dpi",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.dpi = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//ͼƬSize
	if ((nRel = GetNextElement("imgSize",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.imgSize = DataTypeConversion::String2Size(content);
	cur_node = cur_node->next;

	//�Ƿ���ڶ�λ����
	if ((nRel = GetNextElement("isAnchorPointExist",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.isAnchorPointExist= DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//�Ƿ���ڶ�λ���α��
	if ((nRel = GetNextElement("isAnchorRectExist",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.isAnchorRectExist= DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//��λ����
	if ((nRel = GetNextElement("anchorRect",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.anchorRect= DataTypeConversion::String2Rect(content);
	cur_node = cur_node->next;

	//ѡ��������
	if ((nRel = GetNextElement("questionType",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.questionType = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//ҳ���ʶ��
	if ((nRel = GetNextElement("pageMarkerInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadPageMakerInfo(cur_node,acInfo.pageMarker);
	cur_node = cur_node->next;

	//��λ����Ϣ
	if ((nRel = GetNextElement("anchorPointInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadAnchorPointInfo(cur_node,acInfo.anchorPointInfo);
	cur_node = cur_node->next;

	//�����ǵ�����Ϣ
	if ((nRel = GetNextElement("MarkerGroupInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadMarkerGroupInfo(cur_node,acInfo.markerInfo);
	//	cur_node = cur_node->next;	//����ymarker��ǩ
	cur_node = cur_node->next;

	//������Ϣ
	if ((nRel = GetNextElement("barInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadBarInfo(cur_node,acInfo.barGroup);
	cur_node = cur_node->next;
	//Ԥ������Ϳ����
	if ((nRel = GetNextElement("fillingPointGroup",cur_node))!=0)
	{
		return nRel;
	}
	ReadFillingPointsInfo(cur_node,acInfo.fillingPointGroup);
	cur_node = cur_node->next;

	//��Ŀ��Ϣ
	if ((nRel = GetNextElement("questionInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadQuestionInfo(cur_node,acInfo.questioninfo);
	cur_node = cur_node->next;
	//��Ŀ������Ϣ
	if ((nRel = GetNextElement("questionBackgroundInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadQuestionBackgroundInfo(cur_node,acInfo.questionBackgroundInfo);
	cur_node = cur_node->next;
	//��������
	if ((nRel = GetNextElement("cropAreaInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadCropAreaInfo(cur_node,acInfo.cropAreaInfo);
	cur_node = cur_node->next;
	//�ڰ���
	if ((nRel = GetNextElement("blackLine",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.blackLine = DataTypeConversion::String2Rect(content);
	cur_node = cur_node->next;
	if ((nRel = GetNextElement("whiteLine",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.whiteLine = DataTypeConversion::String2Rect(content);
	//ʶ��ο���
	cur_node = cur_node->next;
	if ((nRel = GetNextElement("refPointInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadRefPoint(cur_node,acInfo.refPoint);
	return 0;
}
//���⿨ģ�� ����һ��
int XmlIo::ReadACInfo(xmlNodePtr root_node,AC_info &acInfo)
{
	xmlNodePtr cur_node;      //������ָ��
	cur_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	int nRel;
	string content;
	//��ʼ��ȡ����

	// 	//���⿨����
	if ((nRel = GetNextElement("ac_type",cur_node))!=0)
	{
		return nRel;
	}
	content=string((char * )cur_node->children->content);
	acInfo.ac_type = DataTypeConversion::String2Ushort(content);
	cur_node = cur_node->next;

	//�ֱ���
	if ((nRel = GetNextElement("dpi",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.dpi = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;
	
	//ͼƬSize
	if ((nRel = GetNextElement("imgSize",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.imgSize = DataTypeConversion::String2Size(content);
	cur_node = cur_node->next;

	//�Ƿ�Ϊ����
	if ((nRel = GetNextElement("isFront",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.isFront = DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//�Ƿ���ڶ�λ��
	if ((nRel = GetNextElement("isAnchorPointExist",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.isAnchorPointExist = DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//ѡ��������
	if ((nRel = GetNextElement("questionType",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.questionType = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//��λ����Ϣ
	if ((nRel = GetNextElement("anchorPointInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadAnchorPointInfo(cur_node,acInfo.anchorPointInfo);
	cur_node = cur_node->next;

	//��ǵ���Ϣ
	if ((nRel = GetNextElement("markerInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadMarkerInfo(cur_node,acInfo.markerInfo);
	cur_node = cur_node->next;

	//Id����Ϣ
	if ((nRel = GetNextElement("idPointInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadIdPointInfo(cur_node,acInfo.idPoint);
	cur_node = cur_node->next;

	//������Ϣ
	if ((nRel = GetNextElement("barInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadBarInfo(cur_node,acInfo.barGroup);
	cur_node = cur_node->next;
	//Ԥ������Ϳ����
	if ((nRel = GetNextElement("fillingPointGroup",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadFillingPointsInfo(cur_node,acInfo.fillingPointGroup);
	cur_node = cur_node->next;
	//��Ϳ�㱳����Ϣ
	if ((nRel = GetNextElement("fillingPointBackgroundInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadFillingPointBackgroundInfo(cur_node,acInfo.fillingPointBackgroundInfo);
	cur_node = cur_node->next;
	//��Ŀ��Ϣ
	if ((nRel = GetNextElement("questionInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadQuestionInfo(cur_node,acInfo.questioninfo);
	cur_node = cur_node->next;
	//��Ŀ������Ϣ
	if ((nRel = GetNextElement("questionBackgroundInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadQuestionBackgroundInfo(cur_node,acInfo.questionBackgroundInfo);
	cur_node = cur_node->next;
	//��������
	if ((nRel = GetNextElement("cropAreaInfo",cur_node))!=0)	//��ȡ�Ծ�����Ԫ��
	{
		return nRel;
	}
	ReadCropAreaInfo(cur_node,acInfo.cropAreaInfo);
	cur_node = cur_node->next;
	//�ڰ���
	if ((nRel = GetNextElement("blackLine",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.blackLine = DataTypeConversion::String2Rect(content);
	cur_node = cur_node->next;
	if ((nRel = GetNextElement("whiteLine",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.whiteLine = DataTypeConversion::String2Rect(content);
	//ʶ��ο���
	cur_node = cur_node->next;
	if ((nRel = GetNextElement("refPointInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadRefPoint(cur_node,acInfo.refPoint);
	cur_node = cur_node->next;
	//����ͬ��ͷ
	if ((nRel = GetNextElement("XMarkerInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadMarker(cur_node,acInfo.xMarker);
	cur_node = cur_node->next;
	//����ͬ��ͷ
	if ((nRel = GetNextElement("YMarkerInfo",cur_node))!=0)
	{
		return nRel;
	}
	ReadMarker(cur_node,acInfo.yMarker);
	return 0;
}
//��λ��ģ��
int XmlIo::ReadAnchorPointInfo(xmlNodePtr root_node,AnchorPoint_info &anchorPointInfo)
{
	xmlNodePtr cur_node = root_node->children;
	int nRel;
	string content;
	//��ȡ��λ������
	if ((nRel = GetNextElement("num",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	anchorPointInfo.num = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;
	//��ȡ��λ������
	if ((nRel = GetNextElement("anchorType",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	anchorPointInfo.anchorType = DataTypeConversion::String2Short(content);
	cur_node = cur_node->next;
	//��ȡ��λ��λ��
	if ((nRel = GetNextElement("anchorPtPosInfo",cur_node))!=0)	
		return nRel;
	xmlNodePtr anchorPtPosInfo_node = cur_node;
	xmlNodePtr tmp = cur_node->children;
	while(tmp)
	{
		content = string((char * )tmp->children->content);
		Rect rect=DataTypeConversion::String2Rect(content);
		anchorPointInfo.anchorPt.push_back(rect);
		tmp = tmp->next;
	}
	return 0;
}

//ҳ���ʶ��ģ��
int XmlIo::ReadPageMakerInfo(xmlNodePtr root_node,vector<cv::Rect> &pageMarker)
{
	xmlNodePtr cur_node = root_node->children;
	int nRel;
	string content;
	if ((nRel = GetNextElement("pmPosInfo",cur_node))!=0)	
		return nRel;
	xmlNodePtr tmp = cur_node->children;
	while(tmp)
	{
		content = string((char * )tmp->children->content);
		Rect rect=DataTypeConversion::String2Rect(content);
		pageMarker.push_back(rect);
		tmp = tmp->next;
	}
}

// ��ǵ�ģ��
int XmlIo::ReadMarkerInfo(xmlNodePtr root_node, Marker_info &markerInfo)
{

	xmlNodePtr cur_node = root_node->children;
	int nRel;
	string content;
	//�����ǵ�����
	if ((nRel = GetNextElement("xNum",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.xNum = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//�����ǵ�����
	if ((nRel = GetNextElement("yNum",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.yNum = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//�����ǵ�ߴ�
	if ((nRel = GetNextElement("xSize",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.xSize = DataTypeConversion::String2Size(content);
	cur_node = cur_node->next;

	//�����ǵ�ߴ�
	if ((nRel = GetNextElement("ySize",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.ySize = DataTypeConversion::String2Size(content);
	cur_node = cur_node->next;

	//�����ǵ�����������
	if ((nRel = GetNextElement("xMarker",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.xMarker = DataTypeConversion::String2Rect(content);
	cur_node = cur_node->next;

	//�����ǵ�����������
	if ((nRel = GetNextElement("yMarker",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.yMarker = DataTypeConversion::String2Rect(content);
	return 0;
}
//������ ��ǵ���ģ��
int XmlIo::ReadMarkerGroupInfo(xmlNodePtr root_node, vector<Marker_info3> &markerGroupInfo)
{
	
	
	xmlNodePtr perMarkerInfo_node = root_node->children;
	xmlNodePtr cur_node,xmark_node;
	int nRel,i=0;
	string content;
	while(perMarkerInfo_node)
	{
		Marker_info3 markInfo;
		cur_node=perMarkerInfo_node->children;
		//�����ǵ����
		if ((nRel = GetNextElement("id",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		markInfo.id = DataTypeConversion::String2Int(content);
		xmark_node=cur_node->next;
		cur_node = xmark_node->children;
		while(cur_node)
		{
			content = string((char * )cur_node->children->content);
			markInfo.xMarker.push_back(DataTypeConversion::String2Rect(content));
			cur_node = cur_node->next;
		}
		cur_node = xmark_node->next->children;
		while(cur_node)
		{
			content = string((char * )cur_node->children->content);
			markInfo.yMarker.push_back(DataTypeConversion::String2Rect(content));
			cur_node = cur_node->next;
		}
		markerGroupInfo.push_back(markInfo);
		perMarkerInfo_node=perMarkerInfo_node->next;
	}

	
	return 0;


}

//Id����Ϣ

int XmlIo::ReadIdPointInfo(xmlNodePtr root_node,vector<ItemPos> &idPoint)
{
	xmlNodePtr cur_node = root_node->children;
	int nRel,i=0;
	string content;
	while(cur_node)
	{
		if ((nRel = GetNextElement("perIdPointInfo",cur_node))!=0)	
			return nRel;
		ItemPos itemPos;
		ReadItemPos(cur_node->children,itemPos);
		idPoint.push_back(itemPos);
		cur_node=cur_node->next;
	}
	return 0;
}

//������Ϣ
int XmlIo::ReadBarInfo(xmlNodePtr root_node,vector<Bar_info> &barGroup)
{
	xmlNodePtr perBar_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel,i=0;
	string content;
	//ÿ��������Ϣ
	while (perBar_node)
	{
		Bar_info barInfo;
		cur_node = perBar_node->children;
		//��������
		if ((nRel = GetNextElement("barType",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		barInfo.barType = (BarType)DataTypeConversion::String2Ushort(content);
		cur_node = cur_node->next;
		//����λ��
		if ((nRel = GetNextElement("pos",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		barInfo.pos = DataTypeConversion::String2Rect(content);
		barGroup.push_back(barInfo);

		perBar_node = perBar_node->next;
	}		
	return 0;
}
//Ԥ������Ϳ����
int XmlIo::ReadFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info> &fillingPointGroup)
{
	xmlNodePtr perFillingPoint_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel;
	string content;
	//ÿ����Ϳ����Ϣ
	while (perFillingPoint_node)
	{
		FillingPoints_info fillingPointsInfo;
		cur_node = perFillingPoint_node->children;
		//��Ϳ������
		if ((nRel = GetNextElement("name",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.name = CChineseCode::UTF8ToGBK(content);
		cur_node = cur_node->next;
		//��Ϳ������
		if ((nRel = GetNextElement("type",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.type = (FillingPointsType)DataTypeConversion::String2Ushort(content);
		cur_node = cur_node->next;
		while(cur_node)
		{
			//��Ϳ��λ��
			if ((nRel = GetNextElement("itemPos",cur_node))!=0)	
				return nRel;
			ItemPos itemPos;
			ReadItemPos(cur_node,itemPos);
			fillingPointsInfo.fillingPoints.push_back(itemPos);
			cur_node = cur_node->next;
		}
		fillingPointGroup.push_back(fillingPointsInfo);
		perFillingPoint_node = perFillingPoint_node->next;

	}		
	return 0;

}
//������Ԥ������Ϳ����ģ��
int XmlIo::ReadFillingPointsInfo(xmlNodePtr root_node,vector<FillingPoints_info3> &fillingPointGroup)
{
	xmlNodePtr perFillingPoint_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel;
	string content;
	//ÿ����Ϳ����Ϣ
	while (perFillingPoint_node)
	{
		FillingPoints_info3 fillingPointsInfo;
		cur_node = perFillingPoint_node->children;
		//��Ϳ������
		if ((nRel = GetNextElement("name",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.name = CChineseCode::UTF8ToGBK(content);
		cur_node = cur_node->next;
		//��Ϳ������
		if ((nRel = GetNextElement("type",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.type = (FillingPointsType)DataTypeConversion::String2Ushort(content);
		cur_node = cur_node->next;

		//�Ƿ��Ǻ����
		if ((nRel = GetNextElement("isCrosswise",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.isCrosswise = DataTypeConversion::String2Bool(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bgInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.bgInfo = DataTypeConversion::String2Mat32s(content);
		cur_node = cur_node->next;

		while(cur_node)
		{
			//��Ϳ��λ��
			if ((nRel = GetNextElement("fillingpointItemPos",cur_node))!=0)	
				return nRel;
			FillingpointItemPos itemPos;
			ReadFillingpointItemPos(cur_node,itemPos);
			fillingPointsInfo.fillingPoints.push_back(itemPos);
			cur_node = cur_node->next;
		}
		fillingPointGroup.push_back(fillingPointsInfo);
		perFillingPoint_node = perFillingPoint_node->next;

	}		
	return 0;

}
// ��ȡѡ��λ����Ϣ
int XmlIo::ReadItemPos(xmlNodePtr firstItemPosPtr,ItemPos &itemPos)
{
	xmlNodePtr cur_node = firstItemPosPtr->children;
	int nRel;
	string content;
	//���
	if ((nRel = GetNextElement("id",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.id = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;

	//���
	if ((nRel = GetNextElement("mark_id",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.mark_id = DataTypeConversion::String2Ushort(content);
	cur_node = cur_node->next;

	//�Ƿ��Ǻ����
	if ((nRel = GetNextElement("isCrosswise",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isCrosswise = DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//�Ƿ��ǵ�ѡ
	if ((nRel = GetNextElement("isSingleChoice",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isSingleChoice = DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//����/������
	if ((nRel = GetNextElement("interval",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.interval = DataTypeConversion::String2Ushort(content);
	cur_node = cur_node->next;

	//��Ŀ��Ӧ��λ������
	while(cur_node){
		if ((nRel = GetNextElement("markerIdx",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		string subString;
		int l = 0,r = 0;
		for (int i=0;i<3;i++)
		{
			r = content.find(' ',r+1);
			subString = content.substr(l,r);
			l = r+1;
			itemPos.markerIdx[i] = DataTypeConversion::String2Ushort(subString);
		}
		cur_node = cur_node->next;
	}
	return 0;
}
//��ȡÿλ��Ϳ����Ϣ
int XmlIo::ReadFillingpointItemPos(xmlNodePtr firstItemPosPtr,FillingpointItemPos &itemPos)
{
	xmlNodePtr cur_node = firstItemPosPtr->children;
	int nRel;
	string content;
	//���
	if ((nRel = GetNextElement("id",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.id = DataTypeConversion::String2Int(content);
	cur_node = cur_node->next;


	//�Ƿ��ǵ�ѡ
	if ((nRel = GetNextElement("isSingleChoice",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isSingleChoice = DataTypeConversion::String2Bool(content);
	cur_node = cur_node->next;

	//��Ŀ��Ӧ��λ������
	if ((nRel = GetNextElement("pos",cur_node))!=0)	
		return nRel;
	cur_node = cur_node->children;
	while(cur_node){
		content = string((char * )cur_node->children->content);
		itemPos.pos.push_back(DataTypeConversion::String2Rect(content));
		cur_node = cur_node->next;
	}
	return 0;
}
//��Ϳ�㱳����Ϣ
int XmlIo::ReadFillingPointBackgroundInfo(xmlNodePtr root_node,vector<PerFillingPtBackground_info> &fillingPointBackgroundInfo)
{
	xmlNodePtr perFillingPtBackgroundInfo_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel;
	string content;
	//ÿ����Ϳ������Ϣ
	while(perFillingPtBackgroundInfo_node)
	{
		cur_node = perFillingPtBackgroundInfo_node->children;
		PerFillingPtBackground_info perFillingPtBackgroundInfo;
		//��Ϳ������
		if ((nRel = GetNextElement("type",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perFillingPtBackgroundInfo.type = (FillingPointsType)DataTypeConversion::String2Ushort(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bkInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perFillingPtBackgroundInfo.bkInfo = DataTypeConversion::String2Mat32s(content);
		fillingPointBackgroundInfo.push_back(perFillingPtBackgroundInfo);
		perFillingPtBackgroundInfo_node = perFillingPtBackgroundInfo_node->next;
	}

	return 0;
}
//��Ŀ��Ϣ
int XmlIo::ReadQuestionInfo(xmlNodePtr root_node,vector<ItemPos> &questionInfo)
{
	xmlNodePtr perQuestionInfo_node = root_node->children;
	int nRel;
	ItemPos itemPos;
	//ÿ����Ϳ������Ϣ
	while(perQuestionInfo_node)
	{
		//��ȡ��λ������
		if ((nRel = GetNextElement("itemPos",perQuestionInfo_node))!=0)	
			return nRel;
		ReadItemPos(perQuestionInfo_node,itemPos);
		questionInfo.push_back(itemPos);
		perQuestionInfo_node = perQuestionInfo_node->next;
	}
	return 0;
}
//��Ŀ������Ϣ
int XmlIo::ReadQuestionBackgroundInfo(xmlNodePtr root_node,vector<PerQuestionBackground_info> &questionBackgroundInfo)
{
	xmlNodePtr perQuestionBackgroundInfo_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel;
	string content;
	//ÿ����Ϳ������Ϣ
	while(perQuestionBackgroundInfo_node)
	{
		cur_node = perQuestionBackgroundInfo_node->children;
		PerQuestionBackground_info perQuestionBackgroundInfo;
		//��Ϳ������
		if ((nRel = GetNextElement("type",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perQuestionBackgroundInfo.type = (FillingPointsType)DataTypeConversion::String2Ushort(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bkInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perQuestionBackgroundInfo.bkInfo = DataTypeConversion::String2Mat32s(content);
		questionBackgroundInfo.push_back(perQuestionBackgroundInfo);
		perQuestionBackgroundInfo_node = perQuestionBackgroundInfo_node->next;
	}

	return 0;
}
//��������
int XmlIo::ReadCropAreaInfo(xmlNodePtr root_node,vector<CropArea_info> &cropAreaInfo)
{
	xmlNodePtr perCropAreaInfo_node = root_node->children;
	xmlNodePtr cur_node;
	int nRel;
	string content;
	//ÿ������������Ϣ
	while(perCropAreaInfo_node)
	{
		cur_node = perCropAreaInfo_node->children;
		CropArea_info perCropAreaInfo;
		//����������
		if ((nRel = GetNextElement("name",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.name = CChineseCode::UTF8ToGBK(content);
		cur_node = cur_node->next;

		//��������λ��
		if ((nRel = GetNextElement("pos",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.pos = DataTypeConversion::String2Rect(content);
		cur_node = cur_node->next;

		//�ϲ����
		if ((nRel = GetNextElement("groupNum",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.groupNum = DataTypeConversion::String2Int(content);
		cur_node = cur_node->next;

		//��������
		if ((nRel = GetNextElement("isSecret",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.isSecret = DataTypeConversion::String2Bool(content);
		cropAreaInfo.push_back(perCropAreaInfo);
		perCropAreaInfo_node = perCropAreaInfo_node->next;
	}
	return 0;
}
//ʶ��ο���
int XmlIo::ReadRefPoint(xmlNodePtr root_node,vector<Rect> &refPoint)
{
	xmlNodePtr cur_node = root_node->children;
	string content;
	while(cur_node)
	{
		content = string((char * )cur_node->children->content);
		refPoint.push_back(DataTypeConversion::String2Rect(content));
		cur_node=cur_node->next;
	}
	return 0;
}
//����ͬ��ͷ
int XmlIo::ReadMarker(xmlNodePtr root_node,vector<PerMarker_info> &marker)
{
	xmlNodePtr cur_node ;
	xmlNodePtr perMarker_node = root_node->children;
	int nRel,i=0;
	string content;
	if ((nRel = GetNextElement("perMarkerInfo",perMarker_node))!=0)	
		return nRel;
	while(perMarker_node)
	{
		PerMarker_info perMark;
		cur_node=perMarker_node->children;
		if ((nRel = GetNextElement("id",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perMark.id=DataTypeConversion::String2Short(content);
		cur_node=cur_node->next;
		if ((nRel = GetNextElement("pos",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perMark.pos=DataTypeConversion::String2Rect(content);
		marker.push_back(perMark);
		perMarker_node=perMarker_node->next;
	}
	return 0;
}

// �����ЧԪ��
int XmlIo::GetNextElement(string elementName, xmlNodePtr &cur_node)
{
	while (cur_node != NULL)
	{
		//����ע�ͽڵ�
		if (cur_node->type ==XML_COMMENT_NODE)
			cur_node = cur_node->next;
		else
			break;
	}
	//����ʽ�ļ�������
	if (NULL == cur_node)
	{
		return -1;
	}
	//����ʽ�ļ���ƥ��
	if (elementName.compare((char *)cur_node->name)!=0)
	{
		return -2;
	}
	return 0;
}



