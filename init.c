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

static int	init_mlx(t_env *env)
{
	int dum[3];

	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
		return (1);
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_WIDTH,
									WIN_HEIGHT, "fract_ol");
	if (env->mlx_win == NULL)
		return (1);
	env->image_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (env->image_ptr == NULL)
		return (1);
	env->image = (int*)mlx_get_data_addr(env->image_ptr, dum, dum + 1, dum + 2);
	if (env->image == NULL)
		return (1);
	clear_image(env->image, 0);
	mlx_hook(env->mlx_win, 17, 0, &hook_close, env);
	mlx_hook(env->mlx_win, 2, 0, &hook_key, env);
	mlx_loop_hook(env->mlx_ptr, &hook_loop, env);
	mlx_hook(env->mlx_win, 4, 0, &hook_mouse_wheel, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

int			init(t_env *env)
{
	int err;

	env->colorf = &color_fractal;
	env->max_iterations = 2048;
	env->line = 0;
	env->redraw_mask = (int*)malloc((WIN_WIDTH * WIN_HEIGHT) * sizeof(int));
	if (env->redraw_mask == NULL)
		return (1);
	clear_image(env->redraw_mask, 1);
	env->image2 = (int*)malloc((WIN_WIDTH * WIN_HEIGHT) * sizeof(int));
	if (env->image2 == NULL)
		return (1);
	(*(env->render_init))(env);
	err = init_mlx(env);
	if (err)
		return (err);
	return (0);
}
