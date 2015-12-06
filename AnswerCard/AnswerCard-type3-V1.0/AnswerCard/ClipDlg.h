#ifndef CLIPDLG_H
#define CLIPDLG_H

#include <QDialog>
#include <QMessageBox>
#include "qlistwidget.h"

namespace Ui {class ClipDlg;};

class ClipDlg : public QDialog
{
	Q_OBJECT

public:
	ClipDlg(QWidget *parent = 0);
	~ClipDlg();

	void setConfirmBtnEnabled(bool);
	void initialization();//��ʼ��

	int resume();        //�������ݻָ�������Ϣ
private:
	Ui::ClipDlg *ui;
	bool isSecretClicked;  //�Ƿ�Ϊ��������

	void setProcessing(bool);

signals:
	void clipBegin();   //���п�ʼ
	void clipDone();    //���н���
	void clipDelete();
	void clipClicked(int);

protected slots:
	void on_addBtn_clicked();//�����Ӳ�������İ�ť
	void on_confirmBtn_clicked();//ȷ�ϲ�������
	void on_deleteBtn_clicked();//ɾ����������
	void on_secretCheckBox_toggled();
	void showClicked(QListWidgetItem* item);
};

#endif // CLIPDLG_H
