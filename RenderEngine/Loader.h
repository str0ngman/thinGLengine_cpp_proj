#ifndef LOADER_H
#define LOADER_H

#include "RawModel.h"
#include <GL\glew.h>
#include <vector>

using std::vector;

class Loader{
public:
	Loader();
	virtual ~Loader();

	//RawModel LoadToVAO(float positions[], int count);
	RawModel LoadToVAO(float vertices[], int indices[], int vertCount, int indCount);

	void UnbindVAO();
private:
	vector<GLuint> vaos;
	vector<GLuint> vbos;
	GLuint CreateVAO();
	void StoreDataInAttributeList(GLuint attribNumber,
		float data[],int& count);
	void BindIndicesBuffer(int indices[], int& count);
};

#endif //!LOADER_H