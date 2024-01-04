#include "/c-utils/Math/Vector2/vector2.h"
#include "/c-utils/Math/Vector3/vector3.h"
#include "/c-utils/Math/Vector4/vector4.h"
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