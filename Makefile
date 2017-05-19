CC = gcc
CFLAGS = -Wall -Wextra -O3

NAME = fractol

SRC = ft.c move.c hooks.c hooks_mouse.c init_cleanup.c colors.c draw.c \
		complex1.c complex2.c bitmap.c \
		fractal_mandelbrot.c fractal_julia.c fractal_burning_ship.c \
		fractal_alternate1.c fractal_alternate2.c fractal_alternate3.c \
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
	norminette fract_ol.h bitmap.h $(SRC)

.PHONY: all clean fclean re norminette