/********************************************************************************
** Form generated from reading UI file 'ACSaveDlg.ui'
**
** Created: Mon Jun 30 09:41:35 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACSAVEDLG_H
#define UI_ACSAVEDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_ACSaveDlg
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *okBtn;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *idEdit;
    QLineEdit *dpiEdit;
    QPushButton *cancelBtn;
    QLabel *label;

    void setupUi(QDialog *ACSaveDlg)
    {
        if (ACSaveDlg->objectName().isEmpty())
            ACSaveDlg->setObjectName(QString::fromUtf8("ACSaveDlg"));
        ACSaveDlg->resize(333, 113);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ACSaveDlg->sizePolicy().hasHeightForWidth());
        ACSaveDlg->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(ACSaveDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        okBtn = new QPushButton(ACSaveDlg);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout_2->addWidget(okBtn, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(ACSaveDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        label_2 = new QLabel(ACSaveDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        idEdit = new QLineEdit(ACSaveDlg);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(idEdit, 0, 1, 1, 2);

        dpiEdit = new QLineEdit(ACSaveDlg);
        dpiEdit->setObjectName(QString::fromUtf8("dpiEdit"));
        dpiEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dpiEdit, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        cancelBtn = new QPushButton(ACSaveDlg);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout_2->addWidget(cancelBtn, 2, 2, 1, 1);

        label = new QLabel(ACSaveDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ACSaveDlg);
        QObject::connect(cancelBtn, SIGNAL(clicked()), ACSaveDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(ACSaveDlg);
    } // setupUi

    void retranslateUi(QDialog *ACSaveDlg)
    {
        ACSaveDlg->setWindowTitle(QApplication::translate("ACSaveDlg", "\345\257\274\345\207\272XML", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("ACSaveDlg", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ACSaveDlg", "\345\233\276\345\275\242\345\210\206\350\276\250\347\216\207\344\270\272\357\274\210\345\215\225\344\275\215\357\274\232dpi\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ACSaveDlg", "\350\257\225\345\215\267\347\274\226\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        dpiEdit->setText(QApplication::translate("ACSaveDlg", "0", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ACSaveDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ACSaveDlg", "\350\257\267\350\276\223\345\207\272\344\273\245\344\270\213\344\277\241\346\201\257\345\220\216\347\241\256\345\256\232\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ACSaveDlg: public Ui_ACSaveDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACSAVEDLG_H
