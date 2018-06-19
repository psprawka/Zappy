#pragma once

#include "zappy.hpp"
#include "Model.hpp"

class	Grid
{
	Model *_model;
public:
	Grid(void);
	~Grid(void);

	void	Render(std::pair<glm::mat4, glm::mat4> perspective, glm::vec2 size);
};
