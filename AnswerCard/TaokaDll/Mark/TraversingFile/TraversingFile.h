#pragma once
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;
#define PATH_MAX_LENGTH 1024
class TraversingFile
{
protected:
	WIN32_FIND_DATA FindData;
	HANDLE hError;
	int FileCount;
	char FilePathName[PATH_MAX_LENGTH];
	// ����·��
	char FullPathName[PATH_MAX_LENGTH];
	//����·��
	string path;
	//��׺��
	string suffix;
public:
	TraversingFile(void);
	~TraversingFile(void);
	// ��ʼ��������Ҫ������Ŀ¼
	int Init(string path,string suffix);
	// ���Ҫ����·���µ�һ���ļ���
	int GetFileName(string& filename);
	// �ļ�����������
	int GetFileCounter(void);
};

