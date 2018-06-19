#pragma once

#include "Model.hpp"
#include "zappy.hpp"

class	ResourceRenderer
{
	Model *_models[7];
public:
	ResourceRenderer(void);

	void	Render(std::pair<glm::mat4, glm::mat4> perspective,
		       glm::vec2 pos,
		       const std::vector<int>& resources);
};
