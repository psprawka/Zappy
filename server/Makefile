# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 23:21:55 by psprawka          #+#    #+#              #
#    Updated: 2018/06/14 12:42:05 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
FLAGS = -g -Wall -Wextra -Werror

HEADERS			= includes/
SRCS_DIR		= srcs/
COMMANDS		= commands/
PEVENT			= pevents/
PDEATH			= pdeaths/
BROADCAST		= broadcast/
LIST			= list/
EGG				= egg_system/

#to remove later
SRCS_CLIENT = $(SRCS_DIR)$(LIST)ft_lstlength.c	\
		$(SRCS_DIR)$(LIST)ft_lstnew.c	\
		$(SRCS_DIR)$(LIST)ft_lstadd.c	\
		$(SRCS_DIR)$(LIST)ft_lstutils.c	\
		$(SRCS_DIR)queue.c	\
		$(SRCS_DIR)client.c \
		$(SRCS_DIR)$(EGG)new_egg.c \
		$(SRCS_DIR)$(COMMANDS)connect_nbr.c \
		$(SRCS_DIR)$(COMMANDS)inventory.c \
		$(SRCS_DIR)$(COMMANDS)advance.c \
		$(SRCS_DIR)$(COMMANDS)levelup.c \
		$(SRCS_DIR)$(COMMANDS)death.c \
		$(SRCS_DIR)$(COMMANDS)right.c \
		$(SRCS_DIR)$(COMMANDS)left.c \
		$(SRCS_DIR)$(COMMANDS)kick.c \
		$(SRCS_DIR)$(COMMANDS)fork.c \
		$(SRCS_DIR)$(COMMANDS)take.c \
		$(SRCS_DIR)$(COMMANDS)put.c \
		$(SRCS_DIR)$(COMMANDS)see.c \
		$(SRCS_DIR)$(PEVENT)create_pevent.c \
		$(SRCS_DIR)$(PEVENT)push_pevent.c \
		$(SRCS_DIR)$(PEVENT)free_pevent.c \
		$(SRCS_DIR)$(PEVENT)add_pevent.c \
		$(SRCS_DIR)$(PEVENT)pop_pevent.c \
		$(SRCS_DIR)$(PEVENT)top_pevent.c \
		$(SRCS_DIR)$(PDEATH)top_pdeath.c \
		$(SRCS_DIR)$(PDEATH)pop_pdeath.c \
		$(SRCS_DIR)$(PDEATH)push_pdeath.c \
		$(SRCS_DIR)server_process.c \
		$(SRCS_DIR)init_structs.c \
		$(SRCS_DIR)graphical.c \
		$(SRCS_DIR)randomize.c \
		$(SRCS_DIR)player.c \
		$(SRCS_DIR)server.c \
		$(SRCS_DIR)teams.c \
		$(SRCS_DIR)tools.c \
		$(SRCS_DIR)parse.c \
		$(SRCS_DIR)time.c \
		$(SRCS_DIR)opt.c \
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)broadcast.c \
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)calcul_square.c

SRCS_SERVER = $(SRCS_DIR)$(LIST)ft_lstlength.c	\
		$(SRCS_DIR)$(LIST)ft_lstnew.c	\
		$(SRCS_DIR)$(EGG)new_egg.c \
		$(SRCS_DIR)$(LIST)ft_lstadd.c	\
		$(SRCS_DIR)$(LIST)ft_lstutils.c	\
		$(SRCS_DIR)queue.c	\
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)broadcast.c \
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)calcul_square.c \
		$(SRCS_DIR)$(COMMANDS)connect_nbr.c \
		$(SRCS_DIR)$(COMMANDS)inventory.c \
		$(SRCS_DIR)$(COMMANDS)advance.c \
		$(SRCS_DIR)$(COMMANDS)levelup.c \
		$(SRCS_DIR)$(COMMANDS)death.c \
		$(SRCS_DIR)$(COMMANDS)right.c \
		$(SRCS_DIR)$(COMMANDS)left.c \
		$(SRCS_DIR)$(COMMANDS)kick.c \
		$(SRCS_DIR)$(COMMANDS)fork.c \
		$(SRCS_DIR)$(COMMANDS)take.c \
		$(SRCS_DIR)$(COMMANDS)put.c \
		$(SRCS_DIR)$(COMMANDS)see.c \
		$(SRCS_DIR)$(PEVENT)create_pevent.c \
		$(SRCS_DIR)$(PEVENT)push_pevent.c \
		$(SRCS_DIR)$(PEVENT)free_pevent.c \
		$(SRCS_DIR)$(PEVENT)add_pevent.c \
		$(SRCS_DIR)$(PEVENT)pop_pevent.c \
		$(SRCS_DIR)$(PEVENT)top_pevent.c \
		$(SRCS_DIR)$(PDEATH)top_pdeath.c \
		$(SRCS_DIR)$(PDEATH)pop_pdeath.c \
		$(SRCS_DIR)$(PDEATH)push_pdeath.c \
		$(SRCS_DIR)server_process.c \
		$(SRCS_DIR)init_structs.c \
		$(SRCS_DIR)graphical.c \
		$(SRCS_DIR)randomize.c \
		$(SRCS_DIR)player.c \
		$(SRCS_DIR)server.c \
		$(SRCS_DIR)teams.c \
		$(SRCS_DIR)tools.c \
		$(SRCS_DIR)parse.c \
		$(SRCS_DIR)main.c \
		$(SRCS_DIR)time.c \
		$(SRCS_DIR)opt.c	\


OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

LIBFT = libft/libft.a

BUILD_PRINT = @echo "\r\033[K\033[0;38;5;206m[ZAPPY] \033[38;5;80mBuilding $<"
DONE_CLIENT = @echo "\033[K\033[1;38;5;44mCLIENT\033[K\033[1;38;5;200m ready to use!"
DONE_SERVER = @echo "\033[K\033[1;38;5;44mSERVER\033[K\033[1;38;5;200m ready to use!"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [ZAPPY]"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [ZAPPY]"

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(LIBFT) $(OBJS_CLIENT) $(HEADERS)
		@gcc $(FLAGS) -I $(HEADERS) $(OBJS_CLIENT) $(LIBFT) -lncurses -o $(NAME_CLIENT)
		$(DONE_CLIENT)

$(NAME_SERVER) : $(LIBFT) $(OBJS_SERVER) $(HEADERS)
		@gcc $(FLAGS) -I $(HEADERS) $(OBJS_SERVER) $(LIBFT) -lncurses -o $(NAME_SERVER)
		$(DONE_SERVER)

$(LIBFT):
	@make -C libft
	@echo ""

%.o: %.c
	$(BUILD_PRINT)
	@gcc -g $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(CLEAN_O)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(CLEAN_A)

re: fclean all
