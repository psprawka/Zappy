# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 11:51:37 by psprawka          #+#    #+#              #
#    Updated: 2018/05/22 14:12:03 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/
PRINTF_DIR = ft_printf/srcs/

HEADERS = ./includes

SRC = $(SRC_DIR)ft_atoi.c \
	$(SRC_DIR)ft_bzero.c \
	$(SRC_DIR)ft_convert_hex.c \
	$(SRC_DIR)ft_convert_octal.c \
	$(SRC_DIR)ft_convert_uni.c \
	$(SRC_DIR)ft_ftoa.c \
	$(SRC_DIR)ft_itoa.c \
	$(SRC_DIR)ft_memalloc.c \
	$(SRC_DIR)ft_memset.c \
	$(SRC_DIR)ft_putchar_fd.c \
	$(SRC_DIR)ft_putendl_fd.c \
	$(SRC_DIR)ft_strncat.c \
	$(SRC_DIR)ft_strchr.c \
	$(SRC_DIR)ft_strcmp.c \
	$(SRC_DIR)ft_strdup.c \
	$(SRC_DIR)ft_strjoin.c \
	$(SRC_DIR)ft_strlen.c \
	$(SRC_DIR)ft_strlen_chr.c \
	$(SRC_DIR)ft_strncmp.c \
	$(SRC_DIR)ft_strncpy.c \
	$(SRC_DIR)ft_strnew.c \
	$(SRC_DIR)ft_strrev.c \
	$(SRC_DIR)ft_strstr.c \
	$(SRC_DIR)ft_strsub.c \
	$(SRC_DIR)ft_wstrlen.c \
	$(SRC_DIR)gnl.c \

SRC_PRINTF = $(PRINTF_DIR)atoi_and_ulltoa.c \
		$(PRINTF_DIR)ft_printf.c \
		$(PRINTF_DIR)print.c \
		$(PRINTF_DIR)conversion.c \
		$(PRINTF_DIR)gather_flags.c \
		$(PRINTF_DIR)str_chr.c \
		$(PRINTF_DIR)ptr_dbl.c \
		$(PRINTF_DIR)int_uint.c \
		$(PRINTF_DIR)indirect_ft.c \
		$(PRINTF_DIR)ft_libftprintf.c \

OBJ += $(SRC:.c=.o)
OBJ += $(SRC_PRINTF:.c=.o)

BUILD_PRINT = @echo "\r\033[38;5;214m[LIBFT] \x1B[33mBuilding $<"
DONE = @echo "\033[K\033[1;38;5;226mLIBFT ready to use!"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [LIBFT]"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [LIBFT]"


all: $(NAME)

$(OBJ): %.o: %.c
	$(BUILD_PRINT)
	@gcc $(FLAGS) -I $(HEADERS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(DONE)

clean:
	@/bin/rm -rf $(OBJ)
	$(CLEAN_O)

fclean: clean
	@/bin/rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all

.PHONY: all clean fclean re
