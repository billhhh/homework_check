#include "rkr_gst_match.h"
#include "Hash.h"

void RKR_GST_Match::beginMatch(int initialLength)
{
	searchLength = initialLength;
	while(searchLength > minLength)
	{
		lmax = scanPattern(searchLength);
		if (lmax > 2 * searchLength)
		{
			searchLength = lmax;
		} 
		else
		{
			markStrings(searchLength);
			if (searchLength > 2 * minLength)
			{
				searchLength = (int)ceil((double) searchLength / 2);
			} 
			else if (searchLength > minLength)
			{
				searchLength = minLength;
			}
		}
	}
}

int RKR_GST_Match::scanPattern(int s)
{
	int maxLengthOfMatch = -1;
	MyHash hs;
	hs.initial_hash();
	for (int n = 0; n < lenT; ++n)
	{
		if (! bitvecT.test(n))
		{
			int index = getNextTileIndex(bitvecT, n, lenT);			//��һ�� tile ���±�
			if (index - n < s)													//����һ�� tile �ľ���С�ڵ��� s
			{
				n = moveNextTileIndex(bitvecT, index, lenT);
				continue;
			} 
			else
			{
				string str =strT.substr(n, s);								//���� strT �ĳ���Ϊ s �Ĺ�ϣ��
				hs.insert_hash(str, n);
				//hs.insert(pair<string, int>(str,n));
			}
		}
		else
			continue;
	}
	for (int m = 0; m < lenP; ++m)
	{
		if (! bitvecP.test(m))
		{
			int index = getNextTileIndex(bitvecP, m, lenP);		//��һ�� tile ���±�
			if (index - m < s)													//����һ�� tile �ľ���С�ڵ��� s
			{
				m = moveNextTileIndex(bitvecT, index, lenT);
				continue;
			}
			else
			{
				string str = strP.substr(m, s);
				LinkNode *temp = hs.search_hash(str);
				if (NULL != temp)													
				{
					int n = temp->num;									//��ϣ���д��ڸ��ַ���
					int k = s;
					while(m + k < lenP && n + k < lenT && strP[m + k] == strT[n + k] && (! bitvecP[m + k]) &&(! bitvecT[n + k]))
						++k;
					maxLengthOfMatch = k;
					if (k > 2 * s)												//����ɨ�裬���µ� s ��ʼɨ��
					{
						return k;
					} 
					else															//�����µ����ƥ��
					{
						Match mat(n, m, k);
						mapQue[k].push(mat);
						maxLengthOfMatch = maxLengthOfMatch > k ? maxLengthOfMatch : k;//�������ƥ�䳤��
					}
				}			
			}
		}
		else
			continue;
	}
	return maxLengthOfMatch;
}

void RKR_GST_Match::markStrings(int s)
{
	map<int, queue<Match>, greater<int> >::iterator iter = mapQue.begin();
	for ( ; iter != mapQue.end(); iter = mapQue.begin())									//�� map �е�ÿ�� <int, queue<Match> > ���д���
	{
		const int length = iter->first;
		queue<Match> temp = iter->second;
		mapQue.erase(length);
		while (! temp.empty())										//���в�Ϊ��
		{
			Match mat = temp.front();
			temp.pop();
			if (! occlude(mat))													//��û�ص�
			{
				mark(bitvecP, mat.m, length, lenP);
				mark(bitvecT, mat.n, length, lenT);
				matches.push_back(mat);
			}
			else
				continue;
		}
	}
}

bool RKR_GST_Match::occlude(Match mat)			//����ǰ match �� matches ��Ԫ�����ص����֣����� true�� ���򷵻� false
{
	bool tag = false;
	int m = mat.m;												//ȡ�� mat ��Ԫ���Ԫ��
	int n = mat.n;
	int len = mat.len;
	for (int i = 0; i < matches.size(); ++i)
	{
		Match temp = matches[i];							//�� matches ÿ��Ԫ�ؽ��бȽ�
		int p = temp.m;
		int q = temp.n;
		int r = temp.len;
		if ((m < p && m + len > p) || (m > p && m < p + r))
		{
			tag = true;
			return tag;
		}
		if ((n < q && m + len > q) || (n > q && n < q + r))
		{
			tag = true;
			return tag;
		}
	}
	return tag;
}

int RKR_GST_Match::getNextTileIndex(bitset<MAX_LENGTH_TEXT> &bits, int x, int len)
{
	int i = 0;
	bool tag = false;
	for (i = x + 1; i < len ; ++i)
	{
		if (! bits.test(i))
			continue;
		else
		{
			tag = true;
			break;
		}
	}
	if (tag)
		return i;
	return len;
}

int RKR_GST_Match::moveNextTileIndex(bitset<MAX_LENGTH_TEXT> &bits, int x, int len)
{	int i = 0;
	for ( i = x + 1; i < len - 1; ++i)
	{
		if (bits.test(i))
		{
			continue;
		}
		else
			break;
	}
	return i;
}

void RKR_GST_Match::mark(bitset<MAX_LENGTH_TEXT> &bits, int x, int len, int boundary)
{
	for (int i = x; i < x + len  && i < boundary ; ++i)
	{
		bits.set(i);
	}
}