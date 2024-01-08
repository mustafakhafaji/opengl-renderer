#version 430 core
    
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 v_color;

uniform mat4 full_transformation_matrix;

out vec4 color;
    
void main()
{
    gl_Position = full_transformation_matrix * vec4(position, 1.0);
    color = v_color;
}