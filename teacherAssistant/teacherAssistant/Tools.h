/*
 * 
 * funtion: �����࣬�ṩ�硾�õ��ַ����������Ӵ����ȹ��ߺ���
 *
 *    Author: Bill Wang
 */

#ifndef _TOOLS_H_
#define _TOOLS_H_

#include<iostream>
#include<string>
#include <string>
#include <io.h>
#include <vector>

class Tools
{
public:
	std::string getChinese(std::string inputStr);  //��������Ӵ���������
	bool getDirFilesPath( std::string folderPath, std::vector<std::string>& files); //���ĳ�ļ����µ������ļ����������ļ�����

protected:
private:
};

#endif
