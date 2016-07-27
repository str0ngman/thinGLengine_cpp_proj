#ifndef RENDERER_H
#define RENDERER_H

#include "../Models/RawModel.h"
#include "../Models/TexturedModel.h"

class Renderer{
public:
	Renderer();
	virtual ~Renderer();

	void Prepare();
	void Render(TexturedModel* texutredModel);
};

#endif //!RENDERER_H