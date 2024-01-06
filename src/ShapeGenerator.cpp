// Generates basic shapes
//
// Mustafa Al-Khafaji

#include "/c-utils/Math/Vector4/vector4.h"
#include "Shape.h"
#include "ShapeGenerator.h"
#include "Vertex.h"

Shape* ShapeGenerator_GenerateCube() {
	
	Vertex v1(Vector4_Create(1.0f, 1.0f, 1.0f, 0.0f), Vector4_Create(1.0f, 1.0f, 1.0f, 0.0f));



	Vertex vertices[] = { v1 };

	Shape(vertices);
}