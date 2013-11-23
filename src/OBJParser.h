#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <fstream>
#include <vector>

struct Vector3f{
	float x;
	float y;
	float z;

	Vector3f(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class OBJParser{
public:
	std::vector<Vector3f> verts;
	std::vector<Vector3f> textCoords;
	std::vector<Vector3f> normals;
	std::vector<int> faceVerts;
	std::vector<int> textVerts;
	std::vector<int> normVerts;

	OBJParser();
	void ParseOBJ(char* fileName);
};

#endif
