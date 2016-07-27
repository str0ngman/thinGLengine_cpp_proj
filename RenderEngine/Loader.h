#ifndef LOADER_H
#define LOADER_H

#include "../Models/RawModel.h"
#include <GL\glew.h>
#include <vector>
#include <string>

using std::vector;

class Loader{
public:
	Loader();
	virtual ~Loader();

	//RawModel LoadToVAO(float positions[], int count);
	RawModel LoadToVAO(float vertices[], int indices[], float texCoords[], int vertCount, int indCount, int texCount);

	GLuint	 LoadTexture(const std::string& fileName);

	void UnbindVAO();
private:
	vector<GLuint> vaos;
	vector<GLuint> vbos;
	vector<GLuint> m_textures;
	GLuint CreateVAO();
	void StoreDataInAttributeList(GLuint attribNumber, int size,
		float data[],int& count);
	void BindIndicesBuffer(int indices[], int& count);
};

#endif //!LOADER_H