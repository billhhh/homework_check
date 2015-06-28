#include <stdlib.h>
#include <QtGui/QApplication>
#include "mainwindow.h"

void xmlReaderTest()
{
	XmlReader xr;
	StudentObj stu;
	xr.XmlIO("D:\\xmltest\\pre_out\\1\\1134.xml",stu);

	system("pause");
}

/*
void controllerTest()
{
	//����Cotroller�еģ���ʼ���
	Controller ctrl;
	string homeworkPath = "d:\\input";
	string batchPath = "d:\\input\\2";
	string StudentPath = "d:\\input\\2\\201421031134";
	string batch="2";

	studentMap tmpStu;
	vector <studentMap> tmpMap;

	tmpStu.studentId = "201421031134";
	tmpStu.studentName = "����";
	tmpMap.push_back(tmpStu);

	tmpStu.studentId = "201421031066";
	tmpStu.studentName = "����";
	tmpMap.push_back(tmpStu);

	tmpStu.studentId = "201421031370";
	tmpStu.studentName = "���";
	tmpMap.push_back(tmpStu);

	tmpStu.studentId = "53";
	tmpStu.studentName = "���ﾢ";
	tmpMap.push_back(tmpStu);

	ctrl.startCheck(homeworkPath,batch,batchPath,StudentPath,"����","201421031134",tmpMap);

	system("pause");
}*/


void StringCompareTest()
{
	//���ñȽϺ��������в���ƥ��
	FileObj f1,f2;
	StudentObj tmpStu;
	testStringCompare(tmpStu,f1,f2);

	system("pause");
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QApplication::addLibraryPath("./plugins");
    
	//QTextCodec *codec = QTextCodec::codecForName("System");
    //QTextCodec::setCodecForTr(codec);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	
	QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));
	//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	MainWindow w;
    w.show();

    return a.exec();
 
 	//xmlReaderTest();

	//controllerTest();

	//StringCompareTest();

}