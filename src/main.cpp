
#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif 

#define _USE_MATH_DEFINES
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include "OBJParser.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480
#define KEYBOARD_S 115
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_F 102
#define KEYBOARD_N 110

int windowWidth = DEFAULT_WINDOW_WIDTH;
int windowHeight = DEFAULT_WINDOW_HEIGHT;
char* windowName = "My Glut Window";

int fullscreen = 1;
int stereo = 0;
int texID = 0;

char* title = "c:\\users\\ben romney\\documents\\github\\dolphinattack\\models\\Title.obj";
OBJParser* titleParser = new OBJParser();
LPTSTR titleTexture = L"c:\\users\\ben romney\\documents\\github\\dolphinattack\\textures\\titletexture.bmp";
char* dolphin = "c:\\users\\ben romney\\documents\\github\\dolphinattack\\models\\Dolphin.obj";
OBJParser* dolphinParser = new OBJParser();
LPTSTR dolphinSkin = L"c:\\users\\ben romney\\documents\\github\\dolphinattack\\textures\\dolphinskin.bmp";
char* arena = "c:\\users\\ben romney\\documents\\github\\dolphinattack\\models\\Arena.obj";
OBJParser* arenaParser = new OBJParser();
LPTSTR arenaTexture = L"c:\\users\\ben romney\\documents\\github\\dolphinattack\\textures\\arenatexture.bmp";

GLuint textures[3];

GLuint titleTextID;
GLuint dolphinTextID;
GLuint arenaTextID;

bool specialKeys[1000] = {0};
bool* keyStates = new bool[256];

float tranY = 0.0;
float tranX = 0.0;
float tranZ = 0.0;
float rotY = 0.0;
float rotX = 9.0;
float rotZ = 0.0;

bool InMainMenu = true;

float dolphinTranX = 0;
float dolphinTranY = -13.0;
float dolphinTranZ = -40;
float dolphinRotX = 0.0;
float dolphinRotY = 180.0;

float arenaTranX = -2.0;
float arenaTranY = -190;
float arenaTranZ = -6.9;
float arenaScaleX = 100;
float arenaScaleY = 100;
float arenaScaleZ = 100;

GLvoid HandleKeyboardInput();

GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid IdleGLScene(GLvoid);
GLvoid ReSizeGLScene(int width, int height);
GLvoid GLKeyDown(unsigned char key, int x, int y);
GLvoid GLKeyUp(unsigned char key, int x, int y);
GLvoid SpecialKeys(int key, int x, int y);
GLvoid SpecialKeysUp(int key, int x, int y);
void CleanUp();

#ifdef WIN32
GLvoid PollJoyStick(GLvoid);
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid);
#endif 

int main(int argc, char* argv[]){
	for(int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(windowName);
	glutFullScreen();

	InitGL();

	glutDisplayFunc(DrawGLScene);
	glutIdleFunc(IdleGLScene);
	glutReshapeFunc(ReSizeGLScene);
	glutKeyboardFunc(GLKeyDown);
	glutKeyboardUpFunc(GLKeyUp);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutMainLoop();

	return 0;
}

void CleanUp(){
}

GLvoid InitGL(){
	glShadeModel(GL_SMOOTH);							
	glClearColor(0.10f, 0.59f, 0.74f, 0.0f);				
	glClearDepth(1.0f);									
	glEnable(GL_DEPTH_TEST);							
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);								
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	NeHeLoadBitmap(titleTexture,titleTextID);
	titleParser->ParseOBJ(title);
	NeHeLoadBitmap(dolphinSkin,dolphinTextID);
	dolphinParser->ParseOBJ(dolphin);
	NeHeLoadBitmap(arenaTexture,arenaTextID);
	arenaParser->ParseOBJ(arena);
}

void updateValues()
{
	if (!InMainMenu) {
		if(keyStates['k'])
		{
			rotY += -3;
			dolphinTranX -= 2.12*cos(rotY * (M_PI / 180));
			dolphinTranZ += 2.12*sin(-rotY * (M_PI / 180));
			dolphinRotY += 3;
		}
		if(keyStates[';'])
		{
			rotY += 3;
			dolphinTranX += 2.12*cos(rotY * (M_PI / 180));
			dolphinTranZ -= 2.12*sin(-rotY * (M_PI / 180));
			dolphinRotY += -3;
		}
		if(keyStates['o'])
		{
			rotX -= 1;
			dolphinRotX -= -1;
		}
		if(keyStates['l'])
		{
			rotX += 1;
			dolphinRotX += -1;
		}
		if(keyStates['a'])
		{
			tranX += 2 * cos(rotY * (M_PI / 180));
			tranZ -= 2 * sin(-rotY * M_PI / 180);
			dolphinTranX += -2 * cos(rotY * (M_PI / 180));
			dolphinTranZ -= -2 * sin(-rotY * M_PI / 180);
		}
		if(keyStates['d'])
		{
			tranX -= 2 * cos(rotY * (M_PI / 180));
			tranZ -= 2 * sin(rotY * M_PI / 180);
			dolphinTranX -= -2 * cos(rotY * (M_PI / 180));
			dolphinTranZ -= -2 * sin(rotY * M_PI / 180);
		}
		if(keyStates['w']){
			tranZ += 3 * cos(rotY * (M_PI / 180));
			tranX -= 3 * sin(rotY * M_PI / 180);
			dolphinTranZ += 3 * cos(dolphinRotY * (M_PI / 180));
			dolphinTranX += 3 * sin(dolphinRotY * M_PI / 180);
		}
		if(keyStates['s']){
			tranZ -= 3 * cos(rotY * (M_PI / 180));
			tranX -= 3 * sin(-rotY * M_PI / 180);
			dolphinTranZ -= 3 * cos(dolphinRotY * (M_PI / 180));
			dolphinTranX -= 3 * sin(dolphinRotY * M_PI / 180);
		}
	}
}

void draw(OBJParser * parser)
{
	for(int i = 0; i < parser->faceVerts.size(); i++)
	{
		float x = (parser->textCoords[parser->textVerts[i]-1]).x;
		float y  = (parser->textCoords[parser->textVerts[i]-1]).y;
		glTexCoord2f(x,y);
		x = (parser->normals[parser->normVerts[i]-1]).x;
		y = (parser->normals[parser->normVerts[i]-1]).y;
		float z = (parser->normals[parser->normVerts[i]-1]).z;
		glNormal3f(x,y,z);
		x = (parser->verts[parser->faceVerts[i]-1]).x;
		y = (parser->verts[parser->faceVerts[i]-1]).y;
		z = (parser->verts[parser->faceVerts[i]-1]).z;
		glVertex3f(x,y,z);
	}
}

GLvoid DrawGLScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	updateValues();

	if (InMainMenu) {

		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX-15,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,-1.0f,tranZ);

		glPushMatrix();
			glTranslatef(0,8.3,-30);
			glScalef(1.6,1.4,1.5);
			glRotatef(95,1.0f,0.0f,0.0f);
			glRotatef(180,0.0f,1.0f,0.0f);
			glBindTexture(GL_TEXTURE_2D,titleTextID);
			glBegin(GL_TRIANGLES);
				draw(titleParser);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(arenaTranX,arenaTranY,arenaTranZ);
			glScalef(arenaScaleX,arenaScaleY,arenaScaleZ);
			glBindTexture(GL_TEXTURE_2D,arenaTextID);
			glBegin(GL_TRIANGLES);
				draw(arenaParser);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.2,-5.4,-20);
			glRotatef(-30,1.0f,0.0f,0.0f);
			glRotatef(-40,0.0f,1.0f,0.0f);
			glRotatef(-20,0.0f,0.0f,1.0f);
			glBindTexture(GL_TEXTURE_2D,dolphinTextID);
			glBegin(GL_TRIANGLES);
				draw(dolphinParser);
			glEnd();
		glPopMatrix();

	} else { // In Game

		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,-1.0f,tranZ);

		glPushMatrix();
			glTranslatef(arenaTranX,arenaTranY,arenaTranZ);
			glScalef(arenaScaleX,arenaScaleY,arenaScaleZ);
			glBindTexture(GL_TEXTURE_2D,arenaTextID);
			glBegin(GL_TRIANGLES);
				draw(arenaParser);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(dolphinTranX,dolphinTranY,dolphinTranZ);
			glRotatef(dolphinRotX,1.0f,0.0f,0.0f);
			glRotatef(dolphinRotY,0.0f,1.0f,0.0f);
			glBindTexture(GL_TEXTURE_2D,dolphinTextID);
			glBegin(GL_TRIANGLES);
				draw(dolphinParser);
			glEnd();
		glPopMatrix();
	}

	glFlush();
	glutSwapBuffers();
}

GLvoid IdleGLScene(){
	PollJoyStick();
	HandleKeyboardInput();
	DrawGLScene();
}

GLvoid ReSizeGLScene(int width, int height){
	if(height == 0)
		height = 1;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(stereo)
		gluPerspective(45.0f, (GLfloat)width/((GLfloat)height * 2.0f), 0.1f, 2000.0f);
	else
		gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 2000.0f);

	windowWidth = width;
	windowHeight = height;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

GLvoid GLKeyDown(unsigned char key, int x, int y){
	if(key == KEYBOARD_ESC)
		exit(0);
	if(key == KEYBOARD_ENTER)
		InMainMenu = false;
	/*if(key == KEYBOARD_F){
		if(stereo)
			return;
		if(fullscreen){
			fullscreen = 0;
			glutReshapeWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
			glutPositionWindow(100,100);
		}
		else{
			glutFullScreen();
			fullscreen = 1;
		}
	}*/
	keyStates[key] = true;

#ifdef WIN32
	if(key == KEYBOARD_N){ 
		if(stereo){
			if(!fullscreen){
				glutReshapeWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
				glutPositionWindow(100,100);
			}
			else{
				glutFullScreen();
			}
			stereo = 0;
			DrawGLScene();
		}
		else{
			glutFullScreen();
			stereo = 1;
			DrawGLScene();
		}
	}
#endif 
}

GLvoid GLKeyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}

GLvoid SpecialKeys(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			specialKeys[GLUT_KEY_LEFT] = 1;
			break;
		case GLUT_KEY_RIGHT:
			specialKeys[GLUT_KEY_RIGHT] = 1;
			break;
		case GLUT_KEY_UP:
			specialKeys[GLUT_KEY_UP] = 1;
			//rotX += .5f;
			break;
		case GLUT_KEY_DOWN:
			specialKeys[GLUT_KEY_DOWN] = 1;
			//rotX += -.5f;
			break;
		default:
			break;
	}
}

GLvoid SpecialKeysUp(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			specialKeys[GLUT_KEY_LEFT] = 0;
			break;
		case GLUT_KEY_UP:
			specialKeys[GLUT_KEY_UP] = 0;
			break;
		case GLUT_KEY_RIGHT:
			specialKeys[GLUT_KEY_RIGHT] = 0;
			break;
		case GLUT_KEY_DOWN:
			specialKeys[GLUT_KEY_DOWN] = 0;
			break;
		default:
			break;
	}
}

GLvoid HandleKeyboardInput(){
	if(specialKeys[GLUT_KEY_LEFT]){
		std::cout << "Key left pressed" << std::endl;
	}
	if(specialKeys[GLUT_KEY_RIGHT]){
		std::cout << "Key right pressed" << std::endl;
	}
	if(specialKeys[GLUT_KEY_UP]){
		std::cout << "Key Up pressed" << std::endl;
	}
}

#ifdef WIN32
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid)					
{
	HBITMAP hBMP;														
	BITMAP	BMP;														
	glGenTextures(1, &texid);											
	hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );
	if (!hBMP)															
		return FALSE;													
	GetObject(hBMP, sizeof(BMP), &BMP);									
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);								
	glBindTexture(GL_TEXTURE_2D, texid);								
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	DeleteObject(hBMP);													
	return TRUE;														
}

GLvoid PollJoyStick(){
	JOYINFOEX stuff;
	ZeroMemory(&stuff, sizeof(stuff));
	stuff.dwSize = sizeof(stuff);
	stuff.dwFlags |= JOY_RETURNALL;
	joyGetPosEx(JOYSTICKID1, &stuff);

	/*float axisY = (float)(stuff.dwYpos - 32767.0f) / 32768;
	float axisX = (float)(stuff.dwXpos - 32767.0f) / 32768;
	float axisZ = (float)(stuff.dwZpos - 32767.0f) / 32768;
	float axisR = (float)(stuff.dwRpos - 32767.0f) / 32768;
	
	if(axisX > .2 || axisX < -.2)
	{
		tranX -= axisX * cos(rotY * (M_PI / 180));
		tranZ -= axisX * sin(rotY * M_PI / 180);
	}
	if(axisY > .2 || axisY < -.2)
	{
		tranZ -= axisY * cos(rotY * (M_PI / 180));
		tranX += axisY * sin(rotY * M_PI / 180);
	}

	if(axisR > .2 || axisR < -.2)
	{
		rotY += 3 * axisR;
	}
	if(axisZ > .2 || axisZ < -.2)
	{
		rotX += 3 * axisZ;
	}

	if(stuff.dwPOV == 0 || stuff.dwPOV == 4500 || stuff.dwPOV == 31500)
	{
		
	}
	if(stuff.dwPOV == 9000 || stuff.dwPOV == 4500)
	{
		if(rfRotY > rbRotY - 30)
		{	
			rfRotY -= 5;
		}
		if(lfRotY > lbRotY - 30)
		{
			lfRotY -= 5;
		}
	}
	if(stuff.dwPOV == 18000 || stuff.dwPOV == 22500 || stuff.dwPOV == 13500)
	{
		printf("button down is pressed ");
	}
	if(stuff.dwPOV == 27000 || stuff.dwPOV == 22500)
	{
		if(rfRotY < rbRotY + 30)
		{	
			rfRotY += 5;
		}
		if(lfRotY < lbRotY + 30)
		{
			lfRotY += 5;
		}
	}

	unsigned int buttons = stuff.dwButtons;
	int dPad = stuff.dwPOV;
	
	if(stuff.dwButtons & 1) {
		printf("button triangle is pressed ");
	}
	if(stuff.dwButtons & 2) {
		leftSideX -= 15;
		rightSideX += 15;
		carTranZ += .15 * cos(carRotY * (M_PI / 180));
		carTranX += .15 * sin(carRotY * M_PI / 180);

		if(rfRotY > rbRotY)
		{
			carRotY -= rfRotY/5;
		}
		else if(rfRotY < rbRotY)
		{
			carRotY -= rfRotY/5;
		}
	}
	if(stuff.dwButtons & 4) {
		leftSideX += 15;
		rightSideX -= 15;
		carTranZ -= .15 * cos(carRotY * (M_PI / 180));
		carTranX -= .15 * sin(carRotY * M_PI / 180);
		if(rfRotY > rbRotY)
		{
			carRotY += rfRotY/5;
		}
		else if(rfRotY < rbRotY)
		{
			carRotY += rfRotY/5;
		}
	}
	if(stuff.dwButtons & 8) {
		printf("button square is pressed ");
	}
	
	std::cout << "My joystick outputs: " << std::endl
		<< "Axis Data: " << std::endl
		<< "\tAxisY: " << axisY << std::endl
		<< "\tAxisX: " << axisX << std::endl
		<< "\tAxisZ: " << axisZ << std::endl
		<< "\tAxisR: " << axisR << std::endl << std::endl
		<< "Button Data:" << std::endl
		<< "\tMy Button Data is: " << buttons << std::endl
		<< "POV:" << std::endl
		<< "\t" << stuff.dwPOV << endl;
	*/
}

#endif 
