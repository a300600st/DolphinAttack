#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif 

#define _USE_MATH_DEFINES
#include "DrawObject.h"
#include "CollisionObject.h"
#include <string>
#include <cmath>
#include <iostream>
#include <irrKlang.h>

#using <System.Drawing.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>

#define GLFW_DLL

using namespace std;
using namespace System;
using namespace irrklang;

#include <GLFW/glfw3.h>

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

DrawObject* title = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Title.obj");
LPTSTR titleTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\titletexture.bmp";
DrawObject* creditsScroll = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\CreditsScroll.obj");
LPTSTR creditsTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\creditsScreen.bmp";
LPTSTR creditsScrollTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\creditsScroll.bmp";

DrawObject* headsBox = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\HeadsBox.obj");
LPTSTR heads14 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads14.bmp";
LPTSTR heads13 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads13.bmp";
LPTSTR heads12 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads12.bmp";
LPTSTR heads11 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads11.bmp";
LPTSTR heads10 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads10.bmp";
LPTSTR heads9 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads9.bmp";
LPTSTR heads8 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads8.bmp";
LPTSTR heads7 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads7.bmp";
LPTSTR heads6 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads6.bmp";
LPTSTR heads5 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads5.bmp";
LPTSTR heads4 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads4.bmp";
LPTSTR heads3 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads3.bmp";
LPTSTR heads2 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads2.bmp";
LPTSTR heads1 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads1.bmp";
LPTSTR heads0 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\heads0.bmp";

DrawObject* numBox1 = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* colonBox = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* numBox2 = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\NumberBox.obj");
DrawObject* numBox3 = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\NumberBox.obj");
LPTSTR number0 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number0.bmp";
LPTSTR number1 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number1.bmp";
LPTSTR number2 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number2.bmp";
LPTSTR number3 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number3.bmp";
LPTSTR number4 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number4.bmp";
LPTSTR number5 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number5.bmp";
LPTSTR number6 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number6.bmp";
LPTSTR number7 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number7.bmp";
LPTSTR number8 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number8.bmp";
LPTSTR number9 = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\number9.bmp";
LPTSTR colon = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\colon.bmp";

CollisionObject* dolphin = new CollisionObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Dolphin.obj", 6);
LPTSTR dolphinSkin = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\dolphinskin.bmp";

DrawObject* arena = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Arena.obj");
LPTSTR arenaTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\arenatexture.bmp";

DrawObject* water = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Water.obj");
LPTSTR waterTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\watertexture.bmp";

DrawObject* sky = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Sky.obj");
LPTSTR skyTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\skytexture.bmp";

DrawObject* sun = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Sun.obj");
LPTSTR sunSmileTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\sunsmile.bmp";
LPTSTR sunGaspTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\sungasp.bmp";

CollisionObject* swimmer = new CollisionObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Swimmer.obj", 2);
LPTSTR swimmerTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\swimmertexture.bmp";

DrawObject* trees = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\Trees.obj");
LPTSTR treesTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\treestexture.bmp";

DrawObject* backTrees = new DrawObject("C:\\Users\\Ryan\\Documents\\DolphinAttack\\models\\BackTrees.obj");
LPTSTR backTreesTexture = L"C:\\Users\\Ryan\\Documents\\DolphinAttack\\textures\\backtreestexture.bmp";

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
GLuint backTreesTextID;

bool keyLeft;
bool keyRight;
bool keyUp;
bool keyDown;
bool keyEnter;
bool keyEscape;

float tranX;
float tranY;
float tranZ;
float rotY;
float rotX;
float rotZ;

bool InMainMenu;
bool Credits;
bool victory;
bool gameover;
int score;
int timeLeft;

ISoundEngine* engine;

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
void PlayGame();
void updateValues(double);
void bob(DrawObject* object, double timePassed, float bobbMid, float bobbSize, float bobbAngle, float bobbPeriod);

GLFWwindow* window;

#define NUM_TIMERS 3
double timerValues[NUM_TIMERS];
bool timerActive[NUM_TIMERS] = {false, false, false};

#ifdef WIN32
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha);
#endif 

void startBackgroundMusic(){
	// play some sound stream, looped
	engine->play2D("C:\\Users\\Ryan\\Documents\\DolphinAttack\\audio\\musicLoop.wav", true);
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

static void startTimer(double value, int timerNum)
{
	timerValues[timerNum] = value;
	timerActive[timerNum] = true;
}

static void tickTimer(double timeDiff)
{
	for (int i = 0; i < NUM_TIMERS; i++)
	{
		if (timerActive[i])
			timerValues[i] -= timeDiff;
	}

	if (timerValues[0] <= 0 && timerActive[0])
	{
		timerActive[0] = false;
		if(timeLeft > 0)
		{
			timeLeft--;
			updateTimeTextures();
			startTimer(1, 0);
		}
		else
		{
			GameOver();
		}
	}
	
	if (timerValues[1] <= 0 && timerActive[1])
	{
		timerActive[1] = false;
		sunTextID = sunSmileTextID;
	}

	if (timerValues[2] <= 0 && timerActive[2])
	{
		timerActive[2] = false;
		LaunchMenu();
	}
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if(key == GLFW_KEY_ESCAPE)
		{
			if (InMainMenu)
				glfwSetWindowShouldClose(window, GL_TRUE);
			else
				LaunchMenu();
		}

		if(key == GLFW_KEY_ENTER && InMainMenu)
		{
			PlayGame();
		}

		if (key == GLFW_KEY_LEFT)
		{
			keyLeft = true;
			cout << "left" << endl;
		}

		if (key == GLFW_KEY_RIGHT)
		{
			keyRight = true;
			cout << "right" << endl;
		}

		if (key == GLFW_KEY_UP)
		{
			keyUp = true;
			cout << "up" << endl;
		}

		if (key == GLFW_KEY_DOWN)
		{
			keyDown = true;
			cout << "down" << endl;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_LEFT)
		{
			keyLeft = false;
			cout << "no left" << endl;
		}

		if (key == GLFW_KEY_RIGHT)
		{
			keyRight = false;
			cout << "no right" << endl;
		}

		if (key == GLFW_KEY_UP)
		{
			keyUp = false;
			cout << "no up" << endl;
		}

		if (key == GLFW_KEY_DOWN)
		{
			keyDown = false;
			cout << "no down" << endl;
		}
	}
}

int main(int argc, char* argv[]){
	// start the sound engine with default parameters
	engine = createIrrKlangDevice();

	if (!engine)
	{
		std::cout << "Sound error!" << std::endl;
		return 0; // error starting up the engine
	}

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

	//window = glfwCreateWindow(windowWidth, windowHeight, "Happy Dolphin Attack", glfwGetPrimaryMonitor(), NULL);
	window = glfwCreateWindow(windowWidth, windowHeight, "Happy Dolphin Attack", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	InitGL();
	LaunchMenu();
	startBackgroundMusic();
	double lastTime = glfwGetTime();

	while (!glfwWindowShouldClose(window))
    {
		double currentTime = glfwGetTime();
		double timePassed = currentTime - lastTime;
		lastTime = currentTime;
		tickTimer(timePassed);
		updateValues(timePassed);
		DrawGLScene();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

	engine->drop();
	return 0;
}

void CleanUp(){
}

void LaunchMenu(){
	InMainMenu = true;
	victory = false;
	gameover = false;
	tranX = 0.0;
	tranY = 0.0;
	tranZ = 0.0;
	rotY = 0.0;
	rotX = -3.0;
	rotZ = 0.0;
}

void ShowCredits(){
	Credits = true;
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
	dolphin->bobbSize = .4;
	dolphin->bobbMid = -19.3;
	dolphin->bobbPeriod = 2.5;
	dolphin->bobbAngle = 2.5;
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
	swimmer->bobbSize = .3;
	swimmer->bobbMid = -13.4;
	swimmer->bobbPeriod = 2.5;
	swimmer->bobbAngle = 2.5;
	trees->translation = Vector3f(0, -220 , -6.9);
	trees->scale = Vector3f(120, 120, 120);
	backTrees->translation = Vector3f(0, -220 , -6.9);
	backTrees->scale = Vector3f(120, 120, 120);

	InMainMenu = false;
	Credits = false;
	score = 0;
	headsBoxTextID = heads14TextID;
	numBox1TextID = number2TextID;
	numBox2TextID = number0TextID;
	numBox3TextID = number0TextID;
	timeLeft = 120;
	startTimer(1, 0);
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
	NeHeLoadBitmap(backTreesTexture, backTreesTextID, true);
}

void moveDolphin(double timePassed){
	if(InMainMenu || gameover || victory)
		return;

	int maxDistance = 770;
	float backwardAcceleration = 6;
	float forwardAcceleration = 8;
	float angAcceleration = 5;
	float maxVel = 250;
	float minVel = -40;
	float maxAngVel = 75;
	float decceleration = .98;
	float angDecceleration = .9;
	float bankDecceleration = .93;
	float maxBank = 25;
	float bankSpeed = 70;
	float slowestTurnScale = .17;
	float maxBobVelocity = 45;

	if((keyLeft && !keyDown) || (keyRight && keyDown))
	{
		if (dolphin->angVelocity < maxAngVel)
			dolphin->angVelocity += angAcceleration;
	}

	if((keyRight && !keyDown) || (keyDown && keyLeft))
	{
		if (dolphin->angVelocity > maxAngVel * -1)
			dolphin->angVelocity -= angAcceleration;
	}

	if (keyLeft)
	{
		if (dolphin->rotation.z > maxBank * -1)
			dolphin->rotation.z -= bankSpeed * timePassed;
	}
	else if (keyRight)
	{
		if (dolphin->rotation.z < maxBank)
			dolphin->rotation.z += bankSpeed * timePassed;
	}
	else
	{
		dolphin->angVelocity *= angDecceleration;
		dolphin->rotation.z *= bankDecceleration;
	}

	if(keyUp)
	{
		if (dolphin->velocity <= maxVel)
			dolphin->velocity += forwardAcceleration;
	}
	else if (dolphin->velocity > 0)
	{
		dolphin->velocity *= decceleration;
	}

	if(keyDown)
	{
		if (dolphin->velocity >= minVel)
			dolphin->velocity -= backwardAcceleration;
	}
	else if (dolphin->velocity < 0)
	{
		dolphin->velocity *= decceleration;
	}

	float velocityScale = abs(dolphin->velocity / maxVel);
	
	float turnAmount = dolphin->angVelocity * timePassed * max(slowestTurnScale, velocityScale);
	rotY += -turnAmount;
	dolphin->rotation.y += turnAmount;

	float zMove = dolphin->velocity * cos(dolphin->rotation.y * M_PI / 180) * timePassed;
	float xMove = dolphin->velocity * sin(dolphin->rotation.y * M_PI / 180) * timePassed;
	float dolphinDist = sqrtf(pow(dolphin->translation.z + zMove,2) + pow(dolphin->translation.x + xMove,2));
	
	// keep in the arena
	if (dolphinDist < maxDistance) {
		tranZ += dolphin->velocity * cos(rotY * M_PI / 180) * timePassed;
		tranX -= dolphin->velocity * sin(rotY * M_PI / 180) * timePassed;
		dolphin->translation.z += zMove;
		dolphin->translation.x += xMove;
		sky->translation.z += zMove;
		sky->translation.x += xMove;
		sun->translation.z += zMove;
		sun->translation.x += xMove;
	}

	if (dolphin->velocity < maxBobVelocity)
	{
		//bobbing
		dolphin->bobbSize = .4;
		dolphin->bobbMid = -19.3;
		dolphin->bobbPeriod = 2.5;
		dolphin->bobbAngle = 2.5;
	}
	else
	{
		//jumping
		dolphin->bobbSize = 5;
		dolphin->bobbMid = -15;
		dolphin->bobbPeriod = 1.75;
		dolphin->bobbAngle = 20;
	}

	bob(dolphin, timePassed, dolphin->bobbMid, dolphin->bobbSize, dolphin->bobbAngle, dolphin->bobbPeriod);
}

void bob(DrawObject* object, double timePassed, float bobbMid, float bobbSize, float bobbAngle, float bobbPeriod)
{
	float translationThreshold = .01;
	float rotationThreshold = .001;
	float blendFactor = .03;

	if (bobbPeriod <= 0)
		return;

	object->bobbTime += timePassed;
	
	if (object->bobbTime > bobbPeriod)
		object->bobbTime -= bobbPeriod;

	float bobbProgress = object->bobbTime / bobbPeriod * 2 * M_PI;

	float newY = bobbMid + bobbSize * sin(bobbProgress);
	float newAngle = bobbAngle * cos(bobbProgress) * -1;

	if (newY > object->translation.y + translationThreshold || newY < object->translation.y - translationThreshold)
	{
		// blend with current position
		object->translation.y = object->translation.y + blendFactor * (newY - object->translation.y);
	}
	else
	{
		object->translation.y = newY;
	}

	if (newY > object->rotation.x + rotationThreshold || newY < object->rotation.x - rotationThreshold)
	{
		// blend with current angle
		object->rotation.x = object->rotation.x + blendFactor * (newAngle - object->rotation.x);
	}
	else
	{
		object->rotation.x = newAngle;
	}
}

void updateValues(double timePassed)
{
	if (Credits)
	{
		creditsScroll->translation.y += 1.5 * timePassed;
	}

	moveDolphin(timePassed);
	bob(swimmer, timePassed, swimmer->bobbMid, swimmer->bobbSize, swimmer->bobbAngle, swimmer->bobbPeriod);
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

void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;

	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;

	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

GLvoid DrawGLScene()
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	perspectiveGL(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 2500.0f);
		
	windowWidth = width;
	windowHeight = height;
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (IsCollision())
	{
		engine->play2D("C:\\Users\\Ryan\\Documents\\DolphinAttack\\audio\\dolphinlaugh.wav");
		IncrementScore();
		NewSwimmerPosition();
		sunTextID = sunGaspTextID;
		startTimer(1, 1);
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

	} else if (Credits)
	{
		glViewport(0, 0, windowWidth, windowHeight);
		glRotatef(rotX-10,1.0f,0.0f,0.0f);
		glRotatef(rotY,0.0f,1.0f,0.0f);
		glRotatef(rotZ,0.0f,0.0f,1.0f);
		glTranslatef(tranX,tranY,tranZ);

		glPushMatrix();
		draw(title, creditsTextID);
		glPopMatrix();

		glPushMatrix();
		draw(creditsScroll, creditsScrollTextID);
		glPopMatrix();
	}
	else
	{ // In Game
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
			draw(backTrees, backTreesTextID);
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
	glfwSwapBuffers(window);
    glfwPollEvents();
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
	swimmer->translation = Vector3f(distance * cos(angle), -12.65, distance * sin(angle));
	swimmer->rotation.y = faceAngle;
}

void Victory()
{
	victory = true;
	ShowCredits();
	startTimer(15, 2);
	swimmer->translation = Vector3f(0, -1000, 0);
}

void GameOver()
{
	gameover = true;
	startTimer(3, 2);
	swimmer->translation = Vector3f(0, -1000, 0);
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

#endif 
