
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

#using <System.Drawing.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace std;
using namespace System;
using namespace System::Media;

#define DEFAULT_WINDOW_WIDTH 1366
#define DEFAULT_WINDOW_HEIGHT 768
#define KEYBOARD_S 115
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_SPACE 32
#define KEYBOARD_N 110

int windowWidth = DEFAULT_WINDOW_WIDTH;
int windowHeight = DEFAULT_WINDOW_HEIGHT;
char* windowName = "My Glut Window";
int texID = 0;

// C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack
// C:\\Users\\Todd\\Desktop\\Fall 2013\\groupDolphin attack\\BaseGlutOpenGL
// C:\\Users\\Ryan\\Documents\\DolphinAttack

DrawObject* title = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Title.obj");
LPTSTR titleTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\titletexture.bmp";

CollisionObject* dolphin = new CollisionObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Dolphin.obj", 6);
LPTSTR dolphinSkin = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\dolphinskin.bmp";

DrawObject* arena = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Arena.obj");
LPTSTR arenaTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\arenatexture.bmp";

DrawObject* water = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Water.obj");
LPTSTR waterTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\watertexture.bmp";

DrawObject* sky = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Sky.obj");
LPTSTR skyTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\skytexture.bmp";

DrawObject* sun = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Sun.obj");
LPTSTR sunSmileTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\sunsmile.bmp";
LPTSTR sunGaspTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\sungasp.bmp";

CollisionObject* swimmer = new CollisionObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Swimmer.obj", 2);
LPTSTR swimmerTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\swimmertexture.bmp";

DrawObject* trees = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Trees.obj");
LPTSTR treesTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\treestexture.bmp";

GLuint textures[8];

GLuint titleTextID;
GLuint dolphinTextID;
GLuint arenaTextID;
GLuint waterTextID;
GLuint skyTextID;
GLuint sunSmileTextID;
GLuint sunGaspTextID;
GLuint sunTextID;
GLuint swimmerTextID;
GLuint treesTextID;

bool specialKeys[1000] = {0};
bool* keyStates = new bool[256];

float tranX;
float tranY;
float tranZ;
float rotY;
float rotX;
float rotZ;

bool InMainMenu;
bool victory;
bool gameover;
int score;
char scoreChar[2];
int timeLeft;
char time[2];

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
void IncrementScore();
void LaunchMenu();
void GameOver();
void NewSwimmerPosition();
bool IsCollision();

#ifdef WIN32
GLvoid PollJoyStick(GLvoid);
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha);
#endif 

void startBackgroundMusic(){
	System::Media::SoundPlayer^ backgroundmusic = gcnew System::Media::SoundPlayer();
	backgroundmusic->SoundLocation = "C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\audio\\musicLoop.wav";
	backgroundmusic->Load();
	backgroundmusic->PlayLooping();
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
			GameOver();
		}
		break;
	case 1:
		sunTextID = sunSmileTextID;
		break;
	case 2:
		LaunchMenu();
		break;
	}
}

int main(int argc, char* argv[]){
	for(int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 50);
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
	LaunchMenu();
	glutMainLoop();

	return 0;
}

void CleanUp(){
}

void LaunchMenu(){
	InMainMenu = true;
	victory = false;
	gameover = false;
	startBackgroundMusic();
	tranX = 0.0;
	tranY = 0.0;
	tranZ = 0.0;
	rotY = 0.0;
	rotX = -3.0;
	rotZ = 0.0;
}

void PlayGame(){
	dolphin->translation = Vector3f(0, -19, -40);
	dolphin->rotation = Vector3f(0, 180, 0);
	dolphin->rotateFirst = 1;
	dolphin->rotateSecond = 0;
	dolphin->rotateThird = 2;
	arena->translation = Vector3f(0, -188, -6.9);
	arena->scale = Vector3f(100, 100, 100);
	water->translation = Vector3f(0, -188, -6.9);
	water->scale = Vector3f(100, 100, 100);
	sky->translation = Vector3f(0, -188 , -6.9);
	sky->scale = Vector3f(120, 120, 120);
	sun->translation = Vector3f(0, -188, -6.9);
	sun->scale = Vector3f(120, 120, 120);
	sunTextID = sunSmileTextID;
	NewSwimmerPosition();
	swimmer->scale = Vector3f(40, 40, 40);
	swimmer->bobbingVelocity = 0;
	trees->translation = Vector3f(0, -220 , -6.9);
	trees->scale = Vector3f(120, 120, 120);

	InMainMenu = false;
	score = 0;
	itoa(score,scoreChar,10);
	timeLeft = 99;
	timer(0);
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
	NeHeLoadBitmap(arenaTexture, arenaTextID, false);
	NeHeLoadBitmap(waterTexture, waterTextID, true);
	NeHeLoadBitmap(skyTexture, skyTextID, false);
	NeHeLoadBitmap(sunGaspTexture, sunGaspTextID, true);
	NeHeLoadBitmap(sunSmileTexture, sunSmileTextID, true);
	NeHeLoadBitmap(swimmerTexture, swimmerTextID, false);
	NeHeLoadBitmap(treesTexture, treesTextID, true);
}

void moveDolphin(){
	float zMove = dolphin->velocity * cos(dolphin->rotation.y * (M_PI / 180));
	float xMove = dolphin->velocity * sin(dolphin->rotation.y * M_PI / 180);
	float dolphinDist = sqrtf(pow(dolphin->translation.z + zMove,2) + pow(dolphin->translation.x + xMove,2));
	if (dolphinDist < 770) {
		tranZ += dolphin->velocity * cos(rotY * (M_PI / 180));
		tranX -= dolphin->velocity * sin(rotY * M_PI / 180);
		dolphin->translation.z += zMove;
		dolphin->translation.x += xMove;
		sky->translation.z += zMove;
		sky->translation.x += xMove;
		sun->translation.z += zMove;
		sun->translation.x += xMove;
	}
	if(!specialKeys[GLUT_KEY_UP] && !specialKeys[GLUT_KEY_DOWN])
		dolphin->velocity *= .95;
	if(!specialKeys[GLUT_KEY_LEFT] && !specialKeys[GLUT_KEY_RIGHT])
		dolphin->rotation.z *= .9;
	dolphin->rotation.x = (dolphin->velocity * 0.5) + 3*(dolphin->translation.y+12) - 3*(dolphin->velocity-1)+23;
	rotX = (dolphin->velocity)*.7 - 3;
	if (dolphin->velocity < .2 && dolphin->velocity > -.2)
		dolphin->velocity = 0;
	if(!specialKeys[GLUT_KEY_UP]){
		if (dolphin->bobbingVelocity >= 0 && dolphin->translation.y <= -17.5)
			dolphin->translation.y += .01;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -17.5)
			dolphin->translation.y -= .07;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -18)
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
	moveDolphin();
	bobSwimmer();
	if(keyStates[KEYBOARD_SPACE]){
		// Jump
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

	if (IsCollision())
	{
		IncrementScore();
		NewSwimmerPosition();
		sunTextID = sunGaspTextID;
		glutTimerFunc(1000, timer, 1);
	}

	if (InMainMenu)
	{
		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX-10,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,tranY,tranZ);

		glPushMatrix();
		draw(title, titleTextID);
		glPopMatrix();

	} else { // In Game

		updateValues();
		glViewport(0, 0, windowWidth, windowHeight);

		glPushMatrix();
			glDisable(GL_TEXTURE_2D);
			glTranslatef(0, 14, -40);
			glRasterPos2f(0,0);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,scoreChar[0]);
			if(score > 9)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,scoreChar[1]);
			}
			glEnable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			glDisable(GL_TEXTURE_2D);
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

		glPushMatrix();
		draw(arena, arenaTextID);
		glPopMatrix();

		glPushMatrix();
		draw(water, waterTextID);
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
		PlayGame();
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
	if(!InMainMenu && !gameover && !victory){
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
			if (dolphin->bobbingVelocity >= 0 && dolphin->translation.y <= -15.5)
				dolphin->translation.y += .1;
			else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -18)
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

void Victory()
{
	victory = true;
	System::Media::SoundPlayer^ dolphinlaugh = gcnew System::Media::SoundPlayer();
	dolphinlaugh->SoundLocation = "C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\audio\\dolphinlaugh.wav";
	dolphinlaugh->Load();
	dolphinlaugh->Play();
	glutTimerFunc(3000, timer, 2);
	swimmer->translation = Vector3f(0, -1000, 0);
}

void GameOver()
{
	gameover = true;
	glutTimerFunc(3000, timer, 2);
	swimmer->translation = Vector3f(0, -1000, 0);
}

void IncrementScore()
{
	score++;
	itoa(score,scoreChar,10);
	if (score >= 14)
		Victory();
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
