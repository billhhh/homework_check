#pragma once
#ifndef CARDDOCDLG_H
#define CARDDOCDLG_H

#include "qstring.h"
#include "qlist.h"
#include "Zip\ACZip.h"
#include "qimage.h"
#include "../AnswerCard/DataIO.h"
#include <vector>

using std::vector;

#define PAPERSET_MAGIC_NUM 0x0000CD01
#define VERSION 102

//һ���Ծ�Ľṹ
struct PaperPage
{
	QString pageId;
	bool isPositive;
};

//һ���Ծ�Ľṹ
struct PaperSet
{
	QString setId;
	int dpi;
	//QString setName;
	vector<PaperPage> page;
};

struct Course
{
	QString courseName;
	vector<PaperSet> set;
};

class CardDoc
{
public:
	CardDoc(int acType);
	~CardDoc();

	int getAcType() const {return m_acType;}
	vector<PaperSet> getPaperSet(int courseIndex) {return m_course.at(courseIndex).set;}
	vector<Course> getCourse() {return m_course;}

	//���ɾ��һ�ſ�Ŀ
	void createCourse(const QString& name);
	void removeCourse(int index);
	//void removeCourse(const QString& name);

	//���ɾ��һ���Ծ�
	void createPaperSet(int courseIndex, const QString& setId, int dpi);
	int removePaperSet(int courseIndex, int index);
	//void removePaperSet(const QString& setId);

	//���ɾ��һ���Ծ�
	int insertPaperPage(int courseIndex, int setIndex, const PaperPage& paperPage, const QImage& img);
	//void insertPaperPage(const QString& setId, const PaperPage& paperPage);
	int removePaperPage(int courseIndex, int setIndex, int pageIndex);
	//void removePaperPage(const QString& setId, const QString& pageId);
	
	//��ȡһ���Ծ����ж������Ծ�
	int getPageCountOfSet(int courseIndex, int setIndex) const;
	int getSetCountOfCourse(int courseIndex) const;

	//�ж��Ծ���id�Ƿ���ڣ�������ڣ��򷵻��±꣬���򷵻�-1
	int isPaperSetIdExist(int courseIndex, const QString& id);
	int isPageIdOfSetExist(int courseIndex, int setIndex, const QString& id);
	int isCourseExist(const QString& name);

	PaperPage getPageDetail(int courseIndex, int setIndex, int pageIndex) const;
	PaperSet getPageSetDetail(int courseIndex, int setIndex) const;

	//��������Ծ���Ϣ
	int zipPaperSetInfo(int courseIndex, const QString &zipPath);

	//��ACPOJ�ļ��лָ�����
	int resumeDataFromZip(const QString &zipPath);

private:
	//vector<PaperSet> m_paperSet;
	vector<Course> m_course;
	int m_acType;

	//�����Ծ���ϵ��Ϣ
	int savePaperSetRelationFile(int courseIndex, QString fileName);

	//���������ʱ�ļ�
	void removeTempFile();
	void removeTempFile(const QString& path);
};

#endif