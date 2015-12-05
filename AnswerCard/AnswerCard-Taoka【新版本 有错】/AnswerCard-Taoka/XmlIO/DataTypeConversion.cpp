#include "DataTypeConversion.h"


DataTypeConversion::DataTypeConversion(void)
{
}


DataTypeConversion::~DataTypeConversion(void)
{
}

// �޷��Ŷ����ε��ַ���ת��
string DataTypeConversion::Ushort2String(ushort ushortValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<ushortValue;
	return sStream.str();
}
// �����ε��ַ���ת��
string DataTypeConversion::Short2String(short shortValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<shortValue;
	return sStream.str();
}
// ���ε��ַ���ת��
string DataTypeConversion::Int2String(int intValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<intValue;
	return sStream.str();
}
// �������ε��ַ���ת��
string DataTypeConversion::Float2String(float floatValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<floatValue;
	return sStream.str();
}
// ˫���ȸ������ε��ַ���ת��
string DataTypeConversion::Double2String(double doubleValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<doubleValue;
	return sStream.str();
}

// opencv���ε��ַ���
string DataTypeConversion::Rect2String(cv::Rect rect)
{
	sStream.clear();
	sStream.str("");
	sStream<<rect.x<<' '<<rect.y<<' '<<rect.width<<' '<<rect.height;
	return sStream.str();
}


// opencv�ߴ絽�ַ���ת��
string DataTypeConversion::Size2String(cv::Size size)
{
	sStream.clear();
	sStream.str("");
	sStream<<size.width<<' '<<size.height;
	return sStream.str();
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
	sStream.clear();
	sStream.str("");
	sStream<<mat.cols<<' '<<mat.rows<<' ';

	for (int i = 0;i<mat.rows;i++)
	{
		for (int j=0;j<mat.cols;j++)
		{
			sStream<<mat.at<int>(i,j)<<' ';
		}
		//sStream<<endl;
	}
	return sStream.str();
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
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	ushort tmp;
	sStream>>tmp;
	return tmp;
}
//�ַ�����������
short DataTypeConversion::String2Short(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	short tmp;
	sStream>>tmp;
	return tmp;
}
//�ַ���������
int DataTypeConversion::String2Int(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	int tmp;
	sStream>>tmp;
	return tmp;
}
//�ַ�����������
float DataTypeConversion::String2Float(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	float tmp;
	sStream>>tmp;
	return tmp;
}
//�ַ�����˫���ȸ�����
double DataTypeConversion::String2Double(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	double tmp;
	sStream>>tmp;
	return tmp;
}

//�ַ�����opencv����
cv::Rect DataTypeConversion::String2Rect(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	cv::Rect tmp;
	sStream>>tmp.x>>tmp.y>>tmp.width>>tmp.height;
	return tmp;
}
//�ַ�����opencv�ߴ�
cv::Size DataTypeConversion::String2Size(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	cv::Size tmp;
	sStream>>tmp.width>>tmp.height;
	return tmp;
}
//�ַ�����opencv CV_32S����
cv::Mat DataTypeConversion::String2Mat32s(string stringValue)
{
	sStream.clear();
	sStream.str("");
	sStream<<stringValue;
	cv::Size size;
	sStream>>size.width>>size.height;
	cv::Mat mat(size,CV_32S);
	int length = size.width*size.height;
	for (int i=0;i<length;i++)
	{
		sStream>>mat.at<int>(i);
	}
	return mat;
}