/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:25:33 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/17 13:10:03 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"

void				clear_image(int *image, int color)
{
	int i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
		image[i++] = color;
}

void				copy_image(int *img_dest, int *img_src)
{
	int i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		img_dest[i] = img_src[i];
		i++;
	}
}

static inline void	draw_pixel(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx_ptr, env->mlx_win, x, y, color);
}

void				draw_square(t_env *env)
{
	int					i;
	int					a;
	static const int	square_color = 0xffffff;

	a = env->square;
	i = 0;
	while (i < a)
	{
		draw_pixel(env, i, a, square_color);
		draw_pixel(env, a, i, square_color);
		draw_pixel(env, a / 2, i, square_color);
		i++;
	}
}
