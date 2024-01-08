#include "Vertex.hpp"
#include "glm/glm.hpp"

/*Vertex::Vertex(glm::vec3 position, glm::vec4 color, glm::vec2 UV) {
	position = position;
	color = color;
	UV = UV;
}*/

Vertex::Vertex(glm::vec3 position, glm::vec4 color) {
	this->position = position;
	this->color = color;
}