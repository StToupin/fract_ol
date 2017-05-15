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
	env->center = (t_coordd){0., 0.};
	env->scale = 2. / (double)WIN_WIDTH;
	env->julia_param = (t_coordd){-.7, .27015};
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

void					render_julia(t_env *env)
{
	t_coord		c;
	t_coordd	cd;
	t_coordd	center;
	t_coordd	jp;
	double		scale;

	center = env->center;
	scale = env->scale;
	jp = env->julia_param;
	c = (t_coord){0, 0};
	while (c.y < WIN_HEIGHT)
	{
		c.x = 0;
		while (c.x < WIN_WIDTH)
		{
			cd = (t_coordd){center.x + scale * (c.x - WIN_WIDTH / 2),
							center.y + scale * (c.y - WIN_HEIGHT / 2)};
			env->image[WIN_WIDTH * c.y + c.x] =
				env->colorf(render_pixel(cd, jp, env->max_iterations));
			c.x++;
		}
		c.y++;
	}
}
