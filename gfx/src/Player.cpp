#include "Player.hpp"

Model	*Player::_partyModel = nullptr;
Model	*Player::_normalModel = nullptr;

std::list<Player*> Player::_players;
std::map<uint64_t, std::list<Player*>> Player::_staticPlayers;

Sprite2D	*Player::_guiBackground = nullptr;

static uint64_t	keyHash(glm::vec2 pos)
{
	uint64_t out;

	((float*)&out)[0] = (uint32_t)glm::round(pos.x);
	((float*)&out)[1] = (uint32_t)glm::round(pos.y);
	return out;
}

static glm::vec3 nameHash(const std::string &name)
{
        int x = 0;
	int y = 0;
        int z = 0;

        for (int i = 0; i < name.length(); i++)
        {
                x += name[i] * name[i] * 31;
		y += name[i] * name[i] * 17;
                z += name[i] * name[i] * 13;
        }
        x %= 10;
        y %= 10;
        z %= 10;
	return glm::vec3(x / 10.0f, y / 10.0f, z / 10.0f);
}

void	Player::stopMoving(void)
{
	//add itself to the list of static players and call spaceOutPlayers()

	uint64_t key = keyHash(_pos);

	if (_staticPlayers.count(key) == 0)
	{
		std::list<Player*> l = {this};
		_staticPlayers[key] = l;
	}
	else
	{
		std::list<Player*> &l = _staticPlayers[key];
		l.push_back(this);
	}
	spaceOutPlayers(key);
	_moving = false;
}

void	Player::startMoving(void)
{
	//remove itself from list of static players and call spaceOutPlayers() and set own height to 0

	uint64_t key = keyHash(_pos);

	if (_staticPlayers.count(key) == 0) //can happen if player move 2 time before updata
		return;
	else
	{
		std::list<Player*> &l = _staticPlayers[key];
		auto iter = std::find(l.begin(), l.end(), this);
		if (iter == l.end())
			return;
		l.erase(iter);
		if (l.empty())
			_staticPlayers.erase(key);
	}
	spaceOutPlayers(key);
	_height = 0;
	_moving = true;
}

void	Player::spaceOutPlayers(uint64_t key)
{
	if (_staticPlayers.count(key) == 0)
		return;
	
	std::list<Player*>& list = _staticPlayers[key];
	float i = 0;

	for (auto p : list)
	{
		p->_height = i;
		i++;
	}
}

void	Player::RayCastGUI(glm::vec3 rayPoint, glm::vec3 rayDir)
{
	std::vector<Player*> candidates;
	for (auto p : _players)
	{
		p->_guiActive = false;
		glm::vec3 pos(p->_modelPos.x, p->_height * 0.5 + 0.25, -p->_modelPos.y);
		float dist = glm::length(glm::cross(rayDir, pos - rayPoint));

		if (dist < 0.3)
			candidates.push_back(p);
	}
	//find closest candidate to rayPoint

	Player *playerHit = nullptr;
	float minDist = 10000000;
	
	for (auto p : candidates)
	{
		glm::vec3 v = glm::vec3(p->_modelPos.x, p->_height * 0.5, -p->_modelPos.y) - rayPoint;
		if (glm::dot(v, rayDir) < 0) // ray intersection happened behind ray
			continue;
		float dist = glm::length(v);
		if (dist < minDist)
		{
			dist = minDist;
			playerHit = p;
		}
	}
	if (playerHit == nullptr) // no player was hit by the ray
		return;

	playerHit->_guiActive = true;
}

static void	render_word(std::string word, float x, float y, float size, Window &window)
{
	size_t len = std::max(word.length(), (size_t)2);
	window.SetRenderMask(x, y,
			     std::min(size * len, 1 - x),
			     std::min(size, 1 - y));
	Text t(word);
	t.Render(window.GetAspect());
}

void	Player::DrawGUI(Window& window)
{
	//draw GUI box:

	window.SetRenderMask(0.8, 0.57, 0.2, 0.43);
	_guiBackground->Render();

	window.SetRenderMask(0.81, 0.9, 0.18, 0.1);
	Text team(_teamName);
	team.Render(window.GetAspect());

	
	render_word("Food     ", 0.8, 0.85, 0.015, window);
	render_word("Linemate ", 0.8, 0.80, 0.015, window);
	render_word("Deraumere", 0.8, 0.77, 0.015, window);
	render_word("Sibur    ", 0.8, 0.74, 0.015, window);
	render_word("Mendiane ", 0.8, 0.71, 0.015, window);
	render_word("Phirus   ", 0.8, 0.68, 0.015, window);
	render_word("Thystame ", 0.8, 0.65, 0.015, window);

	render_word(std::to_string(_resources[0]), 0.95, 0.85, 0.015, window);
	for (int i = 1; i < 7; i++)
		render_word(std::to_string(_resources[i]), 0.95, 0.83 - i * 0.03, 0.015, window);
	
	window.RemoveRenderMask();
}

void	Player::RenderGUI(Window& window)
{
	for (auto p : _players)
		if (p->_guiActive)
			p->DrawGUI(window);
}

Player::Player(glm::vec2 pos, glm::vec2 dir, const std::string& name, int ID, int level, glm::vec2 mapSize) :
_pos(pos),
_dir(dir),
_ritualTime(0),
_level(level),
_teamName(name),
_ID(ID),
_mapSize(mapSize)
{
	_resources.resize(7);
	_modelPos = _pos;
	_modelDir = _dir;
	_moveTime = 0;
	_modelDirChange = glm::vec2(0, 0);
	stopMoving();
	if (!_partyModel)
		_partyModel = new Model("assets/party_player.model");
	if (!_normalModel)
		_normalModel = new Model("assets/normal_player.model");
	_model = _normalModel;
	
	_guiActive = false;
	if (!_guiBackground)
		_guiBackground = new Sprite2D("assets/textures/gui_background.png");
	
	_players.push_back(this);

	_light = new Light(glm::vec3(_modelPos.x, _height * 0.5 + 0.5, -_modelPos.y), nameHash(_teamName), 1.0f);
}

Player::~Player(void)
{
	_players.remove(this);

	delete _light;
	
	uint64_t key = keyHash(_modelPos);
	if (_staticPlayers.count(key) == 0)
		return;
	std::list<Player*> &l = _staticPlayers[key];
	auto iter = std::find(l.begin(), l.end(), this);
	if (iter != l.end())
		l.erase(iter);
	if (l.empty())
		_staticPlayers.erase(key);
	spaceOutPlayers(key);
}

void	Player::MoveTo(glm::vec2 pos)
{
	if (pos != _pos)
	{
		startMoving();
		glm::vec2 moveDir;
		if (pos == glm::mod(_pos + glm::vec2(1, 0), _mapSize))
			moveDir = glm::vec2(1, 0);
		else if (pos == glm::mod(_pos + glm::vec2(0, 1), _mapSize))
			moveDir = glm::vec2(0, 1);
		else if (pos == glm::mod(_pos + glm::vec2(-1, 0), _mapSize))
			moveDir = glm::vec2(-1, 0);
		else if (pos == glm::mod(_pos + glm::vec2(0, -1), _mapSize))
			moveDir = glm::vec2(0, -1);
		else
			assert(0 && "player movement was invalid");
		
		_pos = pos;
		_moveTime = 1;
		_moveDir = moveDir;
	}
}

void	Player::SetDir(glm::vec2 dir)
{
	if (dir != _dir)
	{
		assert(glm::dot(dir, _dir) == 0 && "player did not turn 90 degrees");
		
		_dir = dir;
		_modelDirChange = _dir - _modelDir;
	}
}

void	Player::UpdateResources(std::vector<int> resources)
{
	assert(resources.size() == 7);
	for (int i = 0; i < 7; i++)
	{
		assert(resources[i] >= 0);
		_resources[i] = resources[i];
	}
}

void	Player::BeginRitual(void)
{
	_ritualTime = 50;
}

void	Player::SetLevel(int level)
{
	_level = level;
	assert(level >= 0 && level <= 8);
}

const std::string&	Player::Name(void)
{
	return _teamName;
}

int	Player::ID(void)
{
	return _ID;
}

glm::vec2	Player::GetPosition(void)
{
	return _pos;
}

void	Player::Update(double dt)
{
	if (_moveTime > 0)
	{
		glm::vec2 newpos = _modelPos + _moveDir * dt;
		newpos = glm::mod(newpos, _mapSize);
		_modelPos = newpos;
		_moveTime -= dt;
		if (_moveTime <= 0)
		{
			_moveTime = 0;
			_modelPos = _pos;
			stopMoving();
		}
	}

	if (_modelDirChange.x || _modelDirChange.y)
	{
		_modelDir += _modelDirChange * dt;
		glm::vec2 dirError = _dir - _modelDir;
		if (glm::dot(dirError, _modelDirChange) < 0)
		{
			_modelDir = _dir;
			_modelDirChange = glm::vec2(0, 0);
		}
	}

	if (_ritualTime > 0)
	{
		_ritualTime -= dt;
		_model = _partyModel;		
	}
	else
		_model = _normalModel;

	delete _light;
	_light = new Light(glm::vec3(_modelPos.x, _height * 0.5 + 0.5, -_modelPos.y), nameHash(_teamName), 1.0f);
}

void	Player::Render(std::pair<glm::mat4, glm::mat4> perspective)
{
	float angle = acos(glm::dot(_modelDir, glm::vec2(1, 0)));
	
	if (glm::dot(_modelDir, glm::vec2(0, 1)) < 0)
	{
		angle = 2 * M_PI - angle;
	}

	glm::mat4 rot = glm::rotate(angle, glm::vec3(0, 1, 0));

	glm::vec3 outlineCol;
	if (_guiActive)//_ritualTime > 0)
		outlineCol = glm::vec3(0.7, 0.2, 0.2);
	else
		outlineCol = glm::vec3(0, 0, 0);

	_model->Render(perspective,
		       rot,
		       glm::vec3(_modelPos.x, _height * 0.5, -_modelPos.y),
		       outlineCol,
		       0.02,
		       true);

	Character3D::AddToBuffer(glm::vec3(_modelPos.x ,
					   _height * 0.5 + 0.6,
					   -_modelPos.y),
				 nameHash(_teamName),
				 0.07,
				 _level + '0');
}
