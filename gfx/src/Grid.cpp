#include "Grid.hpp"

Grid::Grid(void)
{
	_model = new Model("assets/block.model");
}

Grid::~Grid(void)
{
	delete _model;
}

void	Grid::Render(std::pair<glm::mat4, glm::mat4> perspective, glm::vec2 size)
{
	for (int x = 0; x < size.x; x++)
	{
		for (int y = 0; y < size.y; y++)
		{
			_model->Render(perspective,
				       glm::mat4(1),
				       glm::vec3(x, -1, -y),
				       Obj::noOutline,
				       0.2,
				       true);
		}
	}
}
