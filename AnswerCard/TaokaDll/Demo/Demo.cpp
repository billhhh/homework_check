// Demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../Taoka/ACStructs.h"
#include "../Taoka/MarkAC.h"
#include "../XmlIO/XmlIO.h"
#include "Xml.h"
#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <string>
#include <fstream>
#include <atlimage.h>
#include <cstring>
// #define _CRTDBG_MAP_ALLOC 
// #include<stdlib.h> 
// #include<crtdbg.h> 
// #include "debug_new.h"

using namespace std;
using namespace cv;
#pragma comment(lib,"../debug/Taoka.lib")
#pragma comment(lib,"../debug/XmlIO.lib")
#pragma comment(lib,"../debug/XmlIoDll.lib")

IplImage* hBitmap2Ipl(HBITMAP hBmp)
{
	BITMAP bmp;

	::GetObject(hBmp,sizeof(BITMAP),&bmp);

	int nChannels = bmp.bmBitsPixel == 1 ? 1 : bmp.bmBitsPixel/8 ;
	int depth = bmp.bmBitsPixel == 1 ? IPL_DEPTH_1U : IPL_DEPTH_8U;

	IplImage* img = cvCreateImageHeader( cvSize(bmp.bmWidth, bmp.bmHeight)
		, depth, nChannels );

	img->imageData =
		(char*)malloc(bmp.bmHeight*bmp.bmWidth*nChannels*sizeof(char));
	memcpy(img->imageData,(char*)(bmp.bmBits),bmp.bmHeight*bmp.bmWidth*nChannels);
	cvNamedWindow("aa",1);
	cvShowImage("aa",img);
	cvWaitKey();
	return img;
}

IplImage* hBitmapToIpl(HBITMAP hBmp)   
{   
	BITMAP bmp;    
	GetObject(hBmp,sizeof(BITMAP),&bmp);    

	// get channels which equal 1 2 3 or 4    
	// bmBitsPixel :   
	// Specifies the number of bits    
	// required to indicate the color of a pixel.    
	int nChannels = bmp.bmBitsPixel == 1 ? 1 : bmp.bmBitsPixel/8 ;   

	// get depth color bitmap or grayscale   
	int depth = bmp.bmBitsPixel == 1 ? IPL_DEPTH_1U : IPL_DEPTH_8U;    


	// create header image   
	IplImage* img = cvCreateImage(cvSize(bmp.bmWidth,bmp.bmHeight),depth,nChannels);   

	// allocat memory for the pBuffer   
	BYTE *pBuffer = new BYTE[bmp.bmHeight*bmp.bmWidth*nChannels];    

	// copies the bitmap bits of a specified device-dependent bitmap into a buffer   
	GetBitmapBits(hBmp,bmp.bmHeight*bmp.bmWidth*nChannels,pBuffer);    

	// copy data to the imagedata   
	memcpy(img->imageData,pBuffer,bmp.bmHeight*bmp.bmWidth*nChannels);   
	delete pBuffer;    

	// create the image   
	IplImage *dst = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1); 
	//cvCvtColor(img, dst, CV_RGB2GRAY);

	// convert color 
	if (img->nChannels==3)
	{
		cvCvtColor(img,img,CV_BGRA2BGR);
	}
//	cvReleaseImage(&img); 
	return img;   
}  
unsigned long method(unsigned  long  x)
{
	x=(x & 0x55555555)+(x>>1&0x55555555);
	x=(x & 0x33333333)+(x>>2&0x33333333);
	x=(x & 0x0f0f0f0f)+(x>>4&0x0f0f0f0f);
	x=(x & 0x00ff00ff)+(x>>8&0x00ff00ff);
	x=(x & 0x0000ffff)+(x>>16&0x0000ffff);
	return x;
}


int _tmain(int argc, _TCHAR* argv[])
{
//	_CrtDumpMemoryLeaks();
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
	  _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	//int tmpFlag = _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG );

	//tmpFlag |= _CRTDBG_LEAK_CHECK_DF;

	//_CrtSetDbgFlag( tmpFlag );
 
	  
	  getchar();
	string xmlpath;
	char *xmlPath,* imgPath;
	int taokaInfoAdr;
	AC_RST *fResult,*rResult;
	int acType;
	AcArgs acargs;
	acargs.areaThreshold=0;
	acargs.sensibilityThresh=0;
	acargs.xRangeScale=10;
	acargs.yRangeScale=10;
	int returnValue=0;
/*	Mat fImg,rImg;*/
//	Mat fImg,rImg;
	/************************************************************************/
	/* �׿�ʶ��    ����                                                     */
	/************************************************************************/

	/******************************����һ�����Ͷ�**********************************/
	
// 	xmlpath="D:\\Projects\\12-24�쳣\\1.xml";
// 	acType=1;
// 	
// 
// 		returnValue=GetTKInfo(xmlpath.c_str(),acType,taokaInfoAdr);
// 		if (returnValue)
// 		{
// 			return -1;
// 		}
// 		string imgpath1="D:\\Projects\\12-24�쳣\\image\\2100_00012_R.jpg";
// 		Mat img=imread(imgpath1,0);
// 		if (img.data==NULL)
// 		{
// 			cout<<"img load error";
// 			exit(0);
// 		}
// 		for(int i=0;i<1;i++)
// 		{
// 			AC_RST *result;
// 		returnValue=MarkTaokaSinglePage(img.data,img.size(),acType,taokaInfoAdr,&result,acargs);
// 		TK_info * tkinfo=(TK_info *)taokaInfoAdr;
// 		cout<<tkinfo->tkinfo[0].pageId<<endl;
// 		freeTkInfo(taokaInfoAdr,acType);
// 		freeResult(result);
// 		cout<<tkinfo->tkinfo.size()<<endl;
// 	}

	/******************************������**********************************/
	//������  ��acType��Ϊ3����
// 	xmlPath="C:\\Users\\luzif\\Desktop\\����ʽ�������\\�հ׿�\\������\\Taoka.xml";
// 	acType=3;
// 	returnValue=GetTKInfo(xmlPath,acType,&taokaInfoAdr);
// 	if (returnValue)
// 	{
// 		return -1;
// 	}
// 	imgPath="D:\\1-�����ĵ�\\�½��ļ���\\���Լ�\\������\\��ѧ\\testSet\\1_1.jpg";
// 	img=imread(imgPath,0);
// 	if (img.data==NULL)
// 	{
// 		cout<<"img load error";
// 		exit(0);
// 	}
// 	returnValue=MarkTaokaSinglePage(img.data,img.size(),acType,taokaInfoAdr,&result,acargs);
// 
// 	freeTkInfo(taokaInfoAdr,acType);
// 	freeResult(&result);

// 	/************************************************************************/
// 	/* �׿�ʶ��   ˫��                                                      */
// 	/************************************************************************/
// 	
// 	
// 	/******************************����һ�����Ͷ�**********************************/
// 	
		
	xmlPath="17_1.xml";
	//	xmlPath="I:\\��ʶ��ͼƬ\\cardformat.xml";
	acType=3;
	returnValue=GetTKInfo(xmlPath,acType,taokaInfoAdr);
	if (returnValue)
	{
		cout<<"read error"<<endl;
		getchar();
		return -1;
	}
	TK_info3 *tkinfo=(TK_info3 *)taokaInfoAdr;
	Cum_TK_info3 *cumtkinfo;
	GetCum_TkInfo3(taokaInfoAdr,&cumtkinfo);
	cout<<1<<endl;
	//getchar();
	freeCumTkInfo3(cumtkinfo);
	cout<<2<<endl;
	
		
// 	tkinfo->tkinfo[0].acinfo[0].refPoint.push_back(Rect(1,2,3,4));
// 	tkinfo->tkinfo[0].acinfo[0].refPoint.push_back(Rect(2,4,3,4));
// 	tkinfo->tkinfo[0].acinfo[1].refPoint.push_back(Rect(1,2,3,4));
// 	tkinfo->tkinfo[0].acinfo[1].refPoint.push_back(Rect(2,4,3,4));
// 	PerMarker_info perMark;
// 	perMark.id=1;
// 	perMark.pos=Rect(7,8,9,1);
// 	tkinfo->tkinfo[0].acinfo[0].xMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[0].xMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[1].xMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[1].xMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[0].yMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[0].yMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[1].yMarker.push_back(perMark);
// 	tkinfo->tkinfo[0].acinfo[1].yMarker.push_back(perMark);
// 	XmlIo xml;
// 	xml.Write("I:\\���⿨��Ŀ\\������\\test1.xml",*tkinfo);
// 	string fImgPath="D:\\Projects\\12-24�쳣\\12817_00053_F.jpg";
// 	string rImgPath="D:\\Projects\\12-24�쳣\\12817_00053_R.jpg";




	//char * fImgPath="I:\\���⿨��Ŀ\\������\\20140219\\pic200\\100014014320431_1.jpg";
	//char * rImgPath="I:\\���⿨��Ŀ\\������\\20140219\\pic200\\100014014320436_1.jpg";
	char * fImgPath="I:\\���⿨��Ŀ\\������\\����3��ƫ\\00001_F.jpg";
	char * rImgPath="I:\\���⿨��Ŀ\\������\\cet4_sberror_0314\\1568_00021_R.jpg";
//	returnValue=MarkTaokaSPage(fImgPath.c_str(),acType,taokaInfoAdr,&fResult,acargs);
//	returnValue=MarkTaokaDPage(fImgPath.c_str(),rImgPath.c_str(),acType,taokaInfoAdr,&fResult,&rResult,acargs);
//	cout<<returnValue<<endl;
	//string path="D:\\Projects\\����ʶ��_1230\\time.txt";
	//string wpath="D:\\Projects\\����ʶ��_1230\\error5.txt";
	//fstream imgread(path,ios::in);
	//ofstream imgwrite(wpath,ios::app);
	//if (!imgread)
	//{
	// 	cout<<"txt�ļ���ȡ�쳣��"<<endl;
	// 	getchar();
	// 	imgread.close();
	//	exit(0);
	//}
	//while(getline(imgread,fImgPath))
	//{
 //		getline(imgread,rImgPath);
	/*	Mat fImg=imread(fImgPath,0);
		if (fImg.data==NULL)
		{
			cout<<"fimg load error";
			exit(0);
		}
		Mat rImg=imread(rImgPath,0);
		if (rImg.data==NULL)
		{
			cout<<"rimg load error";
			exit(0);
		}*/
	/*CString fimgp=fImgPath;
	CString rimgp=rImgPath;
	CImage fcimage;
	fcimage.Load(fimgp);
	HBITMAP fhandle = fcimage.Detach();

	CImage rcimage;
	rcimage.Load(rimgp);
	HBITMAP rhandle = rcimage.Detach();

	IplImage* fimage = hBitmapToIpl(fhandle);
	IplImage* rimage = hBitmapToIpl(rhandle);*/
// 	cvNamedWindow("aaa",1);
// 	cvShowImage("aaa",fimage);
// 	cvWaitKey();
	//Mat fImg(fimage,true);
	//Mat rImg(rimage,true);
	//if (rImg.channels==3)
	//	cvtColor(img,img,CV_RGB2GRAY);
 	//imshow("fimg",fImg);
 	//imshow("rimg",rImg);
 	//cvWaitKey();

// int *a=new int[2];
// 	int i=0;
// 	while(i<1000)
// 	{
// //  	returnValue=MarkTaokaSPage(fImgPath,acType,taokaInfoAdr,&fResult,acargs);
// //  	freeResult(fResult);
// //  	freeResult(rResult);
// 		returnValue=GetTKInfo(xmlPath,acType,taokaInfoAdr);
// 		if (returnValue)
// 		{
// 			return -1;
// 		}
// 		freeTkInfo(taokaInfoAdr,acType);
// 		i++;
// 	}



/*
	freeTkInfo(taokaInfoAdr,acType);*/

	//	cout<<fImgPath<<":"<<returnValue<<endl;
	//	if(returnValue)
	//	{
 //			imgwrite<<fImgPath<<endl;
 //			imgwrite<<rImgPath<<endl;
	//	}else

	//	{
	//		freeResult(fResult);
	//		freeResult(rResult);
	//	}
	//}
	//freeTkInfo(taokaInfoAdr,acType);
	//imgread.close();
	//imgwrite.close();
	//

	/******************************������**********************************/
	//������  ��acType��Ϊ3����
// 	xmlPath="F:\\360����\\1-���⿨\\����\\����3ͼƬ\\�հ׿�\\��ѧA4200dpi\\1.xml";
// 	acType=3;
// 	returnValue=GetTKInfo(xmlPath,acType,taokaInfoAdr);
// 	if (returnValue)
// 	{
// 		return -1;
// 	}
// 	string fImgPath="D:\\1-�����ĵ�\\�½��ļ���\\���Լ�\\������\\��ѧ\\testSet\\1_1.jpg";
// 	string rImgPath="D:\\1-�����ĵ�\\�½��ļ���\\���Լ�\\������\\��ѧ\\1\\2_2.jpg";
// 	fImg=imread(fImgPath,0);
// 	if (fImg.data==NULL)
// 	{
// 		cout<<"fimg load error";
// 		exit(0);
// 	}
// 	rImg=imread(rImgPath,0);
// 	if (rImg.data==NULL)
// 	{
// 		cout<<"rimg load error";
// 		exit(0);
// 	}
// 	returnValue=MarkTaokaDoublePage(fImg.data,fImg.size(),rImg.data,rImg.size(),acType,taokaInfoAdr,&fResult,&rResult,acargs);
// 
// 	freeTkInfo(taokaInfoAdr,acType);
// 	freeResult(fResult);
// 	freeResult(rResult);

// 
// 	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
// 	_CrtDumpMemoryLeaks();
getchar();
	return 0;
}

