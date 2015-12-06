/************************************************************************/
/*�쳣���붨��
��λ�����쳣					1-15
��бУ���쳣					16-31
X�����ǵ����쳣				32-47
Y�����ǵ����쳣				48-63
���������쳣					64-79
Ԥ������Ϳ�����쳣				80-111
�����쳣						112
���������쳣					255-511
�𰸼���쳣					512-INF
*/
/************************************************************************/
#include <cv.h>
#ifndef _COMMONSTRUCT_H
#define _COMMONSTRUCT_H
#define REFPOINT_ERROR -4               //ʶ��ο����쳣
#define ACTYPE_NOT_MATCH -3                //���⿨���Ͳ�ƥ��
#define ACINFO_NOT_MATCH -2                //�ṹ�岻ƥ��
#define IDPOINT_NOT_MATCH 1                //id�㲻ƥ��
#define	ANCHOR_POINT_ERR_BASE 1          //��λ��ʶ�����
#define PAGEMAKER_ERR 8					 //ҳ���ʶ�鲻ƥ��
#define	TILTCORRECTION_ERR_BASE 16       //��б��������
#define	XMARKERS_ERR_BASE 32             //X�����ǵ����
#define	YMARKERS_ERR_BASE 48            //Y�����ǵ����
#define	BAR_ERR_BASE 64                 //������ʶ�����
#define FILLING_POINT_ERR_BASE 96       //Ԥ������Ϳ��ʶ�����   
#define	FOLD_ERR 112
#define	CROPAREA_ERR_BASE 255;          
#define ANSWER_ERR_BASE 512
using namespace cv;
//�û��ɵ�������
typedef struct AcArgs{
	double xRangeScale;    //��ǵ��ȳ߶ȷ�Χ
	double yRangeScale;      //��ǵ�߶ȳ߶ȷ�Χ
	double sensibilityThresh;   //��Ϳһ����������
	double areaThreshold;       //��С��Ϳ��ֵ
	int seSize;                //�Ƿ��С��̬ѧģ���С Ϊ0��������  ����0��������
} AcArgs;

enum FillingPointsType :ushort{
	SeatNumZeroFirst,                //��λ�� ��0��ʼ
	ExamHallNumZeroFirst,			//������ ��0��ʼ
	ExamRoomNumZeroFirst,			//���Һ� ��0��ʼ
	FirstCandidateNumZeroFirst,		//�׿����� ��0��ʼ
	TickerNumZeroFirst,				//׼��֤�� ��0��ʼ
	CourseNumZeroFirst,				//��Ŀ�� ��0��ʼ
	SeatNumOneFirst,                //��λ�� ��1��ʼ
	ExamHallNumOneFirst,			//������ ��1��ʼ
	ExamRoomNumOneFirst,			//���Һ� ��1��ʼ
	FirstCandidateNumOneFirst,		//�׿����� ��1��ʼ
	TickerNumOneFirst,				//׼��֤�� ��1��ʼ
	CourseNumOneFirst,				//��Ŀ�� ��1��ʼ
	Absent,							//ȱ��
	PaperType,						//�Ծ�����
	OptionalQuestion,				//ѡ����
	Discipline,						//Υ��
	Question,						//ѡ����
	PageNum                         //ҳ��
};
enum BarType :ushort{
	PaperTypeBar,				//�Ծ�����
	TickerNumBar,				//׼��֤��
	ExamRoomNumBar,			//���Һ�
	AbsentBar,					//ȱ��
};
//ʶ�����ṹ�嶨��

//������ʶ�����ṹ��
typedef struct Bar_RST{
	BarType barType;
	char * bar;
	bool errflag;  //������
}Bar_RST;


//2.����Ϣ�ṹ�嶨��
//2.1С�����Ϣ�ṹ��
typedef struct  Perquestion_RST{
	int questionId;      //���
	//	ushort answer;   //��
	int answer;
	int suspectFlag;      //���ɱ�ǣ�Ϊ0��ʾʶ�����������򷵻ؿ���״̬��Ϣ��
	/*	vector<cv::Point> answerPos;  */
	cv::Point *answerPos;   //��Ϳ����λ��
	int answerPosCount;     //������

}Perquestion_RST;
//2.����Ϣ�ṹ�嶨��
typedef struct  Answer_RST{
	int suspectFlag;      //���ɱ�ǣ�Ϊ0��ʾʶ�����������򷵻ؿ���״̬��Ϣ��
	Perquestion_RST * answer;   //��ʶ����
	int answerCount;
}Answer_RST;
//3.��������
typedef struct CropArea_RST{
	char * name;		//������������
	int groupNum;      //�ϲ����
	bool isSecret;      //��������
	//	Mat img	;		//��������λ��
	cv::Rect cropRect;                   //�˴�����һ��rect�����ǲ���ȷ��
}CropArea_RST;
//4.Ԥ������Ϳ����
typedef struct  PerFP_RST{
	int result;   //��
	int suspectFlag;      //���ɱ�ǣ�Ϊ0��ʾʶ�����������򷵻ؿ���״̬��Ϣ��
	cv::Point *resultPos;  //��Ϳ������λ��
	int resultPosCount;    //��Ϳ�����

}PerFP_RST;

typedef struct FillingPoints_RST{
	char* name;				//����
	FillingPointsType fPType;     //Ԥ������Ϳ������
	PerFP_RST *fillingResult;		//��
	int fillingResultCount;     //�𰸸���
	int suspectFlag;			//���ɱ�ǣ�Ϊ0��ʾʶ�����������򷵻ؿ���״̬��Ϣ��
}FillingPoints_RST;

//ʶ�����ṹ�壬����������Ϣʶ�����ʹ�ʶ�����Լ�������Ϣ
typedef struct  AC_RST{
	int tkId;         //�׿����(����һ�����Ͷ�)
	int pageId;        //�Ծ���(����һ�����Ͷ�)
	int errFlag;           //�����ǣ�Ϊ0��ʾʶ�����������򷵻س���״̬��Ϣ��
	double angle;			//��б�Ƕ�
	Rect blackLine;             //�ڼ����λ��
	Rect whiteLine;             //�׼����λ��
	cv::Size imgSize;       //ͼ��ߴ�
	uchar* img;             //������ͼ������
	Answer_RST answerResult;   //����Ϣʶ����
	Bar_RST * barResult;  //����ʶ����
	int barResultCount;
	CropArea_RST * cropAreaResult;	//����������
	int cropAreaResultCount;
	FillingPoints_RST * cfpResult;	//Ԥ������Ϳ��ʶ����
	int cfpResultCount;
}AC_RST;


/************************************************************************/
/* ת����Ŀ���ʽ�ṹ�嶨��                                             */
/************************************************************************/
//С��λ�ú�׼��֤��λ�ýṹ��
typedef struct Cum_QustionItemPos{
	int id;    //���
	ushort mark_id;  //���ڱ�ǵ�������
	bool isCrosswise; //�Ƿ��Ǻ����
	bool isSingleChoice;	//�Ƿ��ǵ�ѡ
	ushort interval ;      //����/����������ѡ���Ų�Ϊ������Ϊ������
	ushort markerIdx[3];	//��Ŀ��Ӧ��λ����������Ϊ������[0]�洢y����������ţ�[1] [2]��x���������ţ���Ϊ������[0]�洢x����������ţ�[1] [2]��y����������
}Cum_QustionItemPos,Cum_ItemPos;

//1.��Ϳ����Ϣ�ṹ�嶨��
typedef struct Cum_FillingpointItemPos{
	int id;    //���
	bool isSingleChoice;	//�Ƿ��ǵ�ѡ
	Rect * pos;        //������ϽǶ�λ��λ����Ϣ
	int posCount;
}Cum_FillingpointItemPos;
//1.2��������Ϣ�ṹ�嶨��
typedef struct Cum_Bar_info{
	BarType barType;      //��������
	cv::Rect pos;  //����λ�ã�(x,y)��ʾ���Ͻ���Զ�λ���������ꡣwith��high��ʾ����Ĵ�С
}Cum_Bar_info;
//��Ϳ����
typedef struct Cum_FillingPoints_info{
	char * name;				//����
	FillingPointsType fptype;    //Ԥ������Ϳ������
	Cum_ItemPos * fillingPoints;		//����Ϳ���λ����Ϣ
	int fillingPointsCount;
}Cum_FillingPoints_info;

typedef struct Cum_FillingPoints_info3{
	char * name;				//����
	FillingPointsType fptype;    //Ԥ������Ϳ������
	bool isCrosswise;			//�Ƿ��Ǻ����
	Cum_FillingpointItemPos *fillingPoints;		//����Ϳ���λ����Ϣ
	int fillingPointsCount;
}Cum_FillingPoints_info3;

//3.��λ����Ϣ�ṹ�嶨��
typedef struct Cum_AnchorPoint_info{
	int num;  //��λ������
	short anchorType; //��λ��ֲ�����
	Rect *anchorPt;  //������λ�����Ӿ��Σ�����ԭ��Ϊͼ�����Ͻǡ�
	int anchorPtCount;
}Cum_AnchorPoint_info;

//4.��ǵ���Ϣ�ṹ�嶨��
typedef struct Cum_Marker_info{
	int xNum;    //�����ǵ�����
	int yNum;    //�����ǵ�����
	cv::Size xSize;   //�����ǵ�ߴ�
	cv::Size ySize;  //�����ǵ�ߴ�
	cv::Rect xMarker;  //�����ǵ�����������
	cv::Rect yMarker;   //�����ǵ�����������
}Cum_Marker_info;
typedef struct Cum_Marker_info3{
	ushort id;             //�Զ����ǵ������
	Rect * xMarker;  //�����ǵ����������� ��Զ�λ���λ����Ϣ
	Rect * yMarker;   //�����ǵ�����������
	int xMarkerCount;
	int yMarkerCount;
}Cum_Marker_info3;
//5.����������Ϣ
typedef struct Cum_CropArea_info{
	char * name;		//������������
	cv::Rect pos;		//��������λ��
	int groupNum;      //�ϲ����
	bool isSecret;      //��������
}Cum_CropArea_info;
//ͬ��ͷ��λ����Ϣ
typedef struct Cum_PerMarker_info{
	int id;    //ͬ��ͷ��������
	Rect pos;  //ͬ��ͷλ��
}Cum_PerMarker_info;

//�⿨��Ϣ���ṹ�嶨��,���ĸ����֣�1.������Ϣ�ṹ�壻2.����Ϣ�ṹ�壻3.��λ����Ϣ��4.���ݱ�ǵ���Ϣ
typedef struct Cum_AC_info3{
	ushort ac_type;   //���⿨����  1��ʾ����һ��2��ʾ���Ͷ���3��ʾ�������б�ǵ㣬4��ʾ�������ޱ�ǵ�
	char * ac_id;   //�Ծ���
	bool isFront;       //�Ƿ�Ϊ����
	cv::Size imgSize;
	bool isAnchorPointExist;           //�Ƿ���ڶ�λ��
	Cum_AnchorPoint_info anchorPointInfo;  //��λ����Ϣ
	bool isAnchorRectExist;            //�Ƿ���ڶ�λ����
	cv::Rect anchorRect;                   //��λ������������
	Rect *pageMarker;			   //ҳ���ʶ����������
	int pageMarkerCount;
	Cum_Marker_info3  * markerInfo;          //����ͬ��ͷ��Ϣ
	int markInfoCunt;
	Cum_Bar_info *barGroup;     //��������
	int barGroupCount;
	Cum_FillingPoints_info3 * fillingPointGroup;	//Ԥ������Ϳ����
	int fillingPointGroupCount;
	Cum_QustionItemPos * questionInfo;   //��Ŀ��Ϣ
	int questionInfoCount;
	Cum_CropArea_info * cropAreaInfo;		//����������Ϣ
	int cropAreaInfoCount;
	Rect blackLine;             //�ڼ����λ��
	Rect whiteLine;             //�׼����λ��
	Rect * refPoint;  //��ʶ��ο����λ�ã�����ԭ��Ϊͼ�����Ͻǡ�
	int refPointCount;
}Cum_AC_info3;

typedef struct Cum_AC_info{
	ushort ac_type;   //���⿨����  1��ʾ����һ��2��ʾ���Ͷ���3��ʾ�������ж�λ�㣬4��ʾ�������޶�λ��
	bool isFront;       //�Ƿ�Ϊ����
	bool isAnchorPointExist;           //�Ƿ���ڶ�λ��
	cv::Size imgSize;
	Cum_AnchorPoint_info anchorPointInfo;  //��λ����Ϣ
	Cum_Marker_info markerInfo;            //��ǵ���Ϣ
	Cum_ItemPos * idPoint;           //�����Ծ��ID���λ����Ϣ
	int idPointCount;
	Cum_Bar_info * barGroup;         //��������
	int barGroupCount;
	Cum_FillingPoints_info * fillingPointGroup;	//Ԥ������Ϳ����
	int fillingPointGroupCount;
	Cum_QustionItemPos * questionInfo;   //��Ŀ��Ϣ
	int questionInfoCount;
	Cum_CropArea_info * cropAreaInfo;		//����������Ϣ������λ�㲻����ʱ�����Ͻ�Ϊԭ��
	int cropAreaInfoCount;
	Rect blackLine;             //�ڼ����λ��
	Rect whiteLine;             //�׼����λ��
	Rect * refPoint;  //��ʶ��ο����λ�ã�����ԭ��Ϊͼ�����Ͻǡ�
	int refPointCount;   //ʶ��ο�������
	int xMarkerCount;   //����ͬ��ͷ����
	int yMarkerCount;   //����ͬ��ͷ����
	Cum_PerMarker_info *xMarker;  //����ͬ��ͷλ����Ϣ
	Cum_PerMarker_info *yMarker;  //����ͬ��ͷλ����Ϣ
}Cum_AC_info;
//���Ŵ��⿨��Ϣ�ṹ��
typedef struct Cum_PerAC_info{
	int tkId;         //�׿����
	int pageId;        //�Ծ���
	Cum_AC_info * acInfo;  //���������棬���һ��Ϊ������Ϣ���ڶ���Ϊ������Ϣ
	int acInfoCount;
}Cum_PerAC_info;
//���������Ŵ��⿨��Ϣ�ṹ��
typedef struct Cum_PerAC_info3{
	int pageId;        //�Ծ�ҳ��
	Cum_AC_info3 * acinfo;
	int acInfoCount;
}Cum_PerAC_info3;

//�׿���Ϣ�ṹ��
typedef struct Cum_TK_info{
	Cum_PerAC_info * tkInfo;
	int tkInfoCount;

}Cum_TK_info;

typedef struct Cum_TK_info3{
	Cum_PerAC_info3 * tkInfo;
	int tkInfoCount;
}Cum_TK_info3;

#endif