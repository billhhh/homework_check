/**
 * ������ʵ��
 * 
 * @author Bill Wang
 * 
 */
#include "Tools.h"

//����Path�ʹ����ѧ�������ش����ѧ����Ϣ������ѧ����Ϣ
bool Tools::getStudents(string batch,StudentObj &checkStu,vector <StudentObj> &otherStu)
{
	string xmlPath = findXmlPath(batch);
	vector<string> filesPath;
	vector<string> stuId;
	getDirFilesPath(xmlPath,filesPath,stuId); //���XML����·��

	//��������filesPath��stuId�±��Ӧ
	int filesSize=filesPath.size();

	for (int i=0;i<filesSize;i++)
	{
		StudentObj tmpStu;
		tmpStu.studentId = stuId.at(i);

		//��ȥxmlReader
		XmlReader xr;
		xr.XmlIO(filesPath.at(i),tmpStu);
		
		if (tmpStu.studentId.compare(checkStu.studentId) == 0)
		{
			//����Ǵ�����ͬѧ
			checkStu.fileList=tmpStu.fileList;
		}else{
			otherStu.push_back(tmpStu);
		}
	}

	return true;
}

bool Tools::getAllStudentsNum(string batch,vector<StudentObj> &allStudents)
{
	string xmlPath = findXmlPath(batch);
	vector<string> filesPath;
	vector<string> stuId;
	getDirFilesPath(xmlPath,filesPath,stuId); //���XML����·��

	//��������filesPath��stuId�±��Ӧ
	int filesSize=filesPath.size();

	for (int i=0;i<filesSize;i++)
	{
		StudentObj tmpStu;
		tmpStu.studentId = stuId.at(i);

		//��ȥxmlReader
		XmlReader xr;
		xr.XmlIO(filesPath.at(i),tmpStu);

		allStudents.push_back(tmpStu);
	}

	return true;
}

//���xml���ļ��С��ľ���·��
string Tools::findXmlPath(string batch)
{
	string path = "C:\\pre_out\\";
	path.append(batch);
	return path;
}

//���ĳ�ļ����µ������ļ��ľ���·��
bool Tools::getDirFilesPath( string path, vector<string>& files ,vector <string> &stuId )
{
	//�ļ����
	long hFile   =   0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//�����Ŀ¼,����
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					continue;
			}
			else
			{
				string tmp = fileinfo.name;
				tmp = tmp.substr(0,tmp.length()-4);  //�ص�.xml��׺
				stuId.push_back(tmp);  //��������
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}else{
		return false;
	}

	return true;
}