#include "BlackLineDetectDlg.h"
#include "ui_BlackLineDetectDlg.h"
#include "AnswerCardDlg.h"

BlackLineDetectDlg::BlackLineDetectDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::BlackLineDetectDlg();
	ui->setupUi(this);
}

BlackLineDetectDlg::~BlackLineDetectDlg()
{
	delete ui;
}

void BlackLineDetectDlg::initialization()
{
	ui->confirmBtn->setEnabled(false);
	ui->addBtn->setText(tr("���"));
	ui->list->clear();
	ui->nameEdit->clear();
	this->setEnabled(false);
}

void BlackLineDetectDlg::setProcessing(bool b)
{
	ui->nameEdit->setEnabled(!b);
	ui->deleteBtn->setEnabled(!b);
}

void BlackLineDetectDlg::setAddBtnText(const QString& str)
{
	ui->addBtn->setText(str);
}

void BlackLineDetectDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void BlackLineDetectDlg::on_addBtn_clicked()
{
	//�����δȷ��״̬����ʱ�����������¿�ѡ
	if (theApp.m_group_state == BlackLineState && theApp.m_state == BaseRelease)
	{
		//�����ػ�
		theApp.is_synchronous = false;
		ui->addBtn->setText(tr("ȡ��"));
		ui->confirmBtn->setEnabled(false);
	}
	else if (theApp.m_group_state == BlackLineState && theApp.m_state == BaseBegin)
	{
		theApp.m_state = BaseInitial;
		ui->confirmBtn->setEnabled(false);
		ui->nameEdit->setEnabled(true);
		setProcessing(false);
		ui->addBtn->setText(tr("���"));
		emit BlackLineDone();
		return;
	}
	else
	{
		QString name = ui->nameEdit->text();

		//�ж��Ƿ����
		int foundIdx = -1;

		for (ushort i = 0; i < theApp.blackLineGroup.size(); i++)
		{
			if (theApp.blackLineGroup[i].name == name.toStdString())
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
		emit BlackLinebegin();
	}

	//״̬����
	theApp.m_group_state = BlackLineState;
	theApp.m_state = BaseBegin;
}

void BlackLineDetectDlg::on_confirmBtn_clicked()
{
	if (theApp.m_group_state != BlackLineState || theApp.m_state != BaseRelease)
	{
		QMessageBox::information(this, tr(" "),tr("���Ʋ���Ϊ��"));
		return;
	}

	QString name = ui->nameEdit->text();
	
	BlackLine_info info;
	info.name = name.toStdString();
	info.pos = cv::Rect(theApp.cfp_tmpRect);
	theApp.blackLineGroup.push_back(info);

	//����listbox
	QString itemStr;
	itemStr = QString("%1").arg(name);
	ui->list->addItem(itemStr);

	//״̬����
	theApp.m_group_state = BlackLineState;
	theApp.m_state = BaseEnd;

	//�������
	ui->addBtn->setText(tr("���"));
	ui->confirmBtn->setEnabled(false);
	ui->nameEdit->setEnabled(true);
	setProcessing(false);

	emit BlackLineDone();
}

void BlackLineDetectDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->list->currentRow();

	if (idx > -1)
	{
		ui->list->takeItem(idx);
		theApp.blackLineGroup.erase(theApp.blackLineGroup.begin() + idx);

		//�����ػ�
		theApp.is_synchronous = false;
		emit BlackLineDelete();
	}
}