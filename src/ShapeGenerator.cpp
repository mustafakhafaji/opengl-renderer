#include "ShapeGenerator.hpp"
#include "Vertex.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

Object ShapeGenerator_GenerateCube() {
	Vertex v0(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));   // Top    | Left  | Front | 0
	Vertex v1(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));    // Top    | Right | Front | 1
	Vertex v2(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));  // Bottom | Left  | Front | 2
	Vertex v3(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));   // Bottom | Right | Front | 3
	Vertex v4(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));   // Top    | Left  | Back  | 4
	Vertex v5(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));    // Top    | Right | Back  | 5
	Vertex v6(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));  // Bottom | Left  | Back  | 6
	Vertex v7(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));   // Bottom | Right | Back  | 7

	Vertex vertices[] = {v0, v1, v2, v3, v4, v5, v6, v7};

    GLuint indices[] = {
        // Front
        0, 1, 2,
        3, 2, 1,

        // Back
        4, 6, 5,
        7, 5, 6,

        // Right
        1, 7, 5,
        3, 1, 5,

        // Left
        0, 2, 4,
        6, 4, 2,

        // Top
        0, 4, 1,
        5, 1, 4,

        // Bottom
        2, 6, 3,
        7, 3, 6,
    };

	GLuint num_vertices = sizeof(vertices) / sizeof(*vertices);
	GLuint num_indices = sizeof(indices) / sizeof(*indices);

	return Object(vertices, indices, num_vertices, num_indices);
}