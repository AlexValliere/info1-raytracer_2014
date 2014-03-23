/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:19:47 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/23 14:35:57 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	<math.h>
#include	<rtfinal.h>
#include	<pthread.h>

void		pxl_putimg(t_mlx *mlx, int x, int y, u_int color)
{
	int		i;
	int		dest;
	u_int	new_color;

	new_color = mlx_get_color_value(mlx->ptr, color);
	dest = y * mlx->cur_scene->img.sline + x * mlx->cur_scene->img.bpp;
	i = -1;
	while (++i < mlx->cur_scene->img.bpp)
	{
		if (mlx->cur_scene->img.endian == 0)
			mlx->cur_scene->img.data[dest + i] = new_color >> (i << 3) & 0xFF;
		else
			mlx->cur_scene->img.data[dest + i] = new_color
				>> (mlx->cur_scene->img.bpp - ((i + 1) << 3)) & 0xFF;
	}
}
