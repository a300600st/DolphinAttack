#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif 

#define _USE_MATH_DEFINES
#define GLFW_DLL
#include "DrawObject.h"
#include "CollisionObject.h"
#include "Animation.h"
#include <string>
#include <cmath>
#include <iostream>
#include <irrKlang.h>
#include <GLFW/glfw3.h>
#include <time.h>

#using <System.Drawing.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace std;
using namespace System;
using namespace irrklang;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // no console

#define DEFAULT_WINDOW_WIDTH 1366
#define DEFAULT_WINDOW_HEIGHT 768
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_SPACE 32

int windowWidth = DEFAULT_WINDOW_WIDTH;
int windowHeight = DEFAULT_WINDOW_HEIGHT;
char* windowName = "My Glut Window";
int texID = 0;

DrawObject* title = new DrawObject("models\\Title.obj");
LPTSTR titleTexture = L"textures\\titletexture.bmp";
DrawObject* creditsScroll = new DrawObject("models\\CreditsScroll.obj");
LPTSTR creditsTexture = L"textures\\creditsScreen.bmp";
LPTSTR creditsScrollTexture = L"textures\\creditsScroll.bmp";

DrawObject* victory = new DrawObject("models\\failureOBJ.obj");
LPTSTR victoryTexture = L"textures\\victorytexture.bmp";
DrawObject* gameover = new DrawObject("models\\failureOBJ.obj");
LPTSTR gameoverTexture = L"textures\\gameovertexture.bmp";

DrawObject* headsBox = new DrawObject("models\\HeadsBox.obj");
LPTSTR heads14 = L"textures\\heads14.bmp";
LPTSTR heads13 = L"textures\\heads13.bmp";
LPTSTR heads12 = L"textures\\heads12.bmp";
LPTSTR heads11 = L"textures\\heads11.bmp";
LPTSTR heads10 = L"textures\\heads10.bmp";
LPTSTR heads9 = L"textures\\heads9.bmp";
LPTSTR heads8 = L"textures\\heads8.bmp";
LPTSTR heads7 = L"textures\\heads7.bmp";
LPTSTR heads6 = L"textures\\heads6.bmp";
LPTSTR heads5 = L"textures\\heads5.bmp";
LPTSTR heads4 = L"textures\\heads4.bmp";
LPTSTR heads3 = L"textures\\heads3.bmp";
LPTSTR heads2 = L"textures\\heads2.bmp";
LPTSTR heads1 = L"textures\\heads1.bmp";
LPTSTR heads0 = L"textures\\heads0.bmp";

DrawObject* splash = new DrawObject("models\\Splash.obj");
LPTSTR splashFrame0 = L"textures\\splash0.bmp";
LPTSTR splashFrame1 = L"textures\\splash1.bmp";
LPTSTR splashFrame2 = L"textures\\splash2.bmp";

DrawObject* numBox1 = new DrawObject("models\\NumberBox.obj");
DrawObject* colonBox = new DrawObject("models\\NumberBox.obj");
DrawObject* numBox2 = new DrawObject("models\\NumberBox.obj");
DrawObject* numBox3 = new DrawObject("models\\NumberBox.obj");
LPTSTR number0 = L"textures\\number0.bmp";
LPTSTR number1 = L"textures\\number1.bmp";
LPTSTR number2 = L"textures\\number2.bmp";
LPTSTR number3 = L"textures\\number3.bmp";
LPTSTR number4 = L"textures\\number4.bmp";
LPTSTR number5 = L"textures\\number5.bmp";
LPTSTR number6 = L"textures\\number6.bmp";
LPTSTR number7 = L"textures\\number7.bmp";
LPTSTR number8 = L"textures\\number8.bmp";
LPTSTR number9 = L"textures\\number9.bmp";
LPTSTR colon = L"textures\\colon.bmp";

CollisionObject* dolphin = new CollisionObject("models\\Dolphin.obj", 6);
LPTSTR dolphinSkin = L"textures\\dolphinskin.bmp";

DrawObject* arena = new DrawObject("models\\Arena.obj");
LPTSTR arenaTexture = L"textures\\arenatexture.bmp";

DrawObject* water = new DrawObject("models\\Water.obj");
LPTSTR waterTexture = L"textures\\watertexture.bmp";

DrawObject* sky = new DrawObject("models\\Sky.obj");
LPTSTR skyTexture = L"textures\\skytexture.bmp";

DrawObject* sun = new DrawObject("models\\Sun.obj");
LPTSTR sunSmileTexture = L"textures\\sunsmile.bmp";
LPTSTR sunGaspTexture = L"textures\\sungasp.bmp";

CollisionObject* swimmer = new CollisionObject("models\\Swimmer.obj", 2);
LPTSTR swimmerTexture = L"textures\\swimmertexture.bmp";

CollisionObject* monster = new CollisionObject("models\\monster.obj",2);
LPTSTR monsterTexture = L"textures\\beachball.bmp";

DrawObject* trees = new DrawObject("models\\Trees.obj");
LPTSTR treesTexture = L"textures\\treestexture.bmp";

DrawObject* backTrees = new DrawObject("models\\BackTrees.obj");
LPTSTR backTreesTexture = L"textures\\backtreestexture.bmp";

LPTSTR seagullTexture = L"textures\\seagulltexture.bmp";

DrawObject* seagullA = new DrawObject("models\\Seagull.obj");
DrawObject* seagullARWing = new DrawObject("models\\RWing.obj");
DrawObject* seagullALWing = new DrawObject("models\\LWing.obj");

DrawObject* seagullB = new DrawObject("models\\Seagull.obj");
DrawObject* seagullBRWing = new DrawObject("models\\RWing.obj");
DrawObject* seagullBLWing = new DrawObject("models\\LWing.obj");

Animation* splashAnimation;

GLuint titleTextID;
GLuint creditsTextID;
GLuint creditsScrollTextID;
GLuint victoryTextureID;
GLuint gameoverTextureID;
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
GLuint monsterTextID;
GLuint seagullTextID;
GLuint splashTextID;
GLuint splashFrames[3];

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
float monsterDir;

bool InMainMenu;
bool InCredits;
bool InVictoryScene;
bool InGameOverScene;
int score;
int timeLeft;

ISoundEngine* engine;
#define NUM_SPLASH_SOUNDS 4
ISoundSource* splashSounds[NUM_SPLASH_SOUNDS];
bool splashSoundPlaying;

#define SEAGULL_A_HEIGHT 15
#define SEAGULL_B_HEIGHT 25

bool seagullAFlapping;
float seagullAAngle;
float seagullBAngle;
bool seagullBFlapping;

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
void ShowCredits();
bool IsCollision();
void PlayGame();
void updateValues(double);
void bob(DrawObject* object, double timePassed, float bobbMid, float bobbSize, float bobbAngle, float bobbPeriod);
void startTimer(double, int);
bool hitMonster();

GLFWwindow* window;

//timer constants
#define NUM_TIMERS 7

#define TIMER_TICK 0
#define SUN_GASP 1
#define LAUNCH_MENU 2
#define SHOW_CREDITS 3
#define SEAGULL_A 4
#define SEAGULL_B 5
#define SPLASH_PLAYING 6

double timerValues[NUM_TIMERS];
bool timerActive[NUM_TIMERS] = {false, false, false, false, false, false, false};

#ifdef WIN32
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid, bool alpha);
#endif 

void startBackgroundMusic(){
	// play some sound stream, looped
	engine->play2D("audio\\musicLoop.wav", true);
}

void playSplashSound()
{
	ISoundSource* splash = splashSounds[rand() % NUM_SPLASH_SOUNDS];
	engine->play2D(splash);
	startTimer(1, SPLASH_PLAYING);
	splashSoundPlaying = true;
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

	if (timerValues[TIMER_TICK] <= 0 && timerActive[TIMER_TICK])
	{
		timerActive[TIMER_TICK] = false;
		if (!InMainMenu && !InVictoryScene && !InGameOverScene && !InCredits)
		{
			timeLeft--;
			updateTimeTextures();
			
			if(timeLeft > 0)
			{
				startTimer(1, TIMER_TICK);
			}
			else
			{
				GameOver();
			}
		}
	}
	
	if (timerValues[SUN_GASP] <= 0 && timerActive[SUN_GASP])
	{
		timerActive[SUN_GASP] = false;
		sunTextID = sunSmileTextID;
	}

	if (timerValues[LAUNCH_MENU] <= 0 && timerActive[LAUNCH_MENU])
	{
		timerActive[LAUNCH_MENU] = false;
		if (InCredits || InGameOverScene || InVictoryScene)
			LaunchMenu();
	}

	if (timerValues[SHOW_CREDITS] <= 0 && timerActive[SHOW_CREDITS])
	{
		timerActive[SHOW_CREDITS] = false;
		if (InVictoryScene)
		{
			ShowCredits();
			startTimer(14, LAUNCH_MENU);
		}
	}

	if (timerValues[SEAGULL_A] <= 0 && timerActive[SEAGULL_A])
	{
		timerActive[SEAGULL_A] = false;
		seagullAFlapping = !seagullAFlapping;
		startTimer(2 + 7*((float)rand() / RAND_MAX), SEAGULL_B);
	}

	if (timerValues[SEAGULL_B] <= 0 && timerActive[SEAGULL_B])
	{
		timerActive[SEAGULL_B] = false;
		seagullBFlapping = !seagullBFlapping;
		startTimer(2 + 7*((float)rand() / RAND_MAX), SEAGULL_A);
	}

	if (timerValues[SPLASH_PLAYING] <= 0 && timerActive[SPLASH_PLAYING])
	{
		timerActive[SPLASH_PLAYING] = false;
		splashSoundPlaying = false;
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
		}

		if (key == GLFW_KEY_RIGHT)
		{
			keyRight = true;
		}

		if (key == GLFW_KEY_UP)
		{
			keyUp = true;
		}

		if (key == GLFW_KEY_DOWN)
		{
			keyDown = true;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_LEFT)
		{
			keyLeft = false;
		}

		if (key == GLFW_KEY_RIGHT)
		{
			keyRight = false;
		}

		if (key == GLFW_KEY_UP)
		{
			keyUp = false;
		}

		if (key == GLFW_KEY_DOWN)
		{
			keyDown = false;
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

	splashSounds[0] = engine->addSoundSourceFromFile("audio\\splash1.wav", ESM_AUTO_DETECT, true);
	splashSounds[1] = engine->addSoundSourceFromFile("audio\\splash2.wav", ESM_AUTO_DETECT, true);
	splashSounds[2] = engine->addSoundSourceFromFile("audio\\splash3.wav", ESM_AUTO_DETECT, true);
	splashSounds[3] = engine->addSoundSourceFromFile("audio\\splash4.wav", ESM_AUTO_DETECT, true);

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

	glfwSwapInterval(1);

	window = glfwCreateWindow(windowWidth, windowHeight, "Happy Dolphin Attack", glfwGetPrimaryMonitor(), NULL);
	glfwSetWindowPos(window, 50, 50);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	srand (time(NULL));

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
	dolphin->translation = Vector3f(0, -16, -40);
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
	swimmer->rotation.x = 0;
	swimmer->bobbSize = .3;
	swimmer->bobbMid = -11.6;
	swimmer->bobbPeriod = 2.5;
	swimmer->bobbAngle = 2.5;

	seagullAAngle = 0;
	seagullA->rotation.y = 0;
	seagullA->scale = Vector3f(40, 40, 40);
	seagullA->bobbPeriod = .7;
	seagullA->rotation.z = 20;
	seagullAFlapping = true;

	seagullBAngle = 0;
	seagullB->rotation.y = 180;
	seagullB->scale = Vector3f(40, 40, 40);
	seagullB->bobbPeriod = .7;
	seagullB->rotation.z = -20;
	seagullBFlapping = false;

	trees->translation = Vector3f(0, -220 , -6.9);
	trees->scale = Vector3f(120, 120, 120);
	backTrees->translation = Vector3f(0, -220 , -6.9);
	backTrees->scale = Vector3f(120, 120, 120);
	splash->translation = Vector3f(0, -11, -40);
	splashSoundPlaying = false;

	monster->translation = Vector3f(0,4.5,880);
	monster->rotation = Vector3f(0,180,0);

	InMainMenu = false;
	score = 0;
	headsBoxTextID = heads14TextID;
	numBox1TextID = number2TextID;
	numBox2TextID = number0TextID;
	numBox3TextID = number0TextID;
	timeLeft = 120;
	startTimer(1, TIMER_TICK);
	startTimer(3.5, SEAGULL_A);
	startTimer(5, SEAGULL_B);
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
	NeHeLoadBitmap(creditsScrollTexture, creditsScrollTextID, false);
	NeHeLoadBitmap(victoryTexture,victoryTextureID,true);
	NeHeLoadBitmap(gameoverTexture,gameoverTextureID,true);

	title->translation = Vector3f(-.05, 3.89, -16.9);
	title->scale = Vector3f(1.6, 1.55, 1.5);
	title->rotation = Vector3f(103.5, 180, 0);

	creditsScroll->translation = Vector3f(-.05, 3.89, -14);
	creditsScroll->scale = Vector3f(.6, .6, .6);
	creditsScroll->rotation = Vector3f(90, 180, 0);

	victory->translation = Vector3f(-10, .1, -14);
	victory->scale = Vector3f(.6, .6, .6);
	victory->rotation = Vector3f(90, 270, 0);

	gameover->translation = Vector3f(-10, .1, -14);
	gameover->scale = Vector3f(.6, .6, .6);
	gameover->rotation = Vector3f(90, 270, 0);

	seagullA->translation = Vector3f(0, SEAGULL_A_HEIGHT, 0);
	seagullB->translation = Vector3f(0, SEAGULL_B_HEIGHT, 0);

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
	NeHeLoadBitmap(monsterTexture,monsterTextID,false);
	NeHeLoadBitmap(seagullTexture,seagullTextID,false);

	NeHeLoadBitmap(splashFrame0,splashFrames[0],true);
	NeHeLoadBitmap(splashFrame1,splashFrames[1],true);
	NeHeLoadBitmap(splashFrame2,splashFrames[2],true);

	splashAnimation = new Animation(12, 3, splashFrames);
	splashAnimation->stop();
}

void moveDolphin(double timePassed){
	if(InMainMenu || InCredits)
		return;
	int maxDistance = 770;
	float backwardAcceleration = 200 * timePassed;
	float forwardAcceleration = 550 * timePassed;
	float angAcceleration = 280* timePassed;
	float maxVel = 250;
	float minVel = -40;
	float maxAngVel = 80;
	float decceleration = 130 * timePassed;
	float angDecceleration = 280 * timePassed;
	float bankDecceleration = 80 * timePassed;
	float maxBank = 25;
	float bankSpeed = 70 * timePassed;
	float slowestTurnScale = .50;
	float maxBobVelocity = 200;

	if (InGameOverScene || InVictoryScene)
	{
		keyLeft = false;
		keyRight = false;
		keyUp = false;
		keyDown = false;
	}

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
			dolphin->rotation.z -= bankSpeed;
	}
	else if (keyRight)
	{
		if (dolphin->rotation.z < maxBank)
			dolphin->rotation.z += bankSpeed;
	}
	else
	{
		if (dolphin->angVelocity > .01)
			dolphin->angVelocity -= min(angDecceleration, dolphin->angVelocity);
		else if (dolphin->angVelocity < -.01)
			dolphin->angVelocity += max(angDecceleration, dolphin->angVelocity);
		else
			dolphin->angVelocity = 0;

		if (dolphin->rotation.z > .01)
			dolphin->rotation.z -= min(bankDecceleration, dolphin->rotation.z);
		else if (dolphin->rotation.z < -.01)
			dolphin->rotation.z += max(bankDecceleration, dolphin->rotation.z);
		else
			dolphin->rotation.z = 0;
	}

	if(keyUp)
	{
		if (dolphin->velocity <= maxVel)
			dolphin->velocity += forwardAcceleration;
	}
	else if (dolphin->velocity > 0)
	{
		dolphin->velocity -= min(decceleration, dolphin->velocity);
	}

	if(keyDown)
	{
		if (dolphin->velocity >= minVel)
			dolphin->velocity -= backwardAcceleration;
	}
	else if (dolphin->velocity < 0)
	{
		dolphin->velocity += max(decceleration, dolphin->velocity);
	}

	float velocityScale = abs(dolphin->velocity / maxVel);
	
	float turnAmount = dolphin->angVelocity * timePassed * max(slowestTurnScale, velocityScale);
	rotY += -turnAmount;
	dolphin->rotation.y += turnAmount;
	//splash->rotation.y += turnAmount;

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
		//splash->translation.z += zMove;
		//splash->translation.x += xMove;
	}

	//bobbing
	dolphin->bobbSize = .4;
	dolphin->bobbMid = -16.3;
	dolphin->bobbPeriod = 2.5;
	dolphin->bobbAngle = 2.5;

	if (dolphin->velocity >= 0)
	{
		//jumping (don't jump backwards)
		dolphin->bobbSize += 5 * velocityScale;
		dolphin->bobbMid += 2 * velocityScale;
		dolphin->bobbPeriod += -1.25 * velocityScale;
		dolphin->bobbAngle += 13 * velocityScale;
	}

	float splashPoint = .58 * dolphin->bobbPeriod;
	float timeBefore = dolphin->bobbTime;

	bob(dolphin, timePassed, dolphin->bobbMid, dolphin->bobbSize, dolphin->bobbAngle, dolphin->bobbPeriod);

	if (timeBefore < splashPoint && dolphin->bobbTime > splashPoint && velocityScale > .75 & !splashSoundPlaying)
	{
		playSplashSound();
		splash->translation.x = dolphin->translation.x;
		splash->translation.z = dolphin->translation.z;
		splash->rotation.y = dolphin->rotation.y;
		splashAnimation->restart();
	}
}

void bob(DrawObject* object, double timePassed, float bobbMid, float bobbSize, float bobbAngle, float bobbPeriod)
{
	//blend factor of 1 uses only new position, 0 only old position
	float blendFactor = .07;

	if (bobbPeriod <= 0)
		return;

	object->bobbTime += timePassed;
	
	if (object->bobbTime > bobbPeriod)
		object->bobbTime -= bobbPeriod;

	float bobbProgress = object->bobbTime / bobbPeriod * 2 * M_PI;

	float newY = bobbMid + bobbSize * sin(bobbProgress);
	float newAngle = bobbAngle * cos(bobbProgress) * -1;

	// blend with current position
	object->translation.y = object->translation.y + blendFactor * (newY - object->translation.y);

	// blend with current angle
	object->rotation.x = object->rotation.x + blendFactor * (newAngle - object->rotation.x);
}

void flySeagull(double timePassed, DrawObject* seagull, DrawObject* seagullRWing, DrawObject* seagullLWing, bool seagullFlapping, float* seagullAngle, int flightDirection, float height, int radius, int offset)
{
	if (seagullFlapping)
	{
		seagull->bobbTime += timePassed;

		if (seagull->bobbTime > seagull->bobbPeriod)
			seagull->bobbTime -= seagull->bobbPeriod;

		float newZAngle = 18 * sin(seagull->bobbTime / seagull->bobbPeriod * 2 * M_PI);
		seagullRWing->rotation.z = newZAngle;
		seagullLWing->rotation.z = newZAngle * -1;

		float newYAngle = -1 * 6 - 9 * sin(seagull->bobbTime / seagull->bobbPeriod * 2 * M_PI);
		seagullRWing->rotation.y = newYAngle;
		seagullLWing->rotation.y = newYAngle * -1;

		seagull->translation.y = height + .5 * sin(seagull->bobbTime / seagull->bobbPeriod * 2 * M_PI);
	}

	float fullCircleTime = 20;
	*seagullAngle += flightDirection * timePassed/fullCircleTime * 2 * M_PI;
	seagull->translation = Vector3f(radius * cos(*seagullAngle) + offset, seagull->translation.y, radius * sin(*seagullAngle));
	seagull->rotation.y -= flightDirection * timePassed/fullCircleTime * 360;
}

void updateValues(double timePassed)
{
	if (InCredits)
	{
		creditsScroll->translation.y += 1.5 * timePassed;
	}

	moveDolphin(timePassed);
	bob(swimmer, timePassed, swimmer->bobbMid, swimmer->bobbSize, swimmer->bobbAngle, swimmer->bobbPeriod);
	flySeagull(timePassed, seagullA, seagullARWing, seagullALWing, seagullAFlapping, &seagullAAngle, 1, SEAGULL_A_HEIGHT, 250, 200);
	flySeagull(timePassed, seagullB, seagullBRWing, seagullBLWing, seagullBFlapping, &seagullBAngle, -1, SEAGULL_B_HEIGHT, 175, -100);
	splashAnimation->play(timePassed);
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

	if (IsCollision() && !InGameOverScene)
	{
		engine->play2D("audio\\dolphinlaugh.wav");
		IncrementScore();
		sunTextID = sunGaspTextID;
		startTimer(1, SUN_GASP);
	}

	/*if (hitMonster())
	{
		monster->velocity = dolphin->velocity;
		monsterDir = dolphin->rotation.y;
		monster->translation.z += monster->velocity * cos(monsterDir * (M_PI / 180)) * 2;
		monster->translation.x += monster->velocity * sin(monsterDir * M_PI / 180) * 2;
	}*/

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
				draw(seagullA, seagullTextID);

				glPushMatrix();
					draw(seagullARWing, seagullTextID);
				glPopMatrix();

				glPushMatrix();
					draw(seagullALWing, seagullTextID);
				glPopMatrix();
			glPopMatrix();

			glPushMatrix();
				draw(seagullB, seagullTextID);

				glPushMatrix();
					draw(seagullBRWing, seagullTextID);
				glPopMatrix();

				glPushMatrix();
					draw(seagullBLWing, seagullTextID);
				glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			draw(swimmer, swimmerTextID);
			glPopMatrix();

			//glPushMatrix();
			//draw(monster,monsterTextID);
			//glPopMatrix();

			glPushMatrix();
			draw(dolphin, dolphinTextID);
			glPopMatrix();

			glPushMatrix();
			draw(arena, arenaTextID);
			glPopMatrix();

			glPushMatrix();
			draw(water, waterTextID);
			glPopMatrix();

			if (!(splashAnimation->isFinished()))
			{
				glPushMatrix();
				draw(splash, splashAnimation->getFrame());
				glPopMatrix();
			}

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

		if(InGameOverScene)
		{
			glPushMatrix();
			draw(gameover, gameoverTextureID);
			glPopMatrix();
		}
		else if(InVictoryScene)
		{
			glPushMatrix();
			draw(victory, victoryTextureID);
			glPopMatrix();
		}

	}

	glFlush();
	glfwSwapBuffers(window);
    glfwPollEvents();
}

bool IsCollision()
{
	return dolphin->CollidesWith(swimmer);
}

bool hitMonster()
{
	if(monsterDir != dolphin->rotation.y && monster->velocity > 0)
	{
		return false;
	}
	return dolphin->CollidesWith(monster);
}

void NewSwimmerPosition()
{
	float newSpawnSeparation = 300;
	int maxDistance = 670;
	float distFromDolphinPosition;
	float faceAngle;
	float newX;
	float newZ;

	do {
		float angle = (rand() % 360) * (M_PI / 180);
		faceAngle = (rand() % 360) * (M_PI / 180);
		int distance = rand() % maxDistance;
		newX = distance * cos(angle);
		newZ = distance * sin(angle);
		distFromDolphinPosition = sqrt(pow(dolphin->translation.x - newX, 2) + pow(dolphin->translation.z - newZ, 2));
	}
	while (distFromDolphinPosition < newSpawnSeparation);

	swimmer->translation = Vector3f(newX, -12.65, newZ);
	swimmer->rotation.y = faceAngle;
}

void Victory()
{
	InVictoryScene = true;
	startTimer(5, SHOW_CREDITS);
}

void GameOver()
{
	InGameOverScene = true;
	startTimer(5, LAUNCH_MENU);
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
	{
		swimmer->translation.x = 9999;
		Victory();
	}
	else
		NewSwimmerPosition();
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
