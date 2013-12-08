
#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif 

#define _USE_MATH_DEFINES
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include "DrawObject.h"
#include "CollisionObject.h"
#include <string>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <irrKlang.h>

#using <System.Drawing.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace std;
using namespace System;
using namespace irrklang;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

#define DEFAULT_WINDOW_WIDTH 1366
#define DEFAULT_WINDOW_HEIGHT 768
#define KEYBOARD_S 115
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_SPACE 32
#define KEYBOARD_F 102
#define KEYBOARD_N 110

int windowWidth = DEFAULT_WINDOW_WIDTH;
int windowHeight = DEFAULT_WINDOW_HEIGHT;
char* windowName = "My Glut Window";
int stereo = 0;
int texID = 0;

// C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack
// C:\\Users\\Todd\\Desktop\\Fall 2013\\groupDolphin attack\\BaseGlutOpenGL
// C:\\Users\\Ryan\\Documents\\DolphinAttack

DrawObject* title = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Title.obj");
LPTSTR titleTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\titletexture.bmp";

CollisionObject* dolphin = new CollisionObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Dolphin.obj", 6);
LPTSTR dolphinSkin = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\dolphinskin.bmp";

DrawObject* arena = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Arena.obj");
LPTSTR arenaTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\arenatexture.bmp";

DrawObject* sky = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Sky.obj");
LPTSTR skyTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\skytexture.bmp";

DrawObject* sun = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Sun.obj");
LPTSTR sunSmileTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\sunsmile.bmp";
LPTSTR sunGaspTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\sungasp.bmp";

CollisionObject* swimmer = new CollisionObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Swimmer.obj", 2);
LPTSTR swimmerTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\swimmertexture.bmp";

DrawObject* trees = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Trees.obj");
LPTSTR treesTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\treestexture.bmp";

GLuint textures[8];

GLuint titleTextID;
GLuint dolphinTextID;
GLuint arenaTextID;
GLuint skyTextID;
GLuint sunSmileTextID;
GLuint sunGaspTextID;
GLuint sunTextID;
GLuint swimmerTextID;
GLuint treesTextID;

bool specialKeys[1000] = {0};
bool* keyStates = new bool[256];

float tranX = 0.0;
float tranY = 0.0;
float tranZ = 0.0;
float rotY = 0.0;
float rotX = -3.0;
float rotZ = 0.0;

bool InMainMenu = true;
int timeLeft = 99;  //TIMER FOR HOW LONG THE GAME LASTs
char time[2];

ISoundEngine* engine;

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
void NewSwimmerPosition();
bool IsCollision();

#ifdef WIN32
GLvoid PollJoyStick(GLvoid);
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha);
#endif 

void startBackgroundMusic(){
	// play some sound stream, looped
	engine->play2D("C:\\Users\\Ryan\\Documents\\DolphinAttack\\audio\\musicLoop.wav", true);
}


static void timer(int value)
{
	switch (value)
	{
	//Game Timer
	case 0:
		if(timeLeft > 0)
		{
			timeLeft--;
			itoa(timeLeft,time,10);
			glutPostRedisplay();
			glutTimerFunc(1000, timer, 0);
		}
		else
		{
			std::cout<<"Game Over"<<endl;
			//system("pause");
		}
		break;
	case 1:
		sunTextID = sunSmileTextID;
		break;
	}
}

int main(int argc, char* argv[]){
	for(int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
	}

	// start the sound engine with default parameters
	engine = createIrrKlangDevice();

	if (!engine)
	{
		std::cout << "Sound error!" << std::endl;
		return 0; // error starting up the engine
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(windowName);
	glutFullScreen();
	startBackgroundMusic();

	InitGL();

	glutDisplayFunc(DrawGLScene);
	glutIdleFunc(IdleGLScene);
	glutReshapeFunc(ReSizeGLScene);
	glutKeyboardFunc(GLKeyDown);
	glutKeyboardUpFunc(GLKeyUp);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutSetCursor(GLUT_CURSOR_NONE);
	timer(0);
	glutMainLoop();

	engine->drop();
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

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

	NeHeLoadBitmap(titleTexture, titleTextID, false);
	title->translation = Vector3f(-.05, 3.89, -16.9);
	title->scale = Vector3f(1.6, 1.55, 1.5);
	title->rotation = Vector3f(103.5, 180, 0);

	NeHeLoadBitmap(dolphinSkin, dolphinTextID, false);
	dolphin->translation = Vector3f(1.2, -5.4, -20);
	dolphin->rotation = Vector3f(-30, -40, -20);

	NeHeLoadBitmap(arenaTexture, arenaTextID, false);
	arena->translation = Vector3f(0, -188, -6.9);
	arena->scale = Vector3f(100, 100, 100);

	NeHeLoadBitmap(skyTexture, skyTextID, false);
	sky->translation = Vector3f(0, -188 , -6.9);
	sky->scale = Vector3f(120, 120, 120);

	NeHeLoadBitmap(sunGaspTexture, sunGaspTextID, true);
	NeHeLoadBitmap(sunSmileTexture, sunSmileTextID, true);
	sun->translation = Vector3f(0, -188, -6.9);
	sun->scale = Vector3f(120, 120, 120);
	sunTextID = sunSmileTextID;

	NeHeLoadBitmap(swimmerTexture, swimmerTextID, false);
	NewSwimmerPosition();
	swimmer->scale = Vector3f(40, 40, 40);
	swimmer->bobbingVelocity = 0;

	NeHeLoadBitmap(treesTexture, treesTextID, true);
	trees->translation = Vector3f(0, -220 , -6.9);
	trees->scale = Vector3f(120, 120, 120);
}

void moveDolphin(){
	tranZ += dolphin->velocity * cos(rotY * (M_PI / 180));
	tranX -= dolphin->velocity * sin(rotY * M_PI / 180);
	float zMove = dolphin->velocity * cos(dolphin->rotation.y * (M_PI / 180));
	float yMove = dolphin->velocity * sin(dolphin->rotation.y * M_PI / 180);
	dolphin->translation.z += zMove;
	dolphin->translation.x += yMove;
	sky->translation.z += zMove;
	sky->translation.x += yMove;
	sun->translation.z += zMove;
	sun->translation.x += yMove;
	if(!specialKeys[GLUT_KEY_UP] && !specialKeys[GLUT_KEY_DOWN])
		dolphin->velocity *= .95;
	if(!specialKeys[GLUT_KEY_LEFT] && !specialKeys[GLUT_KEY_RIGHT])
		dolphin->rotation.z *= .9;
	dolphin->rotation.x = (dolphin->velocity * 0.5) + 3*(dolphin->translation.y+12) - 3*(dolphin->velocity-1)+15;
	rotX = (dolphin->velocity)*.7 - 3;
	if (dolphin->velocity < .2 && dolphin->velocity > -.2)
		dolphin->velocity = 0;
	if(!specialKeys[GLUT_KEY_UP]){
		if (dolphin->bobbingVelocity >= 0 && dolphin->translation.y <= -16)
			dolphin->translation.y += .01;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -16)
			dolphin->translation.y -= .07;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -16.5)
			dolphin->translation.y -= .01;
		else
			dolphin->bobbingVelocity *= -1;
	}
}

void bobSwimmer()
{
	if (swimmer->translation.y > -12.75)
	{
		swimmer->bobbingVelocity -= .0007;
		swimmer->rotation.x += .05;
	}
	else
	{
		swimmer->bobbingVelocity += .0007;
		swimmer->rotation.x -= .05;
	}

	swimmer->translation.y += swimmer->bobbingVelocity;
}

void updateValues()
{
	if (!InMainMenu) {
		moveDolphin();
		bobSwimmer();
	}
}

void draw(DrawObject * object, GLuint textID)
{
	glTranslatef(object->translation.x, object->translation.y, object->translation.z);
	glScalef(object->scale.x, object->scale.y, object->scale.z);

	switch(object->rotateFirst){
		case 0:
			glRotatef(object->rotation.x,1.0f,0.0f,0.0f);
			break;
		case 1:
			glRotatef(object->rotation.y,0.0f,1.0f,0.0f);
			break;
		case 2:
			glRotatef(object->rotation.z,0.0f,0.0f,1.0f);
			break;
	}

	switch(object->rotateSecond){
		case 0:
			glRotatef(object->rotation.x,1.0f,0.0f,0.0f);
			break;
		case 1:
			glRotatef(object->rotation.y,0.0f,1.0f,0.0f);
			break;
		case 2:
			glRotatef(object->rotation.z,0.0f,0.0f,1.0f);
			break;
	}

	switch(object->rotateThird){
		case 0:
			glRotatef(object->rotation.x,1.0f,0.0f,0.0f);
			break;
		case 1:
			glRotatef(object->rotation.y,0.0f,1.0f,0.0f);
			break;
		case 2:
			glRotatef(object->rotation.z,0.0f,0.0f,1.0f);
			break;
	}

	glBindTexture(GL_TEXTURE_2D, textID);
	glBegin(GL_TRIANGLES);

	for(unsigned int i = 0; i < object->faceVerts.size(); i++)
	{
		float x = (object->textCoords[object->textVerts[i]-1]).x;
		float y  = (object->textCoords[object->textVerts[i]-1]).y;
		glTexCoord2f(x,y);
		x = (object->normals[object->normVerts[i]-1]).x;
		y = (object->normals[object->normVerts[i]-1]).y;
		float z = (object->normals[object->normVerts[i]-1]).z;
		glNormal3f(x,y,z);
		x = (object->verts[object->faceVerts[i]-1]).x;
		y = (object->verts[object->faceVerts[i]-1]).y;
		z = (object->verts[object->faceVerts[i]-1]).z;
		glVertex3f(x,y,z);
	}

	glEnd();
}

GLvoid DrawGLScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	updateValues();

	if (IsCollision())
	{
		engine->play2D("C:\\Users\\Ryan\\Documents\\DolphinAttack\\audio\\dolphinlaugh.wav");
		NewSwimmerPosition();
		sunTextID = sunGaspTextID;
		glutTimerFunc(1000, timer, 1);
	}

	if (InMainMenu) {

		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX-10,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,tranY,tranZ);

		glPushMatrix();
		draw(title, titleTextID);
		glPopMatrix();

	} else { // In Game
		glViewport(0, 0, windowWidth, windowHeight);

		glPushMatrix();
			glDisable(GL_TEXTURE_2D);
			//glColor3f(1, 0, 0);
			glTranslatef(26, 14, -40);
			glRasterPos2f(0,0);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,time[0]);
			if(timeLeft > 9)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,time[1]);
			}
			glEnable(GL_TEXTURE_2D);
		glPopMatrix();

		glTranslatef(0, 0, -40);
		glRotatef(rotX,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(0, 0, 40);
		glTranslatef(tranX,tranY,tranZ);

		glPushMatrix();
		draw(arena, arenaTextID);
		glPopMatrix();

		glPushMatrix();
		draw(sky, skyTextID);
		glPopMatrix();

		glPushMatrix();
		draw(sun, sunTextID);
		glPopMatrix();

		glPushMatrix();
		draw(trees, treesTextID);
		glPopMatrix();

		glPushMatrix();
		draw(swimmer, swimmerTextID);
		glPopMatrix();

		glPushMatrix();
		draw(dolphin, dolphinTextID);
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
	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 2500.0f);
	windowWidth = width;
	windowHeight = height;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

GLvoid GLKeyDown(unsigned char key, int x, int y){
	if(key == KEYBOARD_ESC)
	{
		exit(0);
	}

	if(key == KEYBOARD_ENTER && InMainMenu)
	{
		InMainMenu = false;
		dolphin->translation = Vector3f(0, -14.3, -40);
		dolphin->rotation = Vector3f(0, 180, 0);
		dolphin->rotateFirst = 1;
		dolphin->rotateSecond = 0;
		dolphin->rotateThird = 2;
	}

	if (!InMainMenu)
	{
		keyStates[key] = true;
	}
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
	if(!InMainMenu){
		if(specialKeys[GLUT_KEY_LEFT]){
			float turnAmount = 1.8*fabs(dolphin->velocity/6)+0.2;
			rotY += -turnAmount;
			dolphin->rotation.y += turnAmount;
			if (dolphin->rotation.z >= -10)
				dolphin->rotation.z -= 1;
		}
		if(specialKeys[GLUT_KEY_RIGHT]){
			float turnAmount = 1.8*fabs(dolphin->velocity/6)+0.2;
			rotY += turnAmount;
			dolphin->rotation.y += -turnAmount;
			if (dolphin->rotation.z <= 10)
				dolphin->rotation.z += 1;
		}
		if(specialKeys[GLUT_KEY_UP]){
			if (dolphin->velocity <= 3)
				dolphin->velocity += .3;
			if (dolphin->bobbingVelocity >= 0 && dolphin->translation.y <= -14)
				dolphin->translation.y += .1;
			else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -16.5)
				dolphin->translation.y -= .1;
			else
				dolphin->bobbingVelocity *= -1;
		}
		if(specialKeys[GLUT_KEY_DOWN]){
			if (dolphin->velocity >= -.5)
				dolphin->velocity -= .2;
		}
	}
}

bool IsCollision()
{
	return dolphin->CollidesWith(swimmer);
}

void NewSwimmerPosition()
{
	int maxDistance = 690;
	int angle = (rand() % 360) * (M_PI / 180);
	int faceAngle = (rand() % 360) * (M_PI / 180);
	int distance = rand() % maxDistance;
	swimmer->translation = Vector3f(distance * cos(angle), -12.35, distance * sin(angle));
	swimmer->rotation.y = faceAngle;
	swimmer->bobbingVelocity = 0;
}

#ifdef WIN32
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha)
{
	HBITMAP hBMP;														
	BITMAP	BMP;														
	glGenTextures(1, &texid);											
	hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );
	if (!hBMP)															
		return FALSE;													
	GetObject(hBMP, sizeof(BMP), &BMP);									
	glBindTexture(GL_TEXTURE_2D, texid);								
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (alpha)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, BMP.bmWidth, BMP.bmHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	}
	else
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	}

	DeleteObject(hBMP);													
	return TRUE;														
}

GLvoid PollJoyStick(){
	JOYINFOEX stuff;
	ZeroMemory(&stuff, sizeof(stuff));
	stuff.dwSize = sizeof(stuff);
	stuff.dwFlags |= JOY_RETURNALL;
	joyGetPosEx(JOYSTICKID1, &stuff);
}

#endif 
