#include<stdio.h>
#include<string.h>

#define MAXN 110

bool map[MAXN][MAXN];

int dfn[MAXN],low[MAXN],n,sonTree;
bool visit[MAXN],recrd[MAXN];

inline int get_min(int x,int y){	return x<y?x:y;  }

void init()
{
	memset(map,0,sizeof(map));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(visit,0,sizeof(visit));
	memset(recrd,0,sizeof(recrd));

	sonTree=0;
}

void findArticulat(int u,int depth)
{
	dfn[u]=low[u]=depth; //��ʼ��dfn��low����ֵΪ��ǰ���
	visit[u]=1;

	int i;
	for(i=1;i<=n;i++) //Ϊ�˷��㣬�±��1��ʼ����
	{
		if(map[u][i]) //���u��i������
		{
			if(!visit[i]) //����� i û�б����ʣ���һֱ������ȥ
			{
				findArticulat(i,depth+1);//�����ݹ�

				low[u]=get_min(low[u],low[i]);

				if(u!=1&&low[i]>=dfn[u]) //���low[i]>=dfn[u]������û���������Իر���ȥ
					recrd[u]=1; //���Ϊ�ؽڵ�

				else if(u==1)//���u����������������û�б����ʣ�����������1
					sonTree++;
			}

			//���i�������ˣ�֤���лرߣ�ֱ�Ӹ���
			else
				low[u]=get_min(low[u],dfn[i]);
		}
	}
}

int main()
{
	//��ʼ��
	init();

	//����
	printf("�����봦��������\n");
	scanf("%d",&n);

	printf("�����봦������ߣ�����0������\n");

	int i;
	int u,v;
	while(scanf("%d",&u)&&u!=0)
	{
		while(getchar()!='\n')
		{
			scanf("%d",&v);
			map[u][v]=map[v][u]=1;//˫��ͼ
		}
	}
	//�������

	//����
	findArticulat(1,1);

	printf("\n");

	//���
	int count=0;
	if(sonTree>=2)
	{
		count++;
	}
	for(i=2;i<=n;i++)
	{
		if(recrd[i])
		{
			printf("%d�ǹؽڵ�  ",i);
			count++;
		}
	}
	printf("\nһ���йؽڵ�����%d\n",count);


	return 0;
}
