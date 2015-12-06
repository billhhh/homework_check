#include "WhiteDetectLineDlg.h"
#include "ui_WhiteDetectLineDlg.h"
#include "AnswerCardDlg.h"

WhiteDetectLineDlg::WhiteDetectLineDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::WhiteDetectLineDlg();
	ui->setupUi(this);
}

WhiteDetectLineDlg::~WhiteDetectLineDlg()
{
	delete ui;
}

void WhiteDetectLineDlg::initialization()
{
	ui->confirmBtn->setEnabled(false);
	ui->addBtn->setText(tr("���"));
	ui->list->clear();
	ui->nameEdit->clear();
	this->setEnabled(false);
}

void WhiteDetectLineDlg::setProcessing(bool b)
{
	ui->nameEdit->setEnabled(!b);
	ui->deleteBtn->setEnabled(!b);
}

void WhiteDetectLineDlg::setAddBtnText(const QString& str)
{
	ui->addBtn->setText(str);
}

void WhiteDetectLineDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void WhiteDetectLineDlg::on_addBtn_clicked()
{
	//�����δȷ��״̬����ʱ�����������¿�ѡ
	if (theApp.m_group_state == WhiteLineState && theApp.m_state == BaseRelease)
	{
		//�����ػ�
		theApp.is_synchronous = false;
		ui->addBtn->setText(tr("ȡ��"));
		ui->confirmBtn->setEnabled(false);
	}
	else if (theApp.m_group_state == WhiteLineState && theApp.m_state == BaseBegin)
	{
		theApp.m_state = BaseInitial;
		ui->confirmBtn->setEnabled(false);
		ui->nameEdit->setEnabled(true);
		setProcessing(false);
		ui->addBtn->setText(tr("���"));
		emit whiteLineDone();
		return;
	}
	else
	{
		QString name = ui->nameEdit->text();

		//�ж��Ƿ����
		int foundIdx = -1;

		for (ushort i = 0; i < theApp.whiteLineGroup.size(); i++)
		{
			if (theApp.whiteLineGroup[i].name == name.toStdString())
			{
				foundIdx = i;
			}
		}

		if (foundIdx != -1)
		{
			//�Ѵ��ڸ�����
			QMessageBox::information(this, 
				tr("����"), 
				tr("�������Ѵ��ڣ�"));
			return;
		}

		ui->addBtn->setText(tr("ȡ��"));
		ui->nameEdit->setEnabled(false);
		setProcessing(true);
		emit whiteLinebegin();
	}

	//״̬����
	theApp.m_group_state = WhiteLineState;
	theApp.m_state = BaseBegin;
}

void WhiteDetectLineDlg::on_confirmBtn_clicked()
{
	if (theApp.m_group_state != WhiteLineState || theApp.m_state != BaseRelease)
	{
		QMessageBox::information(this, tr(" "),tr("���Ʋ���Ϊ��"));
		return;
	}

	QString name = ui->nameEdit->text();
	
	WhiteLine_info info;
	info.name = name.toStdString();
	info.pos = cv::Rect(theApp.cfp_tmpRect);
	theApp.whiteLineGroup.push_back(info);

	//����listbox
	QString itemStr;
	itemStr = QString("%1").arg(name);
	ui->list->addItem(itemStr);

	//״̬����
	theApp.m_group_state = WhiteLineState;
	theApp.m_state = BaseEnd;

	//�������
	ui->addBtn->setText(tr("���"));
	ui->confirmBtn->setEnabled(false);
	ui->nameEdit->setEnabled(true);
	setProcessing(false);

	emit whiteLineDone();
}

void WhiteDetectLineDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->list->currentRow();

	if (idx > -1)
	{
		ui->list->takeItem(idx);
		theApp.whiteLineGroup.erase(theApp.whiteLineGroup.begin() + idx);

		//�����ػ�
		theApp.is_synchronous = false;
		emit whiteLineDelete();
	}
}