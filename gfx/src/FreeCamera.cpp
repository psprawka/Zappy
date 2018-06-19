#include "FreeCamera.hpp"

glm::vec3 constexpr FreeCamera::_basePos;
glm::vec3 constexpr FreeCamera::_up;
glm::vec3 constexpr FreeCamera::_forward;
glm::vec3 constexpr FreeCamera::_right;

FreeCamera::FreeCamera(Window& window) : _window(window)
{
	_position = _basePos;
	_rotation = glm::mat4(1);
	_aspect = 1;
	_near = 0.1;
	_far = 512;
	_fov = 45;

        glm::mat4 translate = glm::translate(_position);
	glm::mat4 lookAt = glm::lookAt(glm::vec3(translate * _rotation * glm::vec4(_basePos, 1)),
				       glm::vec3(translate * _rotation * glm::vec4(_forward, 1)),
				       _up);
	glm::mat4 perspective = glm::perspective(glm::radians(_fov), _window.GetAspect(), _near, _far);
	_perspective.first = lookAt;
	_perspective.second = perspective;
}

void	FreeCamera::relativeMove(glm::vec3 amount)
{
	glm::vec3 absolute = glm::vec3(_rotation * glm::vec4(amount, 0));
	_position += absolute * 0.05;
}

void	FreeCamera::Update(void)
{
	bool moved = false;
	
	if (_window.Key('W'))
	{
		relativeMove(_forward);
		moved = true;
	}
	if (_window.Key('S'))
	{
		relativeMove(-_forward);
		moved = true;
	}
	if (_window.Key('A'))
	{
		relativeMove(glm::rotate(_forward, glm::radians(90.0f), _up));
		moved = true;
	}
	if (_window.Key('D'))
	{
		relativeMove(glm::rotate(_forward, glm::radians(-90.0f), _up));
		moved = true;
	}
	if (_window.Key('Z'))
	{
		relativeMove(_up);
		moved = true;
	}
	if (_window.Key('X'))
	{
		relativeMove(-_up);
		moved = true;
	}
	if (_window.Key(GLFW_KEY_LEFT))
	{
		_rotation = glm::rotate(_rotation, glm::radians(1.0f), _up);
		moved = true;
	}
	if (_window.Key(GLFW_KEY_RIGHT))
	{
		_rotation = glm::rotate(_rotation, glm::radians(-1.0f), _up);
		moved = true;
	}
	if (_window.Key(GLFW_KEY_DOWN))
	{
		_rotation = glm::rotate(_rotation, glm::radians(-1.0f), _right);
		moved = true;
	}
	if (_window.Key(GLFW_KEY_UP))
	{
		_rotation = glm::rotate(_rotation, glm::radians(1.0f), _right);
		moved = true;
	}
	
	glm::mat4 translate = glm::translate(_position);
	glm::mat4 lookAt = glm::lookAt(glm::vec3(translate * glm::vec4(_basePos, 1)),
				       glm::vec3(translate * _rotation * glm::vec4(_forward, 1)),
				       glm::vec3(translate * _rotation * glm::vec4(_up, 0)));
	glm::mat4 perspective = glm::perspective(glm::radians(_fov), _window.GetAspect(), _near, _far);
	
	_perspective.first = lookAt;
	_perspective.second = perspective;
}

std::pair<glm::mat4, glm::mat4> FreeCamera::Perspective(void)
{
	return _perspective;
}

bool	FreeCamera::RayShouldTrigger(void)
{
	if (_window.MouseClick(0))
		return true;
	return false;
}

std::pair<glm::vec3, glm::vec3> FreeCamera::Ray(void)
{
	std::pair<glm::vec3, glm::vec3> out;

	glm::mat4 inverseProjection = glm::inverse(_perspective.second);
	glm::mat4 inverseLookAt = glm::inverse(_perspective.first);

	glm::vec4 p = {_window.MousePos().x, _window.MousePos().y, 0, 1};

	p = inverseLookAt * inverseProjection * p;
	p /= p.w;
	
	out.second = glm::normalize(glm::vec3(p) - _position); //vector
	out.first = _position;
	return out;
}
