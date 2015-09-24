#include "teacherassistant.h"
#include <iostream>
#include <vector>
#include <string>
#include <QMessageBox>
#include "xlsIO.h"
#include "Controller.h"

using namespace std;

teacherAssistant::teacherAssistant(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

teacherAssistant::~teacherAssistant()
{

}


//����excel��Ϣ
void teacherAssistant::on_pushButton_clicked()
{
	excelPath = QFileDialog::getOpenFileName(this,tr("ѡ��򿪵��ļ�"),".",tr("Excel Files(*.xlsx *.xls)"));
	if(excelPath.size()==0)
		return;
	
	cout<<"excelPath == "<<excelPath.toStdString()<<"\n";

	XlsIO xlsio;
	xlsio.xlsReader(excelPath,stuNames);

// 	for (int i=0;i<stuNames.size();i++)
// 		cout<<stuNames.at(i)<<endl;

	cout<<"stuNames.size == "<<stuNames.size()<<"\n";
}


void teacherAssistant::on_pushButton_2_clicked()
{
	homeworkPath = QFileDialog::getExistingDirectory(this,tr("ѡ����ҵ���λ��"),".");
	if(homeworkPath.size()==0)
		return;
	QMessageBox::information(NULL, tr("Path"), tr("You selected ") + homeworkPath);
}


//���յġ�ȷ������ť����ʼ����
void teacherAssistant::on_submitBtn_clicked()
{
	if (excelPath.size()==0)
	{
		QMessageBox::information(NULL, tr("����"), tr("δָ��ѧ���������᡿"));
		return;
	}

	if(homeworkPath.size()==0)
	{
		QMessageBox::information(NULL, tr("����"), tr("δѡ����ҵ·����"));
		return;
	}

	Controller ctrl;
	ctrl.startCheck(excelPath,homeworkPath.toStdString(),stuNames);
}