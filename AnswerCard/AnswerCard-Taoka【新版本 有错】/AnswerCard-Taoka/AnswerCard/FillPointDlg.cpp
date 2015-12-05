#include "FillPointDlg.h"
#include "ui_FillPointDlg.h"

FillPointDlg::FillPointDlg(QWidget *parent)
	: QDialog(parent),
	m_singleRadioChecked(true),
	m_isCrosswise(true),
	m_idx_l(0),
	m_idx_r(0),
	m_idx_t(0),
	m_idx_b(0),
	m_optionRange(),
	m_optionCount(0)
{
	ui = new Ui::FillPointDlg();
	ui->setupUi(this);

	//������ʽ
	QRegExp rx("-?\\d{1,3}--?\\d{1,3}");
    QValidator *validator = new QRegExpValidator(rx, this);
	ui->optionEdit->setValidator(validator);

	for (int i = 0; i < 12; ++i)
	{
		count[i] = 0;
	}

	connect(ui->list, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showClicked(QListWidgetItem*)));
}

FillPointDlg::~FillPointDlg()
{
	delete ui;
}

void FillPointDlg::initialization()
{
	for (int i = 0; i < 12; ++i)
	{
		count[i] = 0;
	}

	ui->nameLabel->hide();
	ui->nameEdit->hide();
	ui->checkBox->hide();
	ui->typeLabel->show();
	ui->singleRadioBtn->show();
	ui->multiRadioBtn->show();
	ui->questionTypeCbx->show();
	ui->questionTypeCbx->setChecked(false);
	m_singleRadioChecked = true;
	m_isCrosswise = true;
	m_optionCount = 0;

	ui->singleRadioBtn->setChecked(true);
	ui->horRadioBtn->setChecked(true);
	ui->typeCmb->setCurrentIndex(0);
	ui->addBtn->setText(tr("�����Ϳ��"));
	ui->confirmBtn->setEnabled(false);
	ui->rSpaceEdit->setText("0");
	ui->cSpaceEdit->setText("0");
	ui->optionEdit->clear();
	ui->numEdit->clear();
	ui->list->clear();

	setProcessing(false);
	this->setEnabled(false);
}

void FillPointDlg::setAddBtnText(const QString &str)
{
	ui->addBtn->setText(str);
}

void FillPointDlg::setConfirmBtnEnabled(bool b)
{
	ui->confirmBtn->setEnabled(b);
}

void FillPointDlg::on_addBtn_clicked()
{
	m_optionCount = ui->numEdit->text().toInt();
	QString type = ui->typeCmb->currentText();

	//���ʶ��ο���
	if (type == tr("ʶ��ο���"))
	{
		//�����δȷ��״̬����ʱ�����������¿�ѡ
		if (theApp.m_group_state == FillPointState && theApp.m_state == BaseRelease)
		{
			//�����ػ�
			theApp.is_synchronous = false;
			ui->addBtn->setText(tr("ȡ��"));
			ui->confirmBtn->setEnabled(false);

			theApp.referPoint.pop_back();
		}
		//ȡ������
		else if (theApp.m_group_state == FillPointState && theApp.m_state == BaseBegin)
		{
			theApp.m_state = BaseInitial;
			ui->confirmBtn->setEnabled(false);
			ui->addBtn->setText(tr("�����Ϳ��"));
			setProcessing(false);

			emit fillPointDone();
			return;
		}
		else
		{
			ui->addBtn->setText(tr("ȡ��"));
			setProcessing(true);

			emit fillPointBegin();
		}

		//״̬����
		theApp.m_group_state = FillPointState;
		theApp.m_state = BaseBegin;
	}
	//����Ϣ����
	else if (type == tr("ѡ����"))
	{
		QString edit_questions_id = ui->optionEdit->text();

		if (edit_questions_id == "" || ui->numEdit->text() == ""
			||edit_questions_id == "0" || ui->numEdit->text() == "0")
		{
			QMessageBox::information(NULL, tr(" "),tr("��������ź�ѡ������"));
			return ;
		}

		if (theApp.markersRect[0].width<=0 || theApp.markersRect[1].width <= 0){
			QMessageBox::information(NULL, tr(" "),tr("���ѡ��ǵ�"));
			return ;
		}

		//���ڿ�ʼ��ѡ״̬
		if (theApp.m_group_state == QuestionState 
			&& (theApp.m_state == SingleBegin || theApp.m_state == MultiBegin))
		{
			ui->confirmBtn->setEnabled(false);
			ui->addBtn->setText(tr("�����Ϳ��"));
			setProcessing(false);

			//����״̬
			theApp.m_group_state = QuestionState;
			theApp.m_state = QuestionInitial;

			emit fillPointDone();
			return ;
		}
		//�����δȷ��״̬����ʱ�����������¿�ѡ
		else if (theApp.m_group_state == QuestionState 
			&& (theApp.m_state == SingleRelease || theApp.m_state == MultiRelease))
		{
			//�����ػ�
			theApp.is_synchronous = false;
			ui->addBtn->setText(tr("ȡ��"));
			ui->confirmBtn->setEnabled(false);

			for (int i = 0; i < m_optionRange.size() + 1; ++i)
			{
				theApp.questionInfo.pop_back();
			}
		}
		else
		{
			ui->addBtn->setText(tr("ȡ��"));
			setProcessing(true);
			emit fillPointBegin();
		}

		//�ж������Ƿ�����ŷ�Χ
		int idx = edit_questions_id.indexOf('-');

		if (-1 == idx)			//���뵥�����
		{
			m_optionRange.end = m_optionRange.start = edit_questions_id.toInt();
			theApp.m_group_state = QuestionState;
			theApp.m_state = SingleBegin;
		}
		else					//������ŷ�Χ
		{
			QString start, end;
			start = edit_questions_id.left(idx);
			end = edit_questions_id.right(edit_questions_id.length() - idx - 1);
			m_optionRange.start = start.toInt();
			m_optionRange.end = end.toInt();
			theApp.m_group_state = QuestionState;
			theApp.m_state = MultiBegin;
		}
	}//if (type == tr("ѡ����"))
	else
	{
		QString edit_questions_id = ui->optionEdit->text();

		if (edit_questions_id == "" || ui->numEdit->text() == ""
			||edit_questions_id == "0" || ui->numEdit->text() == "0")
		{
			QMessageBox::information(NULL, tr(" "),tr("������λ����ѡ������"));
			return ;
		}
		if (theApp.markersRect[0].width<=0 || theApp.markersRect[1].width <= 0){
			QMessageBox::information(NULL, tr(" "),tr("���ѡ��ǵ�"));
			return ;
		}
		//�����δȷ��״̬����ʱ�����������¿�ѡ
		if (theApp.m_group_state == FillPointState && theApp.m_state == BaseRelease)
		{
			//�����ػ�
			theApp.is_synchronous = false;
			ui->addBtn->setText(tr("ȡ��"));
			ui->confirmBtn->setEnabled(false);

			theApp.cfp_group.pop_back();
		}
		else if (theApp.m_group_state == FillPointState && theApp.m_state == BaseBegin)
		{
			theApp.m_state = BaseInitial;
			ui->confirmBtn->setEnabled(false);
			setProcessing(false);
			ui->addBtn->setText(tr("�����Ϳ��"));

			if (type == tr("ȱ��") || type == tr("�Ծ�����")
			|| type == tr("ѡ����") || type == tr("Υ��"))
			{
				ui->checkBox->setEnabled(false);
			}

			emit fillPointDone();
			return;
		}
		else
		{
			ui->addBtn->setText(tr("ȡ��"));
			setProcessing(true);

			m_optionRange.end = m_optionRange.start = edit_questions_id.toInt();
			emit fillPointBegin();
		}

		//״̬����
		theApp.m_group_state = FillPointState;
		theApp.m_state = BaseBegin;
	}//if (ui->typeCmb->currentText != tr("ѡ����"))
}

void FillPointDlg::on_confirmBtn_clicked()
{
	QString type = ui->typeCmb->currentText();
	int index = ui->typeCmb->currentIndex();
	int num = ui->numEdit->text().toInt();

	if (ui->typeCmb->currentText() == tr("ѡ����"))
	{
		if (m_isCrosswise)
		{
			int space = ui->cSpaceEdit->text().toInt();
			int rowId = m_idx_t;

			for (int i = m_idx_t; rowId <= m_idx_b; i++)
			{
				addQuestionStrToList(
					m_optionRange.start + i - m_idx_t,
					m_isCrosswise,
					m_singleRadioChecked,
					num, count[QUESTION]);

				count[QUESTION]++;
				rowId += space + 1;
			}
		}
		else
		{
			int space = ui->rSpaceEdit->text().toInt();
			int columnId = m_idx_l;

			for (int i = m_idx_l; columnId <= m_idx_r; i++)
			{
				addQuestionStrToList(
					m_optionRange.start + i - m_idx_l,
					m_isCrosswise,
					m_singleRadioChecked,
					num, count[QUESTION]);

				count[QUESTION]++;
				columnId += space + 1;
			}
		}

		//Ԥ����������
		if (theApp.m_state == SingleRelease)
		{
			QString questionRangePred;
			questionRangePred = QString(tr("%1")).arg(m_optionRange.start+1);
			ui->optionEdit->setText(questionRangePred);
		}
		else
		{			
			QString questionRangePred;
			questionRangePred = QString(tr("%1-%2"))
				.arg(m_optionRange.start + m_optionRange.size() + 1)
				.arg(m_optionRange.end + m_optionRange.size() + 1);
			ui->optionEdit->setText(questionRangePred);
		}
		theApp.m_state++;
		theApp.questionType = ui->questionTypeCbx->isChecked()?1:0;
	}
	else if (ui->typeCmb->currentText() == tr("ʶ��ο���"))
	{
		QString str = QString(tr("ʶ��ο���%1").arg(count[11]+1));
		ui->list->addItem(str);
		count[11]++;
		theApp.m_state++; 
	}
	else
	{
		QString strW;
		QString name = ui->nameEdit->text();

		if (ui->checkBox->isChecked())
		{	
			if (m_singleRadioChecked)
			{
				strW = QString(tr("%1| ��ѡ| ��0��ͷ|").arg(name));
			}
			else
			{
				strW = QString(tr("%1| ��ѡ| ��0��ͷ|").arg(name));
			}
		}
		else
		{
			if (m_singleRadioChecked)
			{
				strW = QString(tr("%1| ��ѡ| ��1��ͷ|").arg(name));
			}
			else
			{
				strW = QString(tr("%1|  ��ѡ| ��1��ͷ|").arg(name));
			}
		}

		ui->list->insertItem(ui->list->count() - theApp.referPoint.size(),strW);
		count[index]++;
		QString str = ui->typeCmb->currentText() 
			+ QString("%1").arg(count[index] + 1);
		ui->nameEdit->setText(str);
		theApp.m_state++; 
	}
	
	//�������
	ui->addBtn->setText(tr("�����Ϳ��"));

	if (ui->typeCmb->currentText() != tr("ѡ����"))
	{
		ui->typeCmb->setCurrentIndex(0);
	}
	ui->confirmBtn->setEnabled(false);
	setProcessing(false);

	emit fillPointDone();
}

void FillPointDlg::on_deleteBtn_clicked()
{
	//�������
	int idx = ui->list->currentRow();

	if (idx > -1)
	{
		ui->list->takeItem(idx);

		if (idx < count[QUESTION])
		{
			theApp.questionInfo.erase(theApp.questionInfo.begin() + idx);
			count[QUESTION]--;
		}
		else if ((idx - count[QUESTION]) < theApp.cfp_group.size())
		{
			theApp.cfp_group.erase(theApp.cfp_group.begin() + (idx - count[QUESTION]));
		}
		else
		{
			theApp.referPoint.erase(theApp.referPoint.begin() + (idx - count[QUESTION] - theApp.cfp_group.size()));
		}

		//�����ػ�
		theApp.is_synchronous = false;
		emit fillPointDelete();
	}
}

void FillPointDlg::setProcessing(bool b)
{
	ui->typeCmb->setEnabled(!b);
	ui->horRadioBtn->setEnabled(!b);
	ui->verRadioBtn->setEnabled(!b);
	ui->singleRadioBtn->setEnabled(!b);
	ui->multiRadioBtn->setEnabled(!b);
	ui->nameEdit->setEnabled(!b);
	ui->checkBox->setEnabled(!b);
	ui->optionEdit->setEnabled(!b);
	ui->numEdit->setEnabled(!b);
	ui->rSpaceEdit->setEnabled(!b);
	ui->cSpaceEdit->setEnabled(!b);
	ui->deleteBtn->setEnabled(!b);
	ui->questionTypeCbx->setEnabled(!b);
}

void FillPointDlg::on_horRadioBtn_clicked()
{
	m_isCrosswise = true;
}

void FillPointDlg::on_verRadioBtn_clicked()
{
	m_isCrosswise = false;
}

void FillPointDlg::on_singleRadioBtn_clicked()
{
	m_singleRadioChecked = true;
}

void FillPointDlg::on_multiRadioBtn_clicked()
{
	m_singleRadioChecked = false;
}

void FillPointDlg::on_typeCmb_currentIndexChanged(int index)
{
//	int idx = index;
	QString type = ui->typeCmb->currentText();

	if (type == tr("ѡ����"))
	{
		ui->paibuLabel->show();
		ui->verRadioBtn->show();
		ui->horRadioBtn->show();

		ui->typeLabel->show();
		ui->singleRadioBtn->show();
		ui->multiRadioBtn->show();
		ui->questionTypeCbx->show();

		ui->countLabel->show();
		ui->numEdit->show();

		ui->optionNumLabel->show();
		ui->optionEdit->show();
		
		ui->hSpaceLabel->show();
		ui->rSpaceEdit->show();
		ui->vSpaceLabel->show();
		ui->cSpaceEdit->show();

		ui->nameLabel->hide();
		ui->nameEdit->hide();
		ui->checkBox->hide();
		ui->typeLabel->show();
		ui->singleRadioBtn->setEnabled(true);
		ui->multiRadioBtn->setEnabled(true);
		ui->singleRadioBtn->show();
		ui->multiRadioBtn->show();
		ui->optionNumLabel->setText(tr("��    �ţ�"));
		ui->optionEdit->setToolTip(tr("��������ŷ�Χ,��: 1-5"));
		
	}
	else if (type == tr("ʶ��ο���"))
	{
		ui->nameLabel->show();
		ui->nameEdit->show();
		ui->checkBox->hide();

		ui->paibuLabel->hide();
		ui->verRadioBtn->hide();
		ui->horRadioBtn->hide();

		ui->typeLabel->hide();
		ui->singleRadioBtn->hide();
		ui->multiRadioBtn->hide();
		ui->questionTypeCbx->hide();

		ui->countLabel->hide();
		ui->numEdit->hide();

		ui->optionNumLabel->hide();
		ui->optionEdit->setToolTip("");
		ui->optionEdit->hide();
		
		ui->hSpaceLabel->hide();
		ui->rSpaceEdit->hide();
		ui->vSpaceLabel->hide();
		ui->cSpaceEdit->hide();

		QString str = ui->typeCmb->currentText() 
			+ QString("%1").arg(count[index] + 1);
		ui->nameEdit->setText(str);
	}
	else
	{
		ui->paibuLabel->show();
		ui->verRadioBtn->show();
		ui->horRadioBtn->show();

		ui->typeLabel->show();
		ui->singleRadioBtn->show();
		ui->multiRadioBtn->show();
		ui->questionTypeCbx->hide();

		ui->countLabel->show();
		ui->numEdit->show();

		ui->optionNumLabel->show();
		ui->optionEdit->show();
		
		ui->hSpaceLabel->show();
		ui->rSpaceEdit->show();
		ui->vSpaceLabel->show();
		ui->cSpaceEdit->show();

		ui->nameLabel->show();
		ui->nameEdit->show();
		ui->checkBox->show();
		ui->checkBox->setEnabled(true);
		ui->checkBox->setChecked(false);
		ui->typeLabel->show();
		ui->singleRadioBtn->show();
		ui->multiRadioBtn->show();
		ui->optionNumLabel->setText(tr("λ    ����"));
		ui->optionEdit->setToolTip("");
		QString str = ui->typeCmb->currentText() 
			+ QString("%1").arg(count[index] + 1);
		ui->nameEdit->setText(str);

		if (type == tr("ȱ��") || type == tr("�Ծ�����")
			|| type == tr("ѡ����") || type == tr("Υ��"))
		{
			ui->checkBox->setEnabled(false);
		}
	}

	ui->rSpaceEdit->setText("0");
	ui->cSpaceEdit->setText("0");
	ui->optionEdit->clear();
	ui->numEdit->clear();
}

void FillPointDlg::showClicked(QListWidgetItem* item)
{
	int idx = ui->list->currentRow();

	if (idx > -1)
	{
		theApp.is_synchronous = false;
		theApp.Redraw();
		//emit imageRefresh();

		if (idx < count[QUESTION])
		{
			//theApp.questionInfo.erase(theApp.questionInfo.begin() + idx);
			vector<ItemPos>::iterator iter= theApp.questionInfo.begin() + idx;
			cv::Point lt,rb;
			if (iter->isCrosswise)
			{
				lt.y = theApp.markerBT.GetTBoundary(iter->markerIdx[0]);
				rb.y = theApp.markerBT.GetBBoundary(iter->markerIdx[0]);
				lt.x = theApp.markerBT.GetLBoundary(iter->markerIdx[1]);
				rb.x = theApp.markerBT.GetRBoundary(iter->markerIdx[2]);
			}
			else
			{
				lt.y = theApp.markerBT.GetTBoundary(iter->markerIdx[1]);
				rb.y = theApp.markerBT.GetBBoundary(iter->markerIdx[2]);
				lt.x = theApp.markerBT.GetLBoundary(iter->markerIdx[0]);
				rb.x = theApp.markerBT.GetRBoundary(iter->markerIdx[0]);
			}

			if (iter->isSingleChoice)
			{
				rectangle(theApp.img_show, lt, rb, 
					theApp.answerClicked_color, theApp.answerClicked_single_thickness);
			}
			else
			{
				rectangle(theApp.img_show, lt, rb, 
					theApp.answerClicked_multi_color, theApp.answerClicked_multi_thickness);
			}
		}
		else if ((idx - count[QUESTION]) >= theApp.cfp_group.size())
		{
			vector<cv::Rect>::iterator it = (theApp.referPoint.begin() + (idx - count[QUESTION] - theApp.cfp_group.size()));
			rectangle(theApp.img_show,*it,theApp.cfpClicked_color,theApp.cfpClicked_thickness);
		}
		else
		{
			vector<FillingPoints_info>::iterator iter = theApp.cfp_group.begin() + (idx - count[QUESTION]);
			for (unsigned int j = 0;j < iter->fillingPoints.size();j++)
			{
				cv::Point lt,rb;
				if (iter->fillingPoints[j].isCrosswise)
				{
					lt.y = theApp.markerBT.GetTBoundary(iter->fillingPoints[j].markerIdx[0]);
					rb.y = theApp.markerBT.GetBBoundary(iter->fillingPoints[j].markerIdx[0]);
					lt.x = theApp.markerBT.GetLBoundary(iter->fillingPoints[j].markerIdx[1]);
					rb.x = theApp.markerBT.GetRBoundary(iter->fillingPoints[j].markerIdx[2]);
				}
				else{
					lt.y = theApp.markerBT.GetTBoundary(iter->fillingPoints[j].markerIdx[1]);
					rb.y = theApp.markerBT.GetBBoundary(iter->fillingPoints[j].markerIdx[2]);
					lt.x = theApp.markerBT.GetLBoundary(iter->fillingPoints[j].markerIdx[0]);
					rb.x = theApp.markerBT.GetRBoundary(iter->fillingPoints[j].markerIdx[0]);
				}
				rectangle(theApp.img_show,lt,rb,theApp.cfpClicked_color,theApp.cfpClicked_thickness);
			}
		}

		emit fillPointClicked(idx);
	}
}

// ������Ŀ��Ϣ�ַ������б�ؼ�
void FillPointDlg::addQuestionStrToList(int id, bool isCrosswise,
	bool isSingleChoice, int num, int idx)
{
	QString strW ;
	
	if (isCrosswise)
	{
		if (isSingleChoice)
		{
			strW = QString(tr("��%1|����|��ѡ|%2��ѡ��").arg(id).arg(num));
		}
		else
		{
			strW = QString(tr("��%1|����|��ѡ|%2��ѡ��").arg(id).arg(num));
		}
	}
	else
	{
		if (isSingleChoice)
		{
			strW = QString(tr("��%1|����|��ѡ|%2��ѡ��").arg(id).arg(num));
		}
		else
		{
			strW = QString(tr("��%1|����|��ѡ|%2��ѡ��").arg(id).arg(num));
		}
	}

	if (idx == -1)
	{
		ui->list->addItem(strW);
	}
	else
	{
		ui->list->insertItem(idx, strW);
	}
}

int FillPointDlg::getCSpace()const
{
	return ui->cSpaceEdit->text().toInt();
}

int FillPointDlg::getRSpace()const
{
	return ui->rSpaceEdit->text().toInt();
}

string FillPointDlg::getFillPointName() const
{
	return ui->nameEdit->text().toAscii().data();
}

FillingPointsType FillPointDlg::getFillPointType()
{
	bool zero = ui->checkBox->isChecked();

	switch (ui->typeCmb->currentIndex())
	{
	case 1:
		if (zero)
			return SeatNumZeroFirst;
		else
			return SeatNumOneFirst;
		break;
	case 2:
		if (zero)
			return ExamHallNumZeroFirst;
		else
			return ExamHallNumOneFirst;
		break;
	case 3:
		if (zero)
			return ExamRoomNumZeroFirst;
		else
			return ExamRoomNumOneFirst;
		break;
	case 4:
		if (zero)
			return FirstCandidateNumZeroFirst;
		else
			return FirstCandidateNumOneFirst;
		break;
	case 5:
		if (zero)
			return TickerNumZeroFirst;
		else
			return TickerNumOneFirst;
		break;
	case 6:
		if (zero)
			return CourseNumZeroFirst;
		else
			return CourseNumOneFirst;
		break;
	case 7:
		return Absent;
		break;
	case 8:
		return PaperType;
		break;
	case 9:
		return OptionalQuestion;
		break;
	case 10:
		return Discipline;
		break;
	case 11:
		return ReferPoint;
		break;
	default:
		return Question;
	}
}

QString FillPointDlg::fillPointTypeToString(int idx)
{
	QString str;

	switch (idx)
	{
	case SeatNumZeroFirst:
	case SeatNumOneFirst:
		str = QString(tr("��λ��"));
		break;
	case ExamHallNumZeroFirst:
	case ExamHallNumOneFirst:
		str = QString(tr("������"));
		break;
	case ExamRoomNumZeroFirst:
	case ExamRoomNumOneFirst:
		str = QString(tr("���Һ�"));
		break;
	case FirstCandidateNumZeroFirst:
	case FirstCandidateNumOneFirst:
		str = QString(tr("�׿�����"));
		break;
	case TickerNumZeroFirst:
	case TickerNumOneFirst:
		str = QString(tr("׼��֤��"));
		break;
	case CourseNumZeroFirst:
	case CourseNumOneFirst:
		str = QString(tr("��Ŀ�ź�"));
		break;
	case Absent:
		str = QString(tr("ȱ��"));
		break;
	case PaperType:
		str = QString(tr("�Ծ�����"));
		break;
	case OptionalQuestion:
		str = QString(tr("ѡ����"));
		break;
	case Discipline:
		str = QString(tr("Υ��"));
		break;
	case PageNum:
		str = QString(tr("ҳ��"));
		break;
	case ReferPoint:
		str = QString(tr("ʶ��ο���"));
		break;
	default:
		str = QString(tr("ѡ����"));
		break;
	}

	return str;
}

int FillPointDlg::resume()
{
	initialization();

	if (theApp.questionType == 1)
	{
		ui->questionTypeCbx->setChecked(true);
	}
	else{
		ui->questionTypeCbx->setChecked(false);
	}

	vector<ItemPos>::iterator iter;
	for (iter = theApp.questionInfo.begin(); 
			iter != theApp.questionInfo.end(); ++iter)
	{
		short interval = iter->interval;
		addQuestionStrToList(
			iter->id,
			iter->isCrosswise,
			iter->isSingleChoice,
			(iter->markerIdx[2] - iter->markerIdx[1] + 1 + interval) / (interval + 1),
			-1);

		count[0]++;
	}

	vector<FillingPoints_info>::iterator iter2;
	for (iter2 = theApp.cfp_group.begin(); 
			iter2 != theApp.cfp_group.end(); ++iter2)
	{
		QString strW;
		QString name = QString::fromLocal8Bit((iter2->name).c_str());
		int typeId = (int)(iter2->type);
		QString type = fillPointTypeToString(typeId);
		bool isSingleChoice = iter2->fillingPoints.at(0).isSingleChoice;

		if (typeId >=0 && typeId <6)
		{		
			if (isSingleChoice)
			{
				strW = QString(tr("%1| ��ѡ| ��0��ͷ|").arg(name));
			}
			else
			{
				strW = QString(tr("%1| ��ѡ| ��0��ͷ|").arg(name));
			}
		}
		else if (typeId>=6)
		{
			if (isSingleChoice)
			{
				strW = QString(tr("%1| ��ѡ| ��1��ͷ|").arg(name));
			}
			else
			{
				strW = QString(tr("%1| ��ѡ| ��1��ͷ|").arg(name));
			}
		}

		ui->list->addItem(strW);

		if (typeId == 18)
		{
			count[11]++;
		}
		else if (typeId >= 6)
		{
			count[typeId - 5]++;
		}
		else
		{
			count[typeId + 1]++;
		}
	}

	for(int i = 0; i < theApp.referPoint.size(); ++i)
	{
		QString str = QString(tr("ʶ��ο���%1").arg(i+1));
		ui->list->addItem(str);
		count[11]++;
	}

	return 1;
}