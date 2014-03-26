/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:10:10 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/26 17:26:48 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<rtfinal.h>

static void	set_vectors(t_mlx *mlx, t_xyz *spot, t_xyz *p, t_xyz *light)
{
	*p = (t_xyz){mlx->cur_scene->camera->pos.x + mlx->k * mlx->vector.x,
				mlx->cur_scene->camera->pos.y + mlx->k * mlx->vector.y,
				mlx->cur_scene->camera->pos.z + mlx->k * mlx->vector.z};
	*light = (t_xyz){spot->x - p->x, spot->y - p->y, spot->z - p->z};
}

int			shadow_cast(t_mlx *mlx, t_xyz *spot)
{
	t_xyz	p;
	t_xyz	light;
	double	new_k;
	double	k[2];
	t_obj	*tmp;

	set_vectors(mlx, spot, &p, &light);
	new_k = -1;
	tmp = mlx->cur_scene->objs;
	while (tmp)
	{
		if (tmp != mlx->cur_obj)
		{
			calc_curobj(&p, &light, tmp, k);
			new_k = (k[0] > 0.1 && k[0] < 0.9 ? k[0] : new_k);
			new_k = (k[1] > 0.1 && k[1] < 0.9 ? k[1] : new_k);
		}
		tmp = tmp->next;
	}
	if (new_k != -1)
		return (1);
	return (0);
}
