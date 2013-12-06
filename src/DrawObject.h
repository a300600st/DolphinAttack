#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

#include <fstream>
#include <vector>

struct Vector3f{
	float x;
	float y;
	float z;

	Vector3f(){
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}

	Vector3f(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class DrawObject{
public:
	std::vector<Vector3f> verts;
	std::vector<Vector3f> textCoords;
	std::vector<Vector3f> normals;

	std::vector<int> faceVerts;
	std::vector<int> textVerts;
	std::vector<int> normVerts;

	Vector3f rotation;
	Vector3f scale;
	Vector3f translation;

	int rotateFirst;
	int rotateSecond;
	int rotateThird;

	DrawObject(char*);
	DrawObject(char*, int*);

private:
	void Init(char*, int*);
};

#endif
