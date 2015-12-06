#include "StdAfx.h"
#include "DataTypeConversion.h"


DataTypeConversion::DataTypeConversion(void)
{
}


DataTypeConversion::~DataTypeConversion(void)
{
	
}

stringstream DataTypeConversion::sStream;

// �޷��Ŷ����ε��ַ���ת��
string DataTypeConversion::Ushort2String(ushort ushortValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<ushortValue;
	return DataTypeConversion::sStream.str();
}
// �����ε��ַ���ת��
string DataTypeConversion::Short2String(short shortValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<shortValue;
	return DataTypeConversion::sStream.str();
}
// ���ε��ַ���ת��
string DataTypeConversion::Int2String(int intValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<intValue;
	return DataTypeConversion::sStream.str();
}
// �������ε��ַ���ת��
string DataTypeConversion::Float2String(float floatValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<floatValue;
	return DataTypeConversion::sStream.str();
}
// ˫���ȸ������ε��ַ���ת��
string DataTypeConversion::Double2String(double doubleValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<doubleValue;
	return DataTypeConversion::sStream.str();
}

// opencv���ε��ַ���
string DataTypeConversion::Rect2String(cv::Rect rect)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<rect.x<<' '<<rect.y<<' '<<rect.width<<' '<<rect.height;
	return DataTypeConversion::sStream.str();
}


// opencv�ߴ絽�ַ���ת��
string DataTypeConversion::Size2String(cv::Size size)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<size.width<<' '<<size.height;
	return DataTypeConversion::sStream.str();
	return string();
}


// ����ֵ���ַ���ת��
string DataTypeConversion::Bool2String(bool boolVaule)
{
	if (boolVaule)
	{
		return "true";
	}else{
		return "false";
	}
}
//opencv CV_32S�����ַ���ת��
string DataTypeConversion::Mat32s2String(cv::Mat mat){
	if (mat.type()!=CV_32S)
	{
		return "error";
	}
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<mat.cols<<' '<<mat.rows<<' ';

	for (int i = 0;i<mat.rows;i++)
	{
		for (int j=0;j<mat.cols;j++)
		{
			DataTypeConversion::sStream<<mat.at<int>(i,j)<<' ';
		}
		//DataTypeConversion::sStream<<endl;
	}
	return DataTypeConversion::sStream.str();
	return string();
}
//�ַ���������ֵ
bool DataTypeConversion::String2Bool(string stringValue)
{
	if (stringValue.compare("true")==0)
	{
		return true;
	}else
		return false;
}
//�ַ������޷��Ŷ�����
ushort DataTypeConversion::String2Ushort(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	ushort tmp;
	DataTypeConversion::sStream>>tmp;
	return tmp;
}
//�ַ�����������
short DataTypeConversion::String2Short(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	short tmp;
	DataTypeConversion::sStream>>tmp;
	return tmp;
}
//�ַ���������
int DataTypeConversion::String2Int(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	int tmp;
	DataTypeConversion::sStream>>tmp;
	return tmp;
}
//�ַ�����������
float DataTypeConversion::String2Float(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	float tmp;
	DataTypeConversion::sStream>>tmp;
	return tmp;
}
//�ַ�����˫���ȸ�����
double DataTypeConversion::String2Double(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	double tmp;
	DataTypeConversion::sStream>>tmp;
	return tmp;
}

//�ַ�����opencv����
cv::Rect DataTypeConversion::String2Rect(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	cv::Rect tmp;
	DataTypeConversion::sStream>>tmp.x>>tmp.y>>tmp.width>>tmp.height;
	return tmp;
}
//�ַ�����opencv�ߴ�
cv::Size DataTypeConversion::String2Size(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	cv::Size tmp;
	DataTypeConversion::sStream>>tmp.width>>tmp.height;
	return tmp;
}
//�ַ�����opencv CV_32S����
cv::Mat DataTypeConversion::String2Mat32s(string stringValue)
{
	DataTypeConversion::sStream.clear();
	DataTypeConversion::sStream.str("");
	DataTypeConversion::sStream<<stringValue;
	cv::Size size;
	DataTypeConversion::sStream>>size.width>>size.height;
	cv::Mat mat(size,CV_32S);
	int length = size.width*size.height;
	for (int i=0;i<length;i++)
	{
		DataTypeConversion::sStream>>mat.at<int>(i);
	}
	return mat;
}