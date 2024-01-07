#include "Object.hpp"

Object::Object(Vertex vertices[], GLuint indices[], GLuint num_vertices, GLuint num_indices) {
	this->vertices = (Vertex*) malloc(sizeof(Vertex) * num_vertices);
	memcpy(this->vertices, vertices, sizeof(Vertex) * num_vertices);

	this->indices = (GLuint*)malloc(sizeof(GLuint) * num_indices);
	memcpy(this->indices, indices, sizeof(GLuint) * num_indices);

	this->num_vertices = num_vertices;
	this->num_indices = num_indices;
}

GLsizeiptr Object::GetVertexBufferSize() const {
	return this->num_vertices * sizeof(Vertex);
}

GLsizeiptr Object::GetIndexBufferSize() const {
	return this->num_indices * sizeof(GLuint);
}

Object::~Object() {
	delete[] this->vertices;
	delete[] this->indices;
	this->num_vertices = 0;
	this->num_indices = 0;
}