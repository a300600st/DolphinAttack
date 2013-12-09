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
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_SPACE 32

int windowWidth = DEFAULT_WINDOW_WIDTH;
int windowHeight = DEFAULT_WINDOW_HEIGHT;
char* windowName = "My Glut Window";
int texID = 0;

// C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack
// C:\\Users\\Todd\\Desktop\\Fall 2013\\groupDolphin attack\\BaseGlutOpenGL
// C:\\Users\\Ryan\\Documents\\DolphinAttack

DrawObject* title = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\Title.obj");
LPTSTR titleTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\titletexture.bmp";
DrawObject* creditsScroll = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\CreditsScroll.obj");
LPTSTR creditsTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\creditsScreen.bmp";
LPTSTR creditsScrollTexture = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\creditsScroll.bmp";

DrawObject* headsBox = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\HeadsBox.obj");
LPTSTR heads14 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads14.bmp";
LPTSTR heads13 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads13.bmp";
LPTSTR heads12 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads12.bmp";
LPTSTR heads11 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads11.bmp";
LPTSTR heads10 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads10.bmp";
LPTSTR heads9 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads9.bmp";
LPTSTR heads8 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads8.bmp";
LPTSTR heads7 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads7.bmp";
LPTSTR heads6 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads6.bmp";
LPTSTR heads5 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads5.bmp";
LPTSTR heads4 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads4.bmp";
LPTSTR heads3 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads3.bmp";
LPTSTR heads2 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads2.bmp";
LPTSTR heads1 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads1.bmp";
LPTSTR heads0 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\heads0.bmp";

DrawObject* numBox1 = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* colonBox = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* numBox2 = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* numBox3 = new DrawObject("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\models\\NumberBox.obj");
LPTSTR number0 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number0.bmp";
LPTSTR number1 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number1.bmp";
LPTSTR number2 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number2.bmp";
LPTSTR number3 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number3.bmp";
LPTSTR number4 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number4.bmp";
LPTSTR number5 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number5.bmp";
LPTSTR number6 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number6.bmp";
LPTSTR number7 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number7.bmp";
LPTSTR number8 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number8.bmp";
LPTSTR number9 = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\number9.bmp";
LPTSTR colon = L"C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\textures\\colon.bmp";

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

GLuint titleTextID;
GLuint creditsTextID;
GLuint creditsScrollTextID;
GLuint headsBoxTextID;
GLuint heads14TextID;
GLuint heads13TextID;
GLuint heads12TextID;
GLuint heads11TextID;
GLuint heads10TextID;
GLuint heads9TextID;
GLuint heads8TextID;
GLuint heads7TextID;
GLuint heads6TextID;
GLuint heads5TextID;
GLuint heads4TextID;
GLuint heads3TextID;
GLuint heads2TextID;
GLuint heads1TextID;
GLuint heads0TextID;
GLuint numBox1TextID;
GLuint colonTextID;
GLuint numBox2TextID;
GLuint numBox3TextID;
GLuint number0TextID;
GLuint number1TextID;
GLuint number2TextID;
GLuint number3TextID;
GLuint number4TextID;
GLuint number5TextID;
GLuint number6TextID;
GLuint number7TextID;
GLuint number8TextID;
GLuint number9TextID;
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
bool InCredits;
bool InVictoryScene;
bool InGameOverScene;
int score;
int timeLeft;

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
void IncrementScore();
void LaunchMenu();
void GameOver();
void NewSwimmerPosition();
void updateValues();
void ShowCredits();
bool IsCollision();

#ifdef WIN32
GLvoid PollJoyStick(GLvoid);
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha);
#endif 

void startBackgroundMusic(){
	// play some sound stream, looped
	engine->play2D("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\audio\\musicLoop.wav", true);
}

void updateTimeTextures(){
	if (timeLeft >= 120)
		numBox1TextID = number2TextID;
	else if (timeLeft < 120 && timeLeft >= 60)
		numBox1TextID = number1TextID;
	else
		numBox1TextID = number0TextID;
	
	if ((timeLeft >= 110 && timeLeft < 120) ||
			(timeLeft >= 50 && timeLeft < 60))
		numBox2TextID = number5TextID;
	else if ((timeLeft >= 100 && timeLeft < 110) ||
			(timeLeft >= 40 && timeLeft < 50))
		numBox2TextID = number4TextID;
	else if ((timeLeft >= 90 && timeLeft < 100) ||
			(timeLeft >= 30 && timeLeft < 40))
		numBox2TextID = number3TextID;
	else if ((timeLeft >= 80 && timeLeft < 90) ||
			(timeLeft >= 20 && timeLeft < 30))
		numBox2TextID = number2TextID;
	else if ((timeLeft >= 70 && timeLeft < 80) ||
			(timeLeft >= 10 && timeLeft < 20))
		numBox2TextID = number1TextID;
	else
		numBox2TextID = number0TextID;

	if (timeLeft % 10 == 9)
		numBox3TextID = number9TextID;
	else if (timeLeft % 10 == 8)
		numBox3TextID = number8TextID;
	else if (timeLeft % 10 == 7)
		numBox3TextID = number7TextID;
	else if (timeLeft % 10 == 6)
		numBox3TextID = number6TextID;
	else if (timeLeft % 10 == 5)
		numBox3TextID = number5TextID;
	else if (timeLeft % 10 == 4)
		numBox3TextID = number4TextID;
	else if (timeLeft % 10 == 3)
		numBox3TextID = number3TextID;
	else if (timeLeft % 10 == 2)
		numBox3TextID = number2TextID;
	else if (timeLeft % 10 == 1)
		numBox3TextID = number1TextID;
	else
		numBox3TextID = number0TextID;
}


static void timer(int value)
{
	switch (value)
	{
	//Game Timer
	case 0:
		if (!InMainMenu && !InVictoryScene && !InGameOverScene && !InCredits)
		{
			if(timeLeft > 0)
			{
				timeLeft--;
				updateTimeTextures();
				glutPostRedisplay();
				glutTimerFunc(1000, timer, 0);
			}
			else
			{
				GameOver();
			}
		}
		break;
	case 1:
		sunTextID = sunSmileTextID;
		break;
	case 2:
		LaunchMenu();
		break;
	case 3:
		if (!InMainMenu && !InCredits)
		{
			updateValues();
			glutTimerFunc(25, timer, 3);
		}
		break;
	case 4:
		ShowCredits();
		glutTimerFunc(25000, timer, 2);
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

	startBackgroundMusic();

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

	engine->drop();
	return 0;
}

void CleanUp(){
}

void LaunchMenu(){
	InMainMenu = true;
	InVictoryScene = false;
	InGameOverScene = false;
	InCredits = false;
	tranX = 0.0;
	tranY = 0.0;
	tranZ = 0.0;
	rotY = 0.0;
	rotX = -3.0;
	rotZ = 0.0;
}

void ShowCredits(){
	InCredits = true;
	tranX = 0.0;
	tranY = 0.0;
	tranZ = 0.0;
	rotY = 0.0;
	rotX = -3.0;
	rotZ = 0.0;
	creditsScroll->translation = Vector3f(-.05, 3.89, -14);
}

void PlayGame(){
	dolphin->translation = Vector3f(0, -19, -40);
	dolphin->rotation = Vector3f(0, 180, 0);
	dolphin->rotateFirst = 1;
	dolphin->rotateSecond = 0;
	dolphin->rotateThird = 2;
	dolphin->velocity = 0;
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
	swimmer->rotation.x = 0;
	swimmer->bobbingVelocity = 0;
	trees->translation = Vector3f(0, -220 , -6.9);
	trees->scale = Vector3f(120, 120, 120);

	InMainMenu = false;
	score = 0;
	headsBoxTextID = heads14TextID;
	numBox1TextID = number2TextID;
	numBox2TextID = number0TextID;
	numBox3TextID = number0TextID;
	timeLeft = 120;
	timer(0);
	timer(3);
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
	NeHeLoadBitmap(creditsTexture, creditsTextID, false);
	NeHeLoadBitmap(creditsScrollTexture, creditsScrollTextID, true);

	title->translation = Vector3f(-.05, 3.89, -16.9);
	title->scale = Vector3f(1.6, 1.55, 1.5);
	title->rotation = Vector3f(103.5, 180, 0);

	creditsScroll->translation = Vector3f(-.05, 3.89, -14);
	creditsScroll->scale = Vector3f(.6, .6, .6);
	creditsScroll->rotation = Vector3f(90, 180, 0);

	NeHeLoadBitmap(heads14, heads14TextID, true);
	NeHeLoadBitmap(heads13, heads13TextID, true);
	NeHeLoadBitmap(heads12, heads12TextID, true);
	NeHeLoadBitmap(heads11, heads11TextID, true);
	NeHeLoadBitmap(heads10, heads10TextID, true);
	NeHeLoadBitmap(heads9, heads9TextID, true);
	NeHeLoadBitmap(heads8, heads8TextID, true);
	NeHeLoadBitmap(heads7, heads7TextID, true);
	NeHeLoadBitmap(heads6, heads6TextID, true);
	NeHeLoadBitmap(heads5, heads5TextID, true);
	NeHeLoadBitmap(heads4, heads4TextID, true);
	NeHeLoadBitmap(heads3, heads3TextID, true);
	NeHeLoadBitmap(heads2, heads2TextID, true);
	NeHeLoadBitmap(heads1, heads1TextID, true);
	NeHeLoadBitmap(heads0, heads0TextID, true);
	headsBox->translation = Vector3f(-5.1, 3.35, -10);
	headsBox->scale = Vector3f(0.23, 0.23, 0.23);
	headsBox->rotation = Vector3f(90, 0, 0);

	NeHeLoadBitmap(number0, number0TextID, true);
	NeHeLoadBitmap(number1, number1TextID, true);
	NeHeLoadBitmap(number2, number2TextID, true);
	NeHeLoadBitmap(number3, number3TextID, true);
	NeHeLoadBitmap(number4, number4TextID, true);
	NeHeLoadBitmap(number5, number5TextID, true);
	NeHeLoadBitmap(number6, number6TextID, true);
	NeHeLoadBitmap(number7, number7TextID, true);
	NeHeLoadBitmap(number8, number8TextID, true);
	NeHeLoadBitmap(number9, number9TextID, true);
	numBox1->translation = Vector3f(5, 3.3, -10);
	numBox1->scale = Vector3f(0.12, 0.12, 0.12);
	numBox1->rotation = Vector3f(90, 0, 0);
	colonBox->translation = Vector3f(5.5, 3.3, -10);
	colonBox->scale = Vector3f(0.12, 0.12, 0.12);
	colonBox->rotation = Vector3f(90, 0, 0);
	numBox2->translation = Vector3f(6, 3.3, -10);
	numBox2->scale = Vector3f(0.12, 0.12, 0.12);
	numBox2->rotation = Vector3f(90, 0, 0);
	numBox3->translation = Vector3f(6.6, 3.3, -10);
	numBox3->scale = Vector3f(0.12, 0.12, 0.12);
	numBox3->rotation = Vector3f(90, 0, 0);

	//avoid swimmer being created on dolphin
	swimmer->translation.x = -1000;

	NeHeLoadBitmap(dolphinSkin, dolphinTextID, false);
	NeHeLoadBitmap(colon, colonTextID, true);
	NeHeLoadBitmap(arenaTexture, arenaTextID, false);
	NeHeLoadBitmap(waterTexture, waterTextID, true);
	NeHeLoadBitmap(skyTexture, skyTextID, false);
	NeHeLoadBitmap(sunGaspTexture, sunGaspTextID, true);
	NeHeLoadBitmap(sunSmileTexture, sunSmileTextID, true);
	NeHeLoadBitmap(swimmerTexture, swimmerTextID, false);
	NeHeLoadBitmap(treesTexture, treesTextID, true);
}

void moveDolphin(){
	float zMove = dolphin->velocity * cos(dolphin->rotation.y * (M_PI / 180)) * 2;
	float xMove = dolphin->velocity * sin(dolphin->rotation.y * M_PI / 180) * 2;
	float dolphinDist = sqrtf(pow(dolphin->translation.z + zMove,2) + pow(dolphin->translation.x + xMove,2));
	if (dolphinDist < 770) {
		tranZ += dolphin->velocity * cos(rotY * (M_PI / 180)) * 2;
		tranX -= dolphin->velocity * sin(rotY * M_PI / 180) * 2;
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
	dolphin->rotation.x = (dolphin->velocity * 1.5) + 3*(dolphin->translation.y+12) - 3*(dolphin->velocity-1)+23;
	rotX = (dolphin->velocity) - 3;
	if (dolphin->velocity < .15 && dolphin->velocity > -.15)
		dolphin->velocity = 0;
	if(!specialKeys[GLUT_KEY_UP]){
		if (dolphin->bobbingVelocity >= 0 && dolphin->translation.y <= -17.5)
			dolphin->translation.y += .02;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -17.5)
			dolphin->translation.y -= .1;
		else if (dolphin->bobbingVelocity < 0 && dolphin->translation.y >= -18)
			dolphin->translation.y -= .02;
		else
			dolphin->bobbingVelocity *= -1;
	}
}

void bobSwimmer()
{
	if (swimmer->translation.y > -12.75)
	{
		swimmer->bobbingVelocity -= .003;
		swimmer->rotation.x += .1;
	}
	else
	{
		swimmer->bobbingVelocity += .003;
		swimmer->rotation.x -= .1;
	}

	swimmer->translation.y += swimmer->bobbingVelocity;
}

void updateValues()
{
	moveDolphin();
	bobSwimmer();
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
		engine->play2D("C:\\Users\\Ben Romney\\Documents\\GitHub\\DolphinAttack\\audio\\dolphinlaugh.wav");
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

	} else if (InCredits)
	{
		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX-10,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,tranY,tranZ);

		creditsScroll->translation.y += .003;

		glPushMatrix();
		draw(title, creditsTextID);
		glPopMatrix();

		glPushMatrix();
		draw(creditsScroll, creditsScrollTextID);
		glPopMatrix();

	}
	else
	{ // In Game

		//updateValues();
		glViewport(0, 0, windowWidth, windowHeight);

		glPushMatrix();

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

		glPopMatrix();

		glPushMatrix();
		draw(headsBox, headsBoxTextID);
		glPopMatrix();

		glPushMatrix();
		draw(numBox1, numBox1TextID);
		glPopMatrix();

		glPushMatrix();
		draw(colonBox, colonTextID);
		glPopMatrix();

		glPushMatrix();
		draw(numBox2, numBox2TextID);
		glPopMatrix();

		glPushMatrix();
		draw(numBox3, numBox3TextID);
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
		if (InMainMenu)
			exit(0);
		else
			LaunchMenu();
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
			break;
		case GLUT_KEY_DOWN:
			specialKeys[GLUT_KEY_DOWN] = 1;
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
	if(!InMainMenu && !InGameOverScene && !InVictoryScene){
		if(specialKeys[GLUT_KEY_LEFT]){
			float turnAmount = dolphin->velocity/2.8+.5;
			rotY += -turnAmount;
			dolphin->rotation.y += turnAmount;
			if (dolphin->rotation.z >= -10)
				dolphin->rotation.z -= 1;
		}
		if(specialKeys[GLUT_KEY_RIGHT]){
			float turnAmount = dolphin->velocity/2.8+.5;
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
	InVictoryScene = true;
	glutTimerFunc(3000, timer, 4);
}

void GameOver()
{
	InGameOverScene = true;
	glutTimerFunc(3000, timer, 2);
}

void updateSwimmerHeads(){
	if (score == 0)
		headsBoxTextID = heads14TextID;
	else if (score == 1)
		headsBoxTextID = heads13TextID;
	else if (score == 2)
		headsBoxTextID = heads12TextID;
	else if (score == 3)
		headsBoxTextID = heads11TextID;
	else if (score == 4)
		headsBoxTextID = heads10TextID;
	else if (score == 5)
		headsBoxTextID = heads9TextID;
	else if (score == 6)
		headsBoxTextID = heads8TextID;
	else if (score == 7)
		headsBoxTextID = heads7TextID;
	else if (score == 8)
		headsBoxTextID = heads6TextID;
	else if (score == 9)
		headsBoxTextID = heads5TextID;
	else if (score == 10)
		headsBoxTextID = heads4TextID;
	else if (score == 11)
		headsBoxTextID = heads3TextID;
	else if (score == 12)
		headsBoxTextID = heads2TextID;
	else if (score == 13)
		headsBoxTextID = heads1TextID;
	else
		headsBoxTextID = heads0TextID;
}

void IncrementScore()
{
	score++;
	updateSwimmerHeads();
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
