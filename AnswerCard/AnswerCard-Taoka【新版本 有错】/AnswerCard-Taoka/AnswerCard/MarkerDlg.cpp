#include "MarkerDlg.h"
#include "ui_MarkerDlg.h"
#include "AnswerCard.h"

MarkerDlg::MarkerDlg(QWidget *parent)
	: QDialog(parent),
	m_hmarkers_num(0),
	m_vmarkers_num(0),
	m_done(false)
{
	ui = new Ui::MarkerDlg();
	ui->setupUi(this);
}

MarkerDlg::~MarkerDlg()
{
	delete ui;
}

void MarkerDlg::initialization()
{
	m_hmarkers_num = 0;
	m_vmarkers_num = 0;

	ui->horMarkersEdit->setText("0");
	ui->verMarkersEdit->setText("0");
	ui->horMarkersEdit->setEnabled(false);
	ui->verMarkersEdit->setEnabled(false);
	m_done = false;
	this->setEnabled(false);
}

void MarkerDlg::on_horMarkersBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.markersRect[0].width > 0)
	{
		if (theApp.questionInfo.size() > 0 || theApp.cfp_group.size() > 0 || theApp.idGroup.size() > 0)
		{
			QMessageBox::information(this," ","�ñ�ǵ��ѱ�ʹ�ã��޷��޸�!");
			return;
		}

		if (QMessageBox::No == QMessageBox::information(this, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡˮƽ��ǵ����򣬼�������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			theApp.is_synchronous = false;
			return;
		}
		else
		{
			theApp.is_synchronous = false;
			setHorEditNum(0);
			theApp.markersRect[0] = cv::Rect();
			m_done = false;
		}
	}
	theApp.m_group_state = MarkerState;
	theApp.m_state = RowBegin;
}

void MarkerDlg::on_verMarkersBtn_clicked()
{
	//�Ѿ��������ѯ�ʸ���
	if (theApp.markersRect[1].width > 0)
	{
		if (theApp.questionInfo.size() > 0 || theApp.cfp_group.size() > 0 || theApp.idGroup.size() > 0)
		{
			QMessageBox::information(this," ","�ñ�ǵ��ѱ�ʹ�ã��޷��޸�!");
			return;
		}

		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("����ѡ��"), 
			tr("�Ѿ���ѡ��ֱ��ǵ����򣬼�������������ԭ��ѡ��\nȷ��Ҫ������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.is_synchronous = false;
			setVerEditNum(0);
			theApp.markersRect[1] = cv::Rect();
			m_done = false;
		}
	}
	theApp.m_group_state = MarkerState;
	theApp.m_state = ColBegin;
}

void MarkerDlg::on_confirmBtn_clicked()
{
	if (m_hmarkers_num <=0 || m_vmarkers_num <= 0)
	{
		QMessageBox::information(NULL, tr(" "),
			tr("��ȷ���ѿ�ѡ��ˮƽ��ǵ���ʹ�ֱ��ǵ��飡"));
		return;
	}

	QString w_str;
	w_str = QString(tr("ˮƽ��ǵ���%1������ֱ�����ǵ���%2��\nȷ�ϣ�")
		.arg(m_hmarkers_num).arg(m_vmarkers_num));

	if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("ȷ�ϱ�ǵ�������"), 
			w_str,
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
	{
		return;
	}

	setHorEditEnabled(false);
	setVerEditEnabled(false);

	theApp.markerBT.InitMarkersBoundaryTable(theApp.hmarkers,theApp.vmarkers);

	m_done = true;
	emit markerDone();
}

void MarkerDlg::setHorEditEnabled(bool isEnable)
{
	ui->horMarkersEdit->setEnabled(isEnable);
}

void MarkerDlg::setVerEditEnabled(bool isEnable)
{
	ui->verMarkersEdit->setEnabled(isEnable);
}
	
void MarkerDlg::setHorEditNum(short num)
{
	m_hmarkers_num = num;
	ui->horMarkersEdit->setText(QString("%1").arg(m_hmarkers_num));

}
void MarkerDlg::setVerEditNum(short num)
{
	m_vmarkers_num = num;
	ui->verMarkersEdit->setText(QString("%1").arg(m_vmarkers_num));
}

int MarkerDlg::resume(bool isDone)
{
	initialization();
	if (theApp.markersRect[0].width > 0)
	{
		vector<cv::Rect> hmarkers = theApp.GetMarkersNum(theApp.img_bw(theApp.markersRect[0]));
		m_hmarkers_num = hmarkers.size();
		if (m_hmarkers_num > 0)
		{
			setHorEditNum(m_hmarkers_num);
			for (int i = hmarkers.size()-1; i>=0; i--)
			{
				hmarkers.at(i).x += theApp.markersRect[0].x;
				hmarkers.at(i).y += theApp.markersRect[0].y;
			}
			theApp.hmarkers = hmarkers;
			theApp.SortMarkers(true);

			ui->horMarkersEdit->setText(tr("%1").arg(m_hmarkers_num));
		}
	}

	if (theApp.markersRect[1].width > 0)
	{
		vector<cv::Rect> vmarkers = theApp.GetMarkersNum(theApp.img_bw(theApp.markersRect[1]));
		m_vmarkers_num = vmarkers.size();
		if (m_vmarkers_num > 0)
		{
			setVerEditNum(m_vmarkers_num);
			for (int i = vmarkers.size()-1; i>=0; i--)
			{
				vmarkers.at(i).x += theApp.markersRect[1].x;
				vmarkers.at(i).y += theApp.markersRect[1].y;
			}
			theApp.vmarkers = vmarkers;
			theApp.SortMarkers(true);

			ui->verMarkersEdit->setText(tr("%1").arg(m_vmarkers_num));
		}
	}

	if (theApp.markersRect[1].width > 0 && theApp.markersRect[0].width > 0 && isDone == true)
	{
		theApp.markerBT.InitMarkersBoundaryTable(theApp.hmarkers,theApp.vmarkers);
		m_done = true;
		return 1;
	}

	if (theApp.markersRect[1].width > 0)
	{
		ui->verMarkersEdit->setEnabled(true);
	}

	if (theApp.markersRect[0].width > 0)
	{
		ui->horMarkersEdit->setEnabled(true);
	}

	return -1;
}