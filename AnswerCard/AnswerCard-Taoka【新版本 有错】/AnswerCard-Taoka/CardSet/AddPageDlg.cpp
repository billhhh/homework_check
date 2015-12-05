#include "AddPageDlg.h"
#include "ui_AddPageDlg.h"
#include "qmessagebox.h"
#include "qfiledialog.h"

AddPageDlg::AddPageDlg(QWidget *parent)
	: QDialog(parent), m_hasBackPage(false)
{
	ui = new Ui::AddPageDlg();
	ui->setupUi(this);
	this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

	connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
	
	QRegExp reg("[1-9][0-9] + $");
	QRegExpValidator *validator = new QRegExpValidator(reg);
	ui->numEdit->setValidator(validator);
}

AddPageDlg::~AddPageDlg()
{
	delete ui;
}

void AddPageDlg::on_okBtn_clicked()
{
	if (ui->numEdit->text() == "")
	{
		QMessageBox::information(this," ",tr("��Ų���Ϊ�գ�"));
		return;
	}

	if (ui->pathEdit->text() == "")
	{
		QMessageBox::information(this," ",tr("��������û��ӣ�"));
		return;
	}

	accept();
}

QString AddPageDlg::getPageNumber() const
{
	return ui->numEdit->text();
}

bool AddPageDlg::hasBackPage() const
{
	return m_hasBackPage;
}

//��ȡ����ͼƬ·��
QString AddPageDlg::getFrontPagePath() const
{
	return ui->pathEdit->text();
}

//��ȡ����ͼƬ·��
QString AddPageDlg::getBackPagePath() const
{
	return ui->backPathEdit->text();
}

void AddPageDlg::on_addFrontPageBtn_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
	this, tr("�����������"),
    ".",
    "Image files (*.bmp *.jpg *.tiff *.tif);;JPEG(*.jpg);;BMP(*.bmp);;TIFF(*.tiff *.tif)");

	if (fileName != "")
	{
		ui->pathEdit->setText(fileName);
		ui->addBackPageBtn->setEnabled(true);
		ui->backPathEdit->setEnabled(true);
	}
}

void AddPageDlg::on_addBackPageBtn_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
	this, tr("��ӷ�������"),
    ".",
    "Image files (*.bmp *.jpg *.tiff *.tif);;JPEG(*.jpg);;BMP(*.bmp);;TIFF(*.tiff *.tif)");

	if (fileName != "")
	{
		ui->backPathEdit->setText(fileName);
		m_hasBackPage = true;
	}
}