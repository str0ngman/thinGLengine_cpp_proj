#include "Maths.h"
#include <glm\gtx\transform.hpp>

Maths::Maths(){
}


Maths::~Maths(){
}


glm::mat4 Maths::CreateTransformMatrix(
	glm::vec3 translation,
	glm::vec3 rotation,
	glm::vec3 scale	){

	glm::mat4 transMatrix = glm::translate(translation);

	glm::mat4 rotMatrix =
		glm::rotate(rotation.z, glm::vec3(0, 0, 1))*
		glm::rotate(rotation.y, glm::vec3(0, 1, 0))*
		glm::rotate(rotation.x, glm::vec3(1, 0, 0));

	glm::mat4 scaleMatrix = glm::scale(scale);

	return transMatrix * rotMatrix * scaleMatrix;

}