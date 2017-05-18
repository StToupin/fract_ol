/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:35:51 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 11:35:52 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

static void	hook_mouse_wheel_up(int x, int y, t_env *env)
{
	int a;

	a = env->square;
	if (x >= 0 && x < a && y >= 0 && y < a)
	{
		if (x < a / 2)
			env->julia_param.x += .00001 * WIN_WIDTH * env->scale;
		else
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

static void	hook_mouse_wheel_down(int x, int y, t_env *env)
{
	int a;

	a = env->square;
	if (x >= 0 && x < a && y >= 0 && y < a)
	{
		if (x < a / 2)
			env->julia_param.x -= .00001 * WIN_WIDTH * env->scale;
		else
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

int			hook_mouse_wheel(int button, int x, int y, t_env *env)
{
	if (button == 4)
		hook_mouse_wheel_up(x, y, env);
	if (button == 5)
		hook_mouse_wheel_down(x, y, env);
	return (0);
}
