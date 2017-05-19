/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:54:17 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/17 13:10:02 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static inline int	in_image(t_coord c)
{
	return (c.x >= 0 && c.x < WIN_WIDTH && c.y >= 0 && c.y < WIN_HEIGHT);
}

static void			move_image(int *image, int *mask, t_coord delta)
{
	t_coord c_loop;
	t_coord c_new;
	t_coord c_old;

	c_loop = (t_coord){0, -1};
	while (++c_loop.y < WIN_HEIGHT)
	{
		c_new.y = (delta.y > 0) ? c_loop.y : (WIN_HEIGHT - c_loop.y - 1);
		c_loop.x = -1;
		while (++c_loop.x < WIN_WIDTH)
		{
			c_new.x = (delta.x > 0) ? c_loop.x : (WIN_WIDTH - c_loop.x - 1);
			c_old = (t_coord){c_new.x + delta.x, c_new.y + delta.y};
			if (in_image(c_old))
			{
				image[AT(c_new.x, c_new.y)] = image[AT(c_old.x, c_old.y)];
				mask[AT(c_new.x, c_new.y)] = mask[AT(c_old.x, c_old.y)];
			}
			else
			{
				image[AT(c_new.x, c_new.y)] = 0;
				mask[AT(c_new.x, c_new.y)] = 1;
			}
		}
	}
}

void				translate(t_env *env, t_coord delta)
{
	env->center.x += delta.x * env->scale;
	env->center.y += delta.y * env->scale;
	move_image(env->image, env->redraw_mask, delta);
	env->line = 0;
}

static void			zoom_image(int *image, int *image2, int *mask, double zoom)
{
	t_coord c_new;
	t_coord c_old;

	c_new.y = -1;
	while (++c_new.y < WIN_HEIGHT)
	{
		c_new.x = -1;
		while (++c_new.x < WIN_WIDTH)
		{
			c_old.x = (int)((c_new.x - WIN_WIDTH / 2) * zoom + WIN_WIDTH / 2);
			c_old.y = (int)((c_new.y - WIN_HEIGHT / 2) * zoom + WIN_HEIGHT / 2);
			if (in_image(c_old))
			{
				image2[AT(c_new.x, c_new.y)] = image[AT(c_old.x, c_old.y)];
				if (zoom > 1.)
					mask[AT(c_new.x, c_new.y)] = mask[AT(c_old.x, c_old.y)];
			}
			else
				image2[AT(c_new.x, c_new.y)] = 0;
		}
	}
	copy_image(image, image2);
}

void				zoom(t_env *env, double zoom)
{
	env->scale *= zoom;
	clear_image(env->redraw_mask, 1);
	zoom_image(env->image, env->image2, env->redraw_mask, zoom);
	env->line = 0;
}
