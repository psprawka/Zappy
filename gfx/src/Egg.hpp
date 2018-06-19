#pragma once

#include "zappy.hpp"
#include "Model.hpp"

class	Egg
{
	glm::vec2 _pos;
	bool _hatched;
	int _ID;

	Model *_model;
	
public:
	Egg(glm::vec2 pos, int ID);
	~Egg(void);

	void	Crack(void);
	int	ID(void);

	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
};
