#include "RawModel.h"

RawModel::RawModel(GLuint &a, int &b):
m_vaoID(a), m_vertexCount(b){

}
RawModel::~RawModel(){

}

GLuint RawModel::GetVaoID(){
	return m_vaoID;
}
int    RawModel::GetVertexCount(){
	return m_vertexCount;
}
