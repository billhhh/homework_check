#include "Controller.h"
#include "Tools.h"
#include "xlsIO.h"

using namespace std;

void Controller::startCheck(QString excelPath,string homeworkPath,vector<string> stuNames)//stuNames���±���Ϣ�;Ϳ���ȷ��excelд��ط�
{
	//��ʼ�����Щѧ��������ҵ

	Tools tools;
	tools.getDirFilesPath(homeworkPath,fileNames);

	//����fileNames
	for (int i=0;i<fileNames.size();i++)
	{
		//cout<<files.at(i)<<"\n";
		chineseFileNames.push_back( tools.getChinese(fileNames.at(i)) );
	}

	//test compareName()
	//compareName("afdsdfs_hello_sdfas#@!","hello");

	XlsIO xlsio;
	//��chineseFileNames�е�ÿһ��ȥ��ѧ����ÿһ����ǲ������Ӵ���ϵ
	for (int i=0;i<chineseFileNames.size();i++)
	{
		for (int j=0;j<stuNames.size();j++)
		{
			//cout<<chineseFileNames.at(i)<<" "<<stuNames.at(j)<<"\n";
			if (compareName( chineseFileNames.at(i),stuNames.at(j)) )
			{
				//�������Ӵ���ϵ
				cout<<"������"<<j<<"\n";
				cout<<"���Ӵ���"<<i+1<<"��"<<stuNames.at(j)<<"\n";
				//дexcel
				xlsio.xlsWriter(excelPath,j);

				break;
			}
		}
	}

	return;
}

bool Controller::compareName(string name1,string name2)
{
	string::size_type findResult = name1.find(name2);

	if (findResult != string::npos) //�ҵ�
		return true;
	else
		return false;
}