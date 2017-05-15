/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:46:22 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/10 10:46:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
** These functions associate a color to a number between 0. and 1.
*/

int						color_jet(double x)
{
	t_coord3d	rgb;
	int			irgb;

	if (x == 1.)
		return (0);
	if (x < .25)
		rgb = (t_coord3d){0., 4. * x, 1.};
	else if (x < .5)
		rgb = (t_coord3d){0., 1., 1. + 4. * (.25 - x)};
	else if (x < .75)
		rgb = (t_coord3d){4. * (x + .5), 1., 0.};
	else
		rgb = (t_coord3d){1., 1. + 4. * (.75 - x), 0.};
	irgb = ((int)(255. * rgb.x) << 16)
			+ ((int)(255. * rgb.y) << 8)
			+ (int)(255. * rgb.z);
	return (irgb);
}

static inline t_coord3d	interp(t_coord3d c0, t_coord3d c1, double x)
{
	return (t_coord3d){(c1.x - c0.x) * x + c0.x,
						(c1.y - c0.y) * x + c0.y,
						(c1.z - c0.z) * x + c0.z};
}

int						color_terrain(double x)
{
	t_coord3d	c;
	int			rgb;

	if (x == 1.)
		return (0);
	if (x < .15)
		c = interp((t_coord3d){0.2, 0.2, 0.6}, (t_coord3d){0.0, 0.6, 1.0},
					x / .15);
	else if (x < .25)
		c = interp((t_coord3d){0.0, 0.6, 1.0}, (t_coord3d){0.0, 0.8, 0.4},
					(x - .15) / (.25 - .15));
	else if (x < .5)
		c = interp((t_coord3d){0.0, 0.8, 0.4}, (t_coord3d){1.0, 1.0, 0.6},
					(x - .25) / (.5 - .25));
	else if (x < .75)
		c = interp((t_coord3d){1.0, 1.0, 0.6}, (t_coord3d){0.5, 0.36, 0.33},
					(x - .5) / (.75 - .5));
	else
		c = interp((t_coord3d){0.5, 0.36, 0.33}, (t_coord3d){1.0, 1.0, 1.0},
					(x - .75) / (1. - .75));
	rgb = ((int)(255. * c.x) << 16)
			+ ((int)(255. * c.y) << 8)
			+ (int)(255. * c.z);
	return (rgb);
}

int						color_fractal(double x)
{
	t_coord3d	c;
	int			rgb;

	if (x < .16)
		c = interp((t_coord3d){0., 7., 100.}, (t_coord3d){32., 107., 203.},
					x / .16);
	else if (x < .42)
		c = interp((t_coord3d){32., 107., 203.}, (t_coord3d){237., 255., 255.},
					(x - .16) / (.42 - .16));
	else if (x < .6425)
		c = interp((t_coord3d){237., 255., 255.}, (t_coord3d){255., 170., 0.},
					(x - .42) / (.6425 - .42));
	else if (x < .8575)
		c = interp((t_coord3d){255., 170., 0.}, (t_coord3d){0., 2., 0.},
					(x - .6425) / (.8575 - .6425));
	else
		c = interp((t_coord3d){0., 2., 0.}, (t_coord3d){0., 0., 0.},
					(x - .8575) / (1. - .8575));
	rgb = ((int)c.x << 16) + ((int)c.y << 8) + (int)c.z;
	return (rgb);
}
