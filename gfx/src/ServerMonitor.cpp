#include "ServerMonitor.hpp"

ServerMonitor::ServerMonitor(int fd) : _fd(fd)
{
	FD_ZERO(&_rfds);
	FD_SET(_fd, &_rfds);

	_tv.tv_sec = 0;
	_tv.tv_usec = 0;
}

void	ServerMonitor::Update(void)
{
	//clear the previous frames commands + data
	_commands.clear();
	_data.clear();
	FD_ZERO(&_rfds); // ask adam about this maybe
	FD_SET(_fd, &_rfds);
	
	//read the server fd, taking care to not get blocked	
	if (select(_fd + 1, &_rfds, NULL, NULL, &_tv) < 0)
		std::cout << "negative" << std::endl;
		
	_tv.tv_sec = 0;
	_tv.tv_usec = 0;
	char buf[100000];	
	if (FD_ISSET(_fd, &_rfds))
	{
		int bytes_read = read(_fd, buf, 99999); //shhh, no one needs to know
		assert(bytes_read < 99999);
		buf[bytes_read] = '\0';

		std::stringstream ss((std::string(buf)));

		for (std::string line; std::getline(ss, line);)
		{
//			std::cout << line << std::endl;
			size_t delim = line.find(' ');
			_commands.push_back(line.substr(0, delim));
			_data.push_back(line.substr(delim + 1));
		}
	}
}

const std::vector<const std::string>&	ServerMonitor::Commands(void)
{
	return _commands;
}

const std::vector<const std::string>&	ServerMonitor::Data(void)
{
	return _data;
}
