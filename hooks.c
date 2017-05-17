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

int			hook_close(t_env *env)
{
	die(env);
	return (0);
}

int			hook_key(int key, t_env *env)
{
	if (key == KEY_ESC)
		die(env);
	if (key == KEY_PAGEUP)
		zoom(env, 2.);
	if (key == KEY_PAGEDOWN)
		zoom(env, .5);
	if (key == KEY_UP)
		translate(env, (t_coord){0, -50});
	if (key == KEY_DOWN)
		translate(env, (t_coord){0, 50});
	if (key == KEY_LEFT)
		translate(env, (t_coord){-50, 0});
	if (key == KEY_RIGHT)
		translate(env, (t_coord){50, 0});
	env->line = 0;
	return (0);
}

int			hook_loop(t_env *env)
{
	int i;
	int drawn;

	drawn = 0;
	i = 0;
	while (i < 10 && env->line < WIN_HEIGHT / 2)
	{
		drawn |= (*env->render_line)(env, WIN_HEIGHT / 2 + env->line);
		drawn |= (*env->render_line)(env, WIN_HEIGHT / 2 - 1 - env->line);
		env->line++;
		if (drawn != 0)
			i++;
	}
	mlx_put_image_to_window(env, env->mlx_win, env->image_ptr, 0, 0);
	return (0);
}

int			hook_mouse_moved(int x, int y, t_env *env)
{
	int a;

	a = env->square;
	if (x >= 0 && x < a && y >= 0 && y < a)
	{
		env->julia_param = (t_coordd){2. * (double)x / (double)a - 1.,
									2. * (double)y / (double)a - 1.};
		clear_image(env->redraw_mask, 1);
		env->line = 0;
	}
	return (0);
}

int			hook_mouse_wheel(int button, int x, int y, t_env *env)
{
	int a;

	a = env->square;
	if (button == 4)
	{
		if (x >= 0 && x < a && y >= 0 && y < a)
		{
			env->julia_param.y += .00001 * WIN_WIDTH * env->scale;
			clear_image(env->redraw_mask, 1);
		}
		else
		{
			translate(env, (t_coord){.1 * (WIN_WIDTH / 2 - x),
										.1 * (WIN_HEIGHT / 2 - y)});
			zoom(env, 1.1);
		}
		env->line = 0;
	}
	if (button == 5)
	{
		if (x >= 0 && x < a && y >= 0 && y < a)
		{
			env->julia_param.y -= .00001 * WIN_WIDTH * env->scale;
			clear_image(env->redraw_mask, 1);
		}
		else
		{
			translate(env, (t_coord){.1 * (x - WIN_WIDTH / 2),
										.1 * (y - WIN_HEIGHT / 2)});
			zoom(env, 1. / 1.1);
		}
		env->line = 0;
	}
	if (button == 6 && x >= 0 && x < a && y >= 0 && y < a)
	{
		env->julia_param.x += .01;
		clear_image(env->redraw_mask, 1);
	}
	if (button == 7 && x >= 0 && x < a && y >= 0 && y < a)
	{
		env->julia_param.x -= .0001;
		clear_image(env->redraw_mask, 1);
	}
	return (0);
}
