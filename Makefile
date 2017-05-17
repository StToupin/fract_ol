CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = fract_ol

SRC = ft.c move.c hooks.c cleanup.c init.c colors.c mandelbrot.c julia.c draw.c \
		fract_ol.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ -lmlx -lm \
		-framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette *.h $(SRC)

.PHONY: all clean fclean re norminette