#include "CollisionObject.h"
#include <iostream>

CollisionObject::CollisionObject(char* fileName, int* rotationOrder, float bound)
	: DrawObject(fileName, rotationOrder)
{
	this->rightBound = bound;
	this->leftBound = bound;
	this->frontBound = bound;
	this->backBound = bound;
}

CollisionObject::CollisionObject(char* fileName, float bound)
	: DrawObject(fileName)
{
	this->rightBound = bound;
	this->leftBound = bound;
	this->frontBound = bound;
	this->backBound = bound;
}

bool CollisionObject::CollidesWith(CollisionObject* other)
{
	// my front right
	Vector3f myFr = Vector3f(this->translation.x + this->rightBound, 0, this->translation.z + this->frontBound);
	float myWidth = this->rightBound + this->leftBound;
	float myHeight = this->frontBound + this->backBound;
	
	// his front right
	Vector3f hisFr = Vector3f(other->translation.x + other->rightBound, 0, other->translation.z + other->frontBound);
	float hisWidth = other->rightBound * 2;
	float hisHeight = other->frontBound * 2;

	if ((myFr.x - myWidth > hisFr.x) || // am I on the right side of him?
		(myFr.z - myHeight > hisFr.z) || // am I above him?
		(hisFr.x - hisWidth > myFr.x) || // is he on the right side of me?
		(hisFr.z - hisHeight > myFr.z))   // is he above me?
    {
        // no collision
        return false;
    }
	else
	{
		return true;
	}
}