/********************************************************************************
** Form generated from reading UI file 'LineDetectDlg.ui'
**
** Created: Mon Jun 30 09:41:39 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEDETECTDLG_H
#define UI_LINEDETECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LineDetectDlg
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QPushButton *blackLineBtn;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QPushButton *whiteLineBtn;

    void setupUi(QDialog *LineDetectDlg)
    {
        if (LineDetectDlg->objectName().isEmpty())
            LineDetectDlg->setObjectName(QString::fromUtf8("LineDetectDlg"));
        LineDetectDlg->resize(243, 101);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LineDetectDlg->sizePolicy().hasHeightForWidth());
        LineDetectDlg->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(LineDetectDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 3, -1, 6);
        groupBox = new QGroupBox(LineDetectDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        blackLineBtn = new QPushButton(groupBox);
        blackLineBtn->setObjectName(QString::fromUtf8("blackLineBtn"));
        blackLineBtn->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, blackLineBtn);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        whiteLineBtn = new QPushButton(groupBox);
        whiteLineBtn->setObjectName(QString::fromUtf8("whiteLineBtn"));
        whiteLineBtn->setMinimumSize(QSize(0, 25));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, whiteLineBtn);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(LineDetectDlg);

        QMetaObject::connectSlotsByName(LineDetectDlg);
    } // setupUi

    void retranslateUi(QDialog *LineDetectDlg)
    {
        LineDetectDlg->setWindowTitle(QApplication::translate("LineDetectDlg", "\351\273\221\347\231\275\347\272\277\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LineDetectDlg", "\351\273\221\347\231\275\347\272\277\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LineDetectDlg", "\351\273\221\346\243\200\346\265\213\347\272\277\357\274\232  ", 0, QApplication::UnicodeUTF8));
        blackLineBtn->setText(QApplication::translate("LineDetectDlg", "\346\241\206\351\200\211\351\273\221\346\243\200\346\265\213\347\272\277", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LineDetectDlg", "\347\231\275\346\243\200\346\265\213\347\272\277\357\274\232  ", 0, QApplication::UnicodeUTF8));
        whiteLineBtn->setText(QApplication::translate("LineDetectDlg", "\346\241\206\351\200\211\347\231\275\346\243\200\346\265\213\347\272\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LineDetectDlg: public Ui_LineDetectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEDETECTDLG_H
