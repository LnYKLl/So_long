# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 02:10:11 by lkiloul           #+#    #+#              #
#    Updated: 2025/01/21 02:27:26 by lkiloul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -lXext -lX11
SRC = keyhook.c get_next_line.c get_next_line_utils.c ft_close.c map.c sprites.c game_init.c
OBJ = $(SRC:.c=.o)
INCLUDES = -I /usr/include -I /usr/local/include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(INCLUDES) -L /usr/local/lib -lmlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re