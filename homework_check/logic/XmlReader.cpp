/**
 * ��ȡxml�Ĺ�����ʵ��
 * 
 * @author Bill Wang
 * 
 */
#include "XmlReader.h"

void XmlReader::test()
{
	cout<<"just for testing!!"<<endl;
}

bool XmlReader::XmlIO(string xmlPath,vector<FileObj> &fileList)
{
	//xml��ȡ�������������·�����������õ�student����
	cout<<"����XmlIO1����"<<endl;

	if(!this->getFileList(xmlPath,fileList))
		return false;

	else
	{
		//��ȷ��ȡxml
		return true;
	}

}

//���صķ������ɴ���ѧ��ID��name
bool XmlReader::XmlIO(string stuName,string stuId,string xmlPath,StudentObj &stu)
{
	//xml��ȡ�������������·�����������õ�student����
	cout<<"����XmlIO2����"<<endl;

	vector<FileObj> fileList;
	if(!this->getFileList(xmlPath,fileList))
		return false;

	else
	{
		//��ȷ��ȡxml
		stu.studentName = stuName;
		stu.studentId = stuId;
		stu.fileList = fileList;

		return true;
	}
}


//���صķ������ɴ�������ID��������ѧ����ֱ�ӻ��������ѧ������
bool XmlReader::XmlIO(string xmlPath,StudentObj &stu)
{
	//xml��ȡ�������������·�����������õ�student����
	cout<<"����XmlIO3����"<<endl;

	cout<<"xmlPath = "<<xmlPath<<endl;

	vector<FileObj> fileList;
	if(!this->getFileList(xmlPath,fileList))
		return false;

	else
	{
		//��ȷ��ȡxml
		stu.fileList = fileList;
		return true;
	}

}




//private����
//����XML·������������vector
bool XmlReader::getFileList(string xmlPath,vector<FileObj> &fileList)
{
	if("" == xmlPath)
	{
		cout<<"Filename is Null"<<endl;
		return false;
	}

	QDomDocument document;

	QString path = QString::fromStdString(xmlPath);
	QFile xmlFile(path); //xml�ļ�·����QString��ʽ���빹�캯��

	if (!xmlFile.open(QIODevice::ReadOnly))
	{
		return false;
	}
	// 	if (!document.setContent(&xmlFile))
	// 	{
	// 		xmlFile.close();
	// 		return false;
	// 	}

	//ת��
	QTextStream floStream(&xmlFile);
	QTextCodec *codec=QTextCodec::codecForName("UTF-8");
	floStream.setCodec(codec);
	QString xmlDataStr = floStream.readAll();
	xmlFile.close();
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));

	//cout<<xmlDataStr.toStdString()<<endl;

	if (!document.setContent(xmlDataStr))
	{
		printf("����xmlʧ��,%s,%d \n",__FILE__,__LINE__);
		return false ;
	}


	QDomElement root = document.documentElement();
	QDomNode node=root.firstChild();   //QDomElement �������tagName,QDomNode��ҪtoElement

	//��ӡ����
	//qDebug()<<root.tagName();
	//cout<<node.toElement().text().toStdString()<<endl;
	//cout<<node.toElement().tagName().toStdString()<<endl;
	// 	qDebug(node.nodeName().toAscii());            //nodeName
	// 	qDebug(node.toElement().text().toAscii());    //����

	QDomNode fileNode=node; //����ļ��ڵ�
	while(!fileNode.isNull())
	{
		if (!fileNode.toElement().isNull()){
			//cout<<qPrintable(fileElem.tagName())<<endl;

			QDomNode tmpNode=fileNode.firstChild();
			FileObj tmpFile;
			while(!tmpNode.isNull())
			{
				if (tmpNode.toElement().tagName().compare("name")==0)
					tmpFile.setFileName(tmpNode.toElement().text().toStdString());
				else if(tmpNode.toElement().tagName().compare("type")==0)
					tmpFile.setFileType(tmpNode.toElement().text().toStdString());
				else if(tmpNode.toElement().tagName().compare("content")==0)
					tmpFile.setContent(tmpNode.toElement().text().toStdString());

				tmpNode = tmpNode.nextSibling();
			}
			//����file����
			//cout<<"fileName = "<<tmpFile.getFileName()<<endl;
			//cout<<"fileContent = "<<tmpFile.getContent()<<endl;

			fileList.push_back(tmpFile);
			//cout<<"fileList.size = "<<fileList.size()<<endl;

		}



		fileNode = fileNode.nextSibling();
	}

	return true;
}