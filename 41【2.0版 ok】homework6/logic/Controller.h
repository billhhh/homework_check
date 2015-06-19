/**
 * �������࣬�ռ�students��Ϣ������xmlReader�����ݸ��㷨���
 * 
 * @author Bill Wang
 * 
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "StudentObj.h"
#include "Tools.h"
#include "studentMap.h"
#include "StringCompare.h"
#include "../mainwindow.h"

using namespace std;

class Controller
{
public:
	StudentObj checkStudent;  //������ѧ��
	vector <StudentObj> otherStudents;  //���˴���������ѧ��
	vector <StudentObj> allStudents;  //����ѧ��info

	bool startCheck(Ui::MainWindow *ui,string homeworkPath,string batch,string batchPath,
		vector <studentMap> stuMap);//�����ֱ�ӽӴ���������ҵ���κʹ����ѧ��ѧ��
	
private:
	string homeworkPath;
	string batchPath;
	string studentPath;
	string batch;  //��ҵ����
	vector <studentMap> stuMap;
	bool runPreprocess(string batchPath);
	void fillStudents();  //��Ӧmap����ѧ����Ϣ��������
	void sendToCompare(Ui::MainWindow *ui); //��ȥ�㷨���
};

#endif