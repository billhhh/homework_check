#ifndef _H_TANK_MODEL_TYPEB_H
#define _H_TANK_MODEL_TYPEB_H

#include "Tank_Model.h"

class Tank_Model_TypeB:public Tank_Model{
private:
	GLUquadric *SP,*LG,*RG,*LG2,*RG2;
public:
	Tank_Model_TypeB();
	Tank_Model_TypeB(point& oriPos);
	virtual ~Tank_Model_TypeB();

	void track_L(void);//����Ĵ�
	void track_R(void);//�ұ��Ĵ�
	void body(void);//����
	void bettery(void);//��̨
	void ball(void);//����
	void gun(void);//�ڹ�

	virtual void init();
	virtual void draw();
};

#endif