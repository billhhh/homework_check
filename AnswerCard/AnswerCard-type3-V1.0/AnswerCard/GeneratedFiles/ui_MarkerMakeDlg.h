/********************************************************************************
** Form generated from reading UI file 'MarkerMakeDlg.ui'
**
** Created: Mon Apr 14 15:53:52 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKERMAKEDLG_H
#define UI_MARKERMAKEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MarkerMakeDlg
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *groupEdit;
    QLabel *label_4;
    QLineEdit *sizeEdit;
    QPushButton *sizeBtn;
    QLabel *label_5;
    QLineEdit *horEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *horBtn;
    QPushButton *hDragBtn;
    QLabel *label_3;
    QLineEdit *verEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *verBtn;
    QPushButton *vDragBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QListWidget *subList;
    QPushButton *deleteMarkerBtn;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *list;
    QVBoxLayout *verticalLayout;
    QPushButton *editBtn;
    QPushButton *deleteBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *addBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *MarkerMakeDlg)
    {
        if (MarkerMakeDlg->objectName().isEmpty())
            MarkerMakeDlg->setObjectName(QString::fromUtf8("MarkerMakeDlg"));
        MarkerMakeDlg->resize(291, 332);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MarkerMakeDlg->sizePolicy().hasHeightForWidth());
        MarkerMakeDlg->setSizePolicy(sizePolicy);
        MarkerMakeDlg->setMaximumSize(QSize(16777215, 1666666));
        gridLayout_2 = new QGridLayout(MarkerMakeDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 3, -1, 6);
        groupBox = new QGroupBox(MarkerMakeDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        groupEdit = new QLineEdit(groupBox);
        groupEdit->setObjectName(QString::fromUtf8("groupEdit"));

        gridLayout->addWidget(groupEdit, 0, 1, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        sizeEdit = new QLineEdit(groupBox);
        sizeEdit->setObjectName(QString::fromUtf8("sizeEdit"));
        sizeEdit->setReadOnly(true);

        gridLayout->addWidget(sizeEdit, 1, 1, 1, 1);

        sizeBtn = new QPushButton(groupBox);
        sizeBtn->setObjectName(QString::fromUtf8("sizeBtn"));
        sizeBtn->setMaximumSize(QSize(65, 16777215));

        gridLayout->addWidget(sizeBtn, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        horEdit = new QLineEdit(groupBox);
        horEdit->setObjectName(QString::fromUtf8("horEdit"));
        horEdit->setReadOnly(true);

        gridLayout->addWidget(horEdit, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horBtn = new QPushButton(groupBox);
        horBtn->setObjectName(QString::fromUtf8("horBtn"));
        horBtn->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_4->addWidget(horBtn);

        hDragBtn = new QPushButton(groupBox);
        hDragBtn->setObjectName(QString::fromUtf8("hDragBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hDragBtn->sizePolicy().hasHeightForWidth());
        hDragBtn->setSizePolicy(sizePolicy1);
        hDragBtn->setMinimumSize(QSize(0, 0));
        hDragBtn->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_4->addWidget(hDragBtn);


        gridLayout->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        verEdit = new QLineEdit(groupBox);
        verEdit->setObjectName(QString::fromUtf8("verEdit"));
        verEdit->setReadOnly(true);

        gridLayout->addWidget(verEdit, 3, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verBtn = new QPushButton(groupBox);
        verBtn->setObjectName(QString::fromUtf8("verBtn"));
        verBtn->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_5->addWidget(verBtn);

        vDragBtn = new QPushButton(groupBox);
        vDragBtn->setObjectName(QString::fromUtf8("vDragBtn"));
        vDragBtn->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_5->addWidget(vDragBtn);


        gridLayout->addLayout(horizontalLayout_5, 3, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        subList = new QListWidget(groupBox);
        subList->setObjectName(QString::fromUtf8("subList"));
        subList->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_3->addWidget(subList);

        deleteMarkerBtn = new QPushButton(groupBox);
        deleteMarkerBtn->setObjectName(QString::fromUtf8("deleteMarkerBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deleteMarkerBtn->sizePolicy().hasHeightForWidth());
        deleteMarkerBtn->setSizePolicy(sizePolicy2);
        deleteMarkerBtn->setMinimumSize(QSize(60, 0));
        deleteMarkerBtn->setMaximumSize(QSize(65, 60));

        horizontalLayout_3->addWidget(deleteMarkerBtn);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        list = new QListWidget(groupBox);
        list->setObjectName(QString::fromUtf8("list"));
        list->setMinimumSize(QSize(0, 0));
        list->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(list);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        editBtn = new QPushButton(groupBox);
        editBtn->setObjectName(QString::fromUtf8("editBtn"));
        sizePolicy2.setHeightForWidth(editBtn->sizePolicy().hasHeightForWidth());
        editBtn->setSizePolicy(sizePolicy2);
        editBtn->setMinimumSize(QSize(60, 0));
        editBtn->setMaximumSize(QSize(60, 16777215));

        verticalLayout->addWidget(editBtn);

        deleteBtn = new QPushButton(groupBox);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        sizePolicy2.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy2);
        deleteBtn->setMinimumSize(QSize(0, 0));
        deleteBtn->setMaximumSize(QSize(60, 73));

        verticalLayout->addWidget(deleteBtn);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(groupBox);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(MarkerMakeDlg);

        QMetaObject::connectSlotsByName(MarkerMakeDlg);
    } // setupUi

    void retranslateUi(QDialog *MarkerMakeDlg)
    {
        MarkerMakeDlg->setWindowTitle(QApplication::translate("MarkerMakeDlg", "\350\231\232\346\213\237\346\240\207\350\256\260\347\202\271\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MarkerMakeDlg", "\347\255\224\346\241\210\345\214\272\350\231\232\346\213\237\346\240\207\350\256\260\347\202\271\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MarkerMakeDlg", "\346\240\207\350\256\260\347\202\271\347\273\204\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MarkerMakeDlg", "\346\240\207\350\256\260\347\202\271\345\244\247\345\260\217\357\274\232", 0, QApplication::UnicodeUTF8));
        sizeBtn->setText(QApplication::translate("MarkerMakeDlg", "\346\213\226\346\233\263\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MarkerMakeDlg", "\346\260\264\345\271\263\345\272\217\345\217\267\347\273\204\357\274\232", 0, QApplication::UnicodeUTF8));
        horBtn->setText(QApplication::translate("MarkerMakeDlg", "\347\273\230\345\210\266", 0, QApplication::UnicodeUTF8));
        hDragBtn->setText(QApplication::translate("MarkerMakeDlg", "\346\213\226\346\233\263", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MarkerMakeDlg", "\345\236\202\347\233\264\345\272\217\345\217\267\347\273\204\357\274\232", 0, QApplication::UnicodeUTF8));
        verBtn->setText(QApplication::translate("MarkerMakeDlg", "\347\273\230\345\210\266", 0, QApplication::UnicodeUTF8));
        vDragBtn->setText(QApplication::translate("MarkerMakeDlg", "\346\213\226\346\233\263", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MarkerMakeDlg", "\350\231\232\346\213\237\346\240\207\350\256\260\347\202\271\357\274\232", 0, QApplication::UnicodeUTF8));
        deleteMarkerBtn->setText(QApplication::translate("MarkerMakeDlg", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        editBtn->setText(QApplication::translate("MarkerMakeDlg", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("MarkerMakeDlg", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("MarkerMakeDlg", "\347\241\256\350\256\244\346\240\207\350\256\260\347\202\271", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("MarkerMakeDlg", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MarkerMakeDlg: public Ui_MarkerMakeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKERMAKEDLG_H
