#include "Object.hpp"

Object::Object(Vertex vertices[], GLuint indices[], int num_vertices, int num_triangles) {
	this->vertices = vertices;
	this->indices = indices;
	this->num_triangles = num_triangles;
	this->num_vertices = num_triangles;
}