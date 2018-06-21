# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 23:21:55 by psprawka          #+#    #+#              #
#    Updated: 2018/06/21 04:49:25 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
FLAGS = -g -Wall -Wextra -Werror
#FLAGS +=  -fsanitize=address

HEADERS		= includes/
SRCS_DIR	= srcs/
COMMANDS	= commands/
BROADCAST	= broadcast/
SEE			= see/
FORK		= fork/
HANDLE		= handle/
PARSE		= parse/
TOOLS		= server_tools/
STRUCTS		= init/
GRAPHICAL	= graphical_commands/

#to remove later
SRCS_CLIENT = $(SRCS_DIR)testing/clienttest.c

SRCS_SERVER = $(SRCS_DIR)main.c \
		$(SRCS_DIR)client.c \
		$(SRCS_DIR)free.c \
		$(SRCS_DIR)time.c \
		$(SRCS_DIR)teams.c \
		$(SRCS_DIR)queue.c \
		$(SRCS_DIR)event.c \
		$(SRCS_DIR)execute.c \
		$(SRCS_DIR)graphical.c \
		$(SRCS_DIR)$(PARSE)opt.c \
		$(SRCS_DIR)$(PARSE)parse.c \
		$(SRCS_DIR)$(TOOLS)tools.c \
		$(SRCS_DIR)$(TOOLS)randomize.c \
		$(SRCS_DIR)$(TOOLS)generator.c \
		$(SRCS_DIR)$(HANDLE)handle.c \
		$(SRCS_DIR)$(HANDLE)handle_ai.c \
		$(SRCS_DIR)$(HANDLE)handle_graphic.c \
		$(SRCS_DIR)$(HANDLE)handle_nondef.c \
		$(SRCS_DIR)$(STRUCTS)init_map.c \
		$(SRCS_DIR)$(STRUCTS)init_server.c \
		$(SRCS_DIR)$(STRUCTS)init_player.c \
		$(SRCS_DIR)$(COMMANDS)connect_nbr.c \
		$(SRCS_DIR)$(COMMANDS)inventory.c \
		$(SRCS_DIR)$(COMMANDS)advance.c \
		$(SRCS_DIR)$(COMMANDS)incantation.c \
		$(SRCS_DIR)$(COMMANDS)levelup.c \
		$(SRCS_DIR)$(COMMANDS)death.c \
		$(SRCS_DIR)$(COMMANDS)right.c \
		$(SRCS_DIR)$(COMMANDS)left.c \
		$(SRCS_DIR)$(COMMANDS)kick.c \
		$(SRCS_DIR)$(COMMANDS)take.c \
		$(SRCS_DIR)$(COMMANDS)put.c \
		$(SRCS_DIR)$(COMMANDS)eat.c \
		$(SRCS_DIR)$(COMMANDS)egg_death.c \
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)broadcast.c \
		$(SRCS_DIR)$(COMMANDS)$(BROADCAST)calcul_square.c \
		$(SRCS_DIR)$(COMMANDS)$(FORK)fork.c \
		$(SRCS_DIR)$(COMMANDS)$(FORK)egg.c \
		$(SRCS_DIR)$(COMMANDS)$(FORK)hatch.c \
		$(SRCS_DIR)$(COMMANDS)$(SEE)see.c \
		$(SRCS_DIR)$(COMMANDS)$(SEE)rotation.c \
		$(SRCS_DIR)$(COMMANDS)$(SEE)put_in_buffer.c \
		$(SRCS_DIR)$(GRAPHICAL)egg/ebo.c \
		$(SRCS_DIR)$(GRAPHICAL)egg/edi.c \
		$(SRCS_DIR)$(GRAPHICAL)egg/eht.c \
		$(SRCS_DIR)$(GRAPHICAL)egg/enw.c \
		$(SRCS_DIR)$(GRAPHICAL)map/bct.c \
		$(SRCS_DIR)$(GRAPHICAL)map/msz.c \
		$(SRCS_DIR)$(GRAPHICAL)map/tna.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pbc.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pdi.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pdr.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pex.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pfk.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pgt.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pic.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pie.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pin.c \
		$(SRCS_DIR)$(GRAPHICAL)player/plv.c \
		$(SRCS_DIR)$(GRAPHICAL)player/pnw.c \
		$(SRCS_DIR)$(GRAPHICAL)player/ppo.c \
		$(SRCS_DIR)$(GRAPHICAL)server_info/sbp.c \
		$(SRCS_DIR)$(GRAPHICAL)server_info/seg.c \
		$(SRCS_DIR)$(GRAPHICAL)server_info/sgt.c \
		$(SRCS_DIR)$(GRAPHICAL)server_info/smg.c \
		$(SRCS_DIR)$(GRAPHICAL)server_info/suc.c \
		$(SRCS_DIR)$(GRAPHICAL)graphic_greeting.c \
		$(SRCS_DIR)testing/test.c \


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
