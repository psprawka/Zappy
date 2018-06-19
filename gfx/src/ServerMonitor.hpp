#pragma once

#include "zappy.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>

class	ServerMonitor
{

	std::vector<const std::string> _commands;
	std::vector<const std::string> _data;
	int _fd;
	fd_set _rfds;
	struct timeval _tv;
	
public:
	ServerMonitor(int fd);

	void	Update(void);
	const std::vector<const std::string>& Commands(void);
	const std::vector<const std::string>& Data(void);
};
