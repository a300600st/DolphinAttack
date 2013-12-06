#include "DrawObject.h"

DrawObject::DrawObject(char* fileName, int rotateFirst, int rotateSecond, int rotateThird)
{
	Init(fileName, rotateFirst, rotateSecond, rotateThird);
}

DrawObject::DrawObject(char* fileName){
	Init(fileName, 0, 1, 2);
}

void DrawObject::Init(char* fileName, int rotateFirst, int rotateSecond, int rotateThird){
	this->rotateFirst = rotateFirst;
	this->rotateSecond = rotateSecond;
	this->rotateThird = rotateThird;
	this->translation = Vector3f(0, 0, 0);
	this->scale = Vector3f(1, 1, 1);
	this->rotation = Vector3f(0, 0, 0);

	std::ifstream file(fileName);
	if(!file.good()){
		printf("There was a problem with the file: %s\n", fileName);
		return;
	}

	char buf[1024];
	memset(buf, '\0', sizeof(buf));

	while(!file.eof()){
		file.getline(buf, sizeof(buf));
		float x, y, z;
		if(strncmp(buf, "v ", 2) == 0){
			sscanf_s(buf, "v %f %f %f", &x, &y, &z);
			verts.push_back(Vector3f(x, y, z));
		}
		else if(strncmp(buf, "vt", 2) == 0){
			sscanf_s(buf, "vt %f %f", &x, &y);
			textCoords.push_back(Vector3f(x, y, 0.f));
		}
		else if(strncmp(buf, "vn", 2) == 0){
			sscanf_s(buf, "vn %f %f %f", &x, &y, &z);
			normals.push_back(Vector3f(x, y, z));
		}
		else if(strncmp(buf, "f ", 2) == 0){
			int v1, v2, v3, vt1, vt2, vt3, vn1, vn2, vn3;
			sscanf_s(buf, "f %d/%d/%d %d/%d/%d %d/%d/%d", &v1, &vt1, &vn1,
														&v2, &vt2, &vn2,
														&v3, &vt3, &vn3);
			faceVerts.push_back(v1); faceVerts.push_back(v2); faceVerts.push_back(v3);
			textVerts.push_back(vt1); textVerts.push_back(vt2); textVerts.push_back(vt3);
			normVerts.push_back(vn1); normVerts.push_back(vn2); normVerts.push_back(vn3);
		}
		memset(buf, '\0', sizeof(buf));
	}
}
