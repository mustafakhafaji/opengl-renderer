#version 330 core
    
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 v_color;

out vec4 color;
    
void main()
{
    gl_Position = vec4(position, 1.0);
    color = v_color;
}