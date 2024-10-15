# Variables
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm
INCLUDES = -Iinclude -Iminilibx-linux  # Ajout du dossier de minilibx-linux
SRCS = errors.c floodfill.c data_init.c get_next_line_utils.c get_next_line.c hooks_utils.c hooks.c free.c main_utils.c main.c paint_map_utils.c paint_map.c parsing_utils.c parsing.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

# Règles

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) -g $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

