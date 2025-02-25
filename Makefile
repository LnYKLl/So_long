# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:03:58 by lkiloul           #+#    #+#              #
#    Updated: 2025/02/25 19:17:11 by lkiloul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = libs
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = game_init.c \
            keyhook.c \
            map_check.c \
			map_render.c \
            sprites.c \
            so_long.c \
            close.c \
			draw.c \
			map_valid.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INCLUDES = -I$(INC_DIR) -Imlx -I$(LIBFT_INC_DIR)

LIBS = -L$(LIBFT_DIR) -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(LIBS) $(NAME)

$(LIBS):
	@make -C $(LIBFT_DIR)
	@make -C  mlx/

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C mlx/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C mlx/ clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)