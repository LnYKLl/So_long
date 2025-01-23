CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes

SRC_FILES = game_init.c \
            get_next_line.c \
            get_next_line_utils.c \
            keyhook.c \
            map.c \
            sprites.c \
            so_long.c \
            ft_close.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INCLUDES = -I$(INC_DIR) -Imlx

LIBS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re