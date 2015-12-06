#include "CustomizeFillPointDlg.h"
#include "ui_CustomizeFillPointDlg.h"
#include "AnswerCard.h"

CustomizeFillPointDlg::CustomizeFillPointDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::CustomizeFillPointDlg();
	ui->setupUi(this);	
}

CustomizeFillPointDlg::~CustomizeFillPointDlg()
{
	delete ui;
}

void CustomizeFillPointDlg::initialization()
{
	ui->confirmBtn->setEnabled(false);
	ui->addBtn->setText(tr("�����Ϳ��"));
	ui->list->clear();
	this->setEnabled(false);
}

void CustomizeFillPointDlg::setAddBtnText(const QString& str)
{
	ui->addBtn->setText(str);
}

void CustomizeFillPointDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void CustomizeFillPointDlg::on_addBtn_clicked()
{
	//�Ƿ��Ѵ�ͼ��
	if (theApp.m_group_state == 0 && theApp.m_state == 0)
	{
		QMessageBox::critical(NULL, tr("����"),tr("���ȴ�ͼ��"));
		return;
	}

	//�����δȷ��״̬����ʱ�����������¿�ѡ
	if (theApp.m_group_state == 5 && theApp.m_state == 3)
	{
		//�����ػ�
		theApp.is_synchronous = false;
		ui->addBtn->setText(tr("ȡ��"));
		ui->confirmBtn->setEnabled(false);
		emit imageUpdated();
	}
	else if (theApp.m_group_state == 5 && theApp.m_state == 1)
	{
		theApp.m_state = 0;
		ui->confirmBtn->setEnabled(false);
		ui->addBtn->setText(tr("�����Ϳ��"));
		return;
	}
	else
	{
		ui->addBtn->setText(tr("ȡ��"));
	}

	//״̬����
	theApp.m_group_state = 5;
	theApp.m_state = 1;
}

void CustomizeFillPointDlg::on_confirmBtn_clicked()
{
	//�Ƿ��Ѵ�ͼ��
	if (theApp.m_group_state == 0 && theApp.m_state == 0)
	{
		QMessageBox::critical(NULL, tr("����"),tr("���ȴ�ͼ��"));
		return;
	}

	if (theApp.m_group_state != 5 || theApp.m_state != 3)
	{
		QMessageBox::information(NULL, tr(" "),tr("���ȿ�ѡ����"));
		return;
	}

	QString type = ui->typeComboBox->currentText();
	string tmpName(type.toAscii().data());

	//�ж��Ƿ����
	int foundIdx = -1;

	for (ushort i = 0; i < theApp.cfp_group.size(); i++)
	{
		if (theApp.cfp_group[i].name == tmpName)
		{
			foundIdx = i;
		}
	}

	if (foundIdx != -1)
	{
		//�Ѵ��ڸ�����->�ϲ���
		if (QMessageBox::No == QMessageBox::information(NULL, 
			tr("�ϲ����飿"), 
			tr("�������Ѿ����ڣ��Ƿ���������"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes))
		{
			return;
		}
		else
		{
			theApp.cfp_group[foundIdx].fillingPoints.push_back(theApp.cfp_tmpRect);

			//����listbox
			QString itemStr;
			itemStr = QString("%1| %2������|")
				.arg(type).arg(theApp.cfp_group[foundIdx].fillingPoints.size());

			ui->list->takeItem(foundIdx);
			ui->list->insertItem(foundIdx, itemStr);
		}
	
	}//if (foundIdx != -1)
	else
	{
		//δ���ڣ�������->�½���
		CustomFillingPoints_info cfp;
		cfp.name = tmpName;
		cfp.fillingPoints.push_back(theApp.cfp_tmpRect);
		theApp.cfp_group.push_back(cfp);

		//����listbox
		QString itemStr;
		itemStr = QString("%1| %2������|")
			.arg(type).arg(cfp.fillingPoints.size());

		ui->list->addItem(itemStr);
	}//else if(foundIdx == -1)

	//״̬����
	theApp.m_group_state = 5;
	theApp.m_state = 5;

	//�������
	ui->addBtn->setText(tr("�����Ϳ��"));
	ui->confirmBtn->setEnabled(false);
}

void CustomizeFillPointDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->list->currentRow();

	if (idx > -1)
	{
		ui->list->takeItem(idx);
		theApp.cfp_group.erase(theApp.cfp_group.begin()+idx);

		//�����ػ�
		theApp.is_synchronous = false;
		emit imageUpdated();
	}
}