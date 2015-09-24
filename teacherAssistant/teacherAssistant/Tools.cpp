#include "Tools.h"

using namespace std;

//��������Ӵ�
string Tools::getChinese(string inputStr)
{
	string result;
	for (int i=0;i<inputStr.size();i++)
	{
		if ( (int)(inputStr.at(i))<0 )
		{
			result.append(&inputStr.at(i),2);
			i++;
		}
	}
	return result;
}



//���ĳ�ļ����µ������ļ����������ļ�����
bool Tools::getDirFilesPath( string folderPath, vector<string>& files)
{
	//�ļ����
	long hFile   =   0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(folderPath).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//�����Ŀ¼,����
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
				{
					//ȥ����Ŀ¼�͵�ǰĿ¼
					files.push_back( fileinfo.name );
				}
			}
			else
			{
				files.push_back( fileinfo.name );
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}else{
		return false;
	}

	return true;
}