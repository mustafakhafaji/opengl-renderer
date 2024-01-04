#pragma once

#include "/c-utils/Math/Vector2/vector2.h"
#include "/c-utils/Math/Vector3/vector3.h"
#include "/c-utils/Math/Vector4/vector4.h"

class Vertex {
public:
	Vertex(Vector3* position, Vector4* color, Vector2* UV);
	Vertex(Vector3* position, Vector4* color);

	Vector3* position;
	Vector4* color;
	Vector2* UV;
};