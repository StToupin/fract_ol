/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:40:12 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 17:40:14 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fract_ol.h"

t_coordd			complex_exp(t_coordd c)
{
	t_coordd	exp_c;
	double		exp_x;

	exp_x = exp(c.x);
	exp_c.x = exp_x * cos(c.y);
	exp_c.y = exp_x * sin(c.y);
	return (exp_c);
}

static inline int	ft_sign(double x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

t_coordd			complex_sqrt(t_coordd c)
{
	double		n;
	t_coordd	c_sqrt;

	n = sqrt(c.x * c.x + c.y * c.y);
	c_sqrt.x = sqrt(2. * (c.x + n)) / 2. * ft_sign(c.x);
	c_sqrt.y = sqrt(2. * (n - c.x)) / 2. * ft_sign(c.y);
	return (c_sqrt);
}

t_coordd			complex_sinh(t_coordd c)
{
	t_coordd c_sinh;

	c_sinh.x = sinh(c.x) * cos(c.y);
	c_sinh.y = cosh(c.x) * sin(c.y);
	return (c_sinh);
}

t_coordd			complex_ln(t_coordd c)
{
	t_coordd	c_ln;

	c_ln.x = log(c.x * c.x + c.y * c.y) / 2.;
	c_ln.y = atan(c.y / c.x);
	return (c_ln);
}
