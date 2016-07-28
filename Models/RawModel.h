#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <gl\glew.h>

class RawModel{
public:
	RawModel(GLuint&,int&);
	virtual ~RawModel();

	inline GLuint GetVaoID(){ return m_vaoID; }
	inline int    GetVertexCount(){ return m_vertexCount; }

private:
	GLuint m_vaoID;
	int    m_vertexCount;
};


#endif //!RAWMODEL_H