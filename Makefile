CC = gcc
CFLAGS = -Wall -Wextra -O3

NAME = fract_ol

SRC = ft.c move.c hooks.c hooks_mouse.c cleanup.c init.c colors.c draw.c \
		complex1.c complex2.c alternate1.c alternate2.c alternate3.c \
		mandelbrot.c julia.c burning_ship.c fract_ol.c
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
	norminette fract_ol.h $(SRC)

.PHONY: all clean fclean re norminette