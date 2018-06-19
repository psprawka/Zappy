#pragma once

#include "zappy.hpp"
#include "Model.hpp"
#include "Character3D.hpp"
#include "Window.hpp"
#include "Sprite2D.hpp"
#include "Light.hpp"

class	Player
{
	glm::vec2 _pos;
	glm::vec2 _dir;
	std::vector<int> _resources;
	double _ritualTime;
	int _level;
	std::string _teamName;
	int _ID;
	glm::vec2 _mapSize;
	static std::list<Player*> _players;
	
//rendering stuff:
	
	glm::vec2 _modelPos;
	float _moveTime;
	glm::vec2 _moveDir;
	glm::vec2 _modelDir;
	glm::vec2 _modelDirChange;
	float _height;
	bool _moving;	
	Model *_model;
	Light *_light;
	static Model *_partyModel;
	static Model *_normalModel;
	static std::map<uint64_t, std::list<Player*>> _staticPlayers;
	
	void	stopMoving(void);
	void	startMoving(void);
	void	spaceOutPlayers(uint64_t key);

//gui stuff:

	bool _guiActive;

	static Sprite2D *_guiBackground;

	void	DrawGUI(Window& window);
	
public:
	static void	RayCastGUI(glm::vec3 rayPoint, glm::vec3 rayDir);
	static void	RenderGUI(Window &window);
	
	Player(glm::vec2 pos, glm::vec2 dir, const std::string& name, int ID, int level, glm::vec2 mapSize);
	~Player(void);

	void	MoveTo(glm::vec2 pos);
	void	SetDir(glm::vec2 dir);
	void	UpdateResources(std::vector<int>);

	void	BeginRitual(void);
	void	SetLevel(int);
	const std::string&	Name(void);
	int	ID(void);

	glm::vec2	GetPosition(void);
	void	Update(double dt);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
};
