/********************************************************************************
** Form generated from reading UI file 'AnchorDlg.ui'
**
** Created: Mon Apr 14 15:53:51 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANCHORDLG_H
#define UI_ANCHORDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AnchorDlg
{
public:
    QGridLayout *mainGridLayout;
    QGroupBox *anchorGroupBox;
    QGridLayout *groupGridLayout;
    QGridLayout *btnGridLayout;
    QPushButton *anchorRBBtn;
    QPushButton *anchorLTBtn;
    QPushButton *anchorRTBtn;
    QPushButton *anchorLBBtn;
    QLabel *label;
    QPushButton *confirmBtn;

    void setupUi(QDialog *AnchorDlg)
    {
        if (AnchorDlg->objectName().isEmpty())
            AnchorDlg->setObjectName(QString::fromUtf8("AnchorDlg"));
        AnchorDlg->setEnabled(true);
        AnchorDlg->resize(218, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AnchorDlg->sizePolicy().hasHeightForWidth());
        AnchorDlg->setSizePolicy(sizePolicy);
        mainGridLayout = new QGridLayout(AnchorDlg);
        mainGridLayout->setSpacing(6);
        mainGridLayout->setContentsMargins(11, 11, 11, 11);
        mainGridLayout->setObjectName(QString::fromUtf8("mainGridLayout"));
        mainGridLayout->setContentsMargins(-1, 3, -1, 5);
        anchorGroupBox = new QGroupBox(AnchorDlg);
        anchorGroupBox->setObjectName(QString::fromUtf8("anchorGroupBox"));
        anchorGroupBox->setEnabled(true);
        anchorGroupBox->setBaseSize(QSize(0, 0));
        anchorGroupBox->setAutoFillBackground(false);
        anchorGroupBox->setFlat(false);
        anchorGroupBox->setCheckable(false);
        groupGridLayout = new QGridLayout(anchorGroupBox);
        groupGridLayout->setSpacing(6);
        groupGridLayout->setContentsMargins(11, 11, 11, 11);
        groupGridLayout->setObjectName(QString::fromUtf8("groupGridLayout"));
        btnGridLayout = new QGridLayout();
        btnGridLayout->setSpacing(6);
        btnGridLayout->setObjectName(QString::fromUtf8("btnGridLayout"));
        anchorRBBtn = new QPushButton(anchorGroupBox);
        anchorRBBtn->setObjectName(QString::fromUtf8("anchorRBBtn"));
        anchorRBBtn->setMinimumSize(QSize(0, 25));

        btnGridLayout->addWidget(anchorRBBtn, 1, 1, 1, 1);

        anchorLTBtn = new QPushButton(anchorGroupBox);
        anchorLTBtn->setObjectName(QString::fromUtf8("anchorLTBtn"));
        anchorLTBtn->setMinimumSize(QSize(0, 25));

        btnGridLayout->addWidget(anchorLTBtn, 0, 0, 1, 1);

        anchorRTBtn = new QPushButton(anchorGroupBox);
        anchorRTBtn->setObjectName(QString::fromUtf8("anchorRTBtn"));
        anchorRTBtn->setMinimumSize(QSize(0, 25));

        btnGridLayout->addWidget(anchorRTBtn, 0, 1, 1, 1);

        anchorLBBtn = new QPushButton(anchorGroupBox);
        anchorLBBtn->setObjectName(QString::fromUtf8("anchorLBBtn"));
        anchorLBBtn->setMinimumSize(QSize(0, 25));

        btnGridLayout->addWidget(anchorLBBtn, 1, 0, 1, 1);


        groupGridLayout->addLayout(btnGridLayout, 1, 0, 1, 1);

        label = new QLabel(anchorGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        groupGridLayout->addWidget(label, 0, 0, 1, 1);

        confirmBtn = new QPushButton(anchorGroupBox);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));
        confirmBtn->setMinimumSize(QSize(0, 28));

        groupGridLayout->addWidget(confirmBtn, 2, 0, 1, 1);


        mainGridLayout->addWidget(anchorGroupBox, 0, 0, 1, 1);

        QWidget::setTabOrder(anchorLTBtn, anchorRTBtn);
        QWidget::setTabOrder(anchorRTBtn, anchorLBBtn);
        QWidget::setTabOrder(anchorLBBtn, anchorRBBtn);
        QWidget::setTabOrder(anchorRBBtn, confirmBtn);

        retranslateUi(AnchorDlg);

        QMetaObject::connectSlotsByName(AnchorDlg);
    } // setupUi

    void retranslateUi(QDialog *AnchorDlg)
    {
        AnchorDlg->setWindowTitle(QApplication::translate("AnchorDlg", "\345\256\232\344\275\215\347\202\271\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        anchorGroupBox->setTitle(QApplication::translate("AnchorDlg", "\345\256\232\344\275\215\347\202\271\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        anchorRBBtn->setText(QApplication::translate("AnchorDlg", "\345\217\263\344\270\213\350\247\222\345\256\232\344\275\215\347\202\271", 0, QApplication::UnicodeUTF8));
        anchorLTBtn->setText(QApplication::translate("AnchorDlg", "\345\267\246\344\270\212\350\247\222\345\256\232\344\275\215\347\202\271", 0, QApplication::UnicodeUTF8));
        anchorRTBtn->setText(QApplication::translate("AnchorDlg", "\345\217\263\344\270\212\350\247\222\345\256\232\344\275\215\347\202\271", 0, QApplication::UnicodeUTF8));
        anchorLBBtn->setText(QApplication::translate("AnchorDlg", "\345\267\246\344\270\213\350\247\222\345\256\232\344\275\215\347\202\271", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AnchorDlg", "\347\202\271\345\207\273\344\270\213\345\210\227\346\214\211\351\222\256\345\274\200\345\247\213\347\202\271\351\200\211\345\220\204\344\270\252\345\256\232\344\275\215\347\202\271", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("AnchorDlg", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnchorDlg: public Ui_AnchorDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANCHORDLG_H
