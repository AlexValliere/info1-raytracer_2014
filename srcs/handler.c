/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 01:56:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/21 16:07:59 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<mlx.h>
#include		"rtfinal.h"

#include <stdio.h>
int				get_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_QUIT)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, mlx->cur_scene->img.ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_RIGHT)
		mlx->cur_scene = mlx->cur_scene->next;
	else if (keycode == KEY_LEFT)
		mlx->cur_scene = mlx->cur_scene->prev;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		mlx_put_image_to_window(mlx->ptr, mlx->win,
								mlx->cur_scene->img.ptr, 0, 0);
	return (0);
}

int				get_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win,
							mlx->cur_scene->img.ptr, 0, 0);
	return (0);
}
