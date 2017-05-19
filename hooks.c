/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:29:03 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/17 13:08:10 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "bitmap.h"

int			hook_close(t_env *env)
{
	die(env);
	return (0);
}

static void	rotate_color(t_env *env)
{
	env->n_color = (env->n_color + 1) % N_COLORS;
	env->line = 0;
	clear_image(env->redraw_mask, 1);
}

int			hook_key(int key, t_env *env)
{
	if (key == KEY_ESC)
		die(env);
	if (key == KEY_PAGEUP)
		zoom(env, 1.5);
	if (key == KEY_PAGEDOWN)
		zoom(env, 1. / 1.5);
	if (key == KEY_UP)
		translate(env, (t_coord){0, -50});
	if (key == KEY_DOWN)
		translate(env, (t_coord){0, 50});
	if (key == KEY_LEFT)
		translate(env, (t_coord){-50, 0});
	if (key == KEY_RIGHT)
		translate(env, (t_coord){50, 0});
	if (key == KEY_RIGHT)
		translate(env, (t_coord){50, 0});
	if (key == KEY_P)
		save_bitmap("fractal.bmp", WIN_WIDTH, WIN_HEIGHT, env->image);
	if (key == KEY_SPACE)
		rotate_color(env);
	return (0);
}

static int	(*color_by_number(int n_color))(double)
{
	static int (*c_table[N_COLORS])(double) = {
		&color_fractal, &color_terrain, &color_jet,
		&color_grayscale, &color_red, &color_green, &color_blue};

	return (c_table[n_color]);
}

int			hook_loop(t_env *env)
{
	int i;
	int drawn;
	int (*colorf)(double);

	colorf = color_by_number(env->n_color);
	drawn = 0;
	i = 0;
	while (i < 10 && env->line < WIN_HEIGHT / 2)
	{
		drawn |= (*env->render_line)(env, WIN_HEIGHT / 2 + env->line, colorf);
		drawn |= (*env->render_line)(env, WIN_HEIGHT / 2 - 1 - env->line,
										colorf);
		env->line++;
		if (drawn != 0)
			i++;
	}
	mlx_put_image_to_window(env, env->mlx_win, env->image_ptr, 0, 0);
	draw_square(env);
	return (0);
}
