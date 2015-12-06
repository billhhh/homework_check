#ifndef AnswerCardDlg3_H
#define AnswerCardDlg3_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QScrollBar>
#include "qlayout.h"
#include "../XmlIO/ACStructs.h"
#include "AnswerCard.h"
#include "AnchorDlg.h"
#include "BarCodeDlg.h"
#include "ClipDlg.h"
#include "QuestionDlg.h"
#include "ACSaveDlg.h"
#include "FillPointDlg.h"
#include "MarkerMakeDlg.h"
#include "LineDetectDlg.h"
#include "IsFrontDlg.h"
#include "AnchorRectDlg.h"
#include "CardSetDlg.h"
#include "PagePointDlg.h"
#include "ClearDlg.h"
#include "CreateCardDlg.h"

namespace Ui {class AnswerCardDlg3;};

#define TOP_LEFT 0
#define TOP_RIGHT 1
#define BOTTOM_RIGHT 2
#define BOTTOM_LEFT 3
#define LEFT 4
#define TOP 5
#define RIGHT 6
#define BOTTOM 7
#define CENTER 8
#define CTRL_POINT_LENGTH 8     //���Ƶ�߳�
#define CTRL_RECT_MIN_LENGTH 12 //ѡ�����С�߳�

class AnswerCardDlg3 : public QDialog
{
	Q_OBJECT

public:
	AnswerCardDlg3(QApplication &app, int type = 4);
	~AnswerCardDlg3();

	//��Mat��ʽ��ͼƬתΪQImage���
	QImage mat2QImage(const cv::Mat &mat);

	//��QImage��ʽ��ͼƬתΪMat
	cv::Mat qImage2Mat(const QImage &img);

protected:
	int setDataSource(const QString &path);
	void saveDataSource(const QString &path);

	//�ػ��¼�
	void paintEvent(QPaintEvent *);

	//��ʼ�����ڲ���
	void initialization();

	// ����ͻ�����һ������ͼ���е�λ��
	QPoint GetImgPosFromClient(const QPoint &clientPos);

	//�¼�����
	bool eventFilter(QObject *, QEvent *);

	//����������
	void mouseLeftButtonPress(const QPoint &pos);

	//����������
	void mouseLeftButtonRelease(const QPoint &pos);

	//����ƶ�
	void mouseMove(const QPoint &pos);

	//���������
	void changeMouseCursor(const QPoint &pos);

	//��ҷѡȡ���ػ�
	void dragMarquee(const QPoint &newPos, int ctlPointIndex);

	//���ƿ��Ƶ�
	void drawControlPoint(const QPoint &centerPos, int length, cv::Scalar scalar, ushort thickness);

	//���¼���Ÿ����Ƶ��λ��
	void computeCtrlPointPos();

	void anchorProcessingOnMouseUp(const QPoint &pos);      //����λģ���������ͷ��¼�
	void barcodeProcessingOnMouseUp(const QPoint &pos);     //����������ģ���������ͷ��¼�
	void fillPointProcessingOnMouseUp(const QPoint &pos);
	void clipProcessingOnMouseUp(const QPoint &pos);
	void questionProcessingOnMouseUp(const QPoint &pos);
	void whiteLineProcessingOnMouseUp(const QPoint &pos);
	void blackLineProcessingOnMouseUp(const QPoint &pos);
	void makerMakeProcessingOnMouseUp(const QPoint &pos);
	void anchorRectProcessingOnMouseUp(const QPoint &pos);
	void pagePointProcessingOnMouseUp(const QPoint &pos);
	void markerProcessingOnMouseUp(const QPoint &pos);

	void barcodeProcessingOnMouseMove(const QPoint &pos);
	void fillPointProcessingOnMouseMove(const QPoint &pos);
	void clipProcessingOnMouseMove(const QPoint &pos);
	void questionProcessingOnMouseMove(const QPoint &pos);
	void whiteLineProcessingOnMouseMove(const QPoint &pos);
	void blackLineProcessingOnMouseMove(const QPoint &pos);
	void makerMakeProcessingOnMouseMove(const QPoint &pos);
	void anchorRectProcessingOnMouseMove(const QPoint &pos);
	void pagePointProcessingOnMouseMove(const QPoint &pos);
	void markerProcessingOnMouseMove(const QPoint &pos);

protected:
	QString m_cardPath;			//��ǰ���⿨�ļ�·��
	QPoint m_mouseDownPoint;    //��갴������
	QRect m_picRect;            //ͼ�������С	
	short m_hmarkers_num;       //ˮƽ��ǵ�����	
	short m_vmarkers_num;       //��ֱ��ǵ�����		
	Mat m_imgTmp;
	bool m_isZooming;
	int m_zoomingIndex;

	QRect m_controlPoint[9];    //ѡȡ��ľŸ����Ƶ�
	cv::Rect m_controlRect;     //ѡȡ������
	int m_ctrlPointIndex;       //����ҷ�Ŀ��Ƶ�
	
	Ui::AnswerCardDlg3 *ui;
	AnchorDlg *m_anchorDlg;               //��λ�㴰��
	BarCodeDlg *m_barcodeDlg;             //�����봰��
	ClipDlg *m_clipDlg;                   //���д���
	FillPointDlg *m_fillPointDlg;         //��Ϳ�㴰��
	MarkerMakeDlg *m_markerMakeDlg;       //�����ǵ���������
	LineDetectDlg * m_lineDetectDlg;      //�ڰ��ߴ���
	PagePointDlg *m_pagePointDlg;         //ҳ���ʶ����
	CardSetDlg * m_cardSetDlg;			  //�׿�������
	ClearDlg *m_clearDlg;
//	IsFrontDlg *m_isFrontDlg;
	AnchorRectDlg *m_anchorRectDlg;       //��λ�򴰿�
	QSpacerItem *m_verticalSpacer;        //ռλ���ؼ�
	QPushButton *m_clearBtn;              //����ʽ�����ť
	QPushButton *m_changePicBtn;          //����ָ���Ծ�ͼƬ��ť
	int m_cardType;

protected slots:
	//�����µ��׿�
	void on_newCardBtn_clicked();
	////���XML�ļ�
	void on_importXMLBtn_clicked();
	//�����ļ�
	void on_saveFileBtn_clicked();
	//��ȡ�ļ�
	void on_openFileBtn_clicked();

	//��λ����
	void anchorDone();
	//��ǵ����
	void markerDone();
	//ʹ�����Ӵ��ڿɱ༭
	void enableDlg();
	//��ʼ�������ѡ
	void barCodeBegin();
	void fillPointBegin();
	void clipBegin();
	void markerMakeBegin();
	void lineDetectBegin();
	void lineDetectDone();
	void pagePointBegin();
	void markerMakeDelete();

	//����������
	void clipClicked(int idx);
	void barCodeClicked(int idx);
	void fillPointClicked();
	void markerMakeClicked();

	void editCard(QString);
	void deleteCard(QString);
	void on_clearBtn_clicked();
	void on_changePicBtn_clicked();
};

#endif // AnswerCardDlg3_H
