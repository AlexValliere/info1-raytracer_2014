/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 01:56:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/19 01:36:51 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<mlx.h>
#include		"rtfinal.h"

int				get_keypress(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == KEY_QUIT)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_image(mlx->ptr, mlx->screen.ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int				get_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->screen.ptr, 0, 0);
	return (0);
}
