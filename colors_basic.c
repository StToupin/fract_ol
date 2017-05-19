/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:19:57 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/12 12:19:58 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	color_grayscale(double x)
{
	int rgb;

	if (x == 1.)
		return (0);
	rgb = (int)(x * 255);
	rgb = (rgb << 16) + (rgb << 8) + rgb;
	return (rgb);
}

int	color_red(double x)
{
	int rgb;

	if (x == 1.)
		return (0);
	rgb = (int)(x * 255);
	rgb <<= 16;
	return (rgb);
}

int	color_green(double x)
{
	int rgb;

	if (x == 1.)
		return (0);
	rgb = (int)(x * 255);
	rgb <<= 8;
	return (rgb);
}

int	color_blue(double x)
{
	int rgb;

	if (x == 1.)
		return (0);
	rgb = (int)(x * 255);
	return (rgb);
}
