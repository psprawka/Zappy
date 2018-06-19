#include "Egg.hpp"

Egg::Egg(glm::vec2 pos, int ID) : _pos(pos), _hatched(false), _ID(ID)
{	
	_model = new Model("assets/egg.model");
}

Egg::~Egg(void)
{
	delete _model;
}

void	Egg::Crack(void)
{
	_hatched = true;
}

int	Egg::ID(void)
{
	return _ID;
}

void	Egg::Render(std::pair<glm::mat4, glm::mat4> perspective)
{
	_model->Render(perspective, glm::mat4(1), glm::vec3(_pos.x - 0.35, 0, -_pos.y - 0.35));
}
