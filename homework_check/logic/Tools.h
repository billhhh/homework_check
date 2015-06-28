/**
 * ������
 * 
 * @author Bill Wang
 * 
 */
#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <io.h>
#include "StudentObj.h"
#include "XmlReader.h"

class Tools
{
public:
	bool getStudents(string batch,StudentObj &checkStu,vector <StudentObj> &otherStu);//����path�ʹ����ѧ�������ش����ѧ����Ϣ������ѧ����Ϣ
	string findXmlPath(string batch);  //�ϳ�XML�ľ���·��������xmlReader�����student����
	bool getDirFilesPath(string path, vector<string>& files ,vector <string> &stuId);   //���ĳ�ļ����µ������ļ��ľ���·�������ļ���������ѧ��ѧ��
	bool getAllStudentsNum(string batch,vector <StudentObj> &allStudents); //��2.0�汾�������������ѧ��num info

private:
	
};

#endif