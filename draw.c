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
