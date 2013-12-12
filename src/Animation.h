#ifndef ANIMATION_H
#define ANIMATION_H

#include "DrawObject.h"
#include "GLFW\glfw3.h"

class Animation
{
public:
	GLuint* frames;

	Animation(int frameRate, int numFrames, GLuint* frames);
	void play(double timePassed);
	GLuint getFrame();
	bool isFinished();
	void restart();
	void stop();

private:
	double time;
	double timePerFrame;
	int numFrames;
	bool finished;
	int curFrame;
};

#endif