#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

void loadShaders()
{
	const char* vertex_shader_source =
		"#version 430 core\n"
		""
		"layout(location = 0) in vec2 position;"
		"layout(location = 1) in vec3 color;"
		""
		"out vec3 daColor;"
		""
		"void main()"
		"{"
		"gl_Position = vec4(position, 0.0, 1.0);"
		"daColor = color;"
		"}";

	const char* fragment_shader_source =
		"#version 430 core\n"
		""
		"in vec3 daColor;"
		"out vec4 fragColor;"
		""
		"void main()"
		"{"
		"fragColor = vec4(daColor, 1.0);"
		"}";

	GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader_id, 1, &vertex_shader_source, nullptr);
	glCompileShader(vertex_shader_id);

	GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader_id, 1, &fragment_shader_source, nullptr);
	glCompileShader(fragment_shader_id);

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader_id);
	glAttachShader(program, fragment_shader_id);

	glLinkProgram(program);
	glUseProgram(program);

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "learning", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit() failed" << std::endl;
		return 0;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
	loadShaders();

	GLfloat vertex_data[] = {
		0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		-1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f,
		0.5f, 0.0f, 0.0f,
		1.0f, -1.0f,
		0.0f, 0.5f, 0.0f,
	};

	GLuint vertex_buffer_object;
	glGenBuffers(1, &vertex_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)(sizeof(GLfloat) * 2));

	GLushort index_data[] = {0, 1, 2, 0, 3, 4};

	GLuint index_buffer_object;
	glGenBuffers(1, &index_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_data), index_data, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}