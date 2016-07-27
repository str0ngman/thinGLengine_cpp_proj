#include "Loader.h"
#include <iostream>
#include <cassert>
#include "../stb_image.h"

Loader::Loader(){
	vaos.clear();
	vbos.clear();
	m_textures.clear();
	//clear() cant release stored memory, just clear the data.
	//need to check the data one by one and delete them ,
	//is a better choice, check this part later.
	//reference page:http://www.cnblogs.com/summerRQ/articles/2407974.html
}

Loader:: ~Loader(){
	while (vbos.size() > 0)	{
		glDeleteBuffers(1, &vbos.back());
		vbos.pop_back();
	}
	while (vaos.size() > 0){
		glDeleteVertexArrays(1, &vaos.back());
		vaos.pop_back();
	}

	while (m_textures.size() > 0){
		glDeleteTextures(1, &m_textures.back());
		m_textures.pop_back();
	}
}

RawModel Loader::LoadToVAO(float vertices[], int indices[], float texCoords[],int vertCount, int indCount,int texCount){

	//create a new VAO
	GLuint vaoID = CreateVAO();
	BindIndicesBuffer(indices, indCount);

	//store the data in an attribute list
	StoreDataInAttributeList(0, 3,vertices, vertCount);
	StoreDataInAttributeList(1, 2, texCoords, texCount);
	UnbindVAO();
	return RawModel(vaoID, vertCount);

}
GLuint Loader::LoadTexture(const std::string& fileName){
	GLuint texture;
	int width, height, numComponents;

	//Load image data
	stbi_uc* imageData = stbi_load(
		("../res/textures/" + fileName + ".png").c_str(),
		&width, &height, &numComponents, 4);
}
void Loader::UnbindVAO(){
	glBindVertexArray(0);
}

GLuint Loader::CreateVAO(){
	GLuint vaoID;
	
	//createa a new vao
	glGenVertexArrays(1, &vaoID);

	//store the vao in the list
	vaos.push_back(vaoID);

	//bind the vao to use it
	glBindVertexArray(vaoID);
	return vaoID;
}

void Loader::StoreDataInAttributeList(GLuint attribNumber,int size,
	float data[], int& count){

	GLuint vboID;
	//create a new buffer
	glGenBuffers(1, &vboID);
	//store the buffer in the list
	vbos.push_back(vboID);
	//bind the buffer to use it.
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	//store the data in the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(data)* count, data, GL_STATIC_DRAW);

	//tell opengl how and where to store this vbo in the vao
	glVertexAttribPointer(attribNumber, size, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Loader::BindIndicesBuffer(int indices[], int& count){
	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices)*count, indices, GL_STATIC_DRAW);
}