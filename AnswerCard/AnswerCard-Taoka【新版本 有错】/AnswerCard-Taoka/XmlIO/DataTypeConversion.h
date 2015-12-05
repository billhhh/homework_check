#pragma once
#include <sstream>
#include <cv.h>
using namespace cv;
using namespace std;
class DataTypeConversion
{
public:
	DataTypeConversion(void);
	~DataTypeConversion(void);
	//��Ա����
	stringstream sStream;
	// ����ֵ���ַ���ת��
	string Bool2String(bool boolVaule);
	// �޷��Ŷ����ε��ַ���ת��
	string Ushort2String(ushort ushortValue);
	// �����ε��ַ���ת��
	string Short2String(short shortValue);
	// ���ε��ַ���ת��
	string Int2String(int intValue);
	// �������ε��ַ���ת��
	string Float2String(float floatValue);
	// ˫���ȸ������ε��ַ���ת��s
	string Double2String(double doubleValue);

	// opencv���ε��ַ���
	string Rect2String(cv::Rect rect);
	// opencv�ߴ絽�ַ���ת��
	string Size2String(cv::Size size);
	//opencv CV_32S�����ַ���ת��
	string Mat32s2String(cv::Mat mat);

	//////////////////////////////////////////////////////////////////////////
	//�ַ���������ֵ
	bool String2Bool(string stringValue);
	//�ַ������޷��Ŷ�����
	ushort String2Ushort(string stringValue);
	//�ַ�����������
	short String2Short(string stringValue);
	//�ַ���������
	int String2Int(string stringValue);
	//�ַ�����������
	float String2Float(string stringValue);
	//�ַ�����˫���ȸ�����
	double String2Double(string stringValue);

	//�ַ�����opencv����
	cv::Rect String2Rect(string stringValue);
	//�ַ�����opencv�ߴ�
	cv::Size String2Size(string stringValue);
	//�ַ�����opencv CV_32S����
	cv::Mat String2Mat32s(string stringValue);

};

