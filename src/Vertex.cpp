#include "Vertex.h"

Vertex::Vertex(Vector3* position, Vector4* color, Vector2* UV) {
	position = position;
	color = color;
	UV = UV;
}

Vertex::Vertex(Vector3* position, Vector4* color) {
	position = position;
	color = color;
}