#pragma once

#include "zappy.hpp"
#include "Texture.hpp"
#include "ShadingProgram.hpp"

#define SKYBOX_VERTEX_SHADER_PATH "src/shaders/skyboxVertex.glsl"
#define SKYBOX_FRAGMENT_SHADER_PATH "src/shaders/skyboxFrag.glsl"

class	SkyBox
{
	static const std::vector<float> _vertexArray;
	
	ShadingProgram *_program;
	GLuint _vertexArrayID;
	GLuint _textureID;
	GLuint _textureLocationID;
	GLuint _projectionID;
public:
	SkyBox(std::string right, std::string left, std::string top,
	       std::string bot, std::string back, std::string front);
	~SkyBox(void);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
};
