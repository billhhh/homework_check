
#include "XmlIo.h"
#include "ChineseCode.h"

XmlIo::XmlIo(void)
{
}


XmlIo::~XmlIo(void)
{
}
//////////////////////////////////д////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int XmlIo::Write(string filename,AC_info acInfo)
{

	xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
	xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"AnswerCardInfo");
	//���ø��ڵ�
	xmlDocSetRootElement(doc,root_node);

	//�Ծ�����
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ծ�����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_id", BAD_CAST (acInfo.ac_id.c_str()));

	//�ֱ���
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ֱ���").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "dpi", BAD_CAST (dtc.Int2String(acInfo.dpi).c_str()));

	//��λ����Ϣ
	WriteAnchorPointInfo(root_node,acInfo.anchorPointInfo);

	//��ǵ���Ϣ
	WriteMarkerInfo(root_node,acInfo.markerInfo);

	//������Ϣ
	WriteBarInfo(root_node,acInfo.barGroup);

	//Ԥ������Ϳ����
	WriteFillingPointsInfo(root_node,acInfo.fillingPointGroup);

	//��Ϳ�㱳����Ϣ
	WriteFillingPointBackgroundInfo(root_node,acInfo.fillingPointBackgroundInfo);

	//��Ŀ��Ϣ
	WriteQuestionInfo(root_node,acInfo.questioninfo);

	//��Ŀ������Ϣ
	WriteQuestionBackgroundInfo(root_node,acInfo.questionBackgroundInfo);

	//����������Ϣ
	WriteCropAreaInfo(root_node,acInfo.cropAreaInfo);
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

	//�Ծ�����
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ծ�����").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "ac_id", BAD_CAST (acInfo.ac_id.c_str()));

	//�ֱ���
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ֱ���").c_str()) ));
	xmlNewTextChild(root_node, NULL, BAD_CAST "dpi", BAD_CAST (dtc.Int2String(acInfo.dpi).c_str()));

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
	xmlNewTextChild(anchorPointInfo_node, NULL, BAD_CAST "num", BAD_CAST(dtc.Int2String(anchorPointInfo.num).c_str()));

	//��λ������
	xmlAddChild(anchorPointInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ������").c_str()) ));
	xmlNewTextChild(anchorPointInfo_node, NULL, BAD_CAST "anchorType", BAD_CAST(dtc.Short2String(anchorPointInfo.anchorType).c_str()));

	//��λ��λ����Ϣ
	xmlAddChild(anchorPointInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��λ��λ����Ϣ").c_str()) ));
	xmlNodePtr anchorPtPosInfo_node = xmlNewNode(NULL,BAD_CAST"anchorPtPosInfo");
	xmlAddChild(anchorPointInfo_node,anchorPtPosInfo_node);
	for (unsigned int i=0;i<anchorPointInfo.anchorPt.size();i++)
	{
		xmlNewTextChild(anchorPtPosInfo_node, NULL, BAD_CAST "perAnchorPtPos", BAD_CAST(dtc.Rect2String(anchorPointInfo.anchorPt[i]).c_str()));
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
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xNum", BAD_CAST(dtc.Int2String(markerInfo.xNum).c_str()));

	//�����ǵ�����
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "yNum", BAD_CAST(dtc.Int2String(markerInfo.yNum).c_str()));

	//�����ǵ�ߴ�
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�ߴ�").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xSize", BAD_CAST(dtc.Size2String(markerInfo.xSize).c_str()));

	//�����ǵ�ߴ�
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�ߴ�").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "ySize", BAD_CAST(dtc.Size2String(markerInfo.ySize).c_str()));

	//�����ǵ�����������
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����������").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "xMarker", BAD_CAST(dtc.Rect2String(markerInfo.xMarker).c_str()));

	//�����ǵ�����������
	xmlAddChild(markerInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�����������").c_str()) ));
	xmlNewTextChild(markerInfo_node, NULL, BAD_CAST "yMarker", BAD_CAST(dtc.Rect2String(markerInfo.yMarker).c_str()));

	return 0;
}

int XmlIo::WriteMarkerInfo3(xmlNodePtr root_node, Marker_info3 markerInfo)
{
	//��ǵ�
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�����ǵ�").c_str()) ));
	xmlNodePtr xMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"xMarkerInfo");
	xmlAddChild(root_node,xMarkerInfo_node);
	for (int i=0;i<markerInfo.xMarker.size();i++)
	{
		xmlNewTextChild(xMarkerInfo_node, NULL, BAD_CAST "perMarkerPos", BAD_CAST(dtc.Rect2String(markerInfo.xMarker[i]).c_str()));
	}
	xmlNodePtr yMarkerInfo_node = xmlNewNode(NULL,BAD_CAST"yMarkerInfo");
	xmlAddChild(root_node,yMarkerInfo_node);
	for (int i=0;i<markerInfo.yMarker.size();i++)
	{
		xmlNewTextChild(yMarkerInfo_node, NULL, BAD_CAST "perMarkerPos", BAD_CAST(dtc.Rect2String(markerInfo.yMarker[i]).c_str()));
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
		xmlNewTextChild(perBarInfo_node,NULL, BAD_CAST "barType", BAD_CAST (dtc.Ushort2String(barGroup[i].barType).c_str()));
		xmlAddChild(perBarInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����λ��").c_str()) ));
		xmlNewTextChild(perBarInfo_node,NULL, BAD_CAST "pos", BAD_CAST (dtc.Rect2String(barGroup[i].pos).c_str()));
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
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "type", BAD_CAST (dtc.Ushort2String(fillingPointGroup[i].type).c_str()));

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
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "type", BAD_CAST (dtc.Ushort2String(fillingPointGroup[i].type).c_str()));

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ��Ǻ����").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "isCrosswise", BAD_CAST (dtc.Ushort2String(fillingPointGroup[i].isCrosswise).c_str()));

		xmlAddChild(perFillingPointGroup_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		xmlNewTextChild(perFillingPointGroup_node,NULL, BAD_CAST "bgInfo", BAD_CAST (dtc.Mat32s2String(fillingPointGroup[i].bgInfo).c_str()));

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
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "id", BAD_CAST (dtc.Int2String(itemPos.id).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ����").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isCrosswise", BAD_CAST (dtc.Bool2String(itemPos.isCrosswise).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ�ѡ").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isSingleChoice", BAD_CAST (dtc.Bool2String(itemPos.isSingleChoice).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("����/����������ѡ���Ų�Ϊ������Ϊ������").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "interval", BAD_CAST (dtc.Ushort2String(itemPos.interval).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��Ŀ��Ӧ��λ����������Ϊ������[0]Ϊˮƽ���������ţ�[1]Ϊ��ֱ�����Ӧ�ĵ�һ�������ţ�[2]Ϊ��ֱ�����Ӧ�����һ��������").c_str()) ));
	string tmpStr = dtc.Ushort2String(itemPos.markerIdx[0]);
	tmpStr += ' '+dtc.Ushort2String(itemPos.markerIdx[1]);
	tmpStr += ' '+dtc.Ushort2String(itemPos.markerIdx[2]);
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "markerIdx", BAD_CAST (tmpStr.c_str()));
	return 0;

}
/////////////////////////////////////ÿλ��Ϳ����Ϣ/////////////////////////////////////
int XmlIo::WriteFillingpointItemPos(xmlNodePtr partent_node,FillingpointItemPos itemPos)
{
	xmlNodePtr itemPos_node = xmlNewNode(NULL,BAD_CAST"fillingpointItemPos");
	xmlAddChild(partent_node,itemPos_node);
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("���").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "id", BAD_CAST (dtc.Int2String(itemPos.id).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�Ƿ�ѡ").c_str()) ));
	xmlNewTextChild(itemPos_node,NULL, BAD_CAST "isSingleChoice", BAD_CAST (dtc.Bool2String(itemPos.isSingleChoice).c_str()));
	xmlAddChild(itemPos_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("λ��").c_str()) ));
	xmlNodePtr pos_node = xmlNewNode(NULL,BAD_CAST"pos");
	xmlAddChild(itemPos_node,pos_node);
	for (int i=0;i<itemPos.pos.size();i++)
	{
		xmlNewTextChild(pos_node,NULL, BAD_CAST "perFillingPointPos", BAD_CAST (dtc.Rect2String(itemPos.pos[i]).c_str()));
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
		xmlNewTextChild(perFillingPointBackgroundInfo_node,NULL, BAD_CAST "type", BAD_CAST (dtc.Ushort2String(fillingPointBackgroundInfo[i].type).c_str()));

		xmlAddChild(perFillingPointBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		if ((matStr = dtc.Mat32s2String(fillingPointBackgroundInfo[i].bkInfo))=="error")
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
		xmlNewTextChild(perQuestionBackgroundInfo_node,NULL, BAD_CAST "type", BAD_CAST (dtc.Ushort2String(questionBackgroundInfo[i].type).c_str()));

		xmlAddChild(perQuestionBackgroundInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("������Ϣ").c_str()) ));
		if ((matStr = dtc.Mat32s2String(questionBackgroundInfo[i].bkInfo))=="error")
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
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "pos", BAD_CAST (dtc.Rect2String(cropAreaInfo[i].pos).c_str()));

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ϲ����").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "groupNum", BAD_CAST (dtc.Int2String(cropAreaInfo[i].groupNum).c_str()));

		xmlAddChild(perCropAreaInfo_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("��������").c_str()) ));
		xmlNewTextChild(perCropAreaInfo_node,NULL, BAD_CAST "isSecret", BAD_CAST (dtc.Bool2String(cropAreaInfo[i].isSecret).c_str()));

	}
	return 0;
}
///////////////////////////////�ڰ׼����/////////////////////////////////////////////

int XmlIo::WriteBlackWhiteLine(xmlNodePtr root_node,Rect blackLine,Rect whiteLine)
{
	xmlAddChild(root_node,xmlNewComment( BAD_CAST (CChineseCode::GBKToUTF8("�ڰ׼����").c_str()) ));
	xmlNewTextChild(root_node,NULL, BAD_CAST "blackLine", BAD_CAST (dtc.Rect2String(blackLine).c_str()));
	xmlNewTextChild(root_node,NULL, BAD_CAST "whiteLine", BAD_CAST (dtc.Rect2String(whiteLine).c_str()));
	return 0;
}
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////��ģ��/////////////////////////////////////////
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
	
	xmlNodePtr cur_node;      //������ָ��
	cur_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	int nRel;
	string content;
	//��ʼ��ȡ����

	//�Ծ�����
	if ((nRel = GetNextElement("ac_id",cur_node))!=0)
	{
		return nRel;
	}
	acInfo.ac_id = string((char * )cur_node->children->content);
	cur_node = cur_node->next;

	//�ֱ���
	if ((nRel = GetNextElement("dpi",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.dpi = dtc.String2Int(content);
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

	return 0;
}
int XmlIo::Read(string filename,AC_info3 &acInfo){

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

	xmlNodePtr cur_node;      //������ָ��
	cur_node = root_node->xmlChildrenNode; //�ӽڵ㼯������
	int nRel;
	string content;
	//��ʼ��ȡ����

	//�Ծ�����
	if ((nRel = GetNextElement("ac_id",cur_node))!=0)
	{
		return nRel;
	}
	acInfo.ac_id = string((char * )cur_node->children->content);
	cur_node = cur_node->next;

	//�ֱ���
	if ((nRel = GetNextElement("dpi",cur_node))!=0)	
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.dpi = dtc.String2Int(content);
	cur_node = cur_node->next;

	//��λ����Ϣ
	if ((nRel = GetNextElement("anchorPointInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadAnchorPointInfo(cur_node,acInfo.anchorPointInfo);
	cur_node = cur_node->next;

	//��ǵ���Ϣ
	if ((nRel = GetNextElement("xMarkerInfo",cur_node))!=0)	
	{
		return nRel;
	}
	ReadMarkerInfo(cur_node,acInfo.markerInfo);
	cur_node = cur_node->next;	//����ymarker��ǩ
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
	acInfo.blackLine = dtc.String2Rect(content);
	cur_node = cur_node->next;
	if ((nRel = GetNextElement("whiteLine",cur_node))!=0)
	{
		return nRel;
	}
	content = string((char * )cur_node->children->content);
	acInfo.whiteLine = dtc.String2Rect(content);

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
	anchorPointInfo.num = dtc.String2Int(content);
	cur_node = cur_node->next;
	//��ȡ��λ������
	if ((nRel = GetNextElement("anchorType",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	anchorPointInfo.anchorType = dtc.String2Short(content);
	cur_node = cur_node->next;
	//��ȡ��λ��λ��
	if ((nRel = GetNextElement("anchorPtPosInfo",cur_node))!=0)	
		return nRel;
	xmlNodePtr anchorPtPosInfo_node = cur_node;
	xmlNodePtr tmp = cur_node->children;
	while(tmp)
	{
		content = string((char * )tmp->children->content);
		anchorPointInfo.anchorPt.push_back(dtc.String2Rect(content));
		tmp = tmp->next;
	}
	return 0;
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
	markerInfo.xNum = dtc.String2Int(content);
	cur_node = cur_node->next;

	//�����ǵ�����
	if ((nRel = GetNextElement("yNum",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.yNum = dtc.String2Int(content);
	cur_node = cur_node->next;

	//�����ǵ�ߴ�
	if ((nRel = GetNextElement("xSize",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.xSize = dtc.String2Size(content);
	cur_node = cur_node->next;

	//�����ǵ�ߴ�
	if ((nRel = GetNextElement("ySize",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.ySize = dtc.String2Size(content);
	cur_node = cur_node->next;

	//�����ǵ�����������
	if ((nRel = GetNextElement("xMarker",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.xMarker = dtc.String2Rect(content);
	cur_node = cur_node->next;

	//�����ǵ�����������
	if ((nRel = GetNextElement("yMarker",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	markerInfo.yMarker = dtc.String2Rect(content);
	return 0;
}
int XmlIo::ReadMarkerInfo(xmlNodePtr root_node, Marker_info3 &markerInfo)
{

	xmlNodePtr cur_node = root_node->children;
	int nRel;
	string content;
	while(cur_node)
	{
		content = string((char * )cur_node->children->content);
		markerInfo.xMarker.push_back(dtc.String2Rect(content));
		cur_node = cur_node->next;
	}
	cur_node = root_node->next->children;
	while(cur_node)
	{
		content = string((char * )cur_node->children->content);
		markerInfo.yMarker.push_back(dtc.String2Rect(content));
		cur_node = cur_node->next;
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
		barInfo.barType = (BarType)dtc.String2Ushort(content);
		cur_node = cur_node->next;
		//����λ��
		if ((nRel = GetNextElement("pos",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		barInfo.pos = dtc.String2Rect(content);
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
		fillingPointsInfo.type = (FillingPointsType)dtc.String2Ushort(content);
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
		fillingPointsInfo.type = (FillingPointsType)dtc.String2Ushort(content);
		cur_node = cur_node->next;

		//�Ƿ��Ǻ����
		if ((nRel = GetNextElement("isCrosswise",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.isCrosswise = dtc.String2Bool(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bgInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		fillingPointsInfo.bgInfo = dtc.String2Mat32s(content);
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
	itemPos.id = dtc.String2Int(content);
	cur_node = cur_node->next;

	//�Ƿ��Ǻ����
	if ((nRel = GetNextElement("isCrosswise",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isCrosswise = dtc.String2Bool(content);
	cur_node = cur_node->next;

	//�Ƿ��ǵ�ѡ
	if ((nRel = GetNextElement("isSingleChoice",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isSingleChoice = dtc.String2Bool(content);
	cur_node = cur_node->next;

	//����/������
	if ((nRel = GetNextElement("interval",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.interval = dtc.String2Ushort(content);
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
			itemPos.markerIdx[i] = dtc.String2Ushort(subString);
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
	itemPos.id = dtc.String2Int(content);
	cur_node = cur_node->next;


	//�Ƿ��ǵ�ѡ
	if ((nRel = GetNextElement("isSingleChoice",cur_node))!=0)	
		return nRel;
	content = string((char * )cur_node->children->content);
	itemPos.isSingleChoice = dtc.String2Bool(content);
	cur_node = cur_node->next;

	//��Ŀ��Ӧ��λ������
	if ((nRel = GetNextElement("pos",cur_node))!=0)	
		return nRel;
	cur_node = cur_node->children;
	while(cur_node){
		content = string((char * )cur_node->children->content);
		itemPos.pos.push_back(dtc.String2Rect(content));
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
		perFillingPtBackgroundInfo.type = (FillingPointsType)dtc.String2Ushort(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bkInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perFillingPtBackgroundInfo.bkInfo = dtc.String2Mat32s(content);
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
		perQuestionBackgroundInfo.type = (FillingPointsType)dtc.String2Ushort(content);
		cur_node = cur_node->next;

		//��Ϳ�㱳��
		if ((nRel = GetNextElement("bkInfo",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perQuestionBackgroundInfo.bkInfo = dtc.String2Mat32s(content);
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
		perCropAreaInfo.pos = dtc.String2Rect(content);
		cur_node = cur_node->next;

		//�ϲ����
		if ((nRel = GetNextElement("groupNum",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.groupNum = dtc.String2Int(content);
		cur_node = cur_node->next;

		//��������
		if ((nRel = GetNextElement("isSecret",cur_node))!=0)	
			return nRel;
		content = string((char * )cur_node->children->content);
		perCropAreaInfo.isSecret = dtc.String2Bool(content);
		cropAreaInfo.push_back(perCropAreaInfo);
		perCropAreaInfo_node = perCropAreaInfo_node->next;
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



