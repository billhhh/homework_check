#pragma once

#ifdef _DLL_XMLIO
#define DLL_XMLIODLL_API   __declspec(dllexport) __stdcall
#else
#define DLL_XMLIODLL_API   __declspec(dllimport) 
#endif
//��ȡ����ʽ����
extern "C" int DLL_XMLIODLL_API GetACInfo(char * filename,int actype,int &acinfoAddress);
//��ȡ�׿�����ʽ����
extern "C" int DLL_XMLIODLL_API GetTKInfo(const char * filename,int &actype,int &tkinfoAddress);
extern "C" void DLL_XMLIODLL_API freeACInfo(int acinfoAddress,int actype);//�ͷ��⿨��ʽ�ṹ��
extern "C" void DLL_XMLIODLL_API freeTkInfo(int tkinfoAddress,int actype);//�ͷ��׿���ʽ�ṹ��
