#include"ACStructs.h"
#include"MarkersBoundaryTable.h"
#define QUESSTION_ERERR_SMALL    1           //�����̫С
#define QUESSTION_ERERR_LARGE  2          //�����̫��
Point GetMinCropArea(MarkersBoundaryTable &mbt,vector<FillingPoints_info> fillingPointGroup);
//���Ͷ�����
//int DetectAnswer1(Mat Img,vector<ItemPos> questionInfo,MarkersBoundaryTable &mbt,AnswerResult &ar,double sensibilityThresh,double areaThreshold);
//������
int DetectAnswer(Mat Img,vector<ItemPos> questionInfo,MarkersBoundaryTable &mbt,AnswerResult &ar,bool quetionType,double sensibilityThresh,double areaThreshold,double seSize=0);
//����������
int DetectAnswer(Mat Img,vector<ItemPos> questionInfo,map<ushort,MarkersBoundaryTable*> &mbtMap,AnswerResult &ar,bool quetionType,double sensibilityThresh,double areaThreshold,double seSize=0);
//����һ
int DetectAnswer1(Mat Img,vector<ItemPos> questionInfo,MarkersBoundaryTable &mbt,AnswerResult &ar,double sensibilityThresh,double areaThreshold);
//���Ͷ����� ÿС��Ĵ�ʶ��
int DetectPreQuestionAnswer( Mat roi,bool isCrosswise,bool isSingleChoice,int optionNum,bool quetionType,double sensibilityThresh,double areaThreshold,double seSizeTh,PerquestionResult &result);
//����һ ÿС��Ĵ�ʶ��
int DetectPreQuestionAnswer1( Mat roi,ItemPos itemPos,int optionNum,double sensibilityThresh,double areaThreshold,PerquestionResult &result);  //0.���� 1.û����Ϳ
//����һ���� ÿС��Ĵ�ʶ�� ����mbt��ȷ��λ
int DetectPreQuestionAnswer1( Mat roi,int &globalGray,MarkersBoundaryTable &mbt,Point rectPos,ItemPos perQuestionInfo,int optionNum,double sensibilityThresh,double areaThreshold,PerquestionResult &result);

