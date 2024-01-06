#pragma once

#include "/c-utils/Math/Vector2/vector2.h"
#include "/c-utils/Math/Vector3/vector3.h"
#include "/c-utils/Math/Vector4/vector4.h"

class Vertex {
public:
	/*
	* Creates a vertex object.
	* 
	* @param position the vertex's 3D position
	* @param color the vertex's color defined in RGBA format
	* @param UV the vertex's UV coordinate
	* @return The vertex object
	*/
	Vertex(Vector3* position, Vector4* color, Vector2* UV);

	/*
	* Creates a vertex object excluding UV (textureless).
	*
	* @param position the vertex's 3D position
	* @param color the vertex's color defined in RGBA format
	* @return The vertex object
	*/
	Vertex(Vector3* position, Vector4* color);

	Vector3* position;
	Vector4* color;
	Vector2* UV;
};