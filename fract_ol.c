/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:48:51 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 11:49:01 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	print_usage(char *command)
{
	ft_putstr_fd("Usage : ", 1);
	ft_putstr_fd(command, 1);
	ft_putstr_fd(" fractal\n", 1);
	ft_putstr_fd("fractal must be either mandelbrot or julia\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		err;
	int		julia;

	if (argc != 2)
		return (print_usage(argv[0]));
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		env.render_init = &init_mandelbrot;
		env.render_line = &render_line_mandelbrot;
		julia = 0;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		env.render_init = &init_julia;
		env.render_line = &render_line_julia;
		julia = 1;
	}
	else
		return (print_usage(argv[0]));
	err = init(&env);
	if (err)
		return (ft_putstr_fd("Error\n", 2));
	return (0);
}
