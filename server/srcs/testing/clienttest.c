/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:29:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 01:45:16 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define BUFF_SIZE 64
#define DEF_COLOR CYAN

typedef struct	s_client
{
	int		sockfd;
	char	*color;
	char	*name;
	char	*room;
}				t_client;

int		errorcli(int errnb, char *msg, bool ifexit)
{
	if (errnb == 1)
		ft_printf("Usage: server -p <port> -x <width> -y <height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	else if (errnb == 2)
		ft_printf("Port number has to be between 1024 and 65535!\n");
	else if (errnb == 3)
		ft_printf("x and y have to be between 2 and 100\n");
	else if (errnb == 4)
		ft_printf("At least one team required\n");
	else if (errnb == 5)
		ft_printf("Number of clients authorized at the beginning of the game has to be grater than 5 and less than %d.\n", FD_SETSIZE);
	else 
		ft_printf("%s%s: %s%s\n", RED, msg, strerror(errno), NORMAL);	
	return (ifexit == true ? EXIT_FAILURE : EXIT_SUCCESS);
}

void	parse_args_client(int ac, char **av)
{
	if (ac != 3)
		exit(errorcli(3, NULL, true));
	if (ft_atoi(av[1]) > 65535 || ft_atoi(av[1]) < 1024)
		exit(errorcli(2, NULL, true));
}

t_client	*create_client(int sockfd, char *name)
{
	t_client *client;

	client = (t_client *)ft_strnew(sizeof(t_client));
	client->name = name;
	client->sockfd = sockfd;
	client->color = DEF_COLOR;
	client->room = NULL;

	return (client);	
}

t_client *client_socket(int ac, char **av)
{
	struct protoent 	*protocol;
	struct sockaddr_in	client_addr;
	static t_client		*clients[FD_SETSIZE];
	int					sockfd;
	
	protocol = getprotobyname("TCP");
	if ((sockfd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1)
		exit(errorcli(0, "Socket", true));
	ft_bzero(&client_addr, sizeof(struct sockaddr_in));
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(ft_atoi(av[1]));
	client_addr.sin_addr.s_addr = inet_addr(av[2]);
	
	if (connect(sockfd, (struct sockaddr*)&client_addr, sizeof(struct sockaddr_in)) == -1)
		exit(errorcli(0, "Connect", true));

	clients[sockfd] = create_client(sockfd, ft_strdup(getenv("USER"))); 
	return (clients[sockfd]);
}

int main(int ac, char **av)
{
	char		getbuff[BUFF_SIZE];
	char		*sendbuff;
	t_client	*me;

	parse_args_client(ac, av);
	me = client_socket(ac, av);

	fd_set	client_fds;
	int		i;
	
	ft_bzero(&client_fds, sizeof(fd_set));
	
	while (1)
	{
		FD_ZERO(&client_fds);
		FD_SET(me->sockfd, &client_fds);
		FD_SET(1, &client_fds);
		ft_bzero(getbuff, BUFF_SIZE);
		i = 0;
		if (select(me->sockfd + 1, &client_fds, NULL, NULL, NULL) == -1)
			exit(errorcli(0, "Select", true));
		while (i < me->sockfd + 1)
		{
			if (FD_ISSET(i, &client_fds))
			{
				if (i == 1)
				{
					sendbuff = ft_strnew(100);
					ft_memset(sendbuff, '\0', 100);
					gnl(1, &sendbuff);
					sendbuff = ft_strjoin(sendbuff, "", 0);
					if (send(me->sockfd, sendbuff, ft_strlen(sendbuff), 0) == -1)
						exit(errorcli(0, "Send", false));
					free(sendbuff);
				}
				else
				{
					if (recv(me->sockfd, getbuff, BUFF_SIZE, 0) == -1)
						exit(1);
					ft_putendl_fd(getbuff, 1);
					if (!ft_strncmp(getbuff, "death\n", 6))
						exit(1);
				}
			}
			i++;
		}
	}
	close(me->sockfd);
	return (0);
}
