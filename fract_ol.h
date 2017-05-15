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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

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
	void		(*render)(struct s_env *env);
	void		(*render_init)(struct s_env *env);
	t_coordd	julia_param;
	int			max_iterations;
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
	KEY_ENTER = 36
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

/*
** From cleanup.c
*/

int				die(t_env *env);

/*
** From mandelbrot.c
*/

void			init_mandelbrot(t_env *env);
void			render_mandelbrot(t_env *env);

/*
** From julia.c
*/

void			init_julia(t_env *env);
void			render_julia(t_env *env);
/*
** From draw.c
*/

void			draw(t_env *env);

#endif