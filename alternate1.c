/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:04:00 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 14:05:17 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fract_ol.h"

void					init_alternate1(t_env *env)
{
	env->render_line = &render_line_alternate1;
	env->center = (t_coordd){0., 0.};
	env->scale = 4. / (double)WIN_WIDTH;
	env->square = 0;
	env->max_iterations = 512;
	env->julia_param = (t_coordd){-.621, 0.};
	env->square = WIN_WIDTH / 10.;
}

static inline double	render_pixel(t_coordd c0, t_coordd jp,
										int max_iterations)
{
	t_coordd			c;
	t_coordd			c2;
	int					iteration;
	t_coordd			ctemp;
	double				d;

	c = c0;
	c2 = (t_coordd){c.x * c.x, c.y * c.y};
	iteration = -1;
	while (c2.x + c2.y < 512 && ++iteration < max_iterations)
	{
		ctemp = complex_add(complex_exp(
							complex_multiply(complex_multiply(c, c), c)), jp);
		if (c.x == ctemp.x && c.y == ctemp.y)
			return (1.);
		c = ctemp;
		c2 = (t_coordd){c.x * c.x, c.y * c.y};
	}
	d = (double)(iteration) / (double)max_iterations;
	return (d);
}

int						render_line_alternate1(t_env *env, int y)
{
	t_coord		c;
	t_coordd	cd;
	t_coordd	center;
	double		scale;
	int			drawn;

	center = env->center;
	scale = env->scale;
	c = (t_coord){0, y};
	drawn = 0;
	while (c.x < WIN_WIDTH)
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
		c.x++;
	}
	return (drawn);
}
