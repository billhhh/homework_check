
#include <vector>
using namespace std;
//������ļ�����
#define MAX_FILE_COUNT  50
//���·���ַ�����

#define MAX_PATH   260

int	ACZip( vector<string> files,string zipname);

int	ACUnZip(string zipname, string path);
//�ļ�ͷ
struct FileHead
{
	unsigned int FileCount;//�ļ�����
	unsigned int FileLen[MAX_FILE_COUNT];//�ļ���С
	char FileName[MAX_FILE_COUNT][MAX_PATH];//�ļ���
};

class MyCab
{
	private:
		FileHead fh;//�ļ�ͷ
		char ObjectFilePathName[MAX_PATH];//���ɴ���ļ�λ�ü�����
	public:
	//�޲�������
	MyCab();
	public:
		//����ļ�������
		void AddFile(string FilePathName);
		//���ô������ļ�
		void SetOutPutFile(char * OutFile);
		//��ȡ�ļ���С(�����Զ����Ʒ�ʽ�򿪵��ļ�ָ��)
		long GetFileSize(FILE *pf);
		//��������ļ�
		void DoMakeCAB();
		//���(Ϊ�˽�ʡʱ�䲻д��������,���Ը��������Լ����)
		void DoUnCAB(char *CabFilePathName,string path);
	private:
		//��ʾ������ļ���Ϣ
		void printCAB();
};

