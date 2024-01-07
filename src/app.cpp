#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.hpp"
#include "ShapeGenerator.hpp"
#include "Object.hpp"

void loadShaders() {
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

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "3D Renderer", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit() failed" << std::endl;
		return 0;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
	loadShaders();

	Object cube = ShapeGenerator_GenerateCube();
	
	GLuint vertex_buffer_object;
	glGenBuffers(1, &vertex_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, cube.GetVertexBufferSize(), cube.vertices, GL_STATIC_DRAW);

	// Position attribute.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, 0);

	// Color attribute.
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)(sizeof(GLfloat) * 3));

	GLuint index_buffer_object;
	glGenBuffers(1, &index_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.GetIndexBufferSize(), cube.indices, GL_STATIC_DRAW);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, cube.GetIndexBufferSize(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}