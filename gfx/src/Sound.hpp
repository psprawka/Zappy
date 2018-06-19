#pragma once

#include "zappy.hpp"
#include "Character3D.hpp"

class	Sound
{
	static std::map<uint64_t, std::list<Sound*>> _sounds;
	static std::vector<uint64_t> _keysToErase;
	static std::vector<Sound*> _soundsToErase;
	
	glm::vec2 _pos;
	std::string _message;
	double _timeLeft;

	void	update(std::pair<glm::mat4, glm::mat4> perspective, double dt);
	
	Sound(glm::vec2 pos, std::string message);
	~Sound(void);

public:

	static void	AddSound(glm::vec2 pos, std::string message);
	static void	Render(std::pair<glm::mat4, glm::mat4> perspective, double dt);
};
