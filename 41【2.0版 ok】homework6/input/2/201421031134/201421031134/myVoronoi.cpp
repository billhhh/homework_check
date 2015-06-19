//������
//����ĳ��������ξ���ֱ��������
//A(250.0,750.0) B(-500.0,0) C(1000.0,0)

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mex.h"


/**********����ṹ��***********/
typedef struct
{
	double x;
	double y;
}Point;

typedef struct
{
	//��űߵ�ʼ����յ��±�
	int Start,End;

	//��ű����ߵ��������±�
	int Left;
	int Right;
}Edge;


typedef struct
{
	//�����ε���������
	//�����ŵ���point������±�
	int A,B,C;

	//��������������
	Point Center;

	double radius;//���Բ�뾶

	bool isValid;//�ж��ǲ�����Ч��
}Triangle;



/**********����ȫ�ֱ���***********/
const int MAXN=6000;
Triangle triangle[MAXN];  //ÿ����һ��������3��������
Point point[200];

int pCnt=0;//��¼�������
int triCnt=0;//���������θ���

//���¡�
int tmpAffTri[MAXN];  //��ǰ��Ӱ����������±�
int affectedTriCnt=0;   //��ǰ��Ӱ��������ε���Ŀ
int affEdgeStart[MAXN];//��Ӱ���������ʼ��
int affEdgeEnd[MAXN];  //��Ӱ����������յ�

int outTri[MAXN];  //���������������±�
int outTriCnt=0;   //���Delaunay�����εĸ���

Edge edge[MAXN];  //��������������õ��ı�����
int edgeCnt=0;	//��������������



/**********���庯��***********/
void init();
double distance(Point A,Point B);
void   miniCircle(Point *p,Point&   center,double&   radius);
void freshTri(int sub);
bool isAffected(int n,int i);
void storeAffEdge(int n);
void pointProcess(int n);
void storeNewTri(int n);         //����������������
void offSupTri();
void initEdge();
void findEdgeTri();


//��ӡ����Ϣ
void printPointInfo(Point p)
{
	//mexmexPrintf("****************��  ��Ϣ********************\n");
	mexPrintf("%.2lf %.2lf\n",p.x,p.y);
	//mexmexPrintf("****************��  ��Ϣ END****************\n\n");
}

void printEdgeInfo(Edge e)
{
	//�����e����Ϣ
	printf("��%d->��%d  Left == %d  Right == %d\n",e.Start,e.End,e.Left,e.Right);
}



//���˵�ں�
//���룺�㼯����    �����������������
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	//�ӿں�������  plhs[]�����ָ��     prhs[]������ָ�� ע��˳��

	//��������C��ָ�����
	double *num,*x,*y,*y1,*y2,*y3;	//x������  y�����

	num = mxGetPr(prhs[0]);  //��ȡ��һ�������ָ�룬����num
	x = mxGetPr(prhs[1]);     //��ȡ�ڶ����������ָ�룬����x

	int pn=num[0];       //���нӿڲ����ĸ�ֵ��������ĵ�һ��������c�ļ��ı���n����ڵ�ĸ���
	pCnt=pn;




	//freopen("input.txt","r",stdin);

	//��ʼ�����������쳬��������
	init();

	if(triCnt==0 || pCnt==0)
	{
		//��ʼ�����ɹ�
		mexPrintf("�����ʼ��ʧ��!!\n");
		return;
	}

	else
		mexPrintf("�����ʼ���ɹ�...\n");



	mexPrintf("���������봦������꣺\n");
	//����㣬����p[]���飬�±�0,1,2�ĵ��ǳ��������εĶ���
	int i;
	Point tmp[MAXN];
	//����㣬����p[]����
	for(i=0;i<pn;i++)
	{
		tmp[i].x=x[i];
		tmp[i].y=x[i+pn];
	}
	for(i=3;i<pCnt;i++)
		point[i]=tmp[i-3];

	//test �������Ϣ
	for(i=0;i<pCnt;i++)
		printPointInfo(point[i]);


	/*for(i=3;i<pCnt;i++)
		scanf("%lf%lf",&point[i].x,&point[i].y);*/


	//����
	//��ÿһ������㰴����˳����
	for(i=3;i<pCnt;i++)
		pointProcess(i);

	offSupTri();

	//���
	outTriCnt=0;
	mexPrintf("\n��������������Ϊ��\n");
	//ȫ����������Ժ������������������
	for(i=0;i<triCnt;i++)
	{
		//�볬���������޹صĲ����
		if(triangle[i].isValid != false)
		{
			outTri[outTriCnt]=i;
			mexPrintf("(%.2lf,%.2lf)\n",triangle[i].Center.x,triangle[i].Center.y);
			outTriCnt++;
		}
	}

	mexPrintf("outTriCnt == %d\n",outTriCnt);
	mexPrintf("triCnt == %d\n",triCnt);

	plhs[0] = mxCreateDoubleMatrix(outTriCnt*3*2, 1, mxREAL); //����һ��(n-1)��2�ľ��󲢽������һ��Ԫ�����ڵ�λ��ָ�븳���������
	y = mxGetPr(plhs[0]); //��ȡ��һ�����ָ�룬����y
	plhs[1] = mxCreateDoubleMatrix(1, 1, mxREAL);
	y1 = mxGetPr(plhs[1]);  //��ȡ�ڶ������ָ�룬����y1

	for(i=0;i<outTriCnt;i++)
	{
		// y[] �ŵľ����������㡾�±꡿Ӧ������

		// AB����
		y[i*6]=triangle[outTri[i]].A-2;
		y[i*6+1]=triangle[outTri[i]].B-2;

		// BC����
		y[i*6+2]=triangle[outTri[i]].B-2;
		y[i*6+3]=triangle[outTri[i]].C-2;

		// AC����
		y[i*6+4]=triangle[outTri[i]].A-2;
		y[i*6+5]=triangle[outTri[i]].C-2;

		//test
		printf("���� %d ��������:",outTri[i]);
		mexPrintf("AB:%d->%d   ",triangle[outTri[i]].A-3,triangle[outTri[i]].B-3);
		mexPrintf("BC:%d->%d   ",triangle[outTri[i]].B-3,triangle[outTri[i]].C-3);
		mexPrintf("AC:%d->%d\n",triangle[outTri[i]].A-3,triangle[outTri[i]].C-3);

		
	}

	//Ϊ�������� ��ʼ��������
	initEdge();

	findEdgeTri();

	y1[0]=outTriCnt;


	printf("\n");
	//���������������      ok
	for(i=0;i<edgeCnt;i++)
	{
		printf("�� %d ���ߣ�",i+1);
		printEdgeInfo(edge[i]);
	}




	//���ĸ�ֵ��matlab�Ǳ���
	plhs[2] = mxCreateDoubleMatrix(edgeCnt*2*2, 1, mxREAL); //����һ��(n-1)��2�ľ��󲢽������һ��Ԫ�����ڵ�λ��ָ�븳���������
	y2 = mxGetPr(plhs[2]);  //��ȡ��3�����ָ�룬����y2

	plhs[3] = mxCreateDoubleMatrix(1, 1, mxREAL);
	y3 = mxGetPr(plhs[3]);  //��ȡ��4�����ָ�룬����y3
	y3[0]=edgeCnt;

	for(i=0;i<edgeCnt;i++)
	{
		y2[i*4]=triangle[edge[i].Left].Center.x;
		y2[i*4+1]=triangle[edge[i].Left].Center.y;

		if(edge[i].Right==-1)
		{
			y2[i*4+2]=( point[edge[i].Start].x + point[edge[i].End].x )/2;
			y2[i*4+3]=( point[edge[i].Start].y + point[edge[i].End].y )/2;
		}

		else
		{
			y2[i*4+2]=triangle[edge[i].Right].Center.x;
			y2[i*4+3]=triangle[edge[i].Right].Center.y;
		}
	}

}








void findEdgeTri()
{
	//�����ı����ߵ�������
	int i,j;
	int edgeCnt_ori;

	for(i=0;i<outTriCnt;i++)
	{
		//����i����������     ����j������
		edgeCnt_ori=edgeCnt;

		//  AB��
		for(j=0;j<edgeCnt_ori;j++)
		{
			if(  (triangle[outTri[i]].A == edge[j].Start && triangle[outTri[i]].B == edge[j].End) || (triangle[outTri[i]].B == edge[j].Start && triangle[outTri[i]].A == edge[j].End)  )
			{
				//�����رߣ��ѱߵ�Rightָ���������
				edge[j].Right=outTri[i];
				break;
			}
		}

		if(j==edgeCnt_ori)
		{
			//�����˳�ѭ����ֱ�Ӽ���ñ�
			edge[edgeCnt].Start=triangle[outTri[i]].A;
			edge[edgeCnt].End=triangle[outTri[i]].B;

			edge[edgeCnt].Left=outTri[i];    //�Լ����Ƹ�Left

			edgeCnt++;
		}



		//  BC��
		for(j=0;j<edgeCnt_ori;j++)
		{
			if(  (triangle[outTri[i]].B == edge[j].Start && triangle[outTri[i]].C == edge[j].End) || (triangle[outTri[i]].C == edge[j].Start && triangle[outTri[i]].B == edge[j].End)  )
			{
				//�����رߣ��ѱߵ�Rightָ���������
				edge[j].Right=outTri[i];
				break;
			}
		}

		if(j==edgeCnt_ori)
		{
			//�����˳�ѭ����ֱ�Ӽ���ñ�
			edge[edgeCnt].Start=triangle[outTri[i]].B;
			edge[edgeCnt].End=triangle[outTri[i]].C;

			edge[edgeCnt].Left=outTri[i];

			edgeCnt++;
		}


		//  AC��
		for(j=0;j<edgeCnt_ori;j++)
		{
			if(  (triangle[outTri[i]].A == edge[j].Start && triangle[outTri[i]].C == edge[j].End) || (triangle[outTri[i]].C == edge[j].Start && triangle[outTri[i]].A == edge[j].End)  )
			{
				//�����رߣ��ѱߵ�Rightָ���������
				edge[j].Right=outTri[i];
				break;
			}
		}

		if(j==edgeCnt_ori)
		{
			//�����˳�ѭ����ֱ�Ӽ���ñ�
			edge[edgeCnt].Start=triangle[outTri[i]].A;
			edge[edgeCnt].End=triangle[outTri[i]].C;

			edge[edgeCnt].Left=outTri[i];

			edgeCnt++;
		}


	}
}



void initEdge()
{
	edgeCnt=0;

	int i;
	for(i=0;i<MAXN;i++)
	{
		edge[i].Left=-1;
		edge[i].Right=-1;
	}
}



void offSupTri()
{
	//ȥ������������
	int i;
	for(i=0;i<triCnt;i++)
	{
		if(triangle[i].A==0 || triangle[i].B==0 || triangle[i].C==0)
			triangle[i].isValid=false;

		else if(triangle[i].A==1 || triangle[i].B==1 || triangle[i].C==1)
			triangle[i].isValid=false;

		else if(triangle[i].A==2 || triangle[i].B==2 || triangle[i].C==2)
			triangle[i].isValid=false;
	}
}



//��ʼ�����������쳬��������
void init()
{
	//��ʼ�����������Σ�isValid Ϊ true
	//��ʼ��ʼ����Ϊ��Ч
	int i;
	for(i=0;i<MAXN;i++)
		triangle[i].isValid=true;

	point[0].x=250.0;
	point[0].y=750.0;

	point[1].x=-500.0;
	point[1].y=0;

	point[2].x=1000.0;
	point[2].y=0;

	//0�±���ǳ���������
	triangle[0].A=0;
	triangle[0].B=1;
	triangle[0].C=2;

	triangle[0].Center.x=250.0;
	triangle[0].Center.y=0;

	triangle[0].radius=750.0;   //707.10678118654752440084436210485

	triCnt=1;

	//mexPrintf("һ���������Ŀ��\n");
	//scanf("%d",&pCnt);
	pCnt+=3;
}



double distance(Point A,Point B)
{
	double dis = (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);

	return sqrt(dis);
}



void   miniCircle(Point *p,Point&   center,double&   radius)
{
	double   Xmove=p[0].x;   
	double   Ymove=p[0].y;
	p[1].x=p[1].x-p[0].x;
	p[1].y=p[1].y-p[0].y;
	p[2].x=p[2].x-p[0].x;
	p[2].y=p[2].y-p[0].y;
	p[0].x=0;
	p[0].y=0;
	int  index;

	double   x1=p[1].x,y1=p[1].y,x2=p[2].x,y2=p[2].y;   
	double   m=2.0*(x1*y2-y1*x2);   
	center.x=(x1*x1*y2-x2*x2*y1+y1*y2*(y1-y2))/m;   
	center.y=(x1*x2*(x2-x1)-y1*y1*x2+x1*y2*y2)/m;   
	radius=distance(center,p[0]);
	center.x+=Xmove;   
	center.y+=Ymove;     

}


//���������� ���ġ��뾶
void freshTri(int sub)
{
	Point p[3];

	//���������ε��±�Ϊsub
	p[0]=point[triangle[sub].A];
	p[1]=point[triangle[sub].B];
	p[2]=point[triangle[sub].C];

	miniCircle(p,triangle[sub].Center,triangle[sub].radius);

}


//�ж��������Ƿ���Ӱ��ĺ���
//�жϵ� n ��͵� i ��������
bool isAffected(int n,int i)
{
	double dis = distance(point[n],triangle[i].Center);

	if(dis<triangle[i].radius)
		return true;

	else
		return false;
}


void storeAffEdge(int n)
{
	//���� ��n�� �����ε�����
	int i;
	int a=triangle[n].A;
	int b=triangle[n].B;
	int c=triangle[n].C;

	for(i=0;i<affectedTriCnt*3;i++)
	{
		if((a == affEdgeStart[i] && b == affEdgeEnd[i]) || (b == affEdgeStart[i] && a == affEdgeEnd[i]))
		{
			//AB�ر�
			affEdgeStart[i]=-1;
			affEdgeEnd[i]=-1;

			affEdgeStart[(affectedTriCnt-1)*3]=-1;
			affEdgeEnd[(affectedTriCnt-1)*3]=-1;

			break;
		}
	}

	if(i==affectedTriCnt*3)
	{
		affEdgeStart[(affectedTriCnt-1)*3]=a;
		affEdgeEnd[(affectedTriCnt-1)*3]=b;
	}

	for(i=0;i<affectedTriCnt*3;i++)
	{
		if((b == affEdgeStart[i] && c == affEdgeEnd[i]) || (c == affEdgeStart[i] && b == affEdgeEnd[i]))
		{
			//BC�ر�
			affEdgeStart[i]=-1;
			affEdgeEnd[i]=-1;

			affEdgeStart[(affectedTriCnt-1)*3+1]=-1;
			affEdgeEnd[(affectedTriCnt-1)*3+1]=-1;

			break;
		}
	}

	if(i==affectedTriCnt*3)
	{
		affEdgeStart[(affectedTriCnt-1)*3+1]=b;
		affEdgeEnd[(affectedTriCnt-1)*3+1]=c;
	}




	for(i=0;i<affectedTriCnt*3;i++)
	{
		if((a == affEdgeStart[i] && c == affEdgeEnd[i]) || (c == affEdgeStart[i] && a == affEdgeEnd[i]))
		{
			//AC�ر�
			affEdgeStart[i]=-1;
			affEdgeEnd[i]=-1;

			affEdgeStart[(affectedTriCnt-1)*3+2]=-1;
			affEdgeEnd[(affectedTriCnt-1)*3+2]=-1;

			break;
		}
	}

	if(i==affectedTriCnt*3)
	{
		affEdgeStart[(affectedTriCnt-1)*3+2]=a;
		affEdgeEnd[(affectedTriCnt-1)*3+2]=c;
	}

}


void storeNewTri(int n)
{
	//�¼�������±�Ϊn�ĵ�
	int i;
	for(i=0;i<affectedTriCnt*3;i++)
	{
		if(affEdgeStart[i]==-1)
			continue;

		triangle[triCnt].A=affEdgeStart[i];
		triangle[triCnt].B=affEdgeEnd[i];
		triangle[triCnt].C=n;

		freshTri(triCnt);

		triCnt++;
	}
}


void pointProcess(int n)
{
	//affEdge[] init
	memset(affEdgeStart,-1,sizeof(affEdgeStart));
	memset(affEdgeEnd,-1,sizeof(affEdgeEnd));

	//�����±�Ϊ��n���� point
	//��õ�ͬ�������������ĵľ��룬�������С�����Բ�뾶����Ϊ����������Ӱ��
	int i;

	int triCnt_ori = triCnt;   //�������¼���ġ�Ӱ�������Ρ�Ӱ��ѭ������



	affectedTriCnt=0;
	for(i=0;i<triCnt_ori;i++)
	{
		//�жϸõ㡾��n�㡿�͡���i����������
		if(triangle[i].isValid==true && isAffected(n,i)==true)
		{
			tmpAffTri[affectedTriCnt]=i;  //1���ܵ�Ӱ���ˣ��Ȱ����е�Ӱ�������δ���һ�������������������
			affectedTriCnt++;
			triangle[i].isValid=false; //֮���ټ��룬����Ϊ��Ч

			storeAffEdge(i);	//2��������i���������εı߷���Ӱ������飬˳��ȥ����ǰӰ���������رߣ��ر�start��end��ֵΪ-1
		}
	}
	storeNewTri(n);     //��������2���ıߺ��¼���ġ���n�㡿����������Σ�����triangle����

}
