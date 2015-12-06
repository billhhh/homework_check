#include "stdafx.h"
#include "TraversingFile.h"
#include <iterator>
#include <algorithm>
TraversingFile::TraversingFile(void)
{
	FindData;
	hError;
	FileCount = 0;
}


TraversingFile::~TraversingFile(void)
{
}
//���������ַ�
bool IsNumOrChar(char ch)
{
	if ((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		return true;
	}else
		return false;
}

// ��ʼ��������Ҫ������Ŀ¼
int TraversingFile::Init(string path,string suffix)
{
	//��׺���Ϸ����ж�
	string::iterator first;
	first = find_if_not(suffix.begin(),suffix.end(),IsNumOrChar);
	if (first != suffix.end())
	{
		//��׺���к��зǷ��ַ�
		return -1;
	}
	//�����ļ���
	strcpy_s(FilePathName, path.c_str());
	if (path[path.length()-1] != '\\'&&path[path.length()-1] != '/')
	{
		strcat_s(FilePathName, "\\*.");
	}else
	{
		strcat_s(FilePathName, "*.");
		path = path.substr(0,path.length()-1);
	}
	strcat_s(FilePathName, suffix.c_str());
	this->path = path;
	this->suffix = suffix;
	return 0;
}


// ���Ҫ����·���µ�һ���ļ���
int TraversingFile::GetFileName(string& filename)
{
	//δ��ʼ����
	if (suffix.length() == 0)
	{
		return -1;
	}
	//��һ���ļ�?
	if (FileCount == 0)
	{
		hError = FindFirstFile(FilePathName, &FindData);
		if (hError == INVALID_HANDLE_VALUE)
		{
			return -2;
		}
	}else{
		if (::FindNextFile(hError, &FindData))
		{
			// ����.��..
			if (strcmp(FindData.cFileName, ".") == 0 || strcmp(FindData.cFileName, "..") == 0 )
			{
				return GetFileName(filename);
			}
		}else
		{
			//�������
			return 1;
		}
	}
	// ��������·��
//	wsprintf(FullPathName, "%s\\%s", path.c_str(),FindData.cFileName);
	string pahta(path.c_str());
	string pathb(FindData.cFileName);
	filename = pahta+"\\"+pathb;
	FileCount++;
	return 0;
}
// �ļ�����������
int TraversingFile::GetFileCounter(void)
{
	return FileCount;
}