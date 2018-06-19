#include "Sound.hpp"

std::map<uint64_t, std::list<Sound*>> Sound::_sounds;
std::vector<uint64_t> Sound::_keysToErase;
std::vector<Sound*> Sound::_soundsToErase;

static uint64_t	getKey(glm::vec2 pos)
{
	uint64_t out;

	((float*)&out)[0] = (uint32_t)pos.x;
	((float*)&out)[1] = (uint32_t)pos.y;
	return out;
}

void	Sound::update(std::pair<glm::mat4, glm::mat4> perspective, double dt)
{
	for (int i = 0; i < _message.length(); i++)
	{
		Character3D::AddToBuffer(glm::vec3(_pos.x,
						   -_timeLeft + 3 + (_message.length() - i) * 0.4,
						   -_pos.y),
					 glm::vec3(0, 0, 0),
					 0.1,
					 _message[i]);
	}

	_timeLeft -= dt;
	if (_timeLeft < 0)
		delete this;
}

Sound::Sound(glm::vec2 pos, std::string message) : _pos(pos), _message(message)
{
	_timeLeft = 2;
}

Sound::~Sound(void)
{
	uint64_t key = getKey(_pos);

	assert(_sounds.count(key));
	auto &list = _sounds[key];
	_soundsToErase.push_back(this);
	if (list.empty())
		_keysToErase.push_back(key);
}

void	Sound::AddSound(glm::vec2 pos, std::string message)
{
	uint64_t key = getKey(pos);

	if (_sounds.count(key))
	{
		auto &list = _sounds[key];
		list.push_back(new Sound(pos, message));
	}
	else
	{
		std::list<Sound*> list;
		list.push_back(new Sound(pos, message));
		_sounds[key] = list;
	}
}

void	Sound::Render(std::pair<glm::mat4, glm::mat4> perspective, double dt)
{
	for (auto &keyPair : _sounds)
	{
		for (auto sound : keyPair.second)
		{
			sound->update(perspective, dt);			
		}
		for (auto sound : _soundsToErase)
			keyPair.second.remove(sound);
		_soundsToErase.resize(0);
	}
	for (auto key : _keysToErase)
		if (_sounds.count(key))
			_sounds.erase(key);
	_keysToErase.resize(0);
}
