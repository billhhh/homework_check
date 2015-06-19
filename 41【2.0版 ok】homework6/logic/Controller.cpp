/**
 * ��������ʵ�֣��ռ�students��Ϣ������xmlReader�����ݸ��㷨���
 * 
 * @author Bill Wang
 * 
 */
#include "Controller.h"

//ֱ�������Ӵ�
bool Controller::startCheck(Ui::MainWindow *ui,string homeworkPath,string batch,string batchPath,vector <studentMap> stuMap)
{
// 	checkStudent.studentId = stuId;
// 	checkStudent.studentName = stuName;
//	this->studentPath = studentPath;

	this->homeworkPath = homeworkPath;
	this->batchPath = batchPath;
	this->batch=batch;
	this->stuMap=stuMap;
	
	//Ԥ����
	runPreprocess(batchPath);

	Tools tool;
	tool.getAllStudentsNum(batch,allStudents);

	//���������С�ѧ����Ϣ
	fillStudents();


	//��һ��ֵcheckStudent��otherStudent
	for (int i=0;i<allStudents.size();i++)
	{
		cout<<"�����"<<i+1<<"��ѧ��\n";
		//system("pause");

		string tmpStuPath = batchPath;
		this->checkStudent.studentId = this->allStudents.at(i).studentId;
		this->checkStudent.studentName = this->allStudents.at(i).studentName;
		this->checkStudent.fileList = this->allStudents.at(i).fileList;
		tmpStuPath.append("\\");
		tmpStuPath.append(this->checkStudent.studentId);
		this->studentPath = tmpStuPath;

		this->otherStudents=this->allStudents;
		std::vector<StudentObj>::iterator it = this->otherStudents.begin()+i;
		this->otherStudents.erase(it);

		//�Ѿ��õ������ѧ��������ѧ����Ϣ����ȥ�㷨
		sendToCompare(ui);
	}


	return true;
}




//��ȥ�㷨���
//c  cpp  txt   java   pdf   doc   docx    h   cs
//< c, cpp >  <java>  <cs>  < txt,doc,docx,pdf>  <h>
void Controller::sendToCompare(Ui::MainWindow *ui)
{
	//����֮ǰ��Ҫɾ���Ѿ����ڵ�Ŀ¼������ɾ���༶Ŀ¼
	//system("rd /s /q c:\\StringCompare");

	//����ֵΪ0����ʾ�����ɹ�
	_mkdir("c:\\StrCompare\\");
	string path="c:\\StrCompare\\";
	string hwNum = QString::number(ui->HwNumComboBox->currentIndex(), 10).toStdString();
	path.append(hwNum);
	const char *path_c = path.c_str();
	_mkdir(path_c);
	path.append("\\");
	path.append(checkStudent.studentId);
	path.append("\\");
	path_c = path.c_str();
	if ((_mkdir(path_c)) != 0)
	{
		//���򴴽�ʧ��
		cout<<path<<"�Ѵ���"<<endl;
		//return ;
	}

	for (int i=0;i<otherStudents.size();i++)   //��i������һ��otherStudents��
	{
		double similarity;
		QTreeWidgetItem *item = new QTreeWidgetItem(ui->rltTreeWidget);
		item->setText(0, QString::fromStdString(checkStudent.studentName));
		item->setText(1, QString::fromStdString(otherStudents.at(i).studentName));
		item->setText(2, "");
		ui->rltTreeWidget->addTopLevelItem(item);
		//��ÿ��otherStudent��ÿ��file������student��file��������ͬ���Ľ��м��
		for (int j=0;j<checkStudent.fileList.size();j++)  //��j����checkStudent���Ǹ��ļ���
		{
			//checkStudent�Ĵ�����ļ�Ϊ< c, cpp >
			if (checkStudent.fileList.at(j).getFileType().compare("c")==0 || 
				checkStudent.fileList.at(j).getFileType().compare("cpp")==0)
			{
				//����otherStudents���ļ����ҵ�< c, cpp >
				for (int k=0;k<otherStudents.at(i).fileList.size();k++) //��k����otherStudents���Ǹ��ļ���
				{
					if (otherStudents.at(i).fileList.at(k).getFileType().compare("c")==0 ||
						otherStudents.at(i).fileList.at(k).getFileType().compare("cpp")==0)
					{
						//��� test
						cout<<"in controller < c, cpp >"<<endl;
						cout<<checkStudent.fileList.at(j).getFileName()<<"."<<checkStudent.fileList.at(j).getFileType()<<"  ";
						cout<<otherStudents.at(i).fileList.at(k).getFileName()<<"."<<otherStudents.at(i).fileList.at(k).getFileType()<<endl;
						similarity=stringCompare(hwNum,checkStudent,otherStudents.at(i),checkStudent.fileList.at(j),otherStudents.at(i).fileList.at(k),0);
						
						QTreeWidgetItem *chil_item = new QTreeWidgetItem();
						chil_item->setText(0, QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType()));
						chil_item->setText(1, QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType()));
						if(similarity==-1)
						{
							QString path_str = QString::fromStdString(path);
							path_str =path_str+QString::fromStdString(otherStudents.at(i).studentId)+"-"+QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType())+"-"+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType())+"@.txt";
							QFile file(path_str);
							if(!file.open(QIODevice::ReadOnly | QIODevice::Text))  
								qDebug()<<"Can't open the file!"<<endl;         
							QString str = file.readLine();    
							str.chop(1);
							qDebug()<< str;
							chil_item->setText(2, str);
							if(str.toInt()!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						else
						{
							chil_item->setText(2, QString::number(similarity));
							if(similarity!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						item->addChild(chil_item);
					}
				}
			}


			//checkStudent�Ĵ�����ļ�Ϊ<java>
			else if (checkStudent.fileList.at(j).getFileType().compare("java")==0 )
			{
				//����otherStudents���ļ����ҵ�< c, cpp >
				for (int k=0;k<otherStudents.at(i).fileList.size();k++) //k����otherStudents���Ǹ��ļ�
				{
					if (otherStudents.at(i).fileList.at(k).getFileType().compare("java")==0 )
					{
						//��� test
						cout<<"in controller <java>"<<endl;
						cout<<checkStudent.fileList.at(j).getFileName()<<"."<<checkStudent.fileList.at(j).getFileType()<<"  ";
						cout<<otherStudents.at(i).fileList.at(k).getFileName()<<"."<<otherStudents.at(i).fileList.at(k).getFileType()<<endl;
						similarity=stringCompare(hwNum, checkStudent,otherStudents.at(i),checkStudent.fileList.at(j),otherStudents.at(i).fileList.at(k),0);

						QTreeWidgetItem *chil_item = new QTreeWidgetItem();
						chil_item->setText(0, QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType()));
						chil_item->setText(1, QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType()));
						if(similarity==-1)
						{
							QString path_str = QString::fromStdString(path);
							path_str =path_str+QString::fromStdString(otherStudents.at(i).studentId)+"-"+QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType())+"-"+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType())+"@.txt";
							QFile file(path_str);
							if(!file.open(QIODevice::ReadOnly | QIODevice::Text))  
								qDebug()<<"Can't open the file!"<<endl;         
							QByteArray line = file.readLine();    
							QString str(line);
							str.chop(1);
							qDebug()<< str;
							chil_item->setText(2, str);
							if(str.toInt()!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						else
						{
							chil_item->setText(2, QString::number(similarity));
							if(similarity!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						item->addChild(chil_item);
					}
				}
			}

			//checkStudent�Ĵ�����ļ�Ϊ<cs>
			else if (checkStudent.fileList.at(j).getFileType().compare("cs")==0 )
			{
				//����otherStudents���ļ����ҵ�< c, cpp >
				for (int k=0;k<otherStudents.at(i).fileList.size();k++) //k����otherStudents���Ǹ��ļ�
				{
					if (otherStudents.at(i).fileList.at(k).getFileType().compare("cs")==0 )
					{
						//��� test
						cout<<"in controller <cs>"<<endl;
						cout<<checkStudent.fileList.at(j).getFileName()<<"."<<checkStudent.fileList.at(j).getFileType()<<"  ";
						cout<<otherStudents.at(i).fileList.at(k).getFileName()<<"."<<otherStudents.at(i).fileList.at(k).getFileType()<<endl;
						similarity=stringCompare(hwNum, checkStudent,otherStudents.at(i),checkStudent.fileList.at(j),otherStudents.at(i).fileList.at(k),0);

						QTreeWidgetItem *chil_item = new QTreeWidgetItem();
						chil_item->setText(0, QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType()));
						chil_item->setText(1, QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType()));
						if(similarity==-1)
						{
							QString path_str = QString::fromStdString(path);
							path_str =path_str+QString::fromStdString(otherStudents.at(i).studentId)+"-"+QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType())+"-"+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType())+"@.txt";
							QFile file(path_str);
							if(!file.open(QIODevice::ReadOnly | QIODevice::Text))  
								qDebug()<<"Can't open the file!"<<endl;         
							QByteArray line = file.readLine();    
							QString str(line);
							str.chop(1);
							qDebug()<< str;
							chil_item->setText(2, str);
							if(str.toInt()!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						else
						{
							chil_item->setText(2, QString::number(similarity));
							if(similarity!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						item->addChild(chil_item);
					}
				}
			}


			//checkStudent�Ĵ�����ļ�Ϊ< txt,doc,docx,pdf>
			else if (checkStudent.fileList.at(j).getFileType().compare("txt")==0 ||
					 checkStudent.fileList.at(j).getFileType().compare("doc")==0 ||
					 checkStudent.fileList.at(j).getFileType().compare("docx")==0 ||
					 checkStudent.fileList.at(j).getFileType().compare("pdf")==0 )
			{
				//����otherStudents���ļ����ҵ�< txt,doc,docx,pdf>
				for (int k=0;k<otherStudents.at(i).fileList.size();k++) //k����otherStudents���Ǹ��ļ�
				{
					if (otherStudents.at(i).fileList.at(k).getFileType().compare("txt")==0 ||
						otherStudents.at(i).fileList.at(k).getFileType().compare("doc")==0 ||
						otherStudents.at(i).fileList.at(k).getFileType().compare("docx")==0 ||
						otherStudents.at(i).fileList.at(k).getFileType().compare("pdf")==0 )
					{
						//��� test
						cout<<"in controller < txt,doc,docx,pdf>"<<endl;
						cout<<checkStudent.fileList.at(j).getFileName()<<"."<<checkStudent.fileList.at(j).getFileType()<<"  ";
						cout<<otherStudents.at(i).fileList.at(k).getFileName()<<"."<<otherStudents.at(i).fileList.at(k).getFileType()<<endl;
						similarity=stringCompare(hwNum, checkStudent,otherStudents.at(i),checkStudent.fileList.at(j),otherStudents.at(i).fileList.at(k),1);

						QTreeWidgetItem *chil_item = new QTreeWidgetItem();
						chil_item->setText(0, QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType()));
						chil_item->setText(1, QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType()));
						if(similarity==-1)
						{
							QString path_str = QString::fromStdString(path);
							path_str =path_str+QString::fromStdString(otherStudents.at(i).studentId)+"-"+QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType())+"-"+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType())+"@.txt";
							QFile file(path_str);
							if(!file.open(QIODevice::ReadOnly | QIODevice::Text))  
								qDebug()<<"Can't open the file!"<<endl;         
							QByteArray line = file.readLine();    
							QString str(line);
							str.chop(1);
							qDebug()<< str;							
							chil_item->setText(2, str);
							if(str.toInt()!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						else
						{
							chil_item->setText(2, QString::number(similarity));
							if(similarity!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						item->addChild(chil_item);
					}
				}
			}


			//checkStudent�Ĵ�����ļ�Ϊ< h >
			else if (checkStudent.fileList.at(j).getFileType().compare("h")==0 )
			{
				//����otherStudents���ļ����ҵ�< c, cpp >
				for (int k=0;k<otherStudents.at(i).fileList.size();k++) //k����otherStudents���Ǹ��ļ�
				{
					if (otherStudents.at(i).fileList.at(k).getFileType().compare("h")==0 )
					{
						//��� test
						cout<<"in controller <h>"<<endl;
						cout<<checkStudent.fileList.at(j).getFileName()<<"."<<checkStudent.fileList.at(j).getFileType()<<"  ";
						cout<<otherStudents.at(i).fileList.at(k).getFileName()<<"."<<otherStudents.at(i).fileList.at(k).getFileType()<<endl;
						similarity=stringCompare(hwNum, checkStudent,otherStudents.at(i),checkStudent.fileList.at(j),otherStudents.at(i).fileList.at(k),0);

						QTreeWidgetItem *chil_item = new QTreeWidgetItem();
						chil_item->setText(0, QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType()));
						chil_item->setText(1, QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType()));
						if(similarity==-1)
						{
							QString path_str = QString::fromStdString(path);
							path_str =path_str+QString::fromStdString(otherStudents.at(i).studentId)+"-"+QString::fromStdString(checkStudent.fileList.at(j).getFileName())+"."+QString::fromStdString(checkStudent.fileList.at(j).getFileType())+"-"+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileName())+"."+QString::fromStdString(otherStudents.at(i).fileList.at(k).getFileType())+"@.txt";
							QFile file(path_str);
							if(!file.open(QIODevice::ReadOnly | QIODevice::Text))  
								qDebug()<<"Can't open the file!"<<endl;         
							QByteArray line = file.readLine();    
							QString str(line);
							str.chop(1);
							qDebug()<< str;
							chil_item->setText(2, str);
							if(str.toInt()!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						else
						{
							chil_item->setText(2, QString::number(similarity));
							if(similarity!=0)
							{	
								item->setTextColor(0 ,Qt::red);
								item->setTextColor(1 ,Qt::red);
							}
						}
						item->addChild(chil_item);
					}
				}
			}



		}
	}
}



//��������ѧ����Ϣ
void Controller::fillStudents()
{
	for (int i=0;i<allStudents.size();i++)
	{
		for (int j=0;j<stuMap.size();j++)
		{
			if ( allStudents.at(i).studentId.compare(stuMap.at(j).studentId) == 0 )
				allStudents.at(i).studentName = stuMap.at(j).studentName;
		}
	}
}


//����Ԥ����
bool Controller::runPreprocess(string batchPath)
{
	//����Ԥ����֮ǰ��Ҫɾ���Ѿ����ڵ�c:\pre_out
	//system("rd /s /q c:\\pre_out");

	//"..\\run_pre.bat "+batchPath+" c:\\";
	//string cmd = "..\\run_pre\\run_pre.bat ";
	string cmd = "c:\\run_pre\\run_pre.bat "; //������ԣ���ʱ��c��

	cmd.append(batchPath);
	cmd.append(" c:\\");
	cout<<"Ԥ����cmd == "<<cmd<<endl;

	const char *cCmd = cmd.data();
	system(cCmd);

	cout<<"Preprocess is over\n"<<endl;

	return true;
}