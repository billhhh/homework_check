#ifndef _H_TANK_MODEL_H
#define _H_TANK_MODEL_H

#include "../BaseDefine.h"


//������
class Tank_Model{
public:
	Tank_Model();
	virtual ~Tank_Model();
	virtual void init() = 0;   //�������麯��������̳�
	virtual void draw() = 0;
	void setAngOri(double ang);
	void setAngPos(double ang);
	void setAngBtyUD(double ang);
	void setAngBtyLR(double ang);

	double getPower() const;
	double getRadius() const;
public:
	double power;
	double width;
	double length;
	double radius;

	double height;//��̨�߶�
	double gHeight;//�ڹܸ߶�

	double angOri;	//��ʼ����
	double angPos;	//̹�����ʼ���������γɵĽǶ�  //+zΪ��ʼ����
	double angBtyUD;
	double angBtyLR;
};

#endif