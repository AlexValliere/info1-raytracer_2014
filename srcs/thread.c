/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 20:31:58 by qde-vial          #+#    #+#             */
/*   Updated: 2014/03/23 14:42:05 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<rtfinal.h>
#include	<stdlib.h>


void		*calc_thread1(void *para_th)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIN_X / 2)
	{
		y = -1;
		while (++y < WIN_Y / 2)
			calc_ray_xy(x, y, ((t_thrd *)para_th)->mlx, ((t_thrd *)para_th)->scene);
	}
	return (NULL);
}



void		*calc_thread2(void *para_th)
{
	int		x;
	int		y;

	x = (WIN_X / 2) - 1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y / 2)
			calc_ray_xy(x, y, ((t_thrd *)para_th)->mlx, ((t_thrd *)para_th)->scene);
	}
	return (NULL);
}



void		*calc_thread3(void *para_th)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIN_X / 2)
	{
		y = WIN_Y / 2 - 1;
		while (++y < WIN_Y)
			calc_ray_xy(x, y, ((t_thrd *)para_th)->mlx, ((t_thrd *)para_th)->scene);
	}
	return (NULL);
}

void		*calc_thread4(void *para_th)
{
	int		x;
	int		y;

	x = (WIN_X / 2) - 1;
	while (++x < WIN_X)
	{
		y = WIN_Y / 2 - 1;
		while (++y < WIN_Y)
			calc_ray_xy(x, y, ((t_thrd *)para_th)->mlx, ((t_thrd *)para_th)->scene);
	}
	return (NULL);
}


