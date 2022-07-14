# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/07/14 12:28:13 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c \
		error_list.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
LINKS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
OBJECTS = $(SRC:.c=.o)

$(NAME): $(OBJECTS)
		@clear
		@make -C ./minilibx
		@$(CC) $(CFLAGS) $(LINKS) $(OBJECTS) -o $(NAME)
		@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
		@clear
		@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
		@rm -f $(OBJECTS)

fclean: clean
		make clean -C ./minilibx
		@rm -rf $(NAME)
		@rm -rf so_long
		@rm -rf libmlx.a

re: fclean all

.PHONY: all clean re