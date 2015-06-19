#include "StringCompare.h"

double stringCompare(string hwNum, StudentObj checkStu,StudentObj otherStu,FileObj checkFile,FileObj otherFile, int flag)
{
	double sim;
	int copy_int, copy_int2;
	string str1,str2;
// 	str1 = "#include <stdio.h>#include <stdlib.h>#include <climits>void swap(int &a, int &b){int temp = a;	a = b;	b = temp;}void Max_HeapIFY(int data[],int length,int i);void Build_Max_Heap(int data[],int length);void HeapSort(int data[],int length);int main(){	int i;	int data[11] = {INT_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(data,10);for(i=1;i<11;++i)printf(%d ,data[i]);printf(\n);return 0;}void Max_HeapIFY(int data[],int length,int i){int left = 2 * i;int right = left + 1;	int largest;if(left <= length && data[left] > data[i])largest = left;else	largest = i;if(right <= length && data[right] > data[largest])	largest = right;if(largest != i){swap(data[largest], data[i]);		Max_HeapIFY(data, length, largest);}}void Build_Max_Heap(int data[],int length){int i;	for(i=length/2;i>0;i--)	Max_HeapIFY(data,length,i);}void HeapSort(int data[],int length){Build_Max_Heap(data,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	int ix =length;	while(ix > 1)	{swap(data[1], data[ix]);-- ix;	Max_HeapIFY(data, ix, 1);//��ʣ��Ĳ��ֹ��������}}";
// 	str1 = "#include <stdio.h>#include <stdlib.h>#include <climits>void swap(long &a, long &b){long temp = a;	a = b;	b = temp;}void Max_HeapIFY(long date[],long length,long i);void Build_Max_Heap(long date[],long length);void HeapSort(long date[],long length);long main(){	long i;	long date[11] = {long_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(date,10);for(i=1;i<11;++i)prlongf(%d ,date[i]);prlongf(\n);return 0;}void Max_HeapIFY(long date[],long length,long i){long left = 2 * i;long right = left + 1;	long largest;if(left <= length && date[left] > date[i])largest = left;else	largest = i;if(right <= length && date[right] > date[largest])	largest = right;if(largest != i){swap(date[largest], date[i]);		Max_HeapIFY(date, length, largest);}}void Build_Max_Heap(long date[],long length){long i;	for(i=length/2;i>0;i--)	Max_HeapIFY(date,length,i);}void HeapSort(long date[],long length){Build_Max_Heap(date,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	long ix =length;	while(ix > 1)	{swap(date[1], date[ix]);-- ix;	Max_HeapIFY(date, ix, 1);//��ʣ��Ĳ��ֹ��������}}";
// 	str2 = "kfd#include <stdio.h>#include <stdlib.h>#include <climits>void swap(long &a, long &b){long temp = a;	a = b;	b = temp;}void Max_HeapIFY(long date[],long length,long i);void Build_Max_Heap(long date[],long length);void HeapSort(long date[],long length);long main(){	long i;	long date[11] = {long_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(date,10);for(i=1;i<11;++i)prlongf(%d ,date[i]);prlongf(\n);return 0;}void Max_HeapIFY(long date[],long length,long i){long left = 2 * i;long right = left + 1;	long largest;if(left <= length && date[left] > date[i])largest = left;else	largest = i;if(right <= length && date[right] > date[largest])	largest = right;if(largest != i){swap(date[largest], date[i]);		Max_HeapIFY(date, length, largest);}}void Build_Max_Heap(long date[],long length){long i;	for(i=length/2;i>0;i--)	Max_HeapIFY(date,length,i);}void HeapSort(long date[],long length){Build_Max_Heap(date,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	long ix =length;	while(ix > 1)	{swap(date[1], date[ix]);-- ix;	Max_HeapIFY(date, ix, 1);//��ʣ��Ĳ��ֹ��������}}";

	str1=checkFile.getContent();
	str2=otherFile.getContent();

	//cout<<"str1 == "<<str1<<endl;


	string filePath;

	filePath = "c:\\StrCompare\\";
	filePath.append(hwNum);
	filePath.append("\\");
	filePath.append(checkStu.studentId);
	filePath.append("\\");
	filePath.append(otherStu.studentId);

	filePath.append("-");
	filePath.append(checkFile.getFileName());
	filePath.append(".");
	filePath.append(checkFile.getFileType());
	filePath.append("-");
	filePath.append(otherFile.getFileName());
	filePath.append(".");
	filePath.append(otherFile.getFileType());
	filePath.append("@.txt");//����β����


	//�ж��ļ��Ƿ��Ѿ����ڣ��������������ʶ
	fstream _isFile;
	_isFile.open(filePath,ios::in);
	if(_isFile)
	{
		//�ļ��Ѿ����ڣ������л����ˣ�������
		cout<<filePath<<"���л��棬����\n"<<endl;
		return -1;
	}
	cout<<"filePath: "<<filePath<<endl;
	//system("pause");

	//��������㷨
	if(flag == 0)
	{
		copy_int = 30;
		copy_int2= 31;
	}
	else if(flag == 1)
	{
		copy_int = 80;
		copy_int2= 81;
	}

	RKR_GST_Match rkr_gst(str1, str2, copy_int);
	rkr_gst.beginMatch(copy_int2);
	int sum = 0;
	for (vector<Match>::iterator it = rkr_gst.matches.begin(); it != rkr_gst.matches.end(); ++it)
	{
		sum += it->len;
	}
	sim=(sum * 2.0 /(str1.length() + str2.length()));
	fstream file;
	file.open(filePath, ios::out );
	file<<sim<<endl; //�ļ��з�����ʶ��
	for (vector<Match>::iterator it = rkr_gst.matches.begin(); it != rkr_gst.matches.end(); ++it)
	{
		file<<it->m<<"-"<<it->n<<"-"<<it->len<<"\n";
	}

	cout<<"\n\nthe length  of the first string is : "<<str1.length()<<"\n";	
	cout<<"the length  of the second string is : "<<str2.length()<<"\n";
	cout<<"The total similar length of these two strings is : " <<sum<<"\n";
	cout<<"The similarity of the two string is : " <<(sum * 2.0 /(str1.length() + str2.length()) )<<"\n\n";
	

	//system("pause");
	return sim;
}




//ֻ������ֻ��
int testStringCompare(StudentObj otherStu,FileObj checkFile,FileObj otherFile)
{
	string str1,str2;
	// 	str1 = "#include <stdio.h>#include <stdlib.h>#include <climits>void swap(int &a, int &b){int temp = a;	a = b;	b = temp;}void Max_HeapIFY(int data[],int length,int i);void Build_Max_Heap(int data[],int length);void HeapSort(int data[],int length);int main(){	int i;	int data[11] = {INT_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(data,10);for(i=1;i<11;++i)printf(%d ,data[i]);printf(\n);return 0;}void Max_HeapIFY(int data[],int length,int i){int left = 2 * i;int right = left + 1;	int largest;if(left <= length && data[left] > data[i])largest = left;else	largest = i;if(right <= length && data[right] > data[largest])	largest = right;if(largest != i){swap(data[largest], data[i]);		Max_HeapIFY(data, length, largest);}}void Build_Max_Heap(int data[],int length){int i;	for(i=length/2;i>0;i--)	Max_HeapIFY(data,length,i);}void HeapSort(int data[],int length){Build_Max_Heap(data,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	int ix =length;	while(ix > 1)	{swap(data[1], data[ix]);-- ix;	Max_HeapIFY(data, ix, 1);//��ʣ��Ĳ��ֹ��������}}";
// 	str1 = "#include <stdio.h>#include <stdlib.h>#include <climits>void swap(long &a, long &b){long temp = a;	a = b;	b = temp;}void Max_HeapIFY(long date[],long length,long i);void Build_Max_Heap(long date[],long length);void HeapSort(long date[],long length);long main(){	long i;	long date[11] = {long_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(date,10);for(i=1;i<11;++i)prlongf(%d ,date[i]);prlongf(\n);return 0;}void Max_HeapIFY(long date[],long length,long i){long left = 2 * i;long right = left + 1;	long largest;if(left <= length && date[left] > date[i])largest = left;else	largest = i;if(right <= length && date[right] > date[largest])	largest = right;if(largest != i){swap(date[largest], date[i]);		Max_HeapIFY(date, length, largest);}}void Build_Max_Heap(long date[],long length){long i;	for(i=length/2;i>0;i--)	Max_HeapIFY(date,length,i);}void HeapSort(long date[],long length){Build_Max_Heap(date,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	long ix =length;	while(ix > 1)	{swap(date[1], date[ix]);-- ix;	Max_HeapIFY(date, ix, 1);//��ʣ��Ĳ��ֹ��������}}";
// 	str2 = "kfd#include <stdio.h>#include <stdlib.h>#include <climits>void swap(long &a, long &b){long temp = a;	a = b;	b = temp;}void Max_HeapIFY(long date[],long length,long i);void Build_Max_Heap(long date[],long length);void HeapSort(long date[],long length);long main(){	long i;	long date[11] = {long_MAX,5,3,17,10,84,19,6,22,9,35};	HeapSort(date,10);for(i=1;i<11;++i)prlongf(%d ,date[i]);prlongf(\n);return 0;}void Max_HeapIFY(long date[],long length,long i){long left = 2 * i;long right = left + 1;	long largest;if(left <= length && date[left] > date[i])largest = left;else	largest = i;if(right <= length && date[right] > date[largest])	largest = right;if(largest != i){swap(date[largest], date[i]);		Max_HeapIFY(date, length, largest);}}void Build_Max_Heap(long date[],long length){long i;	for(i=length/2;i>0;i--)	Max_HeapIFY(date,length,i);}void HeapSort(long date[],long length){Build_Max_Heap(date,length);//����һ�����飬��ʵ�ֶ�������ʱ���Ա��� ix ����־��δ�ź���Ĳ��֡�	long ix =length;	while(ix > 1)	{swap(date[1], date[ix]);-- ix;	Max_HeapIFY(date, ix, 1);//��ʣ��Ĳ��ֹ��������}}";
	str1 = "��|��Ŀ|:|����|matlab| |c|-|mex|��|άŵͼ|ʵ��|��|ѧԺ|��|���|ѧԺ|��|��ʦ|��|������|��|ѧ��|����|��|����|��|ѧ��|��|201421031134|��| | | | | |��|��|��|��ִ���ļ�|��|ʹ��|˵��|��|��¼|��|��|�������|��|����|	|����|matlab| |c|-|mex|��|άŵͼ|ʵ��|��|���|��|Ŀ��|	|1.| | |����|���|���ݽṹ|��|Ӧ��|��ѧ|�㷨|��д|άŵͼ|����|��|��|��|����|��|ͼ�λ�|����|��|��|2.| | |��|��ѧ|��|c|����|֪ʶ|��|matlab|���|����|��|����|��|���|ʵ��|����|��|��|3.| | |����|�ۺ�|����|רҵ֪ʶ|��|���|ʵ��|����|��|����|��|��|���|��|����|	|pc| |+| |win|7|��|��|��װ|vs|2010|��|matlab|��|��������|��|��|����|��|Ҫ��|	|��|c|����|��д|άŵͼ|�㷨|��|��|ʵ��|���|���|��|����ʽ|����|��|���|���|����|��|��|��|�Ҽ�|����|����|��|��|��|ʵ��|����ʽ|����|��|c|�ļ�|��|c|-|mex|�ӿ�|�Խ�|��|��|һ|��|����|����|��|Ϊ��|������|��|���|��ʦ|����|��|άŵͼ|��д|����|��|��|����|��|�ܶ�|����|��|��|�����|��|��|����|����|����|�㷨|���|��|����|��|һ|��|��|��|һ��|��|����|��|����|��|����|ͼ|����|n|��|��|��|���|��|ÿ��|��|����|һ��|��Դ|��|���|��|��|n|��|��|ͬʱ|��ȼ|��|����|��ͬ|��|�ٶ�|��|����|����|����|��|��ô|ȼ��|Ϩ��|����|�γ�|��|ͼ|����|voronoi|ͼ|��|��|��|��|��|����|��|����|��|һ��|����|��|ͨ��|��|���|άŵͼ|����|�ռ�|����|ƽ��|��|��|����|��|��|һ��|����|���|��|����|��|��|����|��|���|��|��|�ϸ�|һЩ|��|����|��|����|һ��|�ռ�| |m|��|�ٶ�|����|����|��|һ��|���|��| |s|��|s| |��|��|����|һ��|���|��|����|��|��|��Χ����|����|����|�ռ�| |m| |��|��|��|��|ʩ��Ӱ��|��|����|�ռ�| |m| |��|��|һ��|��|��|��|��| |s| |��|����|��|����|��|����|��|һ|���| |p| |��|Ӱ��|��Ϊ|ǿ��|��|��ô|��|��|��|��|��|����|�˽�|��| |p| |��|һ��|������|��|��|��|��|�㷨|���|��|����|��|��Ȼ|Ҫ|���|�㷨|���|άŵͼ|����|��|��|��Ҫ|��|άŵͼ|��|����|����|��һ��|��|����|��|��|����|��|άŵͼ|��|�γ�|������|����|������|��|��|����|����|��|����|����|��|ת��|Ϊ|��|������|����|��|��|����|����|delaunay|����|��|��|�㷨|����|������|����|��|����|��|delaunay|��|��|����|����|һЩ|����|��|����|��|��|1.|��|�ӽ�|��|��|���|��|����|�γ�|������|��|��|��|�߶�|(|������|��|��|)|��|��|�ཻ|��|��|2.|Ψһ��|��|����|��|����|�δ�|��ʼ|����|��|����|��|��|�õ�|һ��|��|���|��|��|3.|������|��|����|����|����|������|�γ�|��|͹|�ı���|��|�Խ���|���|����|����|�Ļ�|��|��ô|����|������|����|�ڽ�|��|��С|��|�Ƕ�|����|���|��|��|4.|��|����|��|���|��|������|��|��|ÿ��|������|��|��С|��|����|����|����|��|��|delaunay|������|��|����|�õ�|��|��ֵ|���|��|��|5.|������|��|����|��|ɾ��|��|�ƶ�|ĳ|һ��|����|ʱ|ֻ|��|Ӱ��|�ٽ�|��|������|��|��|6.�ĵ�|��ͬ|Բ|����|��|��|��|1|��|ʧ��|��|����|��|��|��ʼ|����|����|����|д��|��|һ��|������|��|��|��|����|�㷨|��|�㷨|��|˼��|��|��|��|�û�|����|��|����|��|����|ÿ|����|��|��|�γ�|һ��|������|��|Ȼ��|�ж�|ÿ��|������|��|��ȥ|����|��|����|��|�ǲ���|ͬ|Բ|��|���|ͬһ��|Բ|��|ȥ��|���|������|��|��|���|�㷨|����|����|�ó�|��|��ȷ��|��|��ӹ����|��|��|����|�㷨|��|Ч��|���˿���|��|�㷨|��|����|����|��|���|��|����|��|Ѹ��|��|�ó�|��|��|����|һ��|����|��|�����ٶ�|��|����|����|��|��|����|��|25��|��|��Ҫ|��|��ʮ��|��|��|��|ԭ��|Ҳ|��|��|��|��Ϊ|���|�㷨|��|����|��|1|��|����|����|������|��|��|��|һ��|o|��|n|^|3|��|��|һ��|���Ӷ�| | |2|��|�ж�|ÿ��|������|��|��Ч��|��|һ��|o|��|n|^|2|��|��|���Ӷ�|��|����|���Ӷ�|��|��|��|��|��|��|��|2|��|����|����|��|��ȡ|����|��|ʧ��|��|����|֮��|��|��|˼��|��|����|һ��|�Ƚ�|��Ч|��|�㷨|��|�㷨|��|����|����|��|��|��|1|��|����|һ��|����|������|��|����|����|ɢ|��|��|��Щ|ɢ|��|��|�û�|һ����|����|��|��|��|����|������|����|��|��|2|��|��|��|����|��|ɢ|��|����|����|��|��|������|����|��|�ҳ�|���Բ|����|����|��|��|������|��|��Ϊ|��|��|��|Ӱ��|������|��|��|����|��|һ��|��|��Ҫ|��|ϸ��|����|��|��|����|Ӱ��|������|��|��|����|һ��|��|����|��|ɾ��|Ӱ��|������|��|����|��|��|��|����|��|ͬ|Ӱ��|������|��|ȫ��|����|��������|��|���|һ����|��|delaunay|������|����|��|��|����|��|��|3|��|�Ż�|������|��|��|��|�γ�|��|������|����|delaunay|������|����|��|��|4|��|ѭ��|ִ��|����|��2��|��|ֱ��|����|ɢ|��|����|���|��|��|5|��|����|����|��|�γ�|άŵͼ|��|��|��|һ|�㷨|��|�ؼ�|��|��2��|ͼʾ|����|��|��|��|3|��|�㷨|���Ӷ�|����|��|�㷨|��Ҫ|��|��ʱ|����|��|��|��2��|��|�ҳ�|��|����|��|��|Ӱ��|������|��Ҫ|o|��|n|��|��|���Ӷ�|��|��|����|Ӱ��|������|��|��|����|һ��|��|����|��|ɾ��|Ӱ��|������|��|����|��|���|��Ҫ|o|��|n|^|2|��|��|���Ӷ�|��|�ۺ�|��˵|��|���|�㷨|��|ʱ��|���Ӷ�|��|o|��|n|^|2|��|��|��|��|��|����|����|ʵ��|��|��|1|��|����|����|��|Ϊ��|��������|��|��|����|��|�ٶ�|��|��|ʹ��|��|ansi| |c|��д|��|����|���ݽṹ|��|��|�Լ�|����|��|û��|ʹ��|�κ�|c|+|+|��|stl|����|ģ��|��|��|ʹ��|����|����|��|��Ȼ|��|ʹ��|��һЩ|�ռ�|��|����|��|��|����|�±�|����|��|��ʽ|��|��|o|��|1|��|ʱ��|��|ֱ��|��λ|��|�ٶ�|��ȷ|�õ�|��|����|��|����|��|��|����|����|��|����|����|��|��Ȼ|��|�Լ�|����|��|���ݽṹ|��|����|��|����|�ջ�|����|��|��|ʵ��|����|��|��|����|��|����|˵��|����|��|��| | |1|��|�ṹ|��|����|��|typedef| |struct| | | | | | | | |x|;|	|	|	| | | | |y|;|��|}|point|;|��|typedef| |struct| | | | | | | | | | | | |start|,|end|;|��|	| |left|;|��|	|int| |right|;|��|}|edge|;|��|typedef| |struct|	| |a|,|b|,|c|;|��|	| |center|;|��|	|double| |radius|;| |isvalid|;| | |2|��|����|����|��|triangle| |triangle|[|]|;| | | |point|[|]|;|	| | | |pcnt|=|0|;| |tricnt|=|0|;| |tmpafftri|[|]|;| | | |affectedtricnt|=|0|;| | | | |affedgestart|[|]|;| |affedgeend|[|]|;| | | |outtri|[|]|;| | | |outtricnt|=|0|;| | | | |edge|[|]|;| | | |edgecnt|=|0|;|	| |init|(|)|;|	|	|	|	| |distance|(|point| |a|,|point| |b|)|;|	| | | |minicircle|(|point| |*|p|,|point|&amp;| | | |center|,|double|&amp;| | | |radius|)|;| | | | |freshtri|(|int| |sub|)|;| | | | | | | | | | | | |isaffected|(|int| |n|,|int| |i|)|;| | | | | | | | |storeaffedge|(|int| |n|)|;| | | | | | | | | |pointprocess|(|int| |n|)|;|	|	| | | | | |storenewtri|(|int| |n|)|;| | | | | | | | | | |offsuptri|(|)|;| | | | | | | | | | | | | | | | |initedge|(|)|;|	|	|	| | | | | |findedgetri|(|)|;| | | | | | | | | | | | | | |mexfunction|(|int| |nlhs|,| |mxarray| |*|plhs|[|]|,| |int| |nrhs|,| |const| |mxarray| |*|prhs|[|]|)|��|����|˵��|��|����|c|�ļ�|��|matlab|�ӿ�|��|ʵ��|��|����|˵��|��|��|int| |nlhs|:|����|���|����|��|����|��|mxarray| |*|plhs|[|]|:|���|����|Ϊ|mxarray|�ṹ|��|ָ��|����|����|��|int| |nrhs|:|����|����|����|��|����|��|const| |mxarray| |*|prhs|[|]|:|����|����|Ϊ|mxarray|�ṹ|��|ָ��|����|����|��|2|��|pn|=| |mxgetpr|(|prhs|[|0|]|)|��|����|˵��|��|��ȡ����|����|��|ʵ��|��|��|ָ��|��|��|pn|��|����|��ȡ|����|����|��|(|3|)| |plhs|[|0|]| |=| |mxcreatedoublematrix|(|outtricnt|*|3|*|2|,| |1|,| |mxreal|)|��| | | |y| |=| |mxgetpr|(|plhs|[|0|]|)|;|��|����|˵��|��|��ȡ����|����|��|ʵ��|��|��|ָ��|��|��|y|��|plhs|[|1|]| |=| |mxcreatedoublematrix|(|1|,| |1|,| |mxreal|)|;|��|y|1| |=| |mxgetpr|(|plhs|[|1|]|)|;| | | |=| |mxcreatedoublematrix|(|edgecnt|*|2|*|2|,| |1|,| |mxreal|)|;|	| | |=| |mxgetpr|(|plhs|[|2|]|)|;| | | |=| |mxcreatedoublematrix|(|1|,| |1|,| |mxreal|)|;|��|y|3| |=| |mxgetpr|(|plhs|[|3|]|)|;| | | |r|2013|a| |win|64|��|����|��|��|ֱ��|��|��|����|��|��|��Ҫ|��|matlab| |r|2013|a| |win|64|��|runtime|��|��|��|��|��|��|����|��|��|����|����|��|��|ֱ��|��װ|matlab| |r|2013|a| |win|64| |bit|��|����|��|ִ��|mst|��|����|��|dots|.|exe|����|ֱ��|��|matlab|����|��|run| |dots|.|m|�ļ�|��|����|��|��|��װ|mcrinstaller|.|exe|��|һ��|Ҫ|matlab| |r|2013|a| |win|64| |bit|��|��|Ȼ��|��|����|����|mst|��|����|��|dots|.|exe|��|��|��|���|û��|mcrinstaller|.|exe|��|����|��|413|mb|��|��|��|�Ѿ�|��|����|360|����|��|��ַ|��|��|http|:| | |��ȡ|��| |1249|��|�ṩ|����|��|��|2|��|";
	str2 = "asf��|��Ŀ|:|����|matlab| |c|-|mex|��|άŵͼ|ʵ��|��|ѧԺ|��|���|ѧԺ|��|��ʦ|��|������|��|ѧ��|����|��|����|��|ѧ��|��|201421031134|��| | | | | |��|��|��|��ִ���ļ�|��|ʹ��|˵��|��|��¼|��|��|�������|��|����|	|����|matlab| |c|-|mex|��|άŵͼ|ʵ��|��|���|��|Ŀ��|	|1.| | |����|���|���ݽṹ|��|Ӧ��|��ѧ|�㷨|��д|άŵͼ|����|��|��|��|����|��|ͼ�λ�|����|��|��|2.| | |��|��ѧ|��|c|����|֪ʶ|��|matlab|���|����|��|����|��|���|ʵ��|����|��|��|3.| | |����|�ۺ�|����|רҵ֪ʶ|��|���|ʵ��|����|��|����|��|��|���|��|����|	|pc| |+| |win|7|��|��|��װ|vs|2010|��|matlab|��|��������|��|��|����|��|Ҫ��|	|��|c|����|��д|άŵͼ|�㷨|��|��|ʵ��|���|���|��|����ʽ|����|��|���|���|����|��|��|��|�Ҽ�|����|����|��|��|��|ʵ��|����ʽ|����|��|c|�ļ�|��|c|-|mex|�ӿ�|�Խ�|��|��|һ|��|����|����|��|Ϊ��|������|��|���|��ʦ|����|��|άŵͼ|��д|����|��|��|����|��|�ܶ�|����|��|��|�����|��|��|����|����|����|�㷨|���|��|����|��|һ|��|��|��|һ��|��|����|��|����|��|����|ͼ|����|n|��|��|��|���|��|ÿ��|��|����|һ��|��Դ|��|���|��|��|n|��|��|ͬʱ|��ȼ|��|����|��ͬ|��|�ٶ�|��|����|����|����|��|��ô|ȼ��|Ϩ��|����|�γ�|��|ͼ|����|voronoi|ͼ|��|��|��|��|��|����|��|����|��|һ��|����|��|ͨ��|��|���|άŵͼ|����|�ռ�|����|ƽ��|��|��|����|��|��|һ��|����|���|��|����|��|��|����|��|���|��|��|�ϸ�|һЩ|��|����|��|����|һ��|�ռ�| |m|��|�ٶ�|����|����|��|һ��|���|��| |s|��|s| |��|��|����|һ��|���|��|����|��|��|��Χ����|����|����|�ռ�| |m| |��|��|��|��|ʩ��Ӱ��|��|����|�ռ�| |m| |��|��|һ��|��|��|��|��| |s| |��|����|��|����|��|����|��|һ|���| |p| |��|Ӱ��|��Ϊ|ǿ��|��|��ô|��|��|��|��|��|����|�˽�|��| |p| |��|һ��|������|��|��|��|��|�㷨|���|��|����|��|��Ȼ|Ҫ|���|�㷨|���|άŵͼ|����|��|��|��Ҫ|��|άŵͼ|��|����|����|��һ��|��|����|��|��|����|��|άŵͼ|��|�γ�|������|����|������|��|��|����|����|��|����|����|��|ת��|Ϊ|��|������|����|��|��|����|����|delaunay|����|��|��|�㷨|����|������|����|��|����|��|delaunay|��|��|����|����|һЩ|����|��|����|��|��|1.|��|�ӽ�|��|��|���|��|����|�γ�|������|��|��|��|�߶�|(|������|��|��|)|��|��|�ཻ|��|��|2.|Ψһ��|��|����|��|����|�δ�|��ʼ|����|��|����|��|��|�õ�|һ��|��|���|��|��|3.|������|��|����|����|����|������|�γ�|��|͹|�ı���|��|�Խ���|���|����|����|�Ļ�|��|��ô|����|������|����|�ڽ�|��|��С|��|�Ƕ�|����|���|��|��|4.|��|����|��|���|��|������|��|��|ÿ��|������|��|��С|��|����|����|����|��|��|delaunay|������|��|����|�õ�|��|��ֵ|���|��|��|5.|������|��|����|��|ɾ��|��|�ƶ�|ĳ|һ��|����|ʱ|ֻ|��|Ӱ��|�ٽ�|��|������|��|��|6.�ĵ�|��ͬ|Բ|����|��|��|��|1|��|ʧ��|��|����|��|��|��ʼ|����|����|����|д��|��|һ��|������|��|��|��|����|�㷨|��|�㷨|��|˼��|��|��|��|�û�|����|��|����|��|����|ÿ|����|��|��|�γ�|һ��|������|��|Ȼ��|�ж�|ÿ��|������|��|��ȥ|����|��|����|��|�ǲ���|ͬ|Բ|��|���|ͬһ��|Բ|��|ȥ��|���|������|��|��|���|�㷨|����|����|�ó�|��|��ȷ��|��|��ӹ����|��|��|����|�㷨|��|Ч��|���˿���|��|�㷨|��|����|����|��|���|��|����|��|Ѹ��|��|�ó�|��|��|����|һ��|����|��|�����ٶ�|��|����|����|��|��|����|��|25��|��|��Ҫ|��|��ʮ��|��|��|��|ԭ��|Ҳ|��|��|��|��Ϊ|���|�㷨|��|����|��|1|��|����|����|������|��|��|��|һ��|o|��|n|^|3|��|��|һ��|���Ӷ�| | |2|��|�ж�|ÿ��|������|��|��Ч��|��|һ��|o|��|n|^|2|��|��|���Ӷ�|��|����|���Ӷ�|��|��|��|��|��|��|��|2|��|����|����|��|��ȡ|����|��|ʧ��|��|����|֮��|��|��|˼��|��|����|һ��|�Ƚ�|��Ч|��|�㷨|��|�㷨|��|����|����|��|��|��|1|��|����|һ��|����|������|��|����|����|ɢ|��|��|��Щ|ɢ|��|��|�û�|һ����|����|��|��|��|����|������|����|��|��|2|��|��|��|����|��|ɢ|��|����|����|��|��|������|����|��|�ҳ�|���Բ|����|����|��|��|������|��|��Ϊ|��|��|��|Ӱ��|������|��|��|����|��|һ��|��|��Ҫ|��|ϸ��|����|��|��|����|Ӱ��|������|��|��|����|һ��|��|����|��|ɾ��|Ӱ��|������|��|����|��|��|��|����|��|ͬ|Ӱ��|������|��|ȫ��|����|��������|��|���|һ����|��|delaunay|������|����|��|��|����|��|��|3|��|�Ż�|������|��|��|��|�γ�|��|������|����|delaunay|������|����|��|��|4|��|ѭ��|ִ��|����|��2��|��|ֱ��|����|ɢ|��|����|���|��|��|5|��|����|����|��|�γ�|άŵͼ|��|��|��|һ|�㷨|��|�ؼ�|��|��2��|ͼʾ|����|��|��|��|3|��|�㷨|���Ӷ�|����|��|�㷨|��Ҫ|��|��ʱ|����|��|��|��2��|��|�ҳ�|��|����|��|��|Ӱ��|������|��Ҫ|o|��|n|��|��|���Ӷ�|��|��|����|Ӱ��|������|��|��|����|һ��|��|����|��|ɾ��|Ӱ��|������|��|����|��|���|��Ҫ|o|��|n|^|2|��|��|���Ӷ�|��|�ۺ�|��˵|��|���|�㷨|��|ʱ��|���Ӷ�|��|o|��|n|^|2|��|��|��|��|��|����|����|ʵ��|��|��|1|��|����|����|��|Ϊ��|��������|��|��|����|��|�ٶ�|��|��|ʹ��|��|ansi| |c|��д|��|����|���ݽṹ|��|��|�Լ�|����|��|û��|ʹ��|�κ�|c|+|+|��|stl|����|ģ��|��|��|ʹ��|����|����|��|��Ȼ|��|ʹ��|��һЩ|�ռ�|��|����|��|��|����|�±�|����|��|��ʽ|��|��|o|��|1|��|ʱ��|��|ֱ��|��λ|��|�ٶ�|��ȷ|�õ�|��|����|��|����|��|��|����|����|��|����|����|��|��Ȼ|��|�Լ�|����|��|���ݽṹ|��|����|��|����|�ջ�|����|��|��|ʵ��|����|��|��|����|��|����|˵��|����|��|��| | |1|��|�ṹ|��|����|��|typedef| |struct| | | | | | | | |x|;|	|	|	| | | | |y|;|��|}|point|;|��|typedef| |struct| | | | | | | | | | | | |start|,|end|;|��|	| |left|;|��|	|int| |right|;|��|}|edge|;|��|typedef| |struct|	| |a|,|b|,|c|;|��|	| |center|;|��|	|double| |radius|;| |isvalid|;| | |2|��|����|����|��|triangle| |triangle|[|]|;| | | |point|[|]|;|	| | | |pcnt|=|0|;| |tricnt|=|0|;| |tmpafftri|[|]|;| | | |affectedtricnt|=|0|;| | | | |affedgestart|[|]|;| |affedgeend|[|]|;| | | |outtri|[|]|;| | | |outtricnt|=|0|;| | | | |edge|[|]|;| | | |edgecnt|=|0|;|	| |init|(|)|;|	|	|	|	| |distance|(|point| |a|,|point| |b|)|;|	| | | |minicircle|(|point| |*|p|,|point|&amp;| | | |center|,|double|&amp;| | | |radius|)|;| | | | |freshtri|(|int| |sub|)|;| | | | | | | | | | | | |isaffected|(|int| |n|,|int| |i|)|;| | | | | | | | |storeaffedge|(|int| |n|)|;| | | | | | | | | |pointprocess|(|int| |n|)|;|	|	| | | | | |storenewtri|(|int| |n|)|;| | | | | | | | | | |offsuptri|(|)|;| | | | | | | | | | | | | | | | |initedge|(|)|;|	|	|	| | | | | |findedgetri|(|)|;| | | | | | | | | | | | | | |mexfunction|(|int| |nlhs|,| |mxarray| |*|plhs|[|]|,| |int| |nrhs|,| |const| |mxarray| |*|prhs|[|]|)|��|����|˵��|��|����|c|�ļ�|��|matlab|�ӿ�|��|ʵ��|��|����|˵��|��|��|int| |nlhs|:|����|���|����|��|����|��|mxarray| |*|plhs|[|]|:|���|����|Ϊ|mxarray|�ṹ|��|ָ��|����|����|��|int| |nrhs|:|����|����|����|��|����|��|const| |mxarray| |*|prhs|[|]|:|����|����|Ϊ|mxarray|�ṹ|��|ָ��|����|����|��|2|��|pn|=| |mxgetpr|(|prhs|[|0|]|)|��|����|˵��|��|��ȡ����|����|��|ʵ��|��|��|ָ��|��|��|pn|��|����|��ȡ|����|����|��|(|3|)| |plhs|[|0|]| |=| |mxcreatedoublematrix|(|outtricnt|*|3|*|2|,| |1|,| |mxreal|)|��| | | |y| |=| |mxgetpr|(|plhs|[|0|]|)|;|��|����|˵��|��|��ȡ����|����|��|ʵ��|��|��|ָ��|��|��|y|��|plhs|[|1|]| |=| |mxcreatedoublematrix|(|1|,| |1|,| |mxreal|)|;|��|y|1| |=| |mxgetpr|(|plhs|[|1|]|)|;| | | |=| |mxcreatedoublematrix|(|edgecnt|*|2|*|2|,| |1|,| |mxreal|)|;|	| | |=| |mxgetpr|(|plhs|[|2|]|)|;| | | |=| |mxcreatedoublematrix|(|1|,| |1|,| |mxreal|)|;|��|y|3| |=| |mxgetpr|(|plhs|[|3|]|)|;| | | |r|2013|a| |win|64|��|����|��|��|ֱ��|��|��|����|��|��|��Ҫ|��|matlab| |r|2013|a| |win|64|��|runtime|��|��|��|��|��|��|����|��|��|����|����|��|��|ֱ��|��װ|matlab| |r|2013|a| |win|64| |bit|��|����|��|ִ��|mst|��|����|��|dots|.|exe|����|ֱ��|��|matlab|����|��|run| |dots|.|m|�ļ�|��|����|��|��|��װ|mcrinstaller|.|exe|��|һ��|Ҫ|matlab| |r|2013|a| |win|64| |bit|��|��|Ȼ��|��|����|����|mst|��|����|��|dots|.|exe|��|��|��|���|û��|mcrinstaller|.|exe|��|����|��|413|mb|��|��|��|�Ѿ�|��|����|360|����|��|��ַ|��|��|http|:| | |��ȡ|��| |1249|��|�ṩ|����|��|��|2|��|";


// 	str1=checkFile.getContent();
// 	str2=otherFile.getContent();

	//cout<<"str1 == "<<str1<<endl;

	RKR_GST_Match rkr_gst(str1, str2, 14);
	rkr_gst.beginMatch(30);


	fstream file;
	file.open("c:\\result.txt", ios::out );
	int sum = 0;
	for (vector<Match>::iterator it = rkr_gst.matches.begin(); it != rkr_gst.matches.end(); ++it)
	{
		sum += it->len;
		file<<"<"<<it->m<<", "<<it->n<<", "<<it->len<<">"<<"\n";
	}
	file<<"\n\nthe length  of the first string is : "<<str1.length()<<"\n";	
	file<<"the length  of the second string is : "<<str2.length()<<"\n";
	file<<"The total similar length of these two strings is : " <<sum<<"\n";
	file<<"The similarity of the two string is : " <<(sum * 2.0 /(str1.length() + str2.length()) )<<"\n";


	//system("pause");
	return 0;
}