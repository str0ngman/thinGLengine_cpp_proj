#include "StaticShader.h"

StaticShader::StaticShader(const std::string& fileName):
ShaderProgram("../res/shaders/"+fileName){
}

StaticShader::~StaticShader(){
}

void StaticShader::BindAttributes(){
	BindAttribute(0, "position");
}