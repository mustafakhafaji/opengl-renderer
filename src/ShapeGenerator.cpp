#include "ShapeGenerator.hpp"
#include "Vertex.hpp"

Object ShapeGenerator_GenerateCube() {

	Vertex v1(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)); // Top left
	Vertex v2(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)); // Top right
	Vertex v3(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)); // Bottom left
	Vertex v4(glm::vec3(1.0f, -1.0f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)); // Bottom right
	Vertex v5(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	Vertex v6(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	Vertex v7(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	Vertex v8(glm::vec3(1.0f, -1.0f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));

	Vertex vertices[] = {v1, v2, v3, v4, v5, v6, v7, v8};

	GLuint indices[] = {
		// Front
		0, 1, 2, 
		1, 2, 3,

		// Back
		4, 5, 6,
		5, 6, 7

		// Left
		
		// Right
	};

	GLuint num_vertices = 8;
	GLuint num_triangles = 12;

	return Object(vertices, indices, num_vertices, num_triangles);
}