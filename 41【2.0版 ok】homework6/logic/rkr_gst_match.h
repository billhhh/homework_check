#include "match.h"
#include <math.h>
#include <hash_map>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
#include <map>

const int MAX_LENGTH_TEXT = 100000;

using namespace std;
class RKR_GST_Match
{
private:
	string strT;													//�ı���
	string strP;													//ģʽ��
	int lenT;
	int lenP;
	bitset<MAX_LENGTH_TEXT> bitvecT;				//�ı�����mark
	bitset<MAX_LENGTH_TEXT> bitvecP;				//ģʽ����mark
public:
	vector <Match> matches;							//P ��T ��ƥ����
private:
	int minLength;												//��С�����Ӵ�����
	int searchLength;											//��������
	int lmax;														//ѭ�����ҵ����������ƥ���С
	map<int, queue<Match>, greater<int> > mapQue;							//��¼���ƥ��
public:
	RKR_GST_Match(string &t, string &p, int len)
		: strT(t), strP(p)	, minLength(len),	searchLength (0), lmax (0)			//ֻ��������string����������
	{
		lenP = strP.length();
		lenT = strT.length();
		bitvecT.reset();
		bitvecP.reset();
	}
	~RKR_GST_Match() {}
	void beginMatch(int initialLength);
	int scanPattern(int s);																	//ɨ��ģʽ
	void markStrings(int s);																	//�������ƥ��
	bool occlude(Match m);																	//��ǰMatch�Ƿ��ص�
	int getNextTileIndex(bitset<MAX_LENGTH_TEXT> &bits, int , int);
	int moveNextTileIndex(bitset<MAX_LENGTH_TEXT> &bits, int , int);
	void mark(bitset<MAX_LENGTH_TEXT> &bits, int x, int len, int boundary);
};
