/********************************************************************************
** Form generated from reading UI file 'FillPointDlg.ui'
**
** Created: Mon Apr 14 15:53:52 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILLPOINTDLG_H
#define UI_FILLPOINTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FillPointDlg
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *fillPointGroupBox;
    QGridLayout *gridLayout;
    QFormLayout *topLayout;
    QLabel *label;
    QComboBox *typeCmb;
    QFormLayout *formLayout;
    QLabel *groupLabel;
    QComboBox *groupCmb;
    QHBoxLayout *topLayout_2;
    QLabel *paibuLabel;
    QRadioButton *horRadioBtn;
    QRadioButton *verRadioBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *typeLabel;
    QRadioButton *singleRadioBtn;
    QRadioButton *multiRadioBtn;
    QCheckBox *questionTypeCbx;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *optionNumLabel;
    QLineEdit *optionEdit;
    QLabel *countLabel;
    QLineEdit *numEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *hSpaceLabel;
    QLineEdit *rSpaceEdit;
    QLabel *vSpaceLabel;
    QLineEdit *cSpaceEdit;
    QHBoxLayout *midLayout;
    QPushButton *addBtn;
    QPushButton *confirmBtn;
    QGridLayout *bottomLayout;
    QPushButton *deleteBtn;
    QListWidget *list;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *FillPointDlg)
    {
        if (FillPointDlg->objectName().isEmpty())
            FillPointDlg->setObjectName(QString::fromUtf8("FillPointDlg"));
        FillPointDlg->resize(303, 456);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FillPointDlg->sizePolicy().hasHeightForWidth());
        FillPointDlg->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(FillPointDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 3, -1, 6);
        fillPointGroupBox = new QGroupBox(FillPointDlg);
        fillPointGroupBox->setObjectName(QString::fromUtf8("fillPointGroupBox"));
        gridLayout = new QGridLayout(fillPointGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topLayout = new QFormLayout();
        topLayout->setSpacing(6);
        topLayout->setObjectName(QString::fromUtf8("topLayout"));
        label = new QLabel(fillPointGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        topLayout->setWidget(0, QFormLayout::LabelRole, label);

        typeCmb = new QComboBox(fillPointGroupBox);
        typeCmb->setObjectName(QString::fromUtf8("typeCmb"));

        topLayout->setWidget(0, QFormLayout::FieldRole, typeCmb);


        gridLayout->addLayout(topLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupLabel = new QLabel(fillPointGroupBox);
        groupLabel->setObjectName(QString::fromUtf8("groupLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, groupLabel);

        groupCmb = new QComboBox(fillPointGroupBox);
        groupCmb->setObjectName(QString::fromUtf8("groupCmb"));

        formLayout->setWidget(0, QFormLayout::FieldRole, groupCmb);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        topLayout_2 = new QHBoxLayout();
        topLayout_2->setSpacing(6);
        topLayout_2->setObjectName(QString::fromUtf8("topLayout_2"));
        paibuLabel = new QLabel(fillPointGroupBox);
        paibuLabel->setObjectName(QString::fromUtf8("paibuLabel"));

        topLayout_2->addWidget(paibuLabel);

        horRadioBtn = new QRadioButton(fillPointGroupBox);
        buttonGroup_2 = new QButtonGroup(FillPointDlg);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(horRadioBtn);
        horRadioBtn->setObjectName(QString::fromUtf8("horRadioBtn"));
        horRadioBtn->setChecked(true);

        topLayout_2->addWidget(horRadioBtn);

        verRadioBtn = new QRadioButton(fillPointGroupBox);
        buttonGroup_2->addButton(verRadioBtn);
        verRadioBtn->setObjectName(QString::fromUtf8("verRadioBtn"));

        topLayout_2->addWidget(verRadioBtn);


        gridLayout->addLayout(topLayout_2, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        typeLabel = new QLabel(fillPointGroupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        horizontalLayout_2->addWidget(typeLabel);

        singleRadioBtn = new QRadioButton(fillPointGroupBox);
        buttonGroup = new QButtonGroup(FillPointDlg);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(singleRadioBtn);
        singleRadioBtn->setObjectName(QString::fromUtf8("singleRadioBtn"));
        singleRadioBtn->setChecked(true);

        horizontalLayout_2->addWidget(singleRadioBtn);

        multiRadioBtn = new QRadioButton(fillPointGroupBox);
        buttonGroup->addButton(multiRadioBtn);
        multiRadioBtn->setObjectName(QString::fromUtf8("multiRadioBtn"));

        horizontalLayout_2->addWidget(multiRadioBtn);

        questionTypeCbx = new QCheckBox(fillPointGroupBox);
        questionTypeCbx->setObjectName(QString::fromUtf8("questionTypeCbx"));

        horizontalLayout_2->addWidget(questionTypeCbx);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        nameLabel = new QLabel(fillPointGroupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_4->addWidget(nameLabel);

        nameEdit = new QLineEdit(fillPointGroupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(true);
        nameEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(nameEdit);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        checkBox = new QCheckBox(fillPointGroupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_5->addWidget(checkBox);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        optionNumLabel = new QLabel(fillPointGroupBox);
        optionNumLabel->setObjectName(QString::fromUtf8("optionNumLabel"));

        horizontalLayout_3->addWidget(optionNumLabel);

        optionEdit = new QLineEdit(fillPointGroupBox);
        optionEdit->setObjectName(QString::fromUtf8("optionEdit"));
        optionEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(optionEdit);

        countLabel = new QLabel(fillPointGroupBox);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));

        horizontalLayout_3->addWidget(countLabel);

        numEdit = new QLineEdit(fillPointGroupBox);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(numEdit);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hSpaceLabel = new QLabel(fillPointGroupBox);
        hSpaceLabel->setObjectName(QString::fromUtf8("hSpaceLabel"));

        horizontalLayout->addWidget(hSpaceLabel);

        rSpaceEdit = new QLineEdit(fillPointGroupBox);
        rSpaceEdit->setObjectName(QString::fromUtf8("rSpaceEdit"));
        rSpaceEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(rSpaceEdit);

        vSpaceLabel = new QLabel(fillPointGroupBox);
        vSpaceLabel->setObjectName(QString::fromUtf8("vSpaceLabel"));

        horizontalLayout->addWidget(vSpaceLabel);

        cSpaceEdit = new QLineEdit(fillPointGroupBox);
        cSpaceEdit->setObjectName(QString::fromUtf8("cSpaceEdit"));
        cSpaceEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(cSpaceEdit);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        midLayout = new QHBoxLayout();
        midLayout->setSpacing(6);
        midLayout->setObjectName(QString::fromUtf8("midLayout"));
        addBtn = new QPushButton(fillPointGroupBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        midLayout->addWidget(addBtn);

        confirmBtn = new QPushButton(fillPointGroupBox);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));

        midLayout->addWidget(confirmBtn);


        gridLayout->addLayout(midLayout, 7, 0, 1, 1);

        bottomLayout = new QGridLayout();
        bottomLayout->setSpacing(6);
        bottomLayout->setObjectName(QString::fromUtf8("bottomLayout"));
        deleteBtn = new QPushButton(fillPointGroupBox);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy1);
        deleteBtn->setMinimumSize(QSize(0, 30));
        deleteBtn->setMaximumSize(QSize(40, 16777215));

        bottomLayout->addWidget(deleteBtn, 0, 1, 1, 1);

        list = new QListWidget(fillPointGroupBox);
        list->setObjectName(QString::fromUtf8("list"));
        list->setMinimumSize(QSize(0, 30));

        bottomLayout->addWidget(list, 0, 0, 1, 1);


        gridLayout->addLayout(bottomLayout, 8, 0, 1, 1);


        gridLayout_2->addWidget(fillPointGroupBox, 0, 0, 1, 1);


        retranslateUi(FillPointDlg);

        QMetaObject::connectSlotsByName(FillPointDlg);
    } // setupUi

    void retranslateUi(QDialog *FillPointDlg)
    {
        FillPointDlg->setWindowTitle(QApplication::translate("FillPointDlg", "FillPointDlg", 0, QApplication::UnicodeUTF8));
        fillPointGroupBox->setTitle(QApplication::translate("FillPointDlg", "\345\241\253\346\266\202\347\202\271\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FillPointDlg", "\345\241\253\346\266\202\347\202\271\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        typeCmb->clear();
        typeCmb->insertItems(0, QStringList()
         << QApplication::translate("FillPointDlg", "\351\200\211\346\213\251\351\242\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\345\272\247\344\275\215\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\350\200\203\345\234\272\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\350\257\225\345\256\244\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\351\246\226\350\200\203\347\224\237\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\345\207\206\350\200\203\350\257\201\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\347\247\221\347\233\256\345\217\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\347\274\272\350\200\203", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\350\257\225\345\215\267\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\351\200\211\345\201\232\351\242\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\350\277\235\347\272\252", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\351\241\265\347\240\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FillPointDlg", "\350\257\206\345\210\253\345\217\202\350\200\203\347\202\271", 0, QApplication::UnicodeUTF8)
        );
        groupLabel->setText(QApplication::translate("FillPointDlg", "\346\240\207\350\256\260\347\202\271\347\273\204\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        paibuLabel->setText(QApplication::translate("FillPointDlg", "\351\200\211\351\241\271\346\216\222\345\270\203\357\274\232", 0, QApplication::UnicodeUTF8));
        horRadioBtn->setText(QApplication::translate("FillPointDlg", "\346\250\252\345\220\221", 0, QApplication::UnicodeUTF8));
        verRadioBtn->setText(QApplication::translate("FillPointDlg", "\347\272\265\345\220\221", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("FillPointDlg", "\351\242\230\347\233\256\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        singleRadioBtn->setText(QApplication::translate("FillPointDlg", "\345\215\225\351\200\211", 0, QApplication::UnicodeUTF8));
        multiRadioBtn->setText(QApplication::translate("FillPointDlg", "\345\244\232\351\200\211", 0, QApplication::UnicodeUTF8));
        questionTypeCbx->setText(QApplication::translate("FillPointDlg", "\345\220\253ABCD", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("FillPointDlg", "\345\220\215    \347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("FillPointDlg", "\344\273\2450\345\274\200\345\244\264", 0, QApplication::UnicodeUTF8));
        optionNumLabel->setText(QApplication::translate("FillPointDlg", "\351\242\230    \345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        optionEdit->setToolTip(QApplication::translate("FillPointDlg", "\345\217\257\350\276\223\345\205\245\351\242\230\345\217\267\350\214\203\345\233\264,\345\246\202: 1-5", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        countLabel->setText(QApplication::translate("FillPointDlg", "\351\200\211\351\241\271\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        hSpaceLabel->setText(QApplication::translate("FillPointDlg", "\346\250\252\345\220\221\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        vSpaceLabel->setText(QApplication::translate("FillPointDlg", "\347\272\265\345\220\221\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("FillPointDlg", "\346\267\273\345\212\240\345\241\253\346\266\202\347\202\271", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("FillPointDlg", "\347\241\256\350\256\244\345\241\253\346\266\202\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("FillPointDlg", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FillPointDlg: public Ui_FillPointDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILLPOINTDLG_H
