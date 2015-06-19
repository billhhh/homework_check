#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "showdocument.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMainWindow>
#include <QTextCodec>
#include <QAxObject>
#include <QAxWidget>
#include <QVariant>
#include <QMessageBox>
#include <qDebug>
#include <vector>
#include "logic/XmlReader.h"
#include "logic/Controller.h"
#include "logic/studentMap.h"
#include "logic/StringCompare.h"
#include "GeneratedFiles/ui_mainwindow.h"

#define HOMEWORKNUM 7

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString excelPath;
    QString homeworkPath;
    QString *StudentName;//StudentName[0]��StudentNum[0]����Ŀ�
    QString *StudentNum;//��ѧ��ѧ��ͬ��ѧ�������Ĺ��̣���ֹ�����������鸳ֵ֮ǰ�ͽ��з��ʣ�on_StudentNameComboBox_currentIndexChanged(int index)��
	int StuNum;
	vector <studentMap> stuMap;  //ѧ��������ѧ��ӳ��
	void addchild(QTreeWidgetItem *parent, QString studentname1, QString studentname2, QString similarity);
	QTreeWidgetItem *addroot(QString studentname1, QString studentname2, QString similarity);

private slots:

    void on_StudentNameComboBox_currentIndexChanged(int index);
    void on_submitBtn_clicked();
    void on_rltTreeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
