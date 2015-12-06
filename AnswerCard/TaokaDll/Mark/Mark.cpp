// Mark.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TraversingFile/TraversingFile.h"
#include <cv.h>
#include <string>
#include <highgui.h>
#include "TimeCounter.h"
#include "../Taoka/MarkAC.h"
#include "../XmlIO/XmlIO.h"
#include "../Taoka/ACStructs.h"
#include <fstream>
#include <bitset>
#include <iomanip>
//#include <atltrace.h>
using namespace std;
using namespace cv;
#pragma comment(lib,"../debug/Taoka.lib")
#pragma comment(lib,"../debug/XmlIO.lib")


int SaveResultToFile(Result rt,string path,string filename);
int CustomSaveResultToFile(Result rt,string path,string filename);
void DrawAnswerToImgFile(Mat img,string filename,Result result,Size rectSize,Rect barPos);
void SaveCropArea(vector<CropAreaResult> car,string path,string filename);

//ת��result��ʽ
void AC_RST2Result(Result &result,const AC_RST &acrst)
{
	result.angle=acrst.angle;
	result.errFlag=acrst.errFlag;
	//ת���͹���𰸽ṹ��
	result.answerResult.suspectFlag=acrst.answerResult.suspectFlag;
	for (int i=acrst.answerResult.answerCount-1;i>=0;i--)
	{
		PerquestionResult pqrst;
		pqrst.questionId=acrst.answerResult.answer[i].questionId;
		string tmp=string(acrst.answerResult.answer[i].answer,acrst.answerResult.answer[i].answer+4);
		//pqrst.answer=HexString2Int(tmp);
				pqrst.answer=acrst.answerResult.answer[i].answer;
		pqrst.suspectFlag=acrst.answerResult.answer[i].suspectFlag;
		for (int j=acrst.answerResult.answer[i].answerPosCount-1;j>=0;j--)
		{
			pqrst.answerPos.push_back(acrst.answerResult.answer[i].answerPos[j]);
		}
		result.answerResult.answer.push_back(pqrst);
	}
	//ת������ʶ�����ṹ��
	for (int i=acrst.barResultCount-1;i>=0;i--)
	{
		BarResult brst;
		brst.errflag=acrst.barResult[i].errflag;
		brst.barType=acrst.barResult[i].barType;
		brst.bar=acrst.barResult[i].bar;
		result.barResult.push_back(brst);
	}
	//ת������������
	for (int i=acrst.cropAreaResultCount-1;i>=0;i--)
	{
		CropAreaResult crst;
		crst.groupNum=acrst.cropAreaResult[i].groupNum;
		crst.isSecret=acrst.cropAreaResult[i].isSecret;
		crst.rect=acrst.cropAreaResult[i].cropRect;
		crst.name=acrst.cropAreaResult[i].name;
		result.cropAreaResult.push_back(crst);
	}
	//ת��Ԥ������Ϳ��ʶ����
	for (int i=acrst.cfpResultCount-1;i>=0;i--)
	{
		FillingPointsResult fprst;
		fprst.name=acrst.cfpResult[i].name;
		fprst.type=acrst.cfpResult[i].fPType;
		fprst.suspectFlag=acrst.cfpResult[i].suspectFlag;
		for (int j=acrst.cfpResult[i].fillingResultCount-1;j>=0;j--)
		{
			PerFPResult pfprst;
			pfprst.result=acrst.cfpResult[i].fillingResult[j].result;
			pfprst.suspectFlag=acrst.cfpResult[i].fillingResult[j].suspectFlag;
			for (int k=acrst.cfpResult[i].fillingResult[j].resultPosCount-1;k>=0;k--)
			{
				pfprst.resultPos.push_back(acrst.cfpResult[i].fillingResult[j].resultPos[k]);
			}
			fprst.fillingResult.push_back(pfprst);

		}
		result.cfpResult.push_back(fprst);
	}

}


int _tmain(int argc, char* argv[])
{

	if (argc<3)
	{
		cout<<"//////////////////////////////////////////////////////////////////////////////"<<endl<<"����˵��"<<endl
			<<"����һ������ʽ�����ļ�·��"<<endl<<"��������ɨ��ͼ��(jpg��ʽ)�����ļ���"<<endl<<"���������Ƿ���������ģʽ"<<endl<<"�����ģ���ǵ��ȷ�Χ��ֵ����Ϊ�գ�"<<endl
			<<"�����壺��ǵ�߶ȷ�Χ��ֵ����Ϊ�գ�"<<endl
			<<"//////////////////////////////////////////////////////////////////////////////"<<endl;
		getchar();
		return -1;
	}
	char *xmlFilepath = argv[1];
	string path = string(argv[2]);
	
	//unsigned int a = 0x12345678;
	//printf("%x",*((unsigned char *)(&a)+1)+1);
	//char str[]="abcdefghijklmnopqrstuvwxyz";
	//char *pchar=str;
	//int * point=(int *)(str+4);
	//short int * pshort=(short int * )(str+3);
	//printf("%c%c%c",*(++pchar),*((char *)(++point)),*((char *)(++pshort)));

	//////////////////////////////////����ʽ�ļ���ȡ////////////////////////////////////////
//	char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\������\\����ʽ\\dl.xml";
//	char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\ά����\\�ο���ʶ���쳣\\5.xml";
//	char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\error\\6.xml";
//	char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\ά����\\5.xml";
//	char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\�������㷨ʶ������_507\\6.xml";
	//char * xmlFilepath = "I:\\���⿨��Ŀ\\������\\��ɽͼƬ\\1.xml";
	//xmlFilepath = "D:\\ACTest\\whtest2_F.xml";

	int acinfoaddress;
	int actype;
//	xmlFilepath="I:\\���⿨��Ŀ\\������\\����������ͬ��ͷ����\\17_1.xml";
	int returnValue=GetTKInfo(xmlFilepath,actype,acinfoaddress);
	
// 	Cum_TK_info3 *cumtkinfo;
// 	GetCum_TkInfo3(acinfoaddress,&cumtkinfo);
// 	freeCumTkInfo3(cumtkinfo);

	AcArgs acargs;
// 	TK_info3 acinfo;
// 	XmlIo xmlIo;
// 	int returnValue = xmlIo.Read(xmlFilepath,acinfo);
	if (returnValue)
	{
		cout<<"����ʽ�ļ���ȡ�쳣���쳣���룺"<<returnValue<<endl;
		getchar();
		return 1;
	}
	///////////////////////////////////�����ļ�///////////////////////////////////////
	acargs.areaThreshold=acargs.sensibilityThresh=0;
	acargs.xRangeScale=3;
	acargs.yRangeScale=4;
	acargs.sensibilityThresh=0;
	acargs.areaThreshold=1.2;
	acargs.seSize=0.1;
// 	int (*n)[10];
// 	cout<<sizeof(n)<<endl;


	//�������ļ���
//	string path ="I:\\���⿨��Ŀ\\������\\�ο������\\b\\";
//	string path ="I:\\���⿨��Ŀ\\������\\cet4\\��λ\\";
//	string path ="I:\\���⿨��Ŀ\\������\\error\\";
//	string path ="I:\\���⿨��Ŀ\\������\\ά����\\�ο���ʶ���쳣\\time.txt";
//	string path ="I:\\���⿨��Ŀ\\������\\������\\lxa\\";
//	string path ="I:\\���⿨��Ŀ\\������\\�����п�ʶ�𱨴�\\�����п�������ʽδ�ҵ�\\";
	//string path ="I:\\���⿨��Ŀ\\������\\��ɽͼƬ\\";
	//path ="D:\\ACTest\\";

	int flag=1;


	bool isSingle=true;
	//if(argc>=4)
	//	isSingle = argv[3];
//	AcArgs acargs;

// 	for (unsigned int i=0;i<path.size();i++)
// 	{
// 		if (path[i] == '/')
// 		{
// 			path[i] = '\\';
// 		}		
// 	}
	
	string filename;
	string rFilename;
	string fFilename;
	
	////////////////////////////////////��ʱ��//////////////////////////////////////
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	/////////////////////////////////////����ļ�///////////////////////////////////////
	ofstream clear(path+"result.txt",ios::trunc);	
	clear.close();
	clear.open(path+"error.txt",ios::trunc);
	clear.close();
	clear.open(path+"time.txt",ios::trunc);
	clear.close();
// 	clear.open(path+"barerr.txt",ios::trunc);
// 	clear.close();
	int count=0;
	//////////////////////////////////////////////////////////////////////////
	int pos=path.find(".txt",path.length()-4);
	int tpos=path.rfind('\\',path.length()-1);
	string tpath=path.substr(0,tpos+1);
	if (pos!=path.npos)
	{
		fstream imgread(path,ios::in);
		if (!imgread)
		{
			cout<<"txt�ļ���ȡ�쳣��"<<endl;
			getchar();
			imgread.close();
			exit(0);
		}
		if (isSingle) //�Ƿ���
		{
			while(getline(imgread,fFilename))
			{
				count++;
				cout<<"\n��"<<count<<"���ļ�"<<endl;
				cout<<fFilename<<endl;			//����ļ���
				string fffilename;
				int fffpos=fFilename.rfind("jpg");
				fFilename=fFilename.substr(0,fffpos+3);

				Mat fRaw = imread(fFilename);		//��ȡ�ļ�
				if ((!fRaw.data))
				{
					cout<<"��"<<count<<"��:"<<filename<<"ͼ���ļ���ȡ�쳣"<<endl;
					cout<<"�����������������"<<endl;
				//	getchar();
					continue;
				}
				Mat fGray;
				cvtColor(fRaw,fGray,CV_RGB2GRAY);
				string gpath=path+"time.txt";
				ofstream gout(gpath,ios::app);
				//������
				AC_RST *fAC_rt;
				Result fRT;
				fRT.answerResult.answer.clear();

				fRT.errFlag=0;  //��ʼ�������δ����
   			//��ʱ��ʼ		
				QueryPerformanceCounter(&startCount);
				//�����ĺ�������ʽ�����б�����⿨�ĺ���
				//(uchar* img,cv::Size imgSize, int actype,int tkinfoAddress,AC_RST ** pResult,AcArgs acargs���û��ɵ���������)
				returnValue = MarkTaokaSinglePage(fGray.data,fGray.size(),actype,acinfoaddress,&fAC_rt,acargs);
				if (returnValue)
				{
					cout<<"ʶ�����:"<<returnValue<<endl;
					gout<<fFilename<<returnValue<<endl;
					gout.close();
					continue;
				}
				//��ʱ����
				QueryPerformanceCounter(&endCount);
				double elapsed = (double)(endCount.QuadPart - startCount.QuadPart) / freq.QuadPart*1000;  //�����ʱ��
				cout << "��ʱ��" << elapsed <<"ms"<< endl;
				/*gout<<filename<<","<<elapsed<<"ms"<< endl;
				gout.close();*/
				AC_RST2Result(fRT,*fAC_rt);

				//������
				//SaveResultToFile(rt,path+"result.txt",filename);
				SaveResultToFile(fRT,path,fFilename);
				//���溬�𰸵�ͼ��

				unsigned found = fFilename.rfind('\\',fFilename.length()-1);
				string filePath;
				if (found==std::string::npos)
				{
					found = fFilename.rfind('\\',fFilename.length()-1);
					if (found==std::string::npos)
					{
						cout<<"filename error"<<endl;
						continue;
					}
				}
				filePath = fFilename.substr(0,found+1);
				char buf[10];
				sprintf(buf,"%d",count);
				string fname = string(buf)+fFilename.substr(found+1,fffpos+3);
				CreateDirectory((tpath+"ʶ����\\").c_str(),NULL);
				if(flag)	
				{
					DrawAnswerToImgFile(fRaw,tpath+"ʶ����\\"+fname,fRT,Size(28,16),Rect());

				}


				//�����������
				// 			if (fRT.cropAreaResult.size()>0)
				// 			{
				// 				CreateDirectory((filePath+"��������\\").c_str(),NULL);
				// 				SaveCropArea(rt.cropAreaResult,filePath,name);
				// 			}
				if (returnValue)
				{
					//			ATLTRACE("%s\n",filename.c_str());
					cout<<"���⿨ʶ���쳣���쳣����"<<returnValue<<endl;
				}else
				{
					cout<<"���⿨ʶ������"<<endl;
				}
				freeResult(fAC_rt);
			}
			imgread.close();
		}
		else
		{
			//˫��
			while(getline(imgread,fFilename)&&getline(imgread,rFilename))
			{
				count++;
				cout<<"\n��"<<count<<"���ļ�"<<endl;
				cout<<fFilename<<endl;			//����ļ���
				string fffilename;
				int fffpos=fFilename.rfind("jpg");
				fFilename=fFilename.substr(0,fffpos+3);

				Mat fRaw = imread(fFilename);		//��ȡ�ļ�
				Mat rRaw = imread(rFilename);		//��ȡ�ļ�
				if ((!fRaw.data)&&(!rRaw.data))
				{
					cout<<"��"<<count<<"��:"<<filename<<"ͼ���ļ���ȡ�쳣"<<endl;
					cout<<"�����������������"<<endl;
					getchar();
					continue;
				}
				Mat fGray,rGray;
				cvtColor(fRaw,fGray,CV_RGB2GRAY);
				cvtColor(rRaw,rGray,CV_RGB2GRAY);
				string gpath=path+"time.txt";
				ofstream gout(gpath,ios::app);
				//������
				AC_RST *fAC_rt,*rAC_rt;
				Result fRT,rRT;
				fRT.answerResult.answer.clear();
				fRT.errFlag=0;
				rRT.answerResult.answer.clear();
				rRT.errFlag=0;

				//��ʱ��ʼ		
				QueryPerformanceCounter(&startCount);
				returnValue = MarkTaokaDoublePage(fGray.data,fGray.size(),rGray.data,rGray.size(),actype,acinfoaddress,&fAC_rt,&rAC_rt,acargs);
				if (returnValue)
				{
					cout<<"ʶ�����:"<<returnValue<<endl;
					gout<<fFilename<<returnValue<<endl;
					gout<<rFilename<< endl;
					gout.close();
					continue;
				}
				//��ʱ����
				QueryPerformanceCounter(&endCount);
				double elapsed = (double)(endCount.QuadPart - startCount.QuadPart) / freq.QuadPart*1000;
				cout << "��ʱ��" << elapsed <<"ms"<< endl;
				/*gout<<filename<<","<<elapsed<<"ms"<< endl;
				gout.close();*/
				AC_RST2Result(fRT,*fAC_rt);
				AC_RST2Result(rRT,*rAC_rt);

				//������
				//SaveResultToFile(rt,path+"result.txt",filename);
				SaveResultToFile(fRT,path,fFilename);
				SaveResultToFile(rRT,path,rFilename);
				//���溬�𰸵�ͼ��

				unsigned found = fFilename.rfind('\\',fFilename.length()-1);
				string filePath;
				if (found==std::string::npos)
				{
					found = fFilename.rfind('\\',fFilename.length()-1);
					if (found==std::string::npos)
					{
						cout<<"filename error"<<endl;
						continue;
					}
				}
				filePath = fFilename.substr(0,found+1);
				string fname = fFilename.substr(found+1,fffpos+3);
				string rname = rFilename.substr(found+1,rFilename.length());
				CreateDirectory((tpath+"ʶ����\\").c_str(),NULL);
				if(flag)	
				{
					DrawAnswerToImgFile(fRaw,tpath+"ʶ����\\"+fname,fRT,Size(28,16),Rect());
					DrawAnswerToImgFile(rRaw,tpath+"ʶ����\\"+rname,rRT,Size(28,16),Rect());

				}


				//�����������
				// 			if (fRT.cropAreaResult.size()>0)
				// 			{
				// 				CreateDirectory((filePath+"��������\\").c_str(),NULL);
				// 				SaveCropArea(rt.cropAreaResult,filePath,name);
				// 			}
				if (returnValue)
				{
					//			ATLTRACE("%s\n",filename.c_str());
					cout<<"���⿨ʶ���쳣���쳣����"<<returnValue<<endl;
				}else
				{
					cout<<"���⿨ʶ������"<<endl;
				}
				freeResult(fAC_rt);
				freeResult(rAC_rt);
			}
			imgread.close();
		}
	}else
	{
		TraversingFile t;
		t.Init(path,"jpg");
		while (!t.GetFileName(filename))
		{
			cout<<"\n��"<<t.GetFileCounter()<<"���ļ�"<<endl;
			cout<<filename<<endl;			//����ļ���
			Mat raw = imread(filename);		//��ȡ�ļ�
			if (!raw.data)
			{
				cout<<filename<<"ͼ���ļ���ȡ�쳣"<<endl;
				cout<<"�����������������"<<endl;
				continue;
			}
			Mat gray;
			cvtColor(raw,gray,CV_RGB2GRAY);
			string gpath=path+"time.txt";
			ofstream gout(gpath,ios::app);
			//������
			Result rt;
			AC_RST *ac_rt;
			rt.answerResult.answer.clear();
			rt.errFlag=0;
			//��ʱ��ʼ		
			QueryPerformanceCounter(&startCount);
			returnValue = MarkTaokaSinglePage(gray.data,gray.size(),actype,acinfoaddress,&ac_rt,acargs);
			//��ʱ����
			QueryPerformanceCounter(&endCount);
			double elapsed = (double)(endCount.QuadPart - startCount.QuadPart) / freq.QuadPart*1000;
			cout << "��ʱ��" << elapsed <<"ms"<< endl;
			count++;
			gout<<filename<<","<<elapsed<<" ms"<< endl;
			gout.close();

			//������
			//SaveResultToFile(rt,path+"result.txt",filename);
			AC_RST2Result(rt,*ac_rt);
			CustomSaveResultToFile(rt,path,filename);
			//���溬�𰸵�ͼ��

			unsigned found = filename.rfind('\\',filename.length()-1);
			string filePath;
			if (found==std::string::npos)
			{
				found = filename.rfind('\\',filename.length()-1);
				if (found==std::string::npos)
				{
					cout<<"filename error"<<endl;
					continue;
				}
			}
			filePath = filename.substr(0,found+1);
			string name = filename.substr(found+1,filename.length());
			CreateDirectory((filePath+"ʶ����\\").c_str(),NULL);
			if(flag)	
				DrawAnswerToImgFile(raw,filePath+"ʶ����\\"+name,rt,Size(28,16),Rect());

			//�����������
// 			if (rt.cropAreaResult.size()>0)
// 			{
// 				CreateDirectory((filePath+"��������\\").c_str(),NULL);
// 				SaveCropArea(rt.cropAreaResult,filePath,name);
// 			}
			if (returnValue)
			{
				//			ATLTRACE("%s\n",filename.c_str());
				cout<<"���⿨ʶ���쳣���쳣����"<<returnValue<<endl;
			}else
			{
				cout<<"���⿨ʶ������"<<endl;
			}
			if(!returnValue)
				freeResult(ac_rt);
		}
	}
	
	cout<<endl<<"ʶ�����"<<endl;
	getchar();
	return 0;
}
//���𰸼��ϱ�ע����
void DrawAnswerToImgFile(Mat img,string filename,Result result,Size rectSize,Rect barPos)
{
	Rect rect;
	rect.width = rectSize.width;
	rect.height = rectSize.height;
	Mat warp_mat = getRotationMatrix2D(cv::Point2d(img.cols>>1,img.rows>>1),result.angle,1);
	warpAffine( img, img, warp_mat, img.size());
	for (unsigned int i = 0;i<result.answerResult.answer.size();i++)
	{
		for (unsigned int j = 0;j<result.answerResult.answer[i].answerPos.size();j++)
		{
			rect.x = result.answerResult.answer[i].answerPos[j].x-(rect.width>>1);
			rect.y = result.answerResult.answer[i].answerPos[j].y-(rect.height>>1);
			if (result.answerResult.answer[i].suspectFlag==1)
			{
				rectangle(img,rect,Scalar(255,0,0),2);
			}else if (result.answerResult.answer[i].suspectFlag==2)
			{
				rectangle(img,rect,Scalar(0,0,255),2);
			}else
			rectangle(img,rect,Scalar(0,255,0),2);
		}		
	}
	for (unsigned int i = 0;i<result.cfpResult.size();i++)
	{
		for (unsigned int j = 0;j<result.cfpResult[i].fillingResult.size();j++)
		{
			for (unsigned int k = 0;k<result.cfpResult[i].fillingResult[j].resultPos.size();k++)
			{
				rect.x = result.cfpResult[i].fillingResult[j].resultPos[k].x-(rect.width>>1);
				rect.y = result.cfpResult[i].fillingResult[j].resultPos[k].y-(rect.height>>1);
				rectangle(img,rect,Scalar(0,255,0),2);
			}
			
		}		
	}
//	rectangle(img,barPos,Scalar(0,255,0),1);
	for (int i = result.barResult.size()-1;i>=0;i--)
	{
		cv::putText(img,result.barResult[i].bar,cv::Point2d(barPos.x,barPos.y),FONT_HERSHEY_COMPLEX,.6,Scalar(0,255,0),2);
	}

	imwrite(filename,img);
}
int CustomSaveResultToFile(Result rt,string path,string filename)
{
	string resultpath=path+"result.txt";
	string errorpath=path+"error.txt";
//	string barerrorpath=path+"barerr.txt";
	ofstream fout(resultpath,ios::app);
	ofstream eout(errorpath,ios::app);
//	ofstream bout(barerrorpath,ios::app);
	bool flag=true;
	
	if(rt.errFlag!=0)
	{
		eout<<filename<<"�����쳣����:"<<rt.errFlag<<endl;
		eout.close();
		fout.close();
		return 0;
	}
	fout<<filename<<',';

	if (rt.barResult.size()>0)
	{
	//	fout<<"������ʶ����"<<endl;
		for (int i=0;i<rt.barResult.size();i++)
		{
			if (rt.barResult[i].errflag)
			{
//				bout<<filename<<endl;
			}else
			fout<<rt.barResult[i].bar<<",";
		}
		//fout<<',';
	}

	if (rt.cfpResult.size()>0)
	{
		for (int i=0;i<rt.cfpResult.size();i++)
		{
			FillingPointsResult fpResult=rt.cfpResult[i];
			fout<<fpResult.name<<",";
			switch(fpResult.type)
			{
			case PaperType:
				{
					ushort tmpAnswer = fpResult.fillingResult[0].result;
					string strAnswer;
					for (int s = 0;s<15;s++)
					{
						ushort tmp = 1<<s;
						if (tmp&tmpAnswer)
						{
							strAnswer += '0'+s;
						}
					}
					fout<<strAnswer<<",";
					break;

				}

			case Absent:
				{
					fout<<fpResult.fillingResult[0].result<<",";
					break;
				}

			case Discipline:
				{
					fout<<fpResult.fillingResult[0].result<<",";
					break;
				}


			case OptionalQuestion:
				{
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<15;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '0'+s;
							}
						}
						fout<<strAnswer;
					}
					fout<<",";
					break;
				}

			case CourseNumZeroFirst:
			case ExamHallNumZeroFirst:
			case FirstCandidateNumZeroFirst:
			case ExamRoomNumZeroFirst:
			case SeatNumZeroFirst:
			case TickerNumZeroFirst:
				{
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<15;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '0'+s;
							}
						}
						fout<<strAnswer;
					}
					fout<<",";
					break;
				}
			default:
				{
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<9;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '1'+s;
							}
						}
						ushort tmp = 1<<9;
						if(tmp&tmpAnswer)
							strAnswer +='0';
						fout<<strAnswer;
					}
					fout<<",";
					break;
				}

			}

		}
//		fout<<endl;
	}

	bool eoutflag=false;
	for (int i=0;i<rt.answerResult.answer.size();i++)
	{	
		if (rt.answerResult.answer[i].suspectFlag!=0)
		{
//			fout<<"####";
			fout<<"0000";
			if(flag)
			{
//				eout<<endl;
				eout<<filename<<',';
				flag=false;
				eoutflag=true;
			}
			eout<<"  ��"<<rt.answerResult.answer[i].questionId<<"����";


		}else
		{
			ushort tmpAnswer = rt.answerResult.answer[i].answer;
			fout<<setw(4)<<setfill('0')<<hex<<rt.answerResult.answer[i].answer;
		}

	}
	if(eoutflag)
		eout<<endl;
	fout<<endl;
	fout.close();
	eout.close();
	return 0;
}



//����𰸵�txt
int SaveResultToFile(Result rt,string path,string filename)
{
	string resultpath=path+"result.txt";
	string errorpath=path+"error.txt";
	ofstream fout(resultpath,ios::app);
	ofstream eout(errorpath,ios::app);
	bool flag=true;
	if(rt.errFlag!=0)
	{
		eout<<filename<<"�����쳣����:"<<rt.errFlag<<endl;
		eout.close();
		fout.close();
		return 0;
	}
	fout<<filename<<endl;
	if (rt.barResult.size()>0)
	{
		fout<<"������ʶ����"<<endl;
		for (int i=0;i<rt.barResult.size();i++)
		{
			switch(rt.barResult[i].barType)
			{
			case PaperTypeBar:
				fout<<"�Ծ�����: ";
				break;			
			case TickerNumBar:
				fout<<"׼��֤��: ";
				break;		
			case ExamRoomNumBar:
				fout<<"���Һ�: ";
				break;			
			case AbsentBar:
				fout<<"ȱ��: ";
				break;
			}
			fout<<rt.barResult[i].bar<<endl;
		}
	}
	
	if (rt.cfpResult.size()>0)
	{
		fout<<"Ԥ������Ϳ��ʶ����"<<endl;
		for (int i=0;i<rt.cfpResult.size();i++)
		{
			FillingPointsResult fpResult=rt.cfpResult[i];
			switch(fpResult.type)
			{
			case PaperType:
				{
					fout<<"�Ծ�����"<<"   ";
					ushort tmpAnswer = fpResult.fillingResult[0].result;
					string strAnswer;
					for (int s = 0;s<15;s++)
					{
						ushort tmp = 1<<s;
						if (tmp&tmpAnswer)
						{
							strAnswer += '0'+s;
						}
					}
					fout<<strAnswer;
					break;

				}
				
			case Absent:
				{
					fout<<"ȱ����  ";
					fout<<fpResult.fillingResult[0].result<<endl;
					break;
				}
				
			case Discipline:
				{
					fout<<"Υ�ͣ�  ";
					fout<<fpResult.fillingResult[0].result<<endl;
					break;
				}
				

			case OptionalQuestion:
				{
					fout<<fpResult.name<<":  ";
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<15;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '0'+s;
							}
						}
						fout<<strAnswer;
					}
					fout<<endl;
					break;
				}
				
			case CourseNumZeroFirst:
			case ExamHallNumZeroFirst:
			case FirstCandidateNumZeroFirst:
			case ExamRoomNumZeroFirst:
			case SeatNumZeroFirst:
			case TickerNumZeroFirst:
				{
					fout<<fpResult.name<<":  ";
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<15;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '0'+s;
							}
						}
					fout<<strAnswer;
					}
					fout<<endl;
					break;
				}
			default:
				{
					fout<<fpResult.name<<":  ";
					for (int j=0;j<fpResult.fillingResult.size();j++)
					{
						ushort tmpAnswer = fpResult.fillingResult[j].result;
						string strAnswer;
						for (int s = 0;s<9;s++)
						{
							ushort tmp = 1<<s;
							if (tmp&tmpAnswer)
							{
								strAnswer += '1'+s;
							}
						}
						ushort tmp = 1<<9;
						if(tmp&tmpAnswer)
							strAnswer +='0';
						fout<<strAnswer;
					}
					fout<<endl;
					break;
				}
				
			}
			
		}
	}

	for (int i=0;i<rt.answerResult.answer.size();i++)
	{	
		ushort tmpAnswer = rt.answerResult.answer[i].answer;
		string strAnswer;
		for (int j = 0;j<15;j++)
		{
			ushort tmp = 1<<j;
			if (tmp&tmpAnswer)
			{
				strAnswer += 'A'+j;
			}
		}
		if (strAnswer.length()==0)
		{
			strAnswer = "δ����";
		}
		fout<<"\t��"<<rt.answerResult.answer[i].questionId<<":"<<strAnswer;
		//fout<<setw(4)<<setfill('0')<<hex<<rt.answerResult.answer[i].answer;
		if (rt.answerResult.answer[i].suspectFlag!=0)
		{
//			fout<<"\t��"<<rt.answerResult.answer[i].questionId<<":����";
			fout<<"  :����  ";
			if(flag)
			{
				eout<<filename<<endl;
				flag=false;
			}
			eout<<"\t��"<<rt.answerResult.answer[i].questionId<<"����"<<endl;
			

		}
			
		
		
	}
	fout<<endl;
	fout.close();
	eout.close();
	return 0;
}
/*
//����𰸵�txt
int SaveResultToFile(Result rt,string path,string filename)
{
	ofstream fout(path+"result.txt",ios::app);
	fout<<filename<<endl;
	fout<<"��б�Ƕ�Ϊ��"<<rt.angle<<endl;
 	fout<<"������ʶ����"<<endl;
	for (int i=0;i<rt.barResult.size();i++)
	{
		switch(rt.barResult[i].barType)
		{
		case PaperTypeBar:
			fout<<"�Ծ�����: ";
			break;			
		case TickerNumBar:
			fout<<"׼��֤��: ";
			break;		
		case ExamRoomNumBar:
			fout<<"���Һ�: ";
			break;			
		case AbsentBar:
			fout<<"ȱ��: ";
			break;
		}
		fout<<rt.barResult[i].bar<<endl;
	}
	if (rt.cfpResult.size()>0)
	{
		fout<<"�û��Զ�����Ϳ��ʶ����(���Ϊ������)"<<endl;
		for (int i=0;i<rt.cfpResult.size();i++)
		{
			fout<<rt.cfpResult[i].name<<":"<<bitset<sizeof(ushort)*8>(rt.cfpResult[i].fillingResult);
			if (rt.cfpResult[i].suspectFlag)
			{
				fout<<"���ɣ�"<<endl;
			}else
				fout<<endl;
		}
	}
	for (int i=0;i<rt.answerResult.answer.size();i++)
	{
		ushort tmpAnswer = rt.answerResult.answer[i].answer;
		string strAnswer;
		for (int j = 0;j<15;j++)
		{
			ushort tmp = 1<<j;
			if (tmp&tmpAnswer)
			{
				strAnswer += 'A'+j;
			}
		}
		if (strAnswer.length()==0)
		{
			strAnswer = "δ����";
		}
		fout<<"��"<<rt.answerResult.answer[i].questionId<<":\t"<<strAnswer;
		if (rt.answerResult.answer[i].suspectFlag!=0)
		{
			fout<<"\t����!"<<endl;
		}else
			fout<<endl;

	}
	fout<<endl;
	fout.close();
	return 0;
}
*/
void SaveCropArea(vector<CropAreaResult> car,string path,string filename)
{
	int idx = filename.rfind('.');
	string prefix = filename.substr(0,idx);
	string suffix = filename.substr(idx,filename.length()-1);
	for (unsigned int i=0;i<car.size();i++)
	{
//		imwrite(path+"��������\\"+prefix+'_'+car[i].name+'_'+suffix,car[i].img);
	}
}