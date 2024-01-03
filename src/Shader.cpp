#include "Shader.h"

Shader::Shader(const char* shader_code, GLenum shader_type, GLuint program) {
	m_shaderID = glCreateShader(shader_type);
	glShaderSource(m_shaderID, 1, &shader_code, nullptr);
	glCompileShader(m_shaderID);
	glAttachShader(program, m_shaderID);
}