/*
 *
 * funtion:��excel�ļ�����IO����
 *
 *    Author: Bill Wang
 */

#ifndef _XLSIO_H_
#define _XLSIO_H_

#include <iostream>
#include <vector>
#include <string>
#include <QtGui/QApplication>


class XlsIO
{
public:
	bool xlsReader(QString excelPath,std::vector<std::string> &stuNames); //��ȡ����ѧ�����֣�����vector
	bool xlsWriter(QString excelPath,int row);

private:
};

#endif