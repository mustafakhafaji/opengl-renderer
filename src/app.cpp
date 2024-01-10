#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.hpp"
#include "ShapeGenerator.hpp"
#include "Object.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void loadShaders(GLuint program) {
	
	Shader vertex_shader("Vertex.shader", GL_VERTEX_SHADER, program);
	Shader fragment_shader("Fragment.shader", GL_FRAGMENT_SHADER, program);

	glLinkProgram(program);

	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		char error_log[512];
		glGetProgramInfoLog(program, 512, NULL, error_log);
		std::cout << "ERROR: SHADER LINKING FAILED - " << error_log << std::endl;
	}
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

	GLFWwindow* window = glfwCreateWindow(800, 800, "3D Renderer", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit() failed" << std::endl;
		return 0;
	}

	GLuint program = glCreateProgram();

	glViewport(0, 0, 800, 800);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
	loadShaders(program);

	Object cube = ShapeGenerator_GenerateCube();

	GLuint vertex_array_object;
	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);
	glBufferData(GL_ARRAY_BUFFER, cube.GetVertexBufferSize(), cube.vertices, GL_STATIC_DRAW);
	
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

	glUseProgram(program);
	glBindVertexArray(vertex_array_object);

	GLuint element_buffer_object;
	glGenBuffers(1, &element_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube.GetIndexBufferSize(), cube.indices, GL_STATIC_DRAW);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection_matrix = glm::perspective(60.0f, 800.0f / 800.0f, 0.1f, 10.0f);
		glm::mat4 projection_translation_matrix = glm::translate(projection_matrix, glm::vec3(0.0f, 0.0f, -2.5f));
		glm::mat4 full_transformation_matrix = glm::rotate(projection_translation_matrix, glm::pi<float>() / 1.2f, glm::vec3(1.0f, 0.0f, 0.0f));

		GLint projection_matrix_uniform_location = glGetUniformLocation(program, "full_transformation_matrix");
		glUniformMatrix4fv(projection_matrix_uniform_location, 1, GL_FALSE, &full_transformation_matrix[0][0]);

		glDrawElements(GL_TRIANGLES, cube.GetIndexBufferSize(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}