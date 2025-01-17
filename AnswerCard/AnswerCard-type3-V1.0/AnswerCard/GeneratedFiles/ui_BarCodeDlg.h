/********************************************************************************
** Form generated from reading UI file 'BarCodeDlg.ui'
**
** Created: Mon Apr 14 15:53:51 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCODEDLG_H
#define UI_BARCODEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BarCodeDlg
{
public:
    QGridLayout *mainLayout;
    QGroupBox *groupBox;
    QGridLayout *groupLayout;
    QFormLayout *topLayout;
    QLabel *label;
    QComboBox *typeCmb;
    QHBoxLayout *midLayout;
    QPushButton *addBtn;
    QPushButton *confirmBtn;
    QGridLayout *bottomLayout;
    QPushButton *deleteBtn;
    QListWidget *codebarList;

    void setupUi(QDialog *BarCodeDlg)
    {
        if (BarCodeDlg->objectName().isEmpty())
            BarCodeDlg->setObjectName(QString::fromUtf8("BarCodeDlg"));
        BarCodeDlg->resize(259, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BarCodeDlg->sizePolicy().hasHeightForWidth());
        BarCodeDlg->setSizePolicy(sizePolicy);
        BarCodeDlg->setMaximumSize(QSize(16777215, 150));
        mainLayout = new QGridLayout(BarCodeDlg);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(-1, 6, -1, 6);
        groupBox = new QGroupBox(BarCodeDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupLayout = new QGridLayout(groupBox);
        groupLayout->setSpacing(6);
        groupLayout->setContentsMargins(11, 11, 11, 11);
        groupLayout->setObjectName(QString::fromUtf8("groupLayout"));
        topLayout = new QFormLayout();
        topLayout->setSpacing(6);
        topLayout->setObjectName(QString::fromUtf8("topLayout"));
        topLayout->setHorizontalSpacing(6);
        topLayout->setVerticalSpacing(6);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));

        topLayout->setWidget(0, QFormLayout::LabelRole, label);

        typeCmb = new QComboBox(groupBox);
        typeCmb->setObjectName(QString::fromUtf8("typeCmb"));
        typeCmb->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setKerning(true);
        typeCmb->setFont(font);

        topLayout->setWidget(0, QFormLayout::FieldRole, typeCmb);


        groupLayout->addLayout(topLayout, 0, 0, 1, 1);

        midLayout = new QHBoxLayout();
        midLayout->setSpacing(6);
        midLayout->setObjectName(QString::fromUtf8("midLayout"));
        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setMinimumSize(QSize(0, 0));

        midLayout->addWidget(addBtn);

        confirmBtn = new QPushButton(groupBox);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));

        midLayout->addWidget(confirmBtn);


        groupLayout->addLayout(midLayout, 1, 0, 1, 1);

        bottomLayout = new QGridLayout();
        bottomLayout->setSpacing(6);
        bottomLayout->setObjectName(QString::fromUtf8("bottomLayout"));
        deleteBtn = new QPushButton(groupBox);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy1);
        deleteBtn->setMaximumSize(QSize(40, 55));

        bottomLayout->addWidget(deleteBtn, 0, 1, 1, 1);

        codebarList = new QListWidget(groupBox);
        codebarList->setObjectName(QString::fromUtf8("codebarList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(codebarList->sizePolicy().hasHeightForWidth());
        codebarList->setSizePolicy(sizePolicy2);
        codebarList->setMaximumSize(QSize(16777215, 45));

        bottomLayout->addWidget(codebarList, 0, 0, 1, 1);


        groupLayout->addLayout(bottomLayout, 2, 0, 1, 1);


        mainLayout->addWidget(groupBox, 0, 0, 1, 1);

        QWidget::setTabOrder(typeCmb, addBtn);
        QWidget::setTabOrder(addBtn, confirmBtn);
        QWidget::setTabOrder(confirmBtn, codebarList);
        QWidget::setTabOrder(codebarList, deleteBtn);

        retranslateUi(BarCodeDlg);

        QMetaObject::connectSlotsByName(BarCodeDlg);
    } // setupUi

    void retranslateUi(QDialog *BarCodeDlg)
    {
        BarCodeDlg->setWindowTitle(QApplication::translate("BarCodeDlg", "\346\235\241\345\275\242\347\240\201\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BarCodeDlg", "\346\235\241\345\275\242\347\240\201\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BarCodeDlg", "\346\235\241\345\275\242\347\240\201\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        typeCmb->clear();
        typeCmb->insertItems(0, QStringList()
         << QApplication::translate("BarCodeDlg", "\350\257\225\345\215\267\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BarCodeDlg", "\345\207\206\350\200\203\350\257\201\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BarCodeDlg", "\350\257\225\345\256\244\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BarCodeDlg", "\347\274\272\350\200\203", 0, QApplication::UnicodeUTF8)
        );
        addBtn->setText(QApplication::translate("BarCodeDlg", "\346\241\206\351\200\211\346\235\241\345\275\242\347\240\201", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("BarCodeDlg", "\347\241\256\350\256\244\346\235\241\345\275\242\347\240\201", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("BarCodeDlg", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BarCodeDlg: public Ui_BarCodeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCODEDLG_H
