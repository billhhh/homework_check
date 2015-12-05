
#include "AnswerCard.h"
#include "AnswerCardDlg.h"
#include "qdebug.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAnswerCardApp ����
CAnswerCardApp::CAnswerCardApp()
	: m_group_state(0)
	, m_state(0)
	, is_synchronous(false)
	, min_markers_area(0)
	, anchor_type(0)
	, m_hasQuestions(true)
	, questionType(0)
{
	//ͬ����־��ʼ��
	is_synchronous = true;

	//��ȡ�����ļ�
	readConfig();

	min_markers_area = 50;
}

void CAnswerCardApp::readConfig()
{
	QSettings settings("config.ini", QSettings::IniFormat);

	//��λ������
	int color_r = settings.value("AnchorPoint/Color_R").toInt();
	int color_g = settings.value("AnchorPoint/Color_G").toInt();
	int color_b = settings.value("AnchorPoint/Color_B").toInt();
	int thickness = settings.value("AnchorPoint/Thickness").toInt();
	anchor_point_color = Scalar(color_b,color_g,color_r);
	anchor_point_thickness = thickness;

	//��ǵ�����
	color_r = settings.value("MarkerPoint/Color_R").toInt();
	color_g = settings.value("MarkerPoint/Color_G").toInt();
	color_b = settings.value("MarkerPoint/Color_B").toInt();
	thickness = settings.value("MarkerPoint/Thickness").toInt();
	markers_point_color = Scalar(color_b,color_g,color_r);
	markers_point_thickness = thickness;

	//����������
	color_r = settings.value("BarCode/Color_R").toInt();
	color_g = settings.value("BarCode/Color_G").toInt();
	color_b = settings.value("BarCode/Color_B").toInt();
	thickness = settings.value("BarCode/Thickness").toInt();
	barcode_color = Scalar(color_b,color_g,color_r);
	barcode_thickness = thickness;

	color_r = settings.value("BarCode_Clicked/Color_R").toInt();
	color_g = settings.value("BarCode_Clicked/Color_G").toInt();
	color_b = settings.value("BarCode_Clicked/Color_B").toInt();
	thickness = settings.value("BarCode_Clicked/Thickness").toInt();
	barcodeClicked_color = Scalar(color_b,color_g,color_r);
	barcodeClicked_thickness = thickness;

	//��ѡ����ɫ���߿�
	color_r = settings.value("SingleQuestion/Color_R").toInt();
	color_g = settings.value("SingleQuestion/Color_G").toInt();
	color_b = settings.value("SingleQuestion/Color_B").toInt();
	thickness = settings.value("SingleQuestion/Thickness").toInt();
	answer_color = Scalar(color_b,color_g,color_r);
	answer_single_thickness = thickness;

	color_r = settings.value("SingleQuestion_Clicked/Color_R").toInt();
	color_g = settings.value("SingleQuestion_Clicked/Color_G").toInt();
	color_b = settings.value("SingleQuestion_Clicked/Color_B").toInt();
	thickness = settings.value("SingleQuestion_Clicked/Thickness").toInt();
	answerClicked_color = Scalar(color_b,color_g,color_r);
	answerClicked_single_thickness = thickness;

	//��ѡ����ɫ���߿�
	color_r = settings.value("MultiQuestion/Color_R").toInt();
	color_g = settings.value("MultiQuestion/Color_G").toInt();
	color_b = settings.value("MultiQuestion/Color_B").toInt();
	thickness = settings.value("MultiQuestion/Thickness").toInt();
	answer_multi_color = Scalar(color_b,color_g,color_r);
	answer_multi_thickness = thickness;

	color_r = settings.value("MultiQuestion_Clicked/Color_R").toInt();
	color_g = settings.value("MultiQuestion_Clicked/Color_G").toInt();
	color_b = settings.value("MultiQuestion_Clicked").toInt();
	thickness = settings.value("MultiQuestion_Clicked/Thickness").toInt();
	answerClicked_multi_color = Scalar(color_b,color_g,color_r);
	answerClicked_multi_thickness = thickness;

	//Ԥ������Ϳ����ɫ�߿�
	color_r = settings.value("FillPoint_Clicked/Color_R").toInt();
	color_g = settings.value("FillPoint_Clicked/Color_G").toInt();
	color_b = settings.value("FillPoint_Clicked/Color_B").toInt();
	thickness = settings.value("FillPoint_Clicked/Thickness").toInt();
	cfpClicked_color = Scalar(color_b,color_g,color_r);
	cfpClicked_thickness = thickness;

	//Ԥ������Ϳ����ɫ�߿�
	color_r = settings.value("FillPoint/Color_R").toInt();
	color_g = settings.value("FillPoint/Color_G").toInt();
	color_b = settings.value("FillPoint/Color_B").toInt();
	thickness = settings.value("FillPoint/Thickness").toInt();
	cfp_color = Scalar(color_b,color_g,color_r);
	cfp_thickness = thickness;

	//����������ɫ�߿�
	color_r = settings.value("CropArea/Color_R").toInt();
	color_g = settings.value("CropArea/Color_G").toInt();
	color_b = settings.value("CropArea/Color_B").toInt();
	thickness = settings.value("CropArea/Thickness").toInt();
	cropArea_color = Scalar(color_b,color_g,color_r);
	cropArea_thickness = thickness;

	color_r = settings.value("CropArea_Clicked/Color_R").toInt();
	color_g = settings.value("CropArea_Clicked/Color_G").toInt();
	color_b = settings.value("CropArea_Clicked/Color_B").toInt();
	thickness = settings.value("CropArea_Clicked/Thickness").toInt();
	cropAreaClicked_color = Scalar(color_b,color_g,color_r);
	cropAreaClicked_thickness = thickness;

	//�׼������ɫ�߿�
	color_r = settings.value("WhiteLine/Color_R").toInt();
	color_g = settings.value("WhiteLine/Color_G").toInt();
	color_b = settings.value("WhiteLine/Color_B").toInt();
	thickness = settings.value("WhiteLine/Thickness").toInt();
	whiteLine_color = Scalar(color_b,color_g,color_r);
	whiteLine_thickness = thickness;

	//�ڼ������ɫ�߿�
	color_r = settings.value("BlackLine/Color_R").toInt();
	color_g = settings.value("BlackLine/Color_G").toInt();
	color_b = settings.value("BlackLine/Color_B").toInt();
	thickness = settings.value("BlackLine/Thickness").toInt();
	blackLine_color = Scalar(color_b,color_g,color_r);
	blackLine_thickness = thickness;

	//�����ǵ���ɫ
	color_r = settings.value("VirtualMarker/Color_R").toInt();
	color_g = settings.value("VirtualMarker/Color_G").toInt();
	color_b = settings.value("VirtualMarker/Color_B").toInt();
	marker_color = Scalar(color_b,color_g,color_r);

	//�����ǵ㱻��ѡ
	color_r = settings.value("VirTualMarker_Clicked/Color_R").toInt();
	color_g = settings.value("VirTualMarker_Clicked/Color_G").toInt();
	color_b = settings.value("VirTualMarker_Clicked/Color_B").toInt();
	thickness = settings.value("VirTualMarker_Clicked/Thickness").toInt();
	markerClicked_color = Scalar(color_b,color_g,color_r);
	markerClicked_thickness = thickness;

	//id����ɫ�߿�
	color_r = settings.value("IdPoint/Color_R").toInt();
	color_g = settings.value("IdPoint/Color_G").toInt();
	color_b = settings.value("IdPoint/Color_B").toInt();
	thickness = settings.value("IdPoint/Thickness").toInt();
	idPoint_color = Scalar(color_b,color_g,color_r);
	idPoint_thickness = thickness;

	color_r = settings.value("IdPoint_Clicked/Color_R").toInt();
	color_g = settings.value("IdPoint_Clicked/Color_G").toInt();
	color_b = settings.value("IdPoint_Clicked/Color_B").toInt();
	thickness = settings.value("IdPoint_Clicked/Thickness").toInt();
	idPointClicked_color = Scalar(color_b,color_g,color_r);
	idPointClicked_thickness = thickness;
}

//�������ʽ����
void CAnswerCardApp::clear()
{
	for (int i=0;i<4;i++)
	{
		//�ж��Ƿ��Ѿ���ֵ
		if (anchorPoints[i].width>0)
		{
			anchorPoints[i] = cv::Rect();
		}
	}

	if (markersRect[0].width>0)
	{
		markersRect[0] = cv::Rect();
	}
	if (markersRect[1].width>0)
	{
		markersRect[1] = cv::Rect();
	}

	barGroup.clear();
	cropAreas.clear();
	cfp_group.clear();
	questionInfo.clear();
	hmarkers.clear();
	vmarkers.clear();
	whiteLineRect = cv::Rect();
	blackLineRect = cv::Rect();
	markerBT = MarkersBoundaryTable();
	idGroup.clear();
	referPoint.clear();
	anchor_type = 0;
	m_state = BaseBegin;
	m_group_state = InitialState;
}

// Ψһ��һ�� CAnswerCardApp ����
CAnswerCardApp theApp;


// ��������ڵ���ͨ����Ӿ��Σ�������
bool CAnswerCardApp::GetArchorPointRect(QPoint pt,int ap_idx,bool is_draw)
{
	//������Ч�Լ��
	if (ap_idx<0||ap_idx>3)
	{
		return false;
	}
	//��ͨ����
	vector<vector<cv::Point> > contours;
	vector<Vec4i>hierarchy;

	CvRect roirect;
	int roisize=img_bw.rows*0.05;
	roirect.width=roirect.height=2*roisize;
	roirect.x=min(max(0,pt.x()-roisize),img_bw.cols-roirect.width);
	roirect.y=min(max(0,pt.y()-roisize),img_bw.rows-roirect.height);
	Mat roi;
	img_bw(roirect).copyTo(roi);

	findContours(roi,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );

	bool isFound =false;
	if( !contours.empty())
	{
		for( unsigned int i = 0; i< contours.size(); i++ )
		{
			//���ڶ�����ڲ�
			if (pointPolygonTest(contours.at(i),cv::Point(pt.x()-roirect.x,pt.y()-roirect.y),false)<0)
				continue;
			anchorPoints[ap_idx] = boundingRect(contours.at(i));
			anchorPoints[ap_idx].x += roirect.x;
			anchorPoints[ap_idx].y += roirect.y;
			isFound = true;
		}
	}

	//�Ƿ���Ҫ����
	if (is_draw)
	{
		//�ж�������ͼ���Ƿ�ͬ��
		if (is_synchronous)
		{
			switch(ap_idx)
			{
			case 0:
				cv::putText(img_show,"1",cv::Point2d(anchorPoints[ap_idx].x,anchorPoints[ap_idx].y+anchorPoints[ap_idx].height*0.9),FONT_HERSHEY_COMPLEX,.6,anchor_point_color,2);
				break;
			case 1:
				cv::putText(img_show,"2",cv::Point2d(anchorPoints[ap_idx].x,anchorPoints[ap_idx].y+anchorPoints[ap_idx].height*0.9),FONT_HERSHEY_COMPLEX,.6,anchor_point_color,2);
				break;
			case 2:
				cv::putText(img_show,"3",cv::Point2d(anchorPoints[ap_idx].x,anchorPoints[ap_idx].y+anchorPoints[ap_idx].height*0.9),FONT_HERSHEY_COMPLEX,.6,anchor_point_color,2);
				break;
			case 3:
				cv::putText(img_show,"4",cv::Point2d(anchorPoints[ap_idx].x,anchorPoints[ap_idx].y+anchorPoints[ap_idx].height*0.9),FONT_HERSHEY_COMPLEX,.6,anchor_point_color,2);
				break;

			}
			rectangle(img_show,anchorPoints[ap_idx],anchor_point_color,anchor_point_thickness);
		}else
			is_synchronous = false;
	}
	//�Ƿ��ҵ���Ӧ����ͨ��
	if (isFound)
		return true;
	else
		return false;
	
}

//vector�Ƚ��㷨,��x��������
bool RectXCompare(cv::Rect& rt1,cv::Rect& rt2)
{
	return rt1.x <= rt2.x;
}

//vector�Ƚ��㷨,��y��������
bool RectYCompare(cv::Rect& rt1,cv::Rect& rt2)
{
	return rt1.y <= rt2.y;
}

// �����ǵ�����
vector<cv::Rect> CAnswerCardApp::GetMarkersNum(Mat srcroi)
 {
	 Mat roi;
	 srcroi.copyTo(roi);
	 Mat se = getStructuringElement(MORPH_ELLIPSE,Size(5,5));
	 morphologyEx(roi,roi,cv::MORPH_CLOSE,se);
	vector<cv::Rect> mks;
	vector<vector<cv::Point> > contours;
//  	imshow("test",roi);
//  	cvWaitKey(0);
	findContours(roi,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );
	if (contours.size()!=0)
	{
		vector<int> markArea;
		for( int i = contours.size()-1; i>=0 ; i-- )
		{
			int area =(int) contourArea(contours.at(i));
			markArea.push_back(area);
		}
		sort(markArea.begin(),markArea.end());
		min_markers_area=markArea.at(markArea.size()/2)/2;

		vector<int> width;
		vector<int> height;

		for( int i = contours.size()-1; i>=0 ; i-- )
		{
			int area =(int) contourArea(contours.at(i));
			if (area<min_markers_area)
			{
				continue;
			}
			mks.push_back(boundingRect(contours.at(i)));
			width.push_back(boundingRect(contours.at(i)).width);
			height.push_back(boundingRect(contours.at(i)).height);
		}

		int midWidth = width.at(width.size()/2);
		int midHeight = height.at(height.size()/2);
		int anchorWidth = theApp.anchorPoints[0].width;
		int anchorHight = theApp.anchorPoints[0].height;
		//���������С
		int tolerance = 10;

		for(vector<cv::Rect>::iterator it  = mks.begin(); it != mks.end(); )  
		{  
			if (MIN(abs(it->width - midWidth) , abs(it->width-anchorWidth)) > tolerance)
			{
				it = mks.erase(it);
			}
			else if (MIN(abs(it->height - midHeight),abs(it->height-anchorHight)) > tolerance)
			{
				it = mks.erase(it);
			}
			else
				it++;			
		} 

	}
	return mks;
}


// ���»���
int CAnswerCardApp::Redraw(void)
{
	Mat tmp;
	img_raw.copyTo(tmp);

	//���Ʊ�ǵ�����
	if (markersRect[0].width>0)
	{
		rectangle(tmp,markersRect[0],markers_point_color,markers_point_thickness);
		
		for (int i = 0; i < hmarkers.size(); ++i)
		{
			rectangle(tmp,hmarkers.at(i),markers_point_color,2);
		}
	}
	if (markersRect[1].width>0)
	{
		rectangle(tmp,markersRect[1],markers_point_color,markers_point_thickness);
			
		for (int i = 0; i < vmarkers.size(); ++i)
		{
			rectangle(tmp,vmarkers.at(i),markers_point_color,2);
		}
	}

	//���ƶ�λ��
	for (int i=0;i<4;i++)
	{
		//�ж��Ƿ��Ѿ���ֵ
		if (anchorPoints[i].width>0)
		{
			rectangle(tmp,anchorPoints[i],anchor_point_color,anchor_point_thickness);
		}
	}

	//���ư׼����
	if (whiteLineRect.width > 0)
	{
		rectangle(tmp,whiteLineRect,whiteLine_color,whiteLine_thickness);
	}

	if (blackLineRect.width > 0)
	{
		rectangle(tmp,blackLineRect, blackLine_color,blackLine_thickness);
	}

	//����������
	for (unsigned int i = 0; i < barGroup.size(); i++)
	{
		rectangle(tmp, barGroup[i].pos, barcode_color, barcode_thickness);
	}

	//����Ԥ������Ϳ��
	for (unsigned int i = 0;i<cfp_group.size();i++)
	{
		for (unsigned int j = 0;j<cfp_group[i].fillingPoints.size();j++)
		{
			cv::Point lt,rb;
			if (cfp_group[i].fillingPoints[j].isCrosswise)
			{
				lt.y = markerBT.GetTBoundary(cfp_group[i].fillingPoints[j].markerIdx[0]);
				rb.y = markerBT.GetBBoundary(cfp_group[i].fillingPoints[j].markerIdx[0]);
				lt.x = markerBT.GetLBoundary(cfp_group[i].fillingPoints[j].markerIdx[1]);
				rb.x = markerBT.GetRBoundary(cfp_group[i].fillingPoints[j].markerIdx[2]);
			}
			else{
				lt.y = markerBT.GetTBoundary(cfp_group[i].fillingPoints[j].markerIdx[1]);
				rb.y = markerBT.GetBBoundary(cfp_group[i].fillingPoints[j].markerIdx[2]);
				lt.x = markerBT.GetLBoundary(cfp_group[i].fillingPoints[j].markerIdx[0]);
				rb.x = markerBT.GetRBoundary(cfp_group[i].fillingPoints[j].markerIdx[0]);
			}
			rectangle(tmp,lt,rb,cfp_color,cfp_thickness);
		}
	}

	for (int i = 0; i < referPoint.size(); ++i)
	{
		rectangle(tmp,referPoint.at(i),cfp_color,cfp_thickness);
	}

	//������ģ��
	if (questionInfo.size()>0)
	{
		for (unsigned int i=0;i<questionInfo.size();i++)
		{
			cv::Point lt,rb;
			if (questionInfo[i].isCrosswise)
			{
				lt.y = markerBT.GetTBoundary(questionInfo[i].markerIdx[0]);
				rb.y = markerBT.GetBBoundary(questionInfo[i].markerIdx[0]);
				lt.x = markerBT.GetLBoundary(questionInfo[i].markerIdx[1]);
				rb.x = markerBT.GetRBoundary(questionInfo[i].markerIdx[2]);
			}
			else{
				lt.y = markerBT.GetTBoundary(questionInfo[i].markerIdx[1]);
				rb.y = markerBT.GetBBoundary(questionInfo[i].markerIdx[2]);
				lt.x = markerBT.GetLBoundary(questionInfo[i].markerIdx[0]);
				rb.x = markerBT.GetRBoundary(questionInfo[i].markerIdx[0]);
			}

			if (questionInfo[i].isSingleChoice)
			{
				rectangle(tmp,lt,rb,answer_color,answer_single_thickness);
			}
			else
			{
				rectangle(tmp,lt,rb,answer_multi_color,answer_multi_thickness);
			}	
		}
	}

	//���Ʋ�������
	for (unsigned int i = 0; i < cropAreas.size(); i++)
	{
		rectangle(tmp,cropAreas[i].pos,cropArea_color,cropArea_thickness);		
	}

	//����id��
	for (unsigned int i=0;i<idGroup.size();i++)
	{
		cv::Point lt,rb;
		if (idGroup[i].isCrosswise)
		{
			lt.y = markerBT.GetTBoundary(idGroup[i].markerIdx[0]);
			rb.y = markerBT.GetBBoundary(idGroup[i].markerIdx[0]);
			lt.x = markerBT.GetLBoundary(idGroup[i].markerIdx[1]);
			rb.x = markerBT.GetRBoundary(idGroup[i].markerIdx[2]);
		}
		else{
			lt.y = markerBT.GetTBoundary(idGroup[i].markerIdx[1]);
			rb.y = markerBT.GetBBoundary(idGroup[i].markerIdx[2]);
			lt.x = markerBT.GetLBoundary(idGroup[i].markerIdx[0]);
			rb.x = markerBT.GetRBoundary(idGroup[i].markerIdx[0]);
		}

		rectangle(tmp,lt,rb,idPoint_color,idPoint_thickness);		
	}

	tmp.copyTo(img_show);
	is_synchronous = true;
	return 0;
}


//�Ա�ǵ�����
void CAnswerCardApp::SortMarkers(bool is_hmarkers)
{
	if (is_hmarkers)
	{
		sort(hmarkers.begin(),hmarkers.end(),RectXCompare);
	}
	else
	{
		//��������
		sort(vmarkers.begin(),vmarkers.end(),RectYCompare);

	}
}

// ���ļ��ж�ȡͼ��
int CAnswerCardApp::LoadImg(const QString &path)
{
	//��ȡͼ��
	img_raw = imread(path.toAscii().data());
	//�ж�ͼ���ȡ�Ƿ���ȷ
	if (img_raw.data == NULL)
	{
		return -1;
	}
	////ʹͼ�񳤿�Ϊ4��������
	//if (img_raw.rows%4!=0||img_raw.cols%4!=0)
	//{
	//	cv::Rect roi(0,0,img_raw.cols-img_raw.cols%4,img_raw.rows-img_raw.rows%4);
	//	img_raw = img_raw(roi);
	//}
	is_synchronous = false;
	//ͼ���ȡ�ɹ����޸�״̬
	m_state++;
	return 0;
}


// ת��������ṹ��
int CAnswerCardApp::TransToOutputStruct()
{
	acinfo.questionType = this->questionType;
	acinfo.imgSize = cv::Size(img_raw.cols,img_raw.rows);

	////////////////////////////////////��Ŀ��Ϣ////////////////////////////////////////
	for (int i=questionInfo.size()-1;i>=0;i--)
	{
		ItemPos item;
		
		item.id = questionInfo.at(i).id;
		item.isCrosswise = questionInfo.at(i).isCrosswise;
		item.isSingleChoice = questionInfo.at(i).isSingleChoice;
		item.interval = questionInfo.at(i).interval;

		for (int j=0;j<3;j++)
		{
			item.markerIdx[j] = questionInfo.at(i).markerIdx[j];
		}
		acinfo.questioninfo.push_back(item);
	}

	//////////////////////////////////////ID����Ϣ///////////////////////////////////////
	acinfo.idPoint = idGroup;

	/////////////////////////////////////��λ����Ϣ///////////////////////////////////////
	
	acinfo.anchorPointInfo.anchorType = anchor_type;

	if (anchor_type == 0)
	{
		acinfo.isAnchorPointExist = false;
	}
	else
	{
		acinfo.isAnchorPointExist = true;
	}

	switch (anchor_type)
	{
	case 15:
		//1234
		acinfo.anchorPointInfo.num = 4;
		for (int i = 0; i < 4; i++)
		{
			acinfo.anchorPointInfo.anchorPt.push_back(anchorPoints[i]);
		}
		break;
	case 7:
		//123ȱ4
		acinfo.anchorPointInfo.num = 3;
		for (int i = 0; i < 3; i++)
		{
			acinfo.anchorPointInfo.anchorPt.push_back(anchorPoints[i]);
		}
		break;
	case 11:
		//124ȱ3
		acinfo.anchorPointInfo.num = 3;
		for (int i = 0; i< 4; i++)
		{
			if (i == 2)
				continue;
			acinfo.anchorPointInfo.anchorPt.push_back(anchorPoints[i]);
		}
		break;
	case 13:
		//134ȱ2
		acinfo.anchorPointInfo.num = 3;
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			acinfo.anchorPointInfo.anchorPt.push_back(anchorPoints[i]);
		}
		break;
	case 14:
		//234ȱ1
		acinfo.anchorPointInfo.num = 3;
		for (int i = 1; i < 4; i++)
		{
			acinfo.anchorPointInfo.anchorPt.push_back(anchorPoints[i]);
		}
		break;
	}

	int refer_x, refer_y;

	if (acinfo.anchorPointInfo.anchorPt.size() > 0)
	{
		refer_x = acinfo.anchorPointInfo.anchorPt.at(0).x;
		refer_y = acinfo.anchorPointInfo.anchorPt.at(0).y;
	}
	else
	{
		refer_x = 0;
		refer_y = 0;
	}

	//////////////////////////////////��ǵ���Ϣ//////////////////////////////////////////
	
	if (hmarkers.size() != 0 || vmarkers.size() != 0)
	{
		acinfo.markerInfo.xNum = hmarkers.size();
		acinfo.markerInfo.yNum = vmarkers.size();

		//�������ǵ�λ����Ϣ
		for (int i = 0; i < hmarkers.size(); ++i)
		{
			PerMarker_info tmp;
			tmp.id = i;
			tmp.pos = hmarkers.at(i);
			acinfo.xMarker.push_back(tmp);
		}

		for (int i = 0; i < vmarkers.size(); ++i)
		{
			PerMarker_info tmp;
			tmp.id = i;
			tmp.pos = vmarkers.at(i);
			acinfo.yMarker.push_back(tmp);
		}

		//ȡ����ǵ��ƽ��ֵ��Ϊ��ǵ��С
		long width_sum =0;
		long height_sum = 0; 
		for (int i=0;i<acinfo.markerInfo.xNum;i++)
		{
			width_sum+=hmarkers.at(i).width;
			height_sum+=hmarkers.at(i).height;
		}
		acinfo.markerInfo.xSize = cv::Size(width_sum/acinfo.markerInfo.xNum,height_sum/acinfo.markerInfo.xNum);
		width_sum =0;
		height_sum = 0; 
		for (int i=0;i<acinfo.markerInfo.yNum;i++)
		{
			width_sum+=vmarkers.at(i).width;
			height_sum+=vmarkers.at(i).height;
		}
		acinfo.markerInfo.ySize = cv::Size(width_sum/acinfo.markerInfo.yNum,height_sum/acinfo.markerInfo.yNum);

		//���������ϽǶ�λ������Ͻ���Ϊԭ�������
		acinfo.markerInfo.xMarker.x = hmarkers.at(0).x-refer_x-(acinfo.markerInfo.xSize.height>>1);
		acinfo.markerInfo.xMarker.y = hmarkers.at(0).y-refer_y-(acinfo.markerInfo.xSize.height>>1);
		acinfo.markerInfo.xMarker.width = hmarkers.at(acinfo.markerInfo.xNum-1).x-hmarkers.at(0).x+acinfo.markerInfo.xSize.width+acinfo.markerInfo.xSize.height;
		acinfo.markerInfo.xMarker.height = acinfo.markerInfo.xSize.height+acinfo.markerInfo.xSize.height;

		acinfo.markerInfo.yMarker.x = vmarkers.at(0).x-refer_x-(acinfo.markerInfo.ySize.height>>1);
		acinfo.markerInfo.yMarker.y = vmarkers.at(0).y-refer_y-(acinfo.markerInfo.ySize.height>>1);
		acinfo.markerInfo.yMarker.height = vmarkers.at(acinfo.markerInfo.yNum-1).y-vmarkers.at(0).y+acinfo.markerInfo.ySize.height+acinfo.markerInfo.ySize.height;
		acinfo.markerInfo.yMarker.width = acinfo.markerInfo.ySize.width+acinfo.markerInfo.ySize.height;
	}

	//////////////////////////////////��������Ϣ////////////////////////////////////////
	acinfo.barGroup = barGroup;
	for (int i = acinfo.barGroup.size() - 1; i >= 0; i--)
	{
		acinfo.barGroup[i].pos.x -= refer_x;
		acinfo.barGroup[i].pos.y -= refer_y;
	}

	//////////////////////////////////�Զ�����Ϳ��////////////////////////////////////////
	acinfo.fillingPointGroup = cfp_group;

	/////////////////////////////////ʶ��ο���////////////////////////////////////
	acinfo.refPoint = referPoint;

	///////////////////////////////////��������///////////////////////////////////////
	acinfo.cropAreaInfo = cropAreas;
	for (int i = cropAreas.size()-1; i >= 0; i--)
	{
		acinfo.cropAreaInfo[i].pos.x -= refer_x;
		acinfo.cropAreaInfo[i].pos.y -= refer_y;
	}
	//////////////////////////////////////�����////////////////////////////////////////
	acinfo.whiteLine = cv::Rect(whiteLineRect);
	acinfo.blackLine = cv::Rect(blackLineRect);
	acinfo.whiteLine.x -= refer_x;
	acinfo.whiteLine.y -= refer_y;
	acinfo.blackLine.x -= refer_x;
	acinfo.blackLine.y -= refer_y;

	/////////////////////////////////������Ϣ////////////////////////////////////////////
	vector<FillPoint> fpTmp = CountFillPointsBackground();
	vector<FillPoint>::iterator iter = fpTmp.begin();
	for (;iter != fpTmp.end(); ++iter)
	{
		if (iter->type != ReferPoint)
		{
			PerFillingPtBackground_info info;
			info = GetPerFillingPtBackground_info(img_raw(iter->rect), iter->num, 
				iter->interval, iter->isCrossWise, (FillingPointsType)(iter->type));
			acinfo.fillingPointBackgroundInfo.push_back(info);
		}
	}

	vector<Questions> questionTmp = CountQuestionsBackground();
	vector<Questions>::iterator iter2 = questionTmp.begin();
	for (;iter2 != questionTmp.end(); ++iter2)
	{
		PerQuestionBackground_info info;
		info = GetPerQuestionBackground_info(img_raw(iter2->rect), iter2->num, 
			iter2->isCrossWise);
		acinfo.questionBackgroundInfo.push_back(info);
	}
	return 0;
}

//���ID��
void CAnswerCardApp::AddIdPoint(int id, ushort markerIdx0, ushort markerIdx1, ushort markerIdx2)
{
	ItemPos item;
	item.id = id;
	item.isCrosswise = true;
	item.mark_id = 0;
	item.interval = 0;
	item.isSingleChoice = true;
	item.markerIdx[0] = markerIdx0;
	item.markerIdx[1] = markerIdx1;
	item.markerIdx[2] = markerIdx2;
	idGroup.push_back(item);
}

// �¼�һ����
void CAnswerCardApp::AddQuestion(int id, bool isCrosswise, bool isSingleChoice, ushort interval, ushort markerIdx0, ushort markerIdx1, ushort markerIdx2)
{
	ItemPos item;
	item.id = id;
	item.isCrosswise = isCrosswise;
	item.mark_id = 0;
	item.interval = interval;
	item.isSingleChoice = isSingleChoice;
	item.markerIdx[0] = markerIdx0;
	item.markerIdx[1] = markerIdx1;
	item.markerIdx[2] = markerIdx2;
	questionInfo.push_back(item);
}

//��һ���Զ�����Ϳ��
void CAnswerCardApp::AddFillPoint(string name, FillingPointsType type, bool isCrosswise, 
		int cspace, int rspace, int idx_l, int idx_r, int idx_t, int idx_b)
{
	FillingPoints_info info;
	info.name = name;
	info.type = type;

	if (isCrosswise)
	{
		int space = cspace;
		int rowId = idx_t;
		int id = 1;

		for (int i = idx_t; rowId <= idx_b; i++, id++)
		{
			ItemPos item;
			item.id = id;
			item.isCrosswise = isCrosswise;
			item.interval = rspace;
			item.isSingleChoice = true;
			item.markerIdx[0] = rowId;
			item.markerIdx[1] = idx_l;
			item.markerIdx[2] = idx_r;
			info.fillingPoints.push_back(item);

			rowId += space + 1;
		}

		cfp_group.push_back(info);
	}
	else
	{
		int space = rspace;
		int columnId = idx_l;
		int id = 1;

		for (int i = idx_l; columnId <= idx_r; i++, id++)
		{
			ItemPos item;
			item.id = id;
			item.isCrosswise = isCrosswise;
			item.interval = cspace;
			item.isSingleChoice = true;
			item.markerIdx[0] = columnId;
			item.markerIdx[1] = idx_t;
			item.markerIdx[2] = idx_b;
			info.fillingPoints.push_back(item);

			columnId += space + 1;
		}

		cfp_group.push_back(info);
	}
}

//���acinfo��Ϣ
void CAnswerCardApp::clearACInfo()
{
	theApp.acinfo.markerInfo.xMarker = cv::Rect();
	theApp.acinfo.markerInfo.yMarker = cv::Rect();
	theApp.acinfo.markerInfo.xSize = cv::Size();
	theApp.acinfo.markerInfo.ySize = cv::Size();
	theApp.acinfo.markerInfo.xNum = 0;
	theApp.acinfo.markerInfo.yNum = 0;
	theApp.acinfo.barGroup.clear();
	theApp.acinfo.cropAreaInfo.clear();
	theApp.acinfo.fillingPointGroup.clear();
	theApp.acinfo.anchorPointInfo.anchorPt.clear();
	theApp.acinfo.anchorPointInfo.num = 0;
	theApp.acinfo.anchorPointInfo.anchorType = 0;
	theApp.acinfo.questioninfo.clear();
	theApp.acinfo.fillingPointBackgroundInfo.clear();
	theApp.acinfo.questionBackgroundInfo.clear();
	theApp.acinfo.blackLine = cv::Rect();
	theApp.acinfo.whiteLine = cv::Rect();
	theApp.acinfo.idPoint.clear();
	theApp.acinfo.refPoint.clear();
	theApp.acinfo.xMarker.clear();
	theApp.acinfo.yMarker.clear();
	theApp.questionType=0;
}

//��ȡҪ���㱳������Ϳ���б�
vector<FillPoint> CAnswerCardApp::CountFillPointsBackground()
{
	
	vector<FillPoint> fillPoints;
	vector<FillingPoints_info>::iterator iter;

	//����
	for (iter = cfp_group.begin(); iter != cfp_group.end(); ++iter)
	{
		short type = ushort(iter->type);
		bool crossWise = iter->fillingPoints.at(0).isCrosswise;
		short num = iter->fillingPoints.at(0).markerIdx[2] 
			- iter->fillingPoints.at(0).markerIdx[1] + 1;
		bool find = false;
		int interval = iter->fillingPoints.at(0).interval;
		
		vector<FillPoint>::iterator iter2;
		for (iter2 = fillPoints.begin(); iter2 != fillPoints.end(); ++iter2)
		{
			//�ж��Ƿ��ظ�
			if (iter2->num == num && iter2->isCrossWise == crossWise 
				&& iter2->type == type)
			{
				find = true;
				break;
			}
		}

		//��Ϳ�㲻�ظ������vector��
		if (find == false)
		{
			FillPoint f;
			f.isCrossWise = crossWise;
			f.num = num;
			f.type = type;
			f.interval = interval;

			//��markerIdxתΪrect��Ϣ
			cv::Point lt,rb;
			if (crossWise)
			{
				lt.y = markerBT.GetTBoundary(iter->fillingPoints.at(0).markerIdx[0]);
				rb.y = markerBT.GetBBoundary(iter->fillingPoints.at(0).markerIdx[0]);
				lt.x = markerBT.GetLBoundary(iter->fillingPoints.at(0).markerIdx[1]);
				rb.x = markerBT.GetRBoundary(iter->fillingPoints.at(0).markerIdx[2]);
			}
			else{
				lt.y = markerBT.GetTBoundary(iter->fillingPoints.at(0).markerIdx[1]);
				rb.y = markerBT.GetBBoundary(iter->fillingPoints.at(0).markerIdx[2]);
				lt.x = markerBT.GetLBoundary(iter->fillingPoints.at(0).markerIdx[0]);
				rb.x = markerBT.GetRBoundary(iter->fillingPoints.at(0).markerIdx[0]);
			}

			f.rect = cv::Rect(lt, rb);
			fillPoints.push_back(f);
		}
	}

	return fillPoints;
}

//��ȡҪ���㱳���Ĵ𰸵��б�
vector<Questions> CAnswerCardApp::CountQuestionsBackground()
{
	vector<Questions> questions;
	vector<ItemPos>::iterator iter;

	for (iter = questionInfo.begin(); iter != questionInfo.end(); ++iter)
	{
		bool crossWise = iter->isCrosswise;
		short num = iter->markerIdx[2] - iter->markerIdx[1] + 1;
		bool find = false;

		vector<Questions>::iterator iter2;
		for (iter2 = questions.begin(); iter2 != questions.end(); ++iter2)
		{
			if (iter2->num == num && iter2->isCrossWise == crossWise)
			{
				find = true;
				break;
			}
		}

		if (find == false)
		{
			Questions q;
			q.isCrossWise = crossWise;
			q.num = num;

			cv::Point lt,rb;
			if (crossWise)
			{
				lt.y = markerBT.GetTBoundary(iter->markerIdx[0]);
				rb.y = markerBT.GetBBoundary(iter->markerIdx[0]);
				lt.x = markerBT.GetLBoundary(iter->markerIdx[1]);
				rb.x = markerBT.GetRBoundary(iter->markerIdx[2]);
			}
			else{
				lt.y = markerBT.GetTBoundary(iter->markerIdx[1]);
				rb.y = markerBT.GetBBoundary(iter->markerIdx[2]);
				lt.x = markerBT.GetLBoundary(iter->markerIdx[0]);
				rb.x = markerBT.GetRBoundary(iter->markerIdx[0]);
			}

			q.rect = cv::Rect(lt, rb);
			questions.push_back(q);
			
		}
	}

	return questions;
}

double GetEmptyRate(Mat gray)
{
	Mat mask230;
	Mat tmp;
	if(gray.type() == CV_8UC3)
	{
		cvtColor(gray,tmp,CV_RGB2GRAY);
	}

	threshold(tmp,mask230,230,255,THRESH_BINARY_INV);
	Scalar mean,stddev;
	meanStdDev(tmp,mean,stddev,mask230);	//���㷽��

	return stddev.val[0]*stddev.val[0]/cv::countNonZero(mask230);
}

PerFillingPtBackground_info  GetPerFillingPtBackground_info(Mat img2,int num,int interval,bool isCrosswise,FillingPointsType type){
    PerFillingPtBackground_info  pfpt_info;

    int optionNum=(num+interval)/(interval+1);
    Mat questionGraySum(2,optionNum,CV_32S);
	Mat img;
	img2.copyTo(img);
    //ѡ�����
    Rect optionRect;
    double step;
    //�������
    if(isCrosswise)
    {
        step = img.cols/num;
        optionRect = Rect(0,0,(int)step,img.rows);
        Mat optionImg;
        int j=0;
        for (int i=0;i<num;i=i+interval+1)
        {

            optionRect.x=min((int)step*i,img.cols-optionRect.width);
            //ȡ��ÿ��ѡ�����򲢷���
            optionImg = 255-img(optionRect);
            //�����ѡ��ҶȺ�
            questionGraySum.at<int>(0, j) = (int)cv::sum(optionImg).val[0];

			double val = GetEmptyRate(img2(optionRect));
			questionGraySum.at<int>(1, j) = (int)(val * 128  + 0.5);

            j++;
        }
    }
    //�������
    else
    {
        step = img.rows/num;
        optionRect = Rect(0,0,img.cols,(int)step);
        Mat optionImg;
        int j=0;
        for (int i=0;i<num;i=i+interval+1)
        {
            optionRect.y=min((int)step*i,img.rows-optionRect.height);
            //ȡ��ÿ��ѡ�����򲢷���
            optionImg = 255-img(optionRect);
            //�����ѡ��ҶȺ�
            questionGraySum.at<int>(0, j) = (int)cv::sum(optionImg).val[0];

			double val = GetEmptyRate(img2(optionRect));
			questionGraySum.at<int>(1, j) = (int)(val * 128  + 0.5);
            j++;
        }
    }
	pfpt_info.type = type;
    pfpt_info.bkInfo= questionGraySum;
    return pfpt_info;
}

PerQuestionBackground_info  GetPerQuestionBackground_info(Mat img2,int num,bool isCrosswise){
	PerQuestionBackground_info  pq_info;
    Scalar s;
    Mat srcimg;
    img2.copyTo(srcimg);
	srcimg = 255-srcimg;
	Mat grayvalue(2,num,CV_32S,s);
	short type=num;  
	Rect itemrt;
	itemrt.x=0;
	itemrt.y=0;
	if (!isCrosswise)
	{
		itemrt.width=img2.size().width;
		itemrt.height=int(img2.size().height/num);
		for (int i=0;i<num;i++)
		{

			Mat item=srcimg(itemrt);
			double val = GetEmptyRate(img2(itemrt));
			s=sum(item);
			grayvalue.at<int>(0,i)= (int)s.val[0];
			grayvalue.at<int>(1,i)= (int)(val * 128  + 0.5);
			itemrt.y=itemrt.y+itemrt.height;
		}
		pq_info.bkInfo=grayvalue;
		pq_info.type=num;
		return pq_info;
	}
	else {
		itemrt.height=img2.size().height;
		itemrt.width=int(img2.size().width/num);
		for (int i=0;i<num;i++)
		{
			Mat item=srcimg(itemrt);
			double val = GetEmptyRate(img2(itemrt));
			s=sum(item);
			grayvalue.at<int>(0,i)= (int)s.val[0];
			grayvalue.at<int>(1,i)= (int)(val * 128 + 0.5);
			itemrt.x=itemrt.x+itemrt.width;
		}
		pq_info.bkInfo=grayvalue;
		pq_info.type=num;
		return pq_info;
	}
}
