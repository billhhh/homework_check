#ifndef MATCH
#define  MATCH

typedef struct Match
{
	int m;								//P����ʼ�±�
	int n;								//T����ʼ�±�
	int len;								//����
	Match(int p = 0, int q = 0, int r = 0) : m(p), n(q), len(r)	{}	//ֻ�������� int ֵ�������
	~Match() {}
}Match;

#endif	//MATCH