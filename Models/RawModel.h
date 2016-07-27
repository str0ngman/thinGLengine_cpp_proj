#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <gl\glew.h>

class RawModel{
public:
	RawModel(GLuint&,int&);
	virtual ~RawModel();

	GLuint GetVaoID();
	int    GetVertexCount();

private:
	GLuint m_vaoID;
	int    m_vertexCount;
};


#endif //!RAWMODEL_H