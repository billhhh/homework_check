#include "PagePointDlg.h"
#include "ui_PagePointDlg.h"

PagePointDlg::PagePointDlg(QWidget *parent)
	: QDialog(parent),index(1)
{
	ui = new Ui::PagePointDlg();
	ui->setupUi(this);

	connect(ui->idPointList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showClicked(QListWidgetItem*)));
}

PagePointDlg::~PagePointDlg()
{
	delete ui;
}

void PagePointDlg::initialization()
{
	setProcessing(false);
	ui->idPointList->clear();
	ui->confirmBtn->setEnabled(false);
	ui->addBtn->setText(tr("���ҳ���ʶ"));
	this->setEnabled(false);
}

void PagePointDlg::setProcessing(bool b)
{
	ui->idPointList->setEnabled(!b);
	ui->deleteBtn->setEnabled(!b);
}

void PagePointDlg::setAddBtnText(const QString& str)
{
	ui->addBtn->setText(str);
}

void PagePointDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void PagePointDlg::on_addBtn_clicked()
{
		//�����δȷ��״̬����ʱ�����������¿�ѡ
	if (theApp.m_group_state == PagePointState && theApp.m_state == BaseRelease)
	{
		theApp.pagePoint.pop_back();

		//�����ػ�
		theApp.is_synchronous = false;
		ui->addBtn->setText(tr("ȡ��"));
		ui->confirmBtn->setEnabled(false);
	}
	else if (theApp.m_group_state == PagePointState && theApp.m_state == BaseBegin)
	{
		theApp.m_state = BaseInitial;
		ui->confirmBtn->setEnabled(false);
		setProcessing(false);
		ui->addBtn->setText(tr("���ҳ���ʶ"));
		emit pagePointDone();
		return;
	}
	else
	{

		ui->addBtn->setText(tr("ȡ��"));
		setProcessing(true);
		emit pagePointBegin();
	}

	//״̬����
	theApp.m_group_state = PagePointState;
	theApp.m_state = BaseBegin;
}

void PagePointDlg::on_confirmBtn_clicked()
{
	//״̬����
	theApp.m_group_state = PagePointState;
	theApp.m_state = BaseEnd;


	//����listbox
	QString itemStr;
	itemStr = QString("ҳ���ʶ%1").arg(index++);
	ui->idPointList->addItem(itemStr);

	//�������
	ui->addBtn->setText(tr("���ҳ���ʶ"));
	ui->confirmBtn->setEnabled(false);
	setProcessing(false);

	emit pagePointDone();
}

void PagePointDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->idPointList->currentRow();

	if (idx > -1)
	{
		ui->idPointList->takeItem(idx);
		theApp.pagePoint.erase(theApp.pagePoint.begin() + idx);

		//�����ػ�
		theApp.is_synchronous = false;
		emit pagePointDelete();
	}
}

void PagePointDlg::showClicked(QListWidgetItem* item)
{
	int idx = ui->idPointList->currentRow();

	if (idx > -1)
	{
		theApp.is_synchronous = false;
		theApp.Redraw3();

		vector<cv::Rect>::iterator iter= theApp.pagePoint.begin() + idx;

		rectangle(theApp.img_show,*iter,theApp.pagePointClicked_color,theApp.pagePointClicked_thickness);

		emit pagePointClicked(idx);
	}
}

int PagePointDlg::resume()
{
	initialization();
	index=1;
	vector<cv::Rect>::iterator iter;
	for (iter = theApp.pagePoint.begin(); 
			iter != theApp.pagePoint.end(); ++iter)
	{
		//����listbox
		QString itemStr;
		itemStr = QString("ҳ���ʶ%1").arg(index++);
		ui->idPointList->addItem(itemStr);
	}

	return 1;
}