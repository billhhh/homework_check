
#include "ACZip.h"
#include <iostream>
using namespace std;

int	ACUnZip(string zipname, string path){
	char zipName[MAX_PATH];
	strcpy(zipName,zipname.c_str());
	//��������
	MyCab umc;
	//ִ�н��
	umc.DoUnCAB(zipName,path);
	cout<<"������"<<endl;
	return 0;
}