/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:46:27 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 11:47:39 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define AT(x, y) (WIN_WIDTH * (y) + (x))

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_coordd
{
	double	x;
	double	y;
}				t_coordd;

typedef struct	s_coord3d
{
	double x;
	double y;
	double z;
}				t_coord3d;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*image_ptr;
	int			*image;
	t_coordd	center;
	double		scale;
	int			(*colorf)(double);
	int			(*render_line)(struct s_env *env, int y);
	void		(*render_init)(struct s_env *env);
	t_coordd	julia_param;
	int			max_iterations;
	int			*redraw_mask;
	int			*image2;
	int			line;
	int			square;
}				t_env;

typedef	enum	e_key
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_MINUS = 78,
	KEY_PLUS = 69,
	KEY_PAGEUP = 116,
	KEY_PAGEDOWN = 121,
	KEY_SPACE = 49,
	KEY_ENTER = 36,
	KEY_P = 35
}				t_key;

/*
** From init.c
*/

int				init(t_env *env);

/*
** From ft.c
*/

int				ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strcmp(const char *s1, const char *s2);

/*
** From colors.c
*/

int				color_jet(double x);
int				color_terrain(double x);
int				color_fractal(double x);

/*
** From hooks.c
*/

int				hook_close(t_env *env);
int				hook_key(int key, t_env *env);
int				hook_loop(t_env *env);

/*
** Froom hooks_mouse.c
*/

int				hook_mouse_moved(int x, int y, t_env *env);
int				hook_mouse_wheel(int button, int x, int y, t_env *env);

/*
** From cleanup.c
*/

int				die(t_env *env);

/*
** From fractal_mandelbrot.c
*/

void			init_mandelbrot(t_env *env);
int				render_line_mandelbrot(t_env *env, int y);

/*
** From fractal_julia.c
*/

void			init_julia(t_env *env);
int				render_line_julia(t_env *env, int y);

/*
** From fractal_burning_ship.c
*/

void			init_burning_ship(t_env *env);
int				render_line_burning_ship(t_env *env, int y);

/*
** From fractal_alternate1.c
*/

void			init_alternate1(t_env *env);
int				render_line_alternate1(t_env *env, int y);

/*
** From fractal_alternate2.c
*/

void			init_alternate2(t_env *env);
int				render_line_alternate2(t_env *env, int y);

/*
** From fractal_alternate3.c
*/

void			init_alternate3(t_env *env);
int				render_line_alternate3(t_env *env, int y);

/*
** From draw.c
*/

void			clear_image(int *image, int color);
void			copy_image(int *img_dest, int *img_src);
void			draw_square(t_env *env);

/*
** From move.c
*/

void			translate(t_env *env, t_coord delta);
void			zoom(t_env *env, double zoom);

/*
** From complex1.c
*/

t_coordd		complex_multiply(t_coordd c1, t_coordd c2);
t_coordd		complex_add(t_coordd c1, t_coordd c2);
t_coordd		complex_inv(t_coordd c);

/*
** From complex2.c
*/

t_coordd		complex_exp(t_coordd c);
t_coordd		complex_sqrt(t_coordd c);
t_coordd		complex_sinh(t_coordd c);
t_coordd		complex_ln(t_coordd c);

#endif
