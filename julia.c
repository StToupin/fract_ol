/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:47:36 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 16:47:40 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fract_ol.h"

void					init_julia(t_env *env)
{
	env->render_line = &render_line_julia;
	env->center = (t_coordd){0., 0.};
	env->scale = 3.5 / (double)WIN_WIDTH;
	env->julia_param = (t_coordd){-.8, .156};
	env->square = WIN_WIDTH / 10.;
}

static inline double	render_pixel(t_coordd c, t_coordd jp,
										int max_iterations)
{
	t_coordd			c_last;
	t_coordd			c2;
	int					iteration;

	iteration = 0;
	c2 = (t_coordd){c.x * c.x, c.y * c.y};
	while (c2.x + c2.y < 4 && iteration < max_iterations)
	{
		c_last = c;
		c = (t_coordd){c2.x - c2.y + jp.x, 2. * c.x * c.y + jp.y};
		if (c.x == c_last.x && c.y == c_last.y)
			return (1.);
		c2 = (t_coordd){c.x * c.x, c.y * c.y};
		iteration++;
	}
	return ((double)iteration / max_iterations);
}

int						render_line_julia(t_env *env, int y)
{
	t_coord		c;
	t_coordd	cd;
	t_coordd	center;
	double		scale;
	int			drawn;

	center = env->center;
	scale = env->scale;
	drawn = 0;
	c = (t_coord){-1, y};
	while (++c.x < WIN_WIDTH)
	{
		if (env->redraw_mask[AT(c.x, c.y)] == 1)
		{
			cd = (t_coordd){center.x + scale * (c.x - WIN_WIDTH / 2),
							center.y + scale * (c.y - WIN_HEIGHT / 2)};
			env->image[AT(c.x, c.y)] =
				env->colorf(render_pixel(cd, env->julia_param,
											env->max_iterations));
			env->redraw_mask[AT(c.x, c.y)] = 0;
			drawn = 1;
		}
	}
	return (drawn);
}
