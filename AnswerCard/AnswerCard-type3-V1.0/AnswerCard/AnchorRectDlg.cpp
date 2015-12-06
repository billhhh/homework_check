#include "AnchorRectDlg.h"
#include "ui_AnchorRectDlg.h"
#include "AnswerCard.h"

AnchorRectDlg::AnchorRectDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::AnchorRectDlg();
	ui->setupUi(this);
}

AnchorRectDlg::~AnchorRectDlg()
{
	delete ui;
}

void AnchorRectDlg::initialization()
{
	m_done = false;
	this->setEnabled(false);
	ui->anchorBtn->setText(tr("��ѡ��λ��"));
}

void AnchorRectDlg::setAnchorBtnText(QString str)
{
	ui->anchorBtn->setText(str);
}

void AnchorRectDlg::on_anchorBtn_clicked()
{
	if (theApp.anchorRect.width > 0)
	{
		if (QMessageBox::No == QMessageBox::information(this, 
				tr(" "), 
				tr("��λ���Ѿ����ڣ��Ƿ񸲸�ԭ����ѡ��"),
				QMessageBox::Yes | QMessageBox::No,
				QMessageBox::Yes))
		{
			return;
		}

		theApp.anchorRect = cv::Rect();
		theApp.anchor_type = 0;
		m_done = false;

		//�����ػ�
		theApp.is_synchronous = false;
	}

	if (theApp.m_group_state == AnchorRectState && theApp.m_state == BaseBegin)
	{
		theApp.m_state = BaseInitial;
		ui->anchorBtn->setText(tr("��ѡ��λ��"));
		return;
	}

	ui->anchorBtn->setText(tr("ȡ��"));

	//״̬����
	theApp.m_group_state = AnchorRectState;
	theApp.m_state = BaseBegin;
}

void AnchorRectDlg::on_confirmBtn_clicked()
{
	if (theApp.anchorRect.width <= 0)
	{
		QMessageBox::information(this, " ",
			tr("���ѡ��λ��!"));
	}

	Mat tmp;
	double angle;
	Point point;
	cv::Rect rect = theApp.anchorRect;
	theApp.anchor_type = TiltCorrection(theApp.img_raw, tmp, rect, point, angle);

	theApp.anchorRect=rect;
	theApp.originalPoint = point;
	if (theApp.anchor_type < 0)
	{
		theApp.anchor_type = 0;
		QMessageBox::information(this, " ",
			tr("��бУ��ʧ��!"));

		return;
	}

	theApp.img_raw = tmp;

	//���¼���Ҷ�ͼ�񼰶�ֵͼ��
	cvtColor(theApp.img_raw, theApp.img_gray, CV_RGB2GRAY);
	threshold(theApp.img_gray, theApp.img_bw, 128, 255, THRESH_BINARY_INV);

	//for (int i=0; i < 4; i++)
	//{
	//	if (theApp.anchorPoints[i].width != 0)
	//	{
	//		theApp.GetArchorPointRect(
	//			QPoint(theApp.anchorPoints[i].x + theApp.anchorPoints[i].width / 2,
	//			theApp.anchorPoints[i].y + theApp.anchorPoints[i].height / 2), i);
	//	}
	//}

	theApp.is_synchronous =false;
	theApp.m_state = BaseEnd;
	m_done = true;
	emit anchorDone();
}

int AnchorRectDlg::resume()
{
	if (theApp.anchorRect.width > 0)
	{
		ui->anchorBtn->setText(tr("���¿�ѡ��λ��"));
	}
	else
	{
		ui->anchorBtn->setText(tr("��ѡ��λ��"));
	}

	//if (theApp.anchor_type <= 0)
	//{
	//	theApp.anchor_type = 0;
	//	return -1;
	//}
	

	return 1;
}