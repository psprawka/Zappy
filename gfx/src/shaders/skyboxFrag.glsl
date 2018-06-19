#version 410 core

in vec3 texCoor;

out vec4 color;

uniform samplerCube tex;

void	main()
{
	vec4 xcolor = texture(tex, texCoor);
	color = round(xcolor.xxzw * 4) / 4;
}