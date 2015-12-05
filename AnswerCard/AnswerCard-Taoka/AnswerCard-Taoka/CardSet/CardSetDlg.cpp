#include "CardSetDlg.h"
#include "qmessagebox.h"
#include "../XmlIO/XmlIO.h"
#include "qfile.h"
#include "../AnswerCard/DataIO.h"
#include "InputDpiDlg.h"
#include "AddCourseDlg.h"

#pragma comment(lib,"XmlIoDll.lib")

CardSetDlg::CardSetDlg(QApplication &app, int type)
	: QDialog(0),m_cardDoc(type)
{
	ui.setupUi(this);

	//���öԻ������С��󻯰�ť
	this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	this->setWindowFlags(windowFlags()|Qt::WindowMinimizeButtonHint);
	this->setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);

	m_type = type;
	//m_cardDoc = CardDoc(m_type);
	connect(ui.paperSetTable, SIGNAL(cellClicked(int , int)),
		this, SLOT(updatePageDetails(int, int)));

	ui.gridLayout_2->removeWidget(ui.comboBox);
	delete ui.comboBox;
	ui.comboBox = new QComboBox(this);
    ui.comboBox->setObjectName(QString::fromUtf8("comboBox"));
    ui.comboBox->setMinimumSize(QSize(150, 0));

    ui.gridLayout_2->addWidget(ui.comboBox, 0, 1, 1, 1);
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)),
	this, SLOT(courseChanged(int)));
}

CardSetDlg::~CardSetDlg()
{
}

//��ӿ�Ŀ
void CardSetDlg::on_addCourseBtn_clicked()
{
	AddCourseDlg dlg;

	while (dlg.exec() == QDialog::Accepted)
	{
		QString course = dlg.getCourseName();

		if (m_cardDoc.isCourseExist(course) != -1)
		{
			QMessageBox::information(this, tr(" "),tr("�ÿ�Ŀ�Ѵ��ڣ����������룡")); 
		}
		else
		{
			ui.comboBox->addItem(dlg.getCourseName());
			m_cardDoc.createCourse(dlg.getCourseName());
			break;
		}
	}
}

//�Ƴ���Ŀ�����Ծ�
void CardSetDlg::on_deleteCourseBtn_clicked()
{
	if (ui.comboBox->count() <= 0)
	{
		return;
	}

	int courseIdx = ui.comboBox->currentIndex();
	
	
	m_cardDoc.removeCourse(courseIdx);

	ui.comboBox->removeItem(courseIdx);

	if (ui.comboBox->count() > 0)
	{
		ui.comboBox->setCurrentIndex(0);
		courseChanged(0);
	}
	else
	{
		//�������ͼ
		ui.subTable->clearContents();
		ui.subTable->setRowCount(0);

		//����Ծ���ͼ
		ui.paperSetTable->clearContents();
		ui.paperSetTable->setRowCount(0);
	}
}

//���ݵ�ǰѡ��Ŀ�Ŀ������ʾ���Ծ�������
void CardSetDlg::courseChanged(int index)
{
	if (index < 0)
	{
		return;
	}

	//�������ͼ
	ui.subTable->clearContents();
	ui.subTable->setRowCount(0);

	//����Ծ���ͼ
	ui.paperSetTable->clearContents();
	ui.paperSetTable->setRowCount(0);

	for (int i = 0; i < m_cardDoc.getSetCountOfCourse(index); ++i)
	{
		PaperSet set = m_cardDoc.getPageSetDetail(index, i);

		//�������ݵ���ͼ����
		int currentRow = ui.paperSetTable->rowCount();
		ui.paperSetTable->insertRow(currentRow);
		ui.paperSetTable->setItem(currentRow, 0, new QTableWidgetItem(set.setId));

		//���Ծ��׵��Ծ�����
		int count = 0;

		vector<PaperPage>::iterator iter = set.page.begin();

		for (; iter != set.page.end(); ++iter)
		{
			if (iter->isPositive == true)
			{
				++count;
			}
		}

		QString countrSt = tr("%1").arg(count);
		ui.paperSetTable->setItem(currentRow, 1, new QTableWidgetItem(countrSt));
	}
}

//����Ծ���
void CardSetDlg::on_addPaperBtn_clicked()
{
	if (ui.comboBox->count() == 0)
	{
		QMessageBox::information(this, tr(" "),tr("������ӿ�Ŀ��"));
		return;
	}

	AddPaperDlg dlg;
	//������Ծ��׵ĶԻ���
	while (dlg.exec() == QDialog::Accepted)
	{
		QString number = dlg.getPaperSetId();
		int dpi = dlg.getPaperDpi().toInt();

		if (m_cardDoc.isPaperSetIdExist(ui.comboBox->currentIndex(), number) > -1)
		{
			QMessageBox::information(this, tr(" "),tr("���Ծ����Ѵ��ڣ����������룡"));
			continue;
		}

		m_cardDoc.createPaperSet(ui.comboBox->currentIndex(), number, dpi);

		//���ļ���Ϣ�����������
		int currentRow = ui.paperSetTable->rowCount();
		ui.paperSetTable->insertRow(currentRow);
		ui.paperSetTable->setItem(currentRow, 0, new QTableWidgetItem(number));
		ui.paperSetTable->setItem(currentRow, 1, new QTableWidgetItem(tr("0")));
		//ui.paperSetTable->setItem(currentRow, 2, new QTableWidgetItem(name));
		break;
	}
}

//ɾ���Ծ���
void CardSetDlg::on_deletePaperBtn_clicked()
{
	if (ui.comboBox->count() == 0)
	{
		QMessageBox::information(this, tr(" "),tr("������ӿ�Ŀ��"));
		return;
	}

	if (ui.paperSetTable->currentIndex().row() >= 0)
	{
		int idx = ui.paperSetTable->currentItem()->row();
		ui.paperSetTable->removeRow(idx);
		m_cardDoc.removePaperSet(ui.comboBox->currentIndex(), idx);

		ui.subTable->clearContents();
		ui.subTable->setRowCount(0);
		ui.paperSetTable->clearSelection();
		//updatePageDetails(ui.paperSetTable->rowCount() - 1, 0);
	}
	else
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
	}
}


//���һ���Ծ�
void CardSetDlg::on_addPageBtn_clicked()
{
	if (ui.paperSetTable->currentIndex().row() < 0)
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
		return;
	}

	AddPageDlg dlg;
	int setIdx = ui.paperSetTable->currentItem()->row();	

	while (dlg.exec() == QDialog::Accepted)
	{
		QString number = dlg.getPageNumber();

		if (m_cardDoc.isPageIdOfSetExist(ui.comboBox->currentIndex(), setIdx, number) > -1)
		{
			QMessageBox::information(this, tr(" "),tr("�ñ���Ѵ��ڣ����������룡"));
			continue;
		}

		//��������Ծ�
		QString frontFileName = dlg.getFrontPagePath();
		Mat tmp = imread(frontFileName.toStdString());
		QImage img = AnswerCardDlg::mat2QImage(tmp);

		PaperPage page;
		page.pageId = number;
		page.isPositive = true;
		m_cardDoc.insertPaperPage(ui.comboBox->currentIndex(), setIdx, page, img);

		//���ļ���Ϣ�����������
		int currentRow = ui.subTable->rowCount();
		ui.subTable->insertRow(currentRow);
		ui.subTable->setItem(currentRow, 0, new QTableWidgetItem(number));
		ui.subTable->setItem(currentRow, 1, new QTableWidgetItem("����"));

		//��ӷ����Ծ�
		if (dlg.hasBackPage() == true)
		{
			QString backFileName = dlg.getBackPagePath();
			Mat backTmp = imread(backFileName.toStdString());
			QImage backImg = AnswerCardDlg::mat2QImage(backTmp);

			PaperPage backPage;
			backPage.pageId = number;
			backPage.isPositive = false;
			m_cardDoc.insertPaperPage(ui.comboBox->currentIndex(), setIdx, backPage, backImg);
		}

		//int count = m_cardDoc.getCountOfPage(setIdx);
		int count = ui.subTable->rowCount();
		ui.paperSetTable->setItem(setIdx, 1, new QTableWidgetItem(QString(tr("%1").arg(count))));

		break;
	}

}

//�Ƴ�һ���Ծ�
void CardSetDlg::on_deletePageBtn_clicked()
{
	if (ui.paperSetTable->currentIndex().row() < 0)
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
		return;
	}

	if (ui.subTable->currentIndex().row() < 0)
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
		return;
	}
	
	QString pageId = ui.subTable->currentItem()->text();
	int currentRow = ui.subTable->currentItem()->row();
	int setIdx = ui.paperSetTable->currentItem()->row();

	int pageIdx = m_cardDoc.isPageIdOfSetExist(ui.comboBox->currentIndex(), setIdx, pageId);
	m_cardDoc.removePaperPage(ui.comboBox->currentIndex(), setIdx, pageIdx);
	ui.subTable->removeRow(currentRow);

	if (m_cardDoc.getPageCountOfSet(ui.comboBox->currentIndex(), setIdx) > 0
		&& m_cardDoc.getPageCountOfSet(ui.comboBox->currentIndex(), setIdx) > pageIdx
		&& m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), setIdx, pageIdx).isPositive == false
		&& m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), setIdx, pageIdx).pageId == pageId)
	{
		m_cardDoc.removePaperPage(ui.comboBox->currentIndex(), setIdx, pageIdx);
	}

	ui.subTable->clearSelection();

	//�����Ծ���ͼ
	int count = ui.subTable->rowCount();
	ui.paperSetTable->setItem(setIdx, 1, new QTableWidgetItem(QString(tr("%1").arg(count))));
}

//������ĳ�Ծ��׺󣬸������Ծ���Ϣ
void CardSetDlg::updatePageDetails(int row, int column)
{
	if (row > -1)
	{
		ui.subTable->clearContents();
		ui.subTable->setRowCount(0);

		int count = m_cardDoc.getPageCountOfSet(ui.comboBox->currentIndex(), row);

		for (int i = 0; i < count; ++i)
		{
			PaperPage page = m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), row, i);
			
			if (page.isPositive == true)
			{
				//���ļ���Ϣ�����������
				int currentRow = ui.subTable->rowCount();
				ui.subTable->insertRow(currentRow);
				ui.subTable->setItem(currentRow, 0, new QTableWidgetItem(page.pageId));				
			}
		}
	}
}

//�༭��ѡ�Ծ�
void CardSetDlg::on_editPageBtn_clicked()
{
	int setIdx = ui.paperSetTable->currentIndex().row();

	if (setIdx < 0)
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
		return;
	}

	if (ui.subTable->currentIndex().row() < 0)
	{
		QMessageBox::information(this, tr(" "),tr("��ûѡ�������Ծ�"));
		return;
	}

	QString pageId = ui.subTable->currentItem()->text();
	int pageIdx = m_cardDoc.isPageIdOfSetExist(ui.comboBox->currentIndex(), setIdx, pageId);

	QString dataPath = QString(tr("tmp\\%1-%2-%3-%4.dat")
		.arg(ui.comboBox->currentText())
		.arg(m_cardDoc.getPageSetDetail(ui.comboBox->currentIndex(), setIdx).setId)
		.arg(m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), setIdx, pageIdx).pageId)
		.arg((int)(m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), setIdx, pageIdx).isPositive)));

	QString pre = QString(tr("tmp\\%1-%2-%3")
		.arg(ui.comboBox->currentText())
		.arg(m_cardDoc.getPageSetDetail(ui.comboBox->currentIndex(), setIdx).setId)
		.arg(m_cardDoc.getPageDetail(ui.comboBox->currentIndex(), setIdx, pageIdx).pageId));

	AnswerCardDlg dlg(pre);
	dlg.setDataSource(dataPath);
	dlg.exec();
}

//////////////////////////////////�ļ��������////////////////////////////////////
void CardSetDlg::on_savePaperBtn_clicked()
{
	if (ui.comboBox->count() <= 0 || m_cardDoc.getSetCountOfCourse(ui.comboBox->currentIndex()) <= 0)
	{
//		QMessageBox::information(NULL, tr("ʧ��"),tr("�ļ�����Ϊ�գ�"));
		return;
	}

	QString fileName = QFileDialog::getSaveFileName(this, 
		tr("���浱ǰ��Ŀ���׿���Ϣ"), tr(""), tr("ACPROJ (*.acproj)"));

	if (fileName != "")
	{
		int rst = m_cardDoc.zipPaperSetInfo(ui.comboBox->currentIndex(), fileName);

		if (rst >= 0)
		{
			QMessageBox::information(NULL, tr("�ɹ�"),tr("����ɹ���"));
		}
		else
		{
			QMessageBox::information(NULL, tr("ʧ��"),tr("����ʧ�ܣ�"));
		}
	}
}

void CardSetDlg::on_openPaperBtn_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
                this, tr("��ACPROJ�ļ�"),
                ".",
				tr("ACPROJ (*.acproj)"));

	if (fileName != "")
	{
		int currentIdx = ui.comboBox->currentIndex();
		int courseCount = m_cardDoc.getCourse().size();

		int rst = m_cardDoc.resumeDataFromZip(fileName);

		if (rst == 0)
		{
			QMessageBox::information(this," ","�ļ��޷���");
			return;
		}

		if (courseCount < m_cardDoc.getCourse().size())
		{
			ui.comboBox->addItem(m_cardDoc.getCourse().rbegin()->courseName);
		}

		if (currentIdx == -1)
		{
			this->courseChanged(0);
		}
		else
		{
			this->courseChanged(currentIdx);
		}
	}
}

void CardSetDlg::on_importPaperBtn_clicked()
{
	if (ui.comboBox->count() <= 0 || m_cardDoc.getSetCountOfCourse(ui.comboBox->currentIndex()) <= 0)
	{
//		QMessageBox::information(NULL, tr("ʧ��"),tr("�ļ�����Ϊ�գ�"));
		return;
	}

	QString fileName = QFileDialog::getSaveFileName(this, 
		tr("������ǰ��Ŀ���׿�XML�ļ�"), tr(""), tr("XML(*.xml)"));

	if (fileName != "")
	{
		vector<PaperSet> paperSet = m_cardDoc.getPaperSet(ui.comboBox->currentIndex());
		TK_info tkInfo;

		for (int i = 0; i < paperSet.size(); ++i)
		{
			for (int j = 0; j < paperSet.at(i).page.size(); ++j)
			{
				PerAC_info perInfo;
				perInfo.tkId = paperSet.at(i).setId.toInt();			
				perInfo.pageId = paperSet.at(i).page.at(j).pageId.toInt();

				QString dataPath = QString(tr("tmp\\%1-%2-%3-%4.dat")
					.arg(ui.comboBox->currentText())
					.arg(paperSet.at(i).setId)
					.arg(paperSet.at(i).page.at(j).pageId)
					.arg((int)(paperSet.at(i).page.at(j).isPositive)));

				QString pre = QString(tr("tmp\\%1-%2-%3")
					.arg(ui.comboBox->currentText())
					.arg(paperSet.at(i).setId)
					.arg(paperSet.at(i).page.at(j).pageId));

				AnswerCardDlg dlg(pre);
				dlg.setDataSource(dataPath);
				theApp.TransToOutputStruct();

				theApp.acinfo.ac_type = m_cardDoc.getAcType();
				theApp.acinfo.dpi =  paperSet.at(i).dpi;
				theApp.acinfo.isFront = paperSet.at(i).page.at(j).isPositive;
				perInfo.acinfo.push_back(theApp.acinfo);

				if (j + 1 < paperSet.at(i).page.size())
				{
					if (paperSet.at(i).page.at(j).pageId == paperSet.at(i).page.at(j + 1).pageId)
					{
						QString dataPath = QString(tr("tmp\\%1-%2-%3-%4.dat")
							.arg(ui.comboBox->currentText())
							.arg(paperSet.at(i).setId)
							.arg(paperSet.at(i).page.at(j+1).pageId)
							.arg((int)(paperSet.at(i).page.at(j+1).isPositive)));
						AnswerCardDlg dlg1(pre);
						dlg1.setDataSource(dataPath);
						theApp.TransToOutputStruct();

						theApp.acinfo.ac_type = m_cardDoc.getAcType();
						theApp.acinfo.dpi = paperSet.at(i).dpi;
						theApp.acinfo.isFront = paperSet.at(i).page.at(j+1).isPositive;
						perInfo.acinfo.push_back(theApp.acinfo);

						++j;
					}
				}

				tkInfo.tkinfo.push_back(perInfo);
			}
		}

		XmlIo io;		
		//tkInfo.tkinfo
		io.Write(fileName.toStdString(), tkInfo);
		QMessageBox::information(this, "  ", tr("���⿨�����ļ�����ɹ�"));
	}
}