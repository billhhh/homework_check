
#include "Game_System.h"

using std::vector;

GameSystem* GameSystem::instance = NULL;
GLfloat GameSystem::angle = 0.0;
int GameSystem::preSystemTime = 0;
int GameSystem::nowSystemTime = 0;
int GameSystem::shellFlySystemTime = 0;
int GameSystem::shellDspSystemTime = 0;

int GameSystem::windowWidth = 800;
int GameSystem::windowHeight = 600;

MouseView GameSystem::mouseView;
Camera GameSystem::cam;
Camera GameSystem::camPos;
bool GameSystem::bView = false;

GLfloat GameSystem::camPitch = 20;
GLfloat GameSystem::camYaw = 0.0;
GLfloat GameSystem::camRadius = 150.0;

GLint GameSystem::windW = 800;
GLint GameSystem::windH = 600;
GLuint GameSystem::selectBuf[MAXHITS];
GLint GameSystem::hits;
GLint GameSystem::vp[4];

//�������
GLfloat sun_light_position[]={  1.0, 1.0, 1.0,  0.0 }; // first light over z-axis
GLfloat sun_light[]={  1.0,  0.0,  0.0,  1.0 }; // and red
GLfloat amb_color[]={  0.7,  0.7,  0.7,  1.0 }; // even ambiently

//�������
#define TEXTURE_NUM 8
GLuint texture[TEXTURE_NUM];

GameSystem::GameSystem(){

}

GameSystem* GameSystem::getInstance(){
	if( instance == NULL)
		instance = new GameSystem();
	return instance;
}

GameSystem::~GameSystem(){
	if( instance == NULL){
		delete instance;
		instance = NULL;
	}
}

void GameSystem::setWindow(int w, int h){
	windowWidth = w;
	windowHeight = h;
}

bool GameSystem::GameInit(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Tank Combat");

	//����ʱ��ص�����
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialUpFunc(specialKeyUp);

	glutIdleFunc(idle);


	//�����˵�
	int myMenu = glutCreateMenu(mainMenu);
	int selectMenu = glutCreateMenu(selectTankMenu);

	glutSetMenu(myMenu);
	glutAddMenuEntry("����/����ӽ�",1);
	glutAddMenuEntry("ȫ�Զ�!",2);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutAddSubMenu("Choose Tank",selectMenu);

	glutSetMenu(selectMenu);
	char buffer[20] = {0};

	for(int i = 0; i < control_system->getInstance()->getTankSum();++i){
		wsprintfA(buffer,"TankModel.NO%d",i);
		glutAddMenuEntry(buffer,i+1);
	}

	doMyInit();
	//������ʱ��ѭ��
	glutMainLoop();

	return 0;
}

void GameSystem::getView(){
	/*           eye point        center of view      up   */
	if( !bView){
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		cam.camX = sin(camYaw) * cos(camPitch) * camRadius;
		cam.camY = sin(camPitch) * camRadius;
		cam.camZ = cos(camYaw) * cos(camPitch) * camRadius;
		gluLookAt( cam.camX, cam.camY, cam.camZ, camPos.camX, camPos.camY, camPos.camZ, 0.0, 1.0, 0.0);
	}
	else{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		GLfloat camUpX, camUpY, camUpZ;
		control_system->getInstance()->getFirstView(cam.camX, cam.camY, cam.camZ, camPos.camX, camPos.camY, camPos.camZ, camUpX, camUpY, camUpZ);
		gluLookAt( cam.camX, cam.camY, cam.camZ, camPos.camX, camPos.camY, camPos.camZ,  camUpX, camUpY, camUpZ);
	}
}

//��ʾ�ص�����
void GameSystem::display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	control_system->getInstance()->drawAll(GL_RENDER);////�������̹��
	getView();//��ȡ�ӽ�

	glColor3f(1.0f, 1.0f, 1.0f);
	glutSwapBuffers();
}

//�ı䴰�ڻص�����
void GameSystem::reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glGetIntegerv(GL_VIEWPORT, vp);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w/(float)h, 1.0, 1000.0);//300

	glutPostRedisplay();
}

void GameSystem::motion(int x, int y) {
	if( mouseView.buttonDown == GLUT_LEFT_BUTTON) {
		// adjust the camera's yaw
		camYaw += 0.02*(GLfloat)(mouseView.mx-x);
		// wrap the yaw values at 0 and 2*pi
		if(camYaw < 0.0)
			camYaw = 6.28+camYaw;
		else if(camYaw > 6.28)
			camYaw = camYaw-6.28;

		// adjust the camera's pitch
		camPitch += 0.02*(GLfloat)(y-mouseView.my);

		// make sure we don't pitch too far
		if(camPitch > 1.57)
			camPitch = 1.57;
		else if(camPitch < 0)
			camPitch = 0;

		if( !bView){
			camPos.camX = 0;
			camPos.camY = 0;
			camPos.camZ = 0;
		}
	}else {
		// zoom in and out if right mouse button is down
		camRadius += 0.5*(GLfloat)(y-mouseView.my);
		if(camRadius < 1.0)
			camRadius = 1.0;
	}
	mouseView.mx = x;
	mouseView.my = y;
	glutPostRedisplay();
}

void GameSystem::mouse(int button, int state, int x, int y) {
	// save the mouse position for the camera rotation
	mouseView.mx = x;
	mouseView.my = y;
	if(state == GLUT_DOWN){
		mouseView.mdown = 1; //TRUE;
		if( button == GLUT_LEFT_BUTTON)
			DoSelect(x,y);
		if( button == GLUT_RIGHT_BUTTON){
			if( DoSelect(x,y)){
				bView = true;
			}else
				bView = false;
		}
	}else
		mouseView.mdown = 0; //FALSE;
	mouseView.buttonDown = button; // remember which button is down
	glutPostRedisplay();
}

void GameSystem::keyboard(unsigned char key,int x,int y){
	control_system->getInstance()->keyboardFunc(key,x,y);
	control_system->getInstance()->cameraMove(camYaw,camPitch,camRadius,camPos.camX, camPos.camY, camPos.camZ);
	glutPostRedisplay();
}

void GameSystem::keyboardUp(unsigned char key,int x,int y){
	control_system->getInstance()->keyboardUpFunc(key,x,y);
}

void GameSystem::specialKey(int key, int x, int y){
	control_system->getInstance()->specialFunc(key,x,y);
	//glutPostRedisplay();
}

void GameSystem::specialKeyUp(int key, int x, int y){
	control_system->getInstance()->specialUpFunc(key,x,y);
}
void GameSystem::idle(){
	controlFrameAndRedisplay();
	control_system->getInstance()->idleKeyFunc();
}

//��ʼ������
void GameSystem::doMyInit(void){
	glClearColor(1,1,1, 0. ); 
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	setTexture();

	glEnable(GL_TEXTURE_2D);
	bView = false;
}

////����ѡ��
bool GameSystem::DoSelect(GLint x, GLint y){
	glSelectBuffer(MAXHITS, selectBuf);
	glGetIntegerv(GL_VIEWPORT, vp);
	glRenderMode(GL_SELECT);
	glInitNames();

	// set up the viewing model
	glMatrixMode(GL_PROJECTION);///׼��ʰȡ
	glPushMatrix();//������ǰ��ͶӰ����
	glLoadIdentity();//���뵥λ����

	gluPickMatrix(x, 
				vp[3] - y, 
				2.0, 2.0, //ѡ����С
				vp);
	gluPerspective(60.0, (float)windW/(float)windH, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( cam.camX, cam.camY, cam.camZ, camPos.camX, camPos.camY, camPos.camZ, 0.0, 1.0, 0.0);

	control_system->getInstance()->drawAll(GL_SELECT);  /* draw the scene for selection */

	glPopMatrix();
	// reset viewing model
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)windW/(float)windH, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( cam.camX, cam.camY, cam.camZ, camPos.camX, camPos.camY, camPos.camZ, 0.0, 1.0, 0.0);
	//���ѡ�񼯲����
	hits = glRenderMode(GL_RENDER);

	GLuint name, *ptr;
	printf("ѡ�е���ĿΪ%d��\n",hits);

	if( hits <= 0){
		return false;
	}else{
		ptr = selectBuf;
		for(GLint i=0;i<hits; i++){
			name = *ptr;    //ѡ��ͼԪ�ڶ�ջ�е�λ��
			ptr += 3;       //�������ֺ������Ϣ
			ptr += name-1;  //����λ����Ϣ���ѡ�е�ͼԪ����
			printf("��ѡ����̹��%i\n",*ptr);
			control_system->getInstance()->selectTank((*ptr)+1);
			ptr++;
		}
	}
	printf("\n\n");
	return true;
}

void GameSystem::mainMenu(int input){
	control_system->getInstance()->mainMenu(input);
}
void GameSystem::selectTankMenu(int input){
	control_system->getInstance()->selectTank(input);
	glutPostRedisplay();
}

void GameSystem::controlFrameAndRedisplay(){
	nowSystemTime = glutGet(GLUT_ELAPSED_TIME);
	if(nowSystemTime - preSystemTime > 50){
		preSystemTime = nowSystemTime;
	}
	control_system->getInstance()->idleFunc();

	if(nowSystemTime - shellFlySystemTime > 20){
		shellFlySystemTime = nowSystemTime;
		control_system->getInstance()->unFireTank();
	}

	if(nowSystemTime - shellDspSystemTime > 2000){
		shellDspSystemTime = nowSystemTime;
		control_system->getInstance()->reStart();
	}

	if( nowSystemTime % 18 == 0)
		control_system->getInstance()->computerCmd();

	glutPostRedisplay();
}

// ����λͼͼ��
AUX_RGBImageRec* GameSystem::LoadBMP(char *filename){
	FILE *file=NULL; // �ļ���� 
	if (!filename) // ȷ���ļ������ṩ��
		return NULL; // ���û�ṩ������ NULL

	//���Դ��ļ�
	file = fopen(filename,"r"); 
	//�ļ�����ô?
	if(file){
		fclose(file); // �رվ��
		WCHAR wsz[128] = {0};
		//swprintf(wsz,L"%s",pTempPath);
		MultiByteToWideChar(CP_ACP, 0 , filename,-1,wsz,strlen(filename));
		return auxDIBImageLoad(wsz); //����λͼ������ָ��
	} 
	return NULL; // �������ʧ�ܣ����� NULL
} 


void GameSystem::setTexture(){
	char *mapSourFile[] = {"res/micai2.bmp","res/tank_track2.bmp","res/tank_wheel2.bmp","res/micai.bmp","res/tankstone.bmp"
		,"res/Camo.bmp","res/066.bmp","res/sky1.bmp"/*,"078.bmp"*/};
	//�������
	AUX_RGBImageRec *TextureImage[TEXTURE_NUM];					// Create Storage Space For The Texture
	memset(TextureImage,0,sizeof(void *)*TEXTURE_NUM);           	// Set The Pointer To NULL

	for(int i = 0; i< TEXTURE_NUM ; i++){
		if(TextureImage[i] = LoadBMP(mapSourFile[i])){
			glGenTextures(i+1, &texture[i]);
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY,
				0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}

	for( int i = 0; i < TEXTURE_NUM; ++i){
		if (TextureImage[i]){
			if (TextureImage[i]->data)
				free(TextureImage[i]->data);	
			free(TextureImage[i]);
		}
	} 
}