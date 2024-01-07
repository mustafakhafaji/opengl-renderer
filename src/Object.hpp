#pragma once

#include "Vertex.hpp"
#include <GL/glew.h>
#include "GLFW/glfw3.h"

class Object {
public:
	// Creates and stores object data.
	//
	// @param num_vertices The number of vertices in the shape.
	// @param num_triangles The number of triangles in the shape.
	Object(Vertex vertices[], GLuint indices[], GLuint num_vertices, GLuint num_triangles);
	~Object();

	GLsizeiptr GetVertexBufferSize() const;
	GLsizeiptr GetIndexBufferSize() const;

public:
	GLuint num_vertices;
	GLuint num_indices;
	Vertex* vertices;
	GLuint* indices;
};