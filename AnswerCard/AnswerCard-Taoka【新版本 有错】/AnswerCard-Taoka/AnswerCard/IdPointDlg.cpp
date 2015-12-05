#include "IdPointDlg.h"
#include "ui_IdPointDlg.h"

IdPointDlg::IdPointDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::IdPointDlg();
	ui->setupUi(this);

	connect(ui->idPointList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showClicked(QListWidgetItem*)));
}

IdPointDlg::~IdPointDlg()
{
	delete ui;
}

void IdPointDlg::initialization()
{
	setProcessing(false);
	ui->idPointList->clear();
	ui->confirmBtn->setEnabled(false);
	ui->addBtn->setText(tr("���ID��"));
	this->setEnabled(false);
}

void IdPointDlg::setProcessing(bool b)
{
	ui->idPointList->setEnabled(!b);
	ui->deleteBtn->setEnabled(!b);
}

void IdPointDlg::setAddBtnText(const QString& str)
{
	ui->addBtn->setText(str);
}

void IdPointDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void IdPointDlg::on_addBtn_clicked()
{
		//�����δȷ��״̬����ʱ�����������¿�ѡ
	if (theApp.m_group_state == IdPointState && theApp.m_state == BaseRelease)
	{
		theApp.idGroup.pop_back();

		//�����ػ�
		theApp.is_synchronous = false;
		ui->addBtn->setText(tr("ȡ��"));
		ui->confirmBtn->setEnabled(false);
	}
	else if (theApp.m_group_state == IdPointState && theApp.m_state == BaseBegin)
	{
		theApp.m_state = BaseInitial;
		ui->confirmBtn->setEnabled(false);
		setProcessing(false);
		ui->addBtn->setText(tr("���ID��"));
		emit idPointDone();
		return;
	}
	else
	{

		ui->addBtn->setText(tr("ȡ��"));
		setProcessing(true);
		emit idPointBegin();
	}

	//״̬����
	theApp.m_group_state = IdPointState;
	theApp.m_state = BaseBegin;
}

void IdPointDlg::on_confirmBtn_clicked()
{
	//״̬����
	theApp.m_group_state = IdPointState;
	theApp.m_state = BaseEnd;

	int idx = 1;

	if (theApp.idGroup.size() > 0)
	{
		idx = (theApp.idGroup.end() - 1)->id;
	}

	//����listbox
	QString itemStr;
	itemStr = QString("ID%1").arg(idx);
	ui->idPointList->addItem(itemStr);

	//�������
	ui->addBtn->setText(tr("���ID��"));
	ui->confirmBtn->setEnabled(false);
	setProcessing(false);

	emit idPointDone();
}

void IdPointDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->idPointList->currentRow();

	if (idx > -1)
	{
		ui->idPointList->takeItem(idx);
		theApp.idGroup.erase(theApp.idGroup.begin() + idx);

		//�����ػ�
		theApp.is_synchronous = false;
		emit idPointDelete();
	}
}

void IdPointDlg::showClicked(QListWidgetItem* item)
{
	int idx = ui->idPointList->currentRow();

	if (idx > -1)
	{
		theApp.is_synchronous = false;
		theApp.Redraw();

		vector<ItemPos>::iterator iter= theApp.idGroup.begin() + idx;

		cv::Point lt,rb;
		if (iter->isCrosswise)
		{
			lt.y = theApp.markerBT.GetTBoundary(iter->markerIdx[0]);
			rb.y = theApp.markerBT.GetBBoundary(iter->markerIdx[0]);
			lt.x = theApp.markerBT.GetLBoundary(iter->markerIdx[1]);
			rb.x = theApp.markerBT.GetRBoundary(iter->markerIdx[2]);
		}
		else{
			lt.y = theApp.markerBT.GetTBoundary(iter->markerIdx[1]);
			rb.y = theApp.markerBT.GetBBoundary(iter->markerIdx[2]);
			lt.x = theApp.markerBT.GetLBoundary(iter->markerIdx[0]);
			rb.x = theApp.markerBT.GetRBoundary(iter->markerIdx[0]);
		}
		rectangle(theApp.img_show,lt,rb,theApp.idPointClicked_color,theApp.idPointClicked_thickness);

		emit idPointClicked(idx);
	}
}

int IdPointDlg::resume()
{
	initialization();

	vector<ItemPos>::iterator iter;
	for (iter = theApp.idGroup.begin(); 
			iter != theApp.idGroup.end(); ++iter)
	{
		//����listbox
		QString itemStr;
		itemStr = QString("ID%1").arg(iter->id);
		ui->idPointList->addItem(itemStr);
	}

	return 1;
}