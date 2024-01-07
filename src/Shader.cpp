#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

std::string parseShaderFile(std::string shader_file_name) {
	std::filesystem::path file_path = std::filesystem::current_path() / "Resources" / "Shaders" / shader_file_name;
	std::ifstream inputFileStream(file_path);

	std::string shader_string;
	std::string line;

	while (std::getline(inputFileStream, line)) {
		shader_string += line + "\n";
	}

	inputFileStream.close();
	return shader_string;
}

Shader::Shader(std::string shader_file_name, GLenum shader_type, GLuint program) {
	this->ID = glCreateShader(shader_type);

	std::string shader_code = parseShaderFile(shader_file_name);
	const char* shader_code_start = shader_code.c_str();

	glShaderSource(this->ID, 1, &shader_code_start, nullptr);
	glCompileShader(this->ID);
	glAttachShader(program, this->ID);
}

Shader::~Shader() {
	glDeleteShader(this->ID);
}