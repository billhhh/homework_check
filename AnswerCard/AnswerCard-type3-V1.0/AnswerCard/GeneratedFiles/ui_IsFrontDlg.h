/********************************************************************************
** Form generated from reading UI file 'IsFrontDlg.ui'
**
** Created: Mon Apr 14 15:53:52 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISFRONTDLG_H
#define UI_ISFRONTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_IsFrontDlg
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *typeCbx;

    void setupUi(QDialog *IsFrontDlg)
    {
        if (IsFrontDlg->objectName().isEmpty())
            IsFrontDlg->setObjectName(QString::fromUtf8("IsFrontDlg"));
        IsFrontDlg->resize(240, 65);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IsFrontDlg->sizePolicy().hasHeightForWidth());
        IsFrontDlg->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(IsFrontDlg);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 5, -1, 6);
        groupBox = new QGroupBox(IsFrontDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        typeCbx = new QComboBox(groupBox);
        typeCbx->setObjectName(QString::fromUtf8("typeCbx"));

        formLayout->setWidget(0, QFormLayout::FieldRole, typeCbx);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(IsFrontDlg);

        QMetaObject::connectSlotsByName(IsFrontDlg);
    } // setupUi

    void retranslateUi(QDialog *IsFrontDlg)
    {
        IsFrontDlg->setWindowTitle(QApplication::translate("IsFrontDlg", "\346\255\243/\345\217\215\351\235\242", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("IsFrontDlg", "\346\255\243/\345\217\215\351\235\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IsFrontDlg", "\347\261\273\345\236\213\351\200\211\346\213\251\357\274\232  ", 0, QApplication::UnicodeUTF8));
        typeCbx->clear();
        typeCbx->insertItems(0, QStringList()
         << QApplication::translate("IsFrontDlg", "\346\255\243\351\235\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("IsFrontDlg", "\345\217\215\351\235\242", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class IsFrontDlg: public Ui_IsFrontDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISFRONTDLG_H
