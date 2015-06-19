/**
 * ��ȡxml�Ĺ�����
 * 
 * @author Bill Wang
 * 
 */
#ifndef XMLREADER_H
#define XMLREADER_H

#include <iostream>
#include <vector>
#include<QDomDocument>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include "StudentObj.h"
#include "FileObj.h"

using namespace std;

class XmlReader
{
public:
	void test();
	bool XmlIO(string path,vector<FileObj> &fileList); //���سɹ����
	bool XmlIO(string stuName,string stuId,string path,StudentObj &stu); //���صķ��������Դ���ѧ��ID������
	bool XmlIO(string path,StudentObj &stu); //���صķ������ɴ�������ID��������ѧ����ֱ�ӻ��������ѧ������

private:
	bool getFileList(string path,vector<FileObj> &fileList);  //�õ�fileList�����㸳ֵ��stu
};

#endif