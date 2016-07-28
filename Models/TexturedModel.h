#ifndef TEXTURE_MODEL_H
#define TEXTURE_MODEL_H

#include "../Models/RawModel.h"
#include "../Textures/ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel model, ModelTexture texture);
	virtual ~TexturedModel();

	inline RawModel GetRawModel(){ return m_rawModel; }
	inline ModelTexture GetModelTexture(){ return m_texture; }

private:
	RawModel m_rawModel;
	ModelTexture m_texture;
};


#endif //!TEXTURE_MODEL_H