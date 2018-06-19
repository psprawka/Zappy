#include "ResourceRenderer.hpp"

ResourceRenderer::ResourceRenderer(void)
{
	_models[0] = new Model("assets/resource0.model");
	_models[1] = new Model("assets/resource1.model");
	_models[2] = new Model("assets/resource2.model");
	_models[3] = new Model("assets/resource3.model");
	_models[4] = new Model("assets/resource4.model");
	_models[5] = new Model("assets/resource5.model");
	_models[6] = new Model("assets/resource6.model");
}

void	ResourceRenderer::Render(std::pair<glm::mat4, glm::mat4> perspective,
				 glm::vec2 pos,
				 const std::vector<int>& resources)
{
	static constexpr float d = 0.35;
	static constexpr glm::vec2 displacements[7] = {{d, -d},
						       {0, d},
						       {d, d},
						       {d, 0},
						       {-d, 0},
						       {-d, -d},
						       {0, -d}};
	
	for (size_t i = 0; i < 7; i++)
	{
		assert(resources[i] >= 0);
		if (resources[i] == 0)
			continue;
		glm::mat3 transform(std::min(pow(resources[i], 0.333), 3.0));
		transform[1][1] = 1 + 0.2 * resources[i];
		_models[i]->Render(perspective,
				  glm::mat4(transform),
				  glm::vec3(pos.x + displacements[i].x, 0,
					    -(pos.y + displacements[i].y)),
				   glm::vec3(0.8, 0.8, 0.8),
				   0.02,
				   true);
	}
}
