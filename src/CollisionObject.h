#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "DrawObject.h"

class CollisionObject : public DrawObject
{
private:
	// These are DISTANCES from the object's center (aka positive values)
	float rightBound;
	float leftBound;
	float frontBound;
	float backBound;

public:
	CollisionObject(char*, float);
	CollisionObject(char*, int*, float);

	bool CollidesWith(CollisionObject*);

private:
	void Init();
};

#endif
