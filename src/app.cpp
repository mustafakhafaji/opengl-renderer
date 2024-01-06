#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Shader.h"

void loadShaders()
{
	GLuint program = glCreateProgram();
	Shader vertex_shader("Vertex.shader", GL_VERTEX_SHADER, program);
	Shader fragment_shader("Fragment.shader", GL_FRAGMENT_SHADER, program);

	glLinkProgram(program);
	glUseProgram(program);
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
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,

		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,

		-1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		-1.0f, -1.0f, 3.0f,
		0.5f, 0.0f, 0.0f,

		1.0f, -1.0f, 2.3f,
		0.0f, 0.5f, 0.0f,
	};

	GLuint vertex_buffer_object;
	glGenBuffers(1, &vertex_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));

	GLushort index_data[] = {0, 1, 2, 0, 3, 4};

	GLuint index_buffer_object;
	glGenBuffers(1, &index_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_data), index_data, GL_STATIC_DRAW);

	//glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}