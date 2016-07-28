#include "Renderer.h"
#include <GL\glew.h>
#include <glm\gtx\transform.hpp>
#include "../Toolbox/Maths.h"
#include "../Models/RawModel.h"
#include "../Models/TexturedModel.h"

Renderer::Renderer(StaticShader& shader,float& aspect){
	//Create the projection matrix using GLM
	m_projectionMatrix = glm::perspective(m_FOV, aspect, m_NEAR_PLANE, m_FAR_PLANE);

	shader.Use();
	shader.LoadProjectionMatrix(m_projectionMatrix);
	shader.UnUse();

}
Renderer:: ~Renderer(){
}

void Renderer::Prepare(){

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Renderer::Render(Entity& entity, StaticShader& shader){
	
	TexturedModel& texturedModel = entity.GetModel();
	// Get the RawModel from the textured model
	RawModel& model = texturedModel.GetRawModel();
	// Bind the models VAO
	glBindVertexArray(model.GetVaoID());
	// Enable the attrib arrays
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// Load the transformation matrix into the shader
	shader.LoadTransformMatrix(Maths::CreateTransformMatrix(entity.GetPosition(), entity.GetRotation(), entity.GetScale()));

	// Activate an OpenGL texture and tell it where the texture is
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturedModel.GetModelTexture().GetTextureID());
	// Draw the model
	glDrawElements(GL_TRIANGLES, model.GetVertexCount(), GL_UNSIGNED_INT, 0);

	// Disable the attrib arrays
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);

}