#include "xlsIO.h"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QVariant>
#include <QFileDialog>
#include <QMainWindow>
#include <QTextCodec>
#include <QMessageBox>
#include <qDebug>
#include <vector>
#include "ui_teacherassistant.h"

using namespace std;

bool XlsIO::xlsReader(QString excelPath,vector<string> &stuNames)
{
	QAxObject excel("Excel.Application");
	excel.setProperty("Visible", false);
	QAxObject *work_books = excel.querySubObject("WorkBooks");
	work_books->dynamicCall("Open (const QString&)", excelPath);
	QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //SheetsҲ�ɻ���WorkSheets
	int sheet_count = work_sheets->property("Count").toInt();  //��ȡ��������Ŀ

	if(sheet_count > 0)
	{
		QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
		QAxObject *used_range = work_sheet->querySubObject("UsedRange");
		QAxObject *rows = used_range->querySubObject("Rows");
		//QAxObject *columns = used_range->querySubObject("Columns");
		int row_start = used_range->property("Row").toInt();  //��ȡ��ʼ��:1
		//int column_start = used_range->property("Column").toInt();  //��ȡ��ʼ��
		int row_count = rows->property("Count").toInt();  //��ȡ����
		//int column_count = columns->property("Count").toInt();  //��ȡ����

		QString StudentName;
		for(int i=row_start+4; i<=row_count;i++)
		{
			QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", i, 3);
			StudentName = cell->dynamicCall("Value2()").toString();//��ȡ��Ԫ������

			stuNames.push_back(StudentName.toStdString());
		}
	}

	work_books->dynamicCall("Close()");//�رչ�����
	excel.dynamicCall("Quit()");//�ر�excel

	return true;
}


bool XlsIO::xlsWriter(QString excelPath,int row)
{
	QAxObject excel("Excel.Application");
	excel.setProperty("Visible", false);
	QAxObject *work_books = excel.querySubObject("WorkBooks");
	work_books->dynamicCall("Open (const QString&)", excelPath);
	QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //SheetsҲ�ɻ���WorkSheets
	int sheet_count = work_sheets->property("Count").toInt();  //��ȡ��������Ŀ

	if(sheet_count > 0)
	{
		QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
		QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", row+5, 9);

		cell->setProperty("Value","V");
	}

	work_book->dynamicCall("Save()");  //�����ļ�
	work_books->dynamicCall("Close()");//�رչ�����
	excel.dynamicCall("Quit(void)");//�ر�excel

	return true;
}