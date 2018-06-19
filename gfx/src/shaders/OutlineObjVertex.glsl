#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;

uniform mat4 projection;
uniform mat4 transform;
uniform vec3 color;
uniform float size;

out vec3 col;

void	main()
{
	col = color;
	gl_Position = projection * transform * vec4(vertex + size * normal, 1);
}
