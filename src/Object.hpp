#pragma once

#include "Vertex.hpp"
#include "GLFW/glfw3.h"

class Object {
public:
	// Creates and stores object data.
	//
	// @param num_vertices The number of vertices in the shape.
	// @param num_triangles The number of triangles in the shape.
	Object(Vertex vertices[], GLuint indices[], int num_vertices, int num_triangles);

private:
	int num_vertices;
	int num_triangles;
	Vertex* vertices;
	GLuint* indices;
};