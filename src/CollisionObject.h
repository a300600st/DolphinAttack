#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "DrawObject.h"

class CollisionObject : public DrawObject
{
private:
	float rightBound;
	float frontBound;

public:
	CollisionObject(char*, float, float);
	CollisionObject(char*, int*, float, float);

	bool CollidesWith(CollisionObject*);

private:
	void Init();
};

#endif
