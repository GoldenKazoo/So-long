CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm
INCLUDES = -Iinclude -Iminilibx-linux
SRCS = srcs/data_init.c srcs/errors.c srcs/floodfill.c srcs/free.c \
		srcs/hooks_utils.c srcs/hooks.c srcs/main.c srcs/paint_map_utils.c \
		srcs/paint_map.c srcs/parsing_utils.c srcs/parsing.c srcs/utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		printf/ft_printf_nbr_utils.c printf/ft_printf_ptr.c \
		printf/ft_printf_utils.c printf/ft_printf.c

OBJS = $(SRCS:.c=.o)
NAME = so_long
DEBUG = -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
