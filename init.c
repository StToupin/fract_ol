/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:49:06 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/15 11:49:08 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fract_ol.h"

int	init(t_env *env)
{
	int dum[3];

	env->colorf = &color_fractal;
	env->mlx_ptr = mlx_init();
	env->max_iterations = 1024;
	if (env->mlx_ptr == NULL)
		return (1);
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_WIDTH,
									WIN_HEIGHT, "fdf");
	if (env->mlx_win == NULL)
		return (1);
	env->image_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (env->image_ptr == NULL)
		return (1);
	env->image = (int*)mlx_get_data_addr(env->image_ptr, dum, dum + 1, dum + 2);
	(*(env->render_init))(env);
	mlx_hook(env->mlx_win, 17, 0, &hook_close, env);
	mlx_hook(env->mlx_win, 2, 0, &hook_key, env);
	draw(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
