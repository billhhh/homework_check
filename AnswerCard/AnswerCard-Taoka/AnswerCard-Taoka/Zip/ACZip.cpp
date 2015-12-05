
#include "ACZip.h"
#include <memory.h>
#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <string>
#include <error.h>
using namespace std;

int	ACZip( vector<string> files,string zipname){
	char zipName[MAX_PATH];
	strcpy(zipName,zipname.c_str());
	//��������
	MyCab mc;
	//��������ļ�
	mc.SetOutPutFile(zipName);
	//���Ҫ������ļ�
	for (unsigned int i=0;i<files.size();i++)
	{
		mc.AddFile(files.at(i));
	}
	
	//ִ�д��
	mc.DoMakeCAB();
	return 0;
}

MyCab::MyCab() {
	memset(&fh,0x0,sizeof(fh));
	memset(ObjectFilePathName,0x0,sizeof(ObjectFilePathName));
 }

 //����ļ�������
void MyCab::AddFile(string FilePathName){
	if ( fh.FileCount >= MAX_FILE_COUNT - 1 )
	{
	   cout<<"���֧��"<<MAX_FILE_COUNT<<"���ļ�"<<endl;
	   return;
	}
	strcpy(fh.FileName[fh.FileCount],FilePathName.c_str());
	fh.FileCount++;
 }

 //���ô������ļ�
void MyCab::SetOutPutFile(char * OutFile)
 {
	memset(ObjectFilePathName,0x0,sizeof(ObjectFilePathName));
	strcpy(ObjectFilePathName,OutFile);
 }

//��ȡ�ļ���С(�����Զ����Ʒ�ʽ�򿪵��ļ�ָ��)
long MyCab::GetFileSize(FILE *pf)
 {
	//ָ���Ƶ��ļ�β
	fseek(pf,0,/*SEEK_END*/ 2);
	return ftell(pf);
 }

 //��������ļ�
 void MyCab::DoMakeCAB()
 {
	if ( fh.FileCount < 1 )
	{
		cout<<"û���ļ���ӵ����"<<endl;
		return;
	}
	if ( strlen(ObjectFilePathName) < 1 )
	{
		cout<<"û��ָ������ļ����λ��"<<endl;
		return;
	}
	FILE *pOutFile = NULL;
	FILE *pWorkFile = NULL;
	//��ȡ�����ļ���С
	for ( int i = 0 ; i < fh.FileCount ; i++ )
	{
		pWorkFile = fopen(fh.FileName[i],"rb");
		if ( NULL == pWorkFile )
		{
			cout<<"�ļ�:"<<fh.FileName[i]<<"�޷���ȡ["<<strerror(errno)<<"]"<<endl;
			return;
		}
		fh.FileLen[i] = GetFileSize(pWorkFile);
		fclose(pWorkFile);
	}
	//��ʼ�ϲ�д�ļ�
	pOutFile = fopen(ObjectFilePathName,"wb");
	if ( NULL == pOutFile )
	{
		cout<<"����ļ�����ʧ��["<<strerror(errno)<<"]"<<endl;
		return;
	}
	//д���ļ�ͷ
	fwrite(&fh,sizeof(fh),1,pOutFile);
	//д����ļ�
	for ( int i = 0 ; i < fh.FileCount ; i++ )
	{
		unsigned char *pTmpData = NULL;
		pWorkFile = fopen(fh.FileName[i],"rb");
		if ( NULL == pWorkFile )
		{
			cout<<"�ļ�:"<<fh.FileName[i]<<"�޷���ȡ["<<strerror(errno)<<"]"<<endl;
			fclose(pWorkFile);
			fclose(pOutFile);
			return;
		}
		pTmpData = new unsigned char[fh.FileLen[i]];
		fread(pTmpData,fh.FileLen[i],1,pWorkFile);
		if ( ferror(pWorkFile) )
		{
			cout<<"�ļ�:"<<fh.FileName[i]<<"�޷���ȡ["<<strerror(errno)<<"]"<<endl;
			fclose(pWorkFile);
			fclose(pOutFile);
			return;
		}
		fwrite(pTmpData,fh.FileLen[i],1,pOutFile);
		if ( ferror(pOutFile) )
		{
			cout<<"�ļ�:"<<ObjectFilePathName<<"�޷�д��["<<strerror(errno)<<"]"<<endl;
			fclose(pWorkFile);
			fclose(pOutFile);
			return;
		}
		delete [] pTmpData;
		fclose(pWorkFile);
	}
	fclose(pOutFile);
	cout<<"������"<<endl;
 }

 //���(Ϊ�˽�ʡʱ�䲻д��������,���Ը��������Լ����)
 void MyCab::DoUnCAB(char *CabFilePathName,string path)
 {
	FILE *pCAB = NULL;
	FILE *pWork = NULL;
	pCAB = fopen(CabFilePathName,"rb");
	//���ļ�ͷ
	memset(&fh,0x0,sizeof(fh));
	fread(&fh,sizeof(fh),1,pCAB);
	printCAB();
	//����������ļ��ŵ���ǰĿ¼��
	for ( int i = 0 ; i < fh.FileCount ; i++ )
	{
		unsigned char *pTmpData = NULL;
		pTmpData = new unsigned char[fh.FileLen[i]];
		fread(pTmpData,fh.FileLen[i],1,pCAB);
		//ֻȡ�ļ���,��Ҫ�����ļ���·����
		char tmpFileName[MAX_PATH];
		char *ptmpC = fh.FileName[i] + strlen(fh.FileName[i]);
		while( '\\' != *ptmpC)
		{
			ptmpC--;
		 }
		memset(tmpFileName,0x0,sizeof(tmpFileName));
		strcpy(tmpFileName,ptmpC);
		//ȡCAB�ļ�·��
		char tmpPathName[MAX_PATH];
		memset(tmpPathName,0x0,sizeof(tmpPathName));
		strcpy(tmpPathName,path.c_str());
		ptmpC = tmpPathName + strlen(tmpPathName);
		while('\0' != *ptmpC)
		{
			ptmpC--;
		}
		ptmpC++;
		*ptmpC = '\0';
		strcat(tmpPathName,tmpFileName);
		pWork = fopen(tmpPathName,"wb");
		fwrite(pTmpData,fh.FileLen[i],1,pWork);
		fclose(pWork);
		delete [] pTmpData;
	}
	fclose(pCAB);
 }

 //��ʾ������ļ���Ϣ
 void MyCab::printCAB()
 {
	cout<<"�ļ�����Ϣ����:"<<endl;
	cout<<"�ļ�����:"<<fh.FileCount<<endl;
	for ( int i = 0 ; i < fh.FileCount ; i++ )
	{
		cout<<fh.FileName[i]<<"\t\t\t\t"<<fh.FileLen[i]<<"�ֽ�"<<endl;
	}
 }

