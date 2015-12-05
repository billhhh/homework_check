#ifndef _H_TANK_CONTROLLER_H
#define _H_TANK_CONTROLLER_H

#include "Tank_Model.h"
#include "Shell.h"

class Tank_Controller{
private:
	Tank_Model* tank;
	Shell* tank_shell;

	point prePos;			//ǰһ��״̬����λ��
	point nowPos;			//��ǰ״̬����λ��

	double angleOrigin;		//��ʼ����
	double anglePos;		//̹�����ʼ���������γɵĽǶ�  //+zΪ��ʼ����
	double speedMove;			//�ƶ��ٶ�
	double speedTurn;			//ת���ٶ�	//�Ƕ�Ϊ������λ360

	double angleBetteryUD;		//��̨���½Ƕ�
	double angleBetteryLR;		//��̨���ҽǶ�
	double speedTurnBetteryUD;	//��̨ת��
	double speedTurnBetteryLR;
	int		maxTurnUD;			//���������ת�Ƕ�10
	int		maxTurnLR;			//���������ת�Ƕ�

	double shell_speed;
	bool bStatus;

	char dirTank;
	char dirBettery;
public:
	Tank_Controller();
	Tank_Controller(point pos);
	~Tank_Controller();
	void init();
	void initTank(Tank_Model* tank);

	point& getPrePos();
	point& getNowPos();
	void setNowPos(point&);

	double &getAngleOrigin();
	double &getAnglePos();
	double &getAngleBetteryUD();
	double &getAngleBetteryLR();
	double getHeight();

	void move(unsigned int );			//��ֻ̹�˵��ƶ�
	void unMove();
	void turnBettery(unsigned int);		//��̨�ƶ�

	void fire();
	void unfire();
	void moveShell();
	void explosionShell();
	void setStatus(bool val);
	bool getStatus();
	point& getShellPos();
	double getCollisionRad();
	double getShellRad();
	bool isShellExist();

	//protected:
	void moveUp();
	void moveDown();
	void turnLeft();
	void turnRight();

	void turnUpBettery();
	void turnDownBettery();
	void turnLeftBettery();
	void turnRightBettery();

	void draw();

	void setDirTank(char);
	char getDirTank() const;
	void setDirBty(char);
	char getDirBty() const;
};

#endif