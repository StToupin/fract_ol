/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:54:27 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:54:28 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fract_ol.h"
#include "mlx.h"

int		die(t_env *env)
{
	if (env->image_ptr != NULL)
		mlx_destroy_image(env->mlx_ptr, env->image_ptr);
	if (env->mlx_win != NULL)
		mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	if (env->redraw_mask != NULL)
		free(env->redraw_mask);
	exit(0);
}
