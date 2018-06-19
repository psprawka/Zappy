#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Obj.hpp"
#include "Time.hpp"

class	Model
{
public:
	struct	AnimatedPartRaw
	{
		std::string objectFile;
		std::string textureFile;
		float specular;
		float fog;
		glm::vec3 fogcol;
		float diffuse;
		std::vector<glm::mat4> transform;
		std::vector<float> time;
		float cycle;
		glm::vec3 pos;
	};
	
private:
	struct	AnimatedPart
	{
		Obj *object;
		std::vector<glm::mat4> animaTransform;
		std::vector<float> animaTime;
		float animaCycle;
		glm::vec3 partPos;
	};
	
private:

	Time _time;
	std::vector<AnimatedPart> _parts;
	float _totalTime;

	
	glm::mat4	InterpolateMatrix(AnimatedPart part);
	
public:

	Model(std::string filepath);
	~Model(void);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective,
		       glm::mat4 transform,
		       glm::vec3 position,
		       glm::vec3 outlineColor = Obj::noOutline,
		       float outlineSize = 0.2,
		       bool cartoon = false);
};

std::istream	&operator >> (std::istream &is, Model::AnimatedPartRaw &lhs);
