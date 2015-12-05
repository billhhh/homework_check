#include "AnchorDlg.h"
#include "AnswerCard.h"
#include "ui_AnchorDlg.h"

AnchorDlg::AnchorDlg(QWidget *parent)
	: QDialog(parent),done(false)
{
	ui = new Ui::AnchorDlg();
	ui->setupUi(this);
}

AnchorDlg::~AnchorDlg()
{
	delete ui;
}

void AnchorDlg::initialization()
{
	done = false;
	this->setEnabled(false);
}

void AnchorDlg::on_anchorLTBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.anchorPoints[0].width>0)
	{
		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡ���ϽǶ�λ�㣬��������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.is_synchronous =false;
			theApp.anchorPoints[0] = cv::Rect();
			done = false;
		}
	}

	theApp.m_group_state = AnchorState;
	theApp.m_state = LTBegin;
}

void AnchorDlg::on_anchorRTBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.anchorPoints[1].width>0)
	{
		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡ���ϽǶ�λ�㣬��������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.is_synchronous =false;
			theApp.anchorPoints[1] = cv::Rect();
			done = false;
		}
	}

	theApp.m_group_state = AnchorState;
	theApp.m_state = RTBegin;
}

void AnchorDlg::on_anchorLBBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.anchorPoints[2].width>0)
	{
		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡ���ϽǶ�λ�㣬��������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.is_synchronous =false;
			theApp.anchorPoints[2] = cv::Rect();
			done = false;
		}
	}

	theApp.m_group_state = AnchorState;
	theApp.m_state = LBBegin;
}

void AnchorDlg::on_anchorRBBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.anchorPoints[3].width>0)
	{
		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡ���ϽǶ�λ�㣬��������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.is_synchronous =false;
			theApp.anchorPoints[3] = cv::Rect();
			done = false;
		}
	}

	theApp.m_group_state = AnchorState;
	theApp.m_state = RBBegin;
}

void AnchorDlg::on_confirmBtn_clicked()
{
	Mat tmp;
	double angle;
	int count = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (theApp.anchorPoints[i].width > 0)
		{
			++count;
		}
	}

	if (count < 3)
	{
		QMessageBox::information(this, " ",
			tr("��бУ��ʧ��\n��ȷ���ѱ궨�����������Ķ�λ��"));

		return;
	}

	theApp.anchor_type = TiltCorrection(theApp.img_raw, tmp, theApp.anchorPoints, angle);

	if (theApp.anchor_type < 0)
	{
		theApp.anchor_type = 0;
		QMessageBox::information(NULL, " ",
			tr("��бУ��ʧ��\n��ȷ���ѱ궨�����������Ķ�λ��"));

		return;
	}

	theApp.img_raw = tmp;

	//���¼���Ҷ�ͼ�񼰶�ֵͼ��
	cvtColor(theApp.img_raw, theApp.img_gray, CV_RGB2GRAY);
	threshold(theApp.img_gray, theApp.img_bw, 128, 255, THRESH_BINARY_INV);

	for (int i=0; i < 4; i++)
	{
		if (theApp.anchorPoints[i].width != 0)
		{
			theApp.GetArchorPointRect(
				QPoint(theApp.anchorPoints[i].x + theApp.anchorPoints[i].width / 2,
				theApp.anchorPoints[i].y + theApp.anchorPoints[i].height / 2), i);
		}
	}

	theApp.is_synchronous =false;
	theApp.m_state = RBEnd;
	done = true;
	emit anchorDone();
}

int AnchorDlg::resume()
{
	if (theApp.anchor_type <= 0)
	{
		theApp.anchor_type = 0;
		return -1;
	}

	return 1;
}