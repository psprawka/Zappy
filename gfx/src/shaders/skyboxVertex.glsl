#version 410 core

layout(location = 0) in vec3 vertex;

out vec3 texCoor;

uniform mat4 projection;

void	main()
{
	texCoor = vertex;	
	gl_Position = projection * vec4(vertex, 1.0);
}