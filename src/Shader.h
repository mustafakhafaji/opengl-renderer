#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader {
public:
	Shader(const char* shader_code, GLenum shader_type, GLuint program);

private:
	GLuint m_shaderID;
};