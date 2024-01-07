#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Parses a shader's file.
//
// @param shader_file_name The name of shader file inside of /Resources/Shaders/{...}.
// @return Shader in string format.
std::string parseShaderFile(std::string shader_file_name);

class Shader {
public:

	// Creates and attaches a shader to program.
	// 
	// @param shader_name File name containing the shader's code.
	// @param shader_type Enum specifiying the type of shader (e.x. GL_VERTEX_SHADER).
	// @param program The ID of the program to attach the shader to.
	Shader(std::string shader_name, GLenum shader_type, GLuint program);

	// Deletes the shader from memory.
	~Shader();

	GLuint ID;
};