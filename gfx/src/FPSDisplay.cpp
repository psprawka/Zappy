#include "FPSDisplay.hpp"

FPSDisplay::FPSDisplay(void)
{
	_index = 0;
	std::memset(_times, 0, sizeof(double) * 60);
	_timer = 0;
}

void	FPSDisplay::Render(void)
{
	_clock.Step();
	
	_times[_index] = _clock.Delta();
	_index += 1;
	_index %= 60;

	_timer += _clock.Delta();
	if (_timer > 1)
	{
		double av = 0;

		for (auto t : _times)
			av += t;
		av /= 60;
		av = 1 / av;
		
		_timer = 0;
		std::cout << "Fps: " << std::setprecision(4) << av << std::endl;
	}
}
