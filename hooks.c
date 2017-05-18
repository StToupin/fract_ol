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
	draw_square(env);
	return (0);
}
