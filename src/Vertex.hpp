#pragma once

#include "glm/glm.hpp"

class Vertex {
public:
	// Creates a vertex object.
	// 
	// @param position the vertex's 3D position
	// @param color the vertex's color defined in RGBA format
	// @param UV the vertex's UV coordinate
	// @return The vertex object
	//Vertex(glm::vec3 position, glm::vec4 color, glm::vec2 UV);

	// Creates a vertex object excluding UV (textureless).
	//
	// @param position the vertex's 3D position
	// @param color the vertex's color defined in RGBA format
	// @return The vertex object
	Vertex(glm::vec3 position, glm::vec4 color);

	glm::vec3 position;
	glm::vec4 color;
};