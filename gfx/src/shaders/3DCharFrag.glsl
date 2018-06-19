#version 410 core

in vec2 tex_uv;

uniform vec3 color;
uniform sampler2D tex;

out vec4 col;

void	main()
{
	col = texture(tex, tex_uv).rgba * vec4(color, 1);
	col.a = pow(col.a, 3);
}