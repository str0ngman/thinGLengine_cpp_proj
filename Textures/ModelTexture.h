#ifndef MODEL_TEXTURE_H
#define MODEL_TEXTURE_H

#include <GL\glew.h>

class ModelTexture{
public:
	ModelTexture(GLuint id);
	virtual ~ModelTexture();

	GLuint GetTextureID();
private:
	GLuint m_textureID;
};

#endif