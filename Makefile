# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/07/27 18:01:11 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = ./so_long.c \
		./srcs/error_list.c \
		./srcs/ft_bzero.c \
		./srcs/ft_calloc.c \
		./srcs/ft_split.c \
		./srcs/ft_strlen.c \
		./srcs/ft_substr.c \
		./srcs/get_map.c \
		./srcs/free_and_exit.c \
		./srcs/put_images_in_game.c \
		./srcs/keyboard_controls.c \
		./srcs/get_next_line/get_next_line.c \
		./srcs/get_next_line/get_next_line_utils.c
		
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
LINKS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
OBJECTS = $(SRC:.c=.o)

$(NAME): $(OBJECTS)
		@clear
		@make -C minilibx
		@$(CC) $(CFLAGS) $(LINKS) $(OBJECTS) -I include/ -o $(NAME)
		@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@make clean -C ./minilibx
	@rm -rf $(NAME)
	@rm -rf so_long
	@rm -rf libmlx.a

re: fclean all

.PHONY: all clean re