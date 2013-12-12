#include "Animation.h"

Animation::Animation(int frameRate, int numFrames, GLuint* frames)
{
	this->timePerFrame = 1/(float)frameRate;
	this->numFrames = numFrames;
	this->time = 0;
	this->frames = frames;
	this->finished = false;
	this->curFrame = 0;
}

void Animation::play(double timePassed)
{
	if (!finished)
		time += timePassed;

	while (time > timePerFrame * (curFrame + 1))
	{
		if (curFrame == numFrames - 1)
		{
			finished = true;
			break;
		}

		curFrame++;
	}
}

GLuint Animation::getFrame()
{
	return frames[curFrame];
}

bool Animation::isFinished()
{
	return finished;
}

void Animation::restart()
{
	finished = false;
	curFrame = 0;
	time = 0;
}

void Animation::stop()
{
	finished = true;
}