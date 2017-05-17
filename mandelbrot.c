/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:04:00 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 14:05:17 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fract_ol.h"

void					init_mandelbrot(t_env *env)
{
	env->center = (t_coordd){-.75, 0.};
	env->scale = 3.5 / (double)WIN_WIDTH;
	env->square = 0;
}

static inline int		check_cardioid(t_coordd c)
{
	double				d;

	if ((c.x + 1.) * (c.x + 1.) + c.y * c.y < 1. / 16.)
		return (1);
	d = (c.x - .25) * (c.x - .25) + c.y * c.y;
	return (d * (d + (c.x - .25)) < .25 * c.y * c.y);
}

static inline double	render_pixel(t_coordd c0, int max_iterations)
{
	t_coordd			c;
	t_coordd			c2;
	int					iteration;
	t_coordd			ctemp;
	double				d;

	if (check_cardioid(c0))
		return (1.);
	c = (t_coordd){0., 0.};
	c2 = c;
	iteration = -1;
	while (c2.x + c2.y < 4 && ++iteration < max_iterations)
	{
		ctemp.x = c2.x - c2.y + c0.x;
		ctemp.y = 2. * c.x * c.y + c0.y;
		if (c.x == ctemp.x && c.y == ctemp.y)
			return (1.);
		c = ctemp;
		c2 = (t_coordd){c.x * c.x, c.y * c.y};
	}
	d = 0.;
	if (iteration < max_iterations)
		d = 1. - log(log(c2.x + c2.y) / 2. / log(2.)) / log(2.);
	d = ((double)(iteration) + d) / (double)max_iterations;
	return (log(1. + 20. * d) / log(20.));
}

int						render_line_mandelbrot(t_env *env, int y)
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
				env->colorf(render_pixel(cd, env->max_iterations));
			env->redraw_mask[AT(c.x, c.y)] = 0;
			drawn = 1;
		}
		c.x++;
	}
	return (drawn);
}
