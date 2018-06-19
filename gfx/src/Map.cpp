#include "Map.hpp"

const glm::vec2 Map::_directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

Player	*Map::getPlayer(int ID)
{
	for (size_t i = 0; i < _players.size(); i++)
	{
		if (ID == _players[i]->ID())
			return _players[i];
	}
	assert(1);
	return nullptr;
}

Egg	*Map::getEgg(int ID)
{
	for (size_t i = 0; i < _players.size(); i++)
	{
		if (ID == _eggs[i]->ID())
			return _eggs[i];
	}
	assert(1);
	return nullptr;
}

Map::Map(int fd) : _size(glm::vec2(0, 0)), _serverMonitor(fd)
{
	// [this] is basically calling every member from the class Map
	_events["ppo"] = [this](std::string data)
	{
		int playerID;
		glm::vec2 pos;
		int orientation;

		std::stringstream ss;
		ss << data; //Putting in my data string

		ss >> playerID >> pos.x >> pos.y >> orientation;

		//change player position
		Player *p = getPlayer(playerID);

		p->MoveTo(pos);
		p->SetDir(_directions[orientation - 1]);

	};
	_events["pnw"] = [this](std::string data) //add new player
	{
		int playerID;
		glm::vec2 pos;
		int orientation;
		int level;
		std::string team_name;

		std::stringstream ss;
		ss << data;
		ss >> playerID >> pos.x >> pos.y >> orientation >> level >> team_name;

		_players.push_back(new Player(pos, _directions[orientation - 1], team_name, playerID, level, _size));
	};
	_events["tna"] = [this](std::string data)
	{
		//ignore
	};
	_events["bct"] = [this](std::string data) //content of map block
	{
		size_t x, y;
		int quantity[7];

		std::stringstream ss;
		ss << data;
		ss >> x >> y;
		for (auto& q : quantity)
			ss >> q;
		for (int i = 0; i < _resources[x][y].size(); i++)
			_resources[x][y][i] = quantity[i];
	};

	_events["sgt"] = [this](std::string data) //get time unit (check Time.cpp/hpp)
	{
		std::stringstream ss;
		ss << data;

		ss >> _timeUnit;
	};

	_events["msz"] = [this](std::string data) //map size or dimensions (check Map.cpp/hpp)
	{
		size_t x, y;
		std::vector<std::vector<size_t>> some_matrix;

		std::stringstream ss;
		ss << data;

		ss >> x >> y;
		_size.x = x;
		_size.y = y;
		
		_resources.resize(_size.x);
		for (auto &v : _resources)
		{
			v.resize(_size.y);
			for (auto &r : v)
				r.resize(7);
		}
	};
	
	_events["enw"] = [this](std::string data) //add an egg from the player
	{
		int egg;
		int playerID;
		glm::vec2 pos;

		std::stringstream ss;
		ss << data;

		ss >> egg >> playerID >> pos.x >> pos.y;

		_eggs.push_back(new Egg(pos, egg));

	};

	_events["pgt"] = [this](std::string data) //player picks resource - ignore
	{
	};

	_events["pdr"] = [this](std::string data) //player drops resource - ignore
	{
	};
	
	_events["pin"] = [this](std::string data) //ignore
	{
		int playerid;
		size_t x, y;
		std::vector<int> quantity;
		quantity.resize(7);

		std::stringstream ss;
		ss << data;
		ss >> playerid >> x >> y;
		for (auto& q : quantity)
			ss >> q;
		Player *p = getPlayer(playerid);
		p->UpdateResources(quantity);
	};

	_events["pex"] = [this](std::string data) //a player kick out
	{
		int playerID;

		std::stringstream ss;
		ss << data;

		ss >> playerID;
		
	};
	
	_events["pbc"] = [this](std::string data) //IGNORE: a player makes a sound
	{
		int playerID;
		std::string message;
		std::string temp;
		
		std::stringstream ss;
		ss << data;

		ss >> playerID;
		while (ss)
		{
			ss >> temp;
			message += temp + " ";
		}
		
		Player *p = getPlayer(playerID);
		glm::vec2 pos = glm::round(p->GetPosition());
		Sound::AddSound(pos, message);
	};

	_events["pic"] = [this](std::string data) // IGNORE: a ritual happens on square
	{
		glm::vec2 pos;
		int level;
		int playerID;

		std::stringstream ss;
		ss << data;

		ss >> pos.x >> pos.y >> level; // can ignore these because of previous info
		while (ss)
		{
			ss >> playerID;
			Player *p = getPlayer(playerID);
			p->BeginRitual();
		}
	};

	_events["plv"] = [this](std::string data) //player levels up
	{
		int playerID;
                int level;

                std::stringstream ss;
                ss << data;

                ss >> playerID >> level;

		Player *p = getPlayer(playerID);
		p->SetLevel(level);
	};

	_events["pfk"] = [this](std::string data) //IGNORE
	{
		//ignore
	};

	_events["ebo"] = [this](std::string data) //player connects, remove egg
	{
		int eggID;

		std::stringstream ss;
		ss << data;

		ss >> eggID;

		for (size_t i = 0; i < _eggs.size(); i++)
		{
			if (_eggs[i]->ID() == eggID)
			{
				delete _eggs[i];
				_eggs.erase(_eggs.begin() + i);
				break;
			}
		}
	};

	_events["edi"] = [this](std::string data) //egg is bad - remove it
	{
		int eggID;

		std::stringstream ss;
		ss << data;

		ss >> eggID;
		
		for (size_t i = 0; i < _eggs.size(); i++)
		{
			if (_eggs[i]->ID() == eggID)
			{
				delete _eggs[i];
				_eggs.erase(_eggs.begin() + i);
				break ;
			}
		}
	};

	_events["pdi"] = [this](std::string data) //player dies - remove it
	{
		int playerID;

		std::stringstream ss;
		ss << data;

		ss >> playerID;
		
		for (size_t i = 0; i < _players.size(); i++)
		{
			if (_players[i]->ID() == playerID)
			{
				delete _players[i];
				_players.erase(_players.begin() + i);
				break ;
			}
		}
	};

	_events["seg"] = [this](std::string data) //IGNORE: game is over (true/false of the map)
	{
		std::string team_name;

		std::stringstream ss;
		ss << data;

		ss >> team_name;

		_gameOver = team_name;
	};
	_events["pie"] = [this](std::string data) //end of ritual, just ignore
	{
	};
}

Map::~Map(void)
{
	for (auto p : _players)
		delete p;
	for (auto e : _eggs)
		delete e;
}

void	Map::Render(std::pair<glm::mat4, glm::mat4> perspective, double dt)
{
	dt *= _timeUnit / 6.0f;
	_serverMonitor.Update();
	const std::vector<const std::string>& commands = _serverMonitor.Commands();
	const std::vector<const std::string>& data = _serverMonitor.Data();
	
	for (size_t i = 0; i < commands.size(); i++)
	{
		if (_events.count(commands[i]) != 0)
			_events[commands[i]](data[i]);
	}

	for (Egg *e : _eggs)
	{
		e->Render(perspective);
	}
	
	for (int x = 0; x < _size.x; x++)
		for (int y = 0; y < _size.y; y++)
			_resourceRenderer.Render(perspective, glm::vec2(x, y), _resources[x][y]);

	_grid.Render(perspective, _size);

	for (Player *p : _players)
	{
		p->Update(dt);
		p->Render(perspective);
	}
	Sound::Render(perspective, dt);
	Character3D::RenderAndClearBuffer(perspective);

	if (_gameOver.length())
	{
		Text t("   " + _gameOver + " wins!   ");
		t.Render(16.0f/9.0f);
	}
}

void	Map::RayCast(std::pair<glm::vec3, glm::vec3> ray)
{	
	Player::RayCastGUI(ray.first, ray.second);
}
