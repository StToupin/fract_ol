/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:29:03 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 15:29:04 by stoupin          ###   ########.fr       */
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
		env->scale *= 1.1;
	if (key == KEY_PAGEDOWN)
		env->scale /= 1.1;
	if (key == KEY_UP)
		env->center.y -= env->scale * 20.;
	if (key == KEY_DOWN)
		env->center.y += env->scale * 20.;
	if (key == KEY_LEFT)
		env->center.x -= env->scale * 20.;
	if (key == KEY_RIGHT)
		env->center.x += env->scale * 20.;
	draw(env);
	return (0);
}

int			hook_scroll_up(t_env *env)
{
	env->scale *= 1.1;
	return (0);
}

int			hook_scroll_down(t_env *env)
{
	env->scale /= 1.1;
	return (0);
}
