/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:40:07 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 17:40:09 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coordd	complex_multiply(t_coordd c1, t_coordd c2)
{
	t_coordd c;

	c.x = c1.x * c2.x - c1.y * c2.y;
	c.y = c1.x * c2.y + c1.y * c2.x;
	return (c);
}

t_coordd	complex_add(t_coordd c1, t_coordd c2)
{
	t_coordd c;

	c.x = c1.x + c2.x;
	c.y = c1.y + c2.y;
	return (c);
}

t_coordd	complex_inv(t_coordd c)
{
	t_coordd	inv_c;
	double		n;

	n = c.x * c.x + c.y * c.y;
	inv_c.x = c.x / n;
	inv_c.y = -c.y / n;
	return (inv_c);
}
