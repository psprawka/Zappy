#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;

uniform mat4 projection;
uniform mat4 lookAt;
uniform vec3 position;
uniform float size;

out vec2 tex_uv;

void	main()
{
	float aspect = projection[1][1] / projection[0][0];
	vec3 centerTransformed = vec3(lookAt * vec4(position, 1));
	vec3 cameraRight = vec3( projection[0][0], projection[1][0], projection[2][0] );
	vec3 cameraUp = vec3( projection[0][1], projection[1][1], projection[2][1] );
	vec3 vertexPos = centerTransformed +
			cameraRight * vertex.x * size * aspect +
			cameraUp * vertex.y * size;

	gl_Position = projection * vec4(vertexPos, 1);
	tex_uv = uv;
}