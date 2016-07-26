#include<iostream>
#include<fstream>

#include "ShaderProgam.h"


ShaderProgram::ShaderProgram(const std::string& fileName){
	//Load shader from file
	m_vertexShaderID = LoadShader(fileName + ".vert", GL_VERTEX_SHADER);
	m_fragmentShaderID = LoadShader(fileName + ".frag", GL_FRAGMENT_SHADER);

	//create shader program
	m_programID = glCreateProgram();

	//attach the shaders to the program
	glAttachShader(m_programID, m_vertexShaderID);
	glAttachShader(m_programID, m_fragmentShaderID);

	//Link the program
	glLinkProgram(m_programID);
	glValidateProgram(m_programID);

	//check validation status
	GLint status;
	glGetProgramiv(m_programID, GL_VALIDATE_STATUS, &status);
	if (status == GL_FALSE)
	{
		// Get info log length
		GLint infoLogLength;
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		// Get the info log
		GLchar* infoLog = new GLchar[infoLogLength];
		glGetProgramInfoLog(m_programID, infoLogLength, NULL, infoLog);
		std::cerr << "ERROR: could not validate program \n" << infoLog << std::endl;
		// Delete the array
		delete[] infoLog;
	}
}


ShaderProgram:: ~ShaderProgram(){
	UnUse();
	glDetachShader(m_programID, m_vertexShaderID);
	glDetachShader(m_programID, m_fragmentShaderID);
	glDeleteShader(m_vertexShaderID);
	glDeleteShader(m_fragmentShaderID);
	glDeleteProgram(m_programID);
}

void ShaderProgram::Use(){
	glUseProgram(m_programID);
}
void ShaderProgram::UnUse(){
	glUseProgram(0);
}


GLuint ShaderProgram::LoadShader(const std::string& fileName, GLenum type){

	//open the file
	std::ifstream file;
	file.open((fileName).c_str());

	//Create temp variable
	std::string source, line;

	if (file.is_open()){
		while (file.good()){

			getline(file, line);
			source.append(line + "\n");

		}
	}
	else {
		std::cerr << "Unable to load Shader: " << fileName << std::endl;
	}

	GLuint shaderID = glCreateShader(type);

	//Prepare source for OpenGL
	const GLchar* sourceStrings[1];
	GLint sourceLengths[1];

	sourceStrings[0] = source.c_str();
	sourceLengths[0] = source.length();

	//load source to OpenGL and Compile
	glShaderSource(shaderID, 1, sourceStrings, sourceLengths);
	glCompileShader(shaderID);

	//check comiple status
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
			<< "infoLog: " << infoLog << std::endl;
	}
	return shaderID;
}


void ShaderProgram::BindAttribute(int attribute, const std::string& variableName){
	glBindAttribLocation(m_programID, attribute, variableName.c_str());
}
