/********************************************************************************
** Form generated from reading UI file 'InputNumberDlg.ui'
**
** Created: Mon Apr 14 15:53:52 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTNUMBERDLG_H
#define UI_INPUTNUMBERDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_InputNumberDlg
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *numEdit;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *InputNumberDlg)
    {
        if (InputNumberDlg->objectName().isEmpty())
            InputNumberDlg->setObjectName(QString::fromUtf8("InputNumberDlg"));
        InputNumberDlg->resize(266, 82);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputNumberDlg->sizePolicy().hasHeightForWidth());
        InputNumberDlg->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(InputNumberDlg);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(InputNumberDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        numEdit = new QLineEdit(InputNumberDlg);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));

        gridLayout_2->addWidget(numEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        okBtn = new QPushButton(InputNumberDlg);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout->addWidget(okBtn, 0, 1, 1, 1);

        cancelBtn = new QPushButton(InputNumberDlg);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(InputNumberDlg);

        QMetaObject::connectSlotsByName(InputNumberDlg);
    } // setupUi

    void retranslateUi(QDialog *InputNumberDlg)
    {
        InputNumberDlg->setWindowTitle(QApplication::translate("InputNumberDlg", "\350\231\232\346\213\237\346\240\207\350\256\260\347\202\271", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InputNumberDlg", "\350\257\267\350\276\223\345\205\245\350\246\201\347\273\230\345\210\266\347\232\204\346\240\207\350\256\260\347\202\271\347\232\204\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("InputNumberDlg", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("InputNumberDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InputNumberDlg: public Ui_InputNumberDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTNUMBERDLG_H
