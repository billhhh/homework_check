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
	static stringstream sStream;
	// ����ֵ���ַ���ת��
	static string Bool2String(bool boolVaule);
	// �޷��Ŷ����ε��ַ���ת��
	static string Ushort2String(ushort ushortValue);
	// �����ε��ַ���ת��
	static string Short2String(short shortValue);
	// ���ε��ַ���ת��
	static string Int2String(int intValue);
	// �������ε��ַ���ת��
	static string Float2String(float floatValue);
	// ˫���ȸ������ε��ַ���ת��s
	static string Double2String(double doubleValue);

	// opencv���ε��ַ���
	static string Rect2String(cv::Rect rect);
	// opencv�ߴ絽�ַ���ת��
	static string Size2String(cv::Size size);
	//opencv CV_32S�����ַ���ת��
	static string Mat32s2String(cv::Mat mat);

	//////////////////////////////////////////////////////////////////////////
	//�ַ���������ֵ
	static bool String2Bool(string stringValue);
	//�ַ������޷��Ŷ�����
	static ushort String2Ushort(string stringValue);
	//�ַ�����������
	static short String2Short(string stringValue);
	//�ַ���������
	static int String2Int(string stringValue);
	//�ַ�����������
	static float String2Float(string stringValue);
	//�ַ�����˫���ȸ�����
	static double String2Double(string stringValue);

	//�ַ�����opencv����
	static cv::Rect String2Rect(string stringValue);
	//�ַ�����opencv�ߴ�
	static cv::Size String2Size(string stringValue);
	//�ַ�����opencv CV_32S����
	static cv::Mat String2Mat32s(string stringValue);

};

