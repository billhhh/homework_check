#ifndef ANSWERCARDDLG_H
#define ANSWERCARDDLG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QScrollBar>
#include <QCloseEvent>
#include "qlayout.h"
#include "DataIO.h"
#include "AnswerCard.h"
#include "AnchorDlg.h"
#include "MarkerDlg.h"
#include "BarCodeDlg.h"
#include "ClipDlg.h"
#include "ACSaveDlg.h"
#include "FillPointDlg.h"
#include "LineDetectDlg.h"
#include "IdPointDlg.h"
#include "IsFrontDlg.h"
#include "qpushbutton.h"

namespace Ui {class AnswerCardDlg;};

#define TOP_LEFT 0            //����
#define TOP_RIGHT 1           //����
#define BOTTOM_RIGHT 2
#define BOTTOM_LEFT 3
#define LEFT 4
#define TOP 5
#define RIGHT 6
#define BOTTOM 7
#define CENTER 8
#define CTRL_POINT_LENGTH 8     //���Ƶ�߳�
#define CTRL_RECT_MIN_LENGTH 12 //ѡ�����С�߳�

class AnswerCardDlg : public QDialog
{
	Q_OBJECT

public:
	AnswerCardDlg(QString pathPrefix = "");
	~AnswerCardDlg();

	//��Mat��ʽ��ͼƬתΪQImage���
	static QImage mat2QImage(const cv::Mat &mat);

	//��QImage��ʽ��ͼƬתΪMat
	static cv::Mat qImage2Mat(const QImage &img);

	//����������Դ
	int setDataSource(const QString& filePath); 

protected:
	void keyPressEvent(QKeyEvent *event);

	//�ػ��¼�
	void paintEvent(QPaintEvent *);

	//��ʼ�����ڲ���
	void initialization();

	//�����˳�����ĺ���
	void closeEvent(QCloseEvent *event);

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

	void anchorProcessingOnMouseUp(const QPoint &pos);
	void markerProcessingOnMouseUp(const QPoint &pos);
	void barcodeProcessingOnMouseUp(const QPoint &pos);
	void fillPointProcessingOnMouseUp(const QPoint &pos);
	void clipProcessingOnMouseUp(const QPoint &pos);
	void questionProcessingOnMouseUp(const QPoint &pos);
	void whiteLineProcessingOnMouseUp(const QPoint &pos);
	void blackLineProcessingOnMouseUp(const QPoint &pos);
	void idPointProcessingOnMouseUp(const QPoint &pos);

	void markerProcessingOnMouseMove(const QPoint &pos);
	void barcodeProcessingOnMouseMove(const QPoint &pos);
	void fillPointProcessingOnMouseMove(const QPoint &pos);
	void clipProcessingOnMouseMove(const QPoint &pos);
	void questionProcessingOnMouseMove(const QPoint &pos);
	void whiteLineProcessingOnMouseMove(const QPoint &pos);
	void blackLineProcessingOnMouseMove(const QPoint &pos);
	void idPointProcessingOnMouseMove(const QPoint &pos);

	//�ļ�����
	void saveDataSource();

protected:
	QPoint m_mouseDownPoint;    //��갴������
	QRect m_picRect;            //ͼ�������С	
	short m_hmarkers_num;       //ˮƽ��ǵ�����	
	short m_vmarkers_num;       //��ֱ��ǵ�����		
	QString m_dataPath;         //�ļ�·��
	QString m_dataPathPrefix;   //�ļ�·��ǰ׺
	bool m_isSaved;             //�Ƿ��ѱ���
	bool m_isFront;             //�Ƿ�Ϊ����
	static Mat m_imgTmp; 
	bool m_isZooming;           //�Ƿ��������ſ�ѡ����
	int m_zoomingIndex;         //��¼���϶���ѡ����ĸ��㣬���ϡ����ϡ����µ�

	QRect m_controlPoint[9];    //ѡȡ��ľŸ����Ƶ�
	cv::Rect m_controlRect;     //ѡȡ������
	int m_ctrlPointIndex;       //����ҷ�Ŀ��Ƶ�
	
	Ui::AnswerCardDlg *ui;

	AnchorDlg *m_anchorDlg;               //��λ�㴰��
	MarkerDlg *m_markerDlg;               //��ǵ㴰��
	BarCodeDlg *m_barcodeDlg;             //�����봰��
	ClipDlg *m_clipDlg;                   //���д���
	FillPointDlg *m_fillPointDlg;         //��Ϳ�㴰��
	IsFrontDlg *m_isFrontDlg;
	LineDetectDlg * m_lineDetectDlg;
	IdPointDlg *m_idPointDlg;

	QPushButton *m_clearBtn;             //�������ʽ����
	QPushButton *m_changePicBtn;            //�滻����ʽͼƬ

protected slots:
	
	void on_backBtn_clicked();

	//�����ڼ�����ر�
	void anchorDone();
	void markerDone();	
	void enableDlg();
	void barCodeBegin();
	void fillPointBegin();
	void clipBegin();
	void deleteBtnClicked();
	void lineDetectBegin();
	void lineDetectDone();
	void idPointBegin();
	void clipClicked(int idx);
	void barCodeClicked(int idx);
	void fillPointClicked(int idx);
	void idPointClicked(int idx);
	void pageChanged(int idx);
	void on_clearBtn_clicked();
	void on_changePicBtn_clicked();
};

#endif // ANSWERCARDDLG_H
