#include "zappy.hpp"
#include "Window.hpp"
#include "Map.hpp"
#include "FreeCamera.hpp"
#include "Player.hpp"
#include "SkyBox.hpp"
#include "Grid.hpp"
#include "Egg.hpp"
#include "FPSDisplay.hpp"
#include "Character3D.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int client_socket(char *ip, uint16_t port)
{
	struct sockaddr_in	client_addr;
	int					        sockfd;
	
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 6)) == -1)
		return (-1);

	std::cout << sockfd << std::endl;
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(port);
	if ((client_addr.sin_addr.s_addr = inet_addr(ip)) == (in_addr_t)-1)
		return (-1);
	if (connect(sockfd, (struct sockaddr*)&client_addr, sizeof(struct sockaddr_in)) == -1)
	{
		printf("No bueno %s\n", strerror(errno));		
		return (-1);
	}
	std::cout << sockfd << std::endl;
	return (sockfd);
}

int	main(int argc, char *argv[])
{
	int	clientfd;
		
	if (argc <= 2
	    || ((clientfd = client_socket(argv[1], atoi(argv[2]))) == -1))
		return (EXIT_FAILURE);
	
	Window window(1600, 900, "zap");
	FreeCamera cam(window);
	Light light(glm::vec3(5, 10, -5), glm::vec3(1, 1, 1), 100);
	Map map(clientfd);
	Time clock;
	FPSDisplay fps;
	SkyBox sky("assets/textures/skybox/right.png",
		   "assets/textures/skybox/left.png",
		   "assets/textures/skybox/top.png",
		   "assets/textures/skybox/bottom.png",
		   "assets/textures/skybox/front.png",
		   "assets/textures/skybox/back.png");

	char buf[10];
	int lol = read(clientfd, buf, 10);
	write(clientfd, "GRAPHIC\n", 8);

	glClearColor(0.2, 0.25, 0.3, 1);
	while (!window.ShouldClose())
	{
		GLenum err;
		if ((err = glGetError()) != GL_NO_ERROR)
			std::cerr << err << std::endl;
		window.Clear();		
		clock.Step();
		cam.Update();

		sky.Render(cam.Perspective());
		if (cam.RayShouldTrigger())
			map.RayCast(cam.Ray());
		map.Render(cam.Perspective(), clock.Delta());
		Player::RenderGUI(window);
		fps.Render();
		window.Render();
	}	
	window.Close();
}
