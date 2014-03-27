/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/27 14:56:03 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<stdlib.h>
#include	<rtfinal.h>

void		move_eye(t_xyz *eye, t_xyz *vector, t_obj *tmp, int invert)
{
	if (invert == 1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
	eye->x += invert * tmp->pos.x;
	eye->y += invert * tmp->pos.y;
	eye->z += invert * tmp->pos.z;
	vector->x += invert * tmp->pos.x;
	vector->y += invert * tmp->pos.y;
	vector->z += invert * tmp->pos.z;
	if (invert == -1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
}

void		calc_curobj(t_xyz *eye, t_xyz *vector, t_obj *obj, double *k)
{
	int		i;
	t_type	type[NB_OBJ - 2] = {SPHERE, CYLIND, CONE, PLANE, HYPERB, PARAB};
	t_calc	ptr[NB_OBJ - 2] = {&calc_sphere, &calc_cylinder, &calc_cone,
								&calc_plane, &calc_hyperb, &calc_parab};

	move_eye(eye, vector, obj, -1);
	i = 0;
	while (i < NB_OBJ - 2)
	{
		if (obj->type == type[i])
			(ptr[i])(eye, vector, k, obj);
		++i;
	}
	move_eye(eye, vector, obj, 1);
}

void	calculus(t_mlx *mlx, t_scene *scene, t_int *color)
{
		all_rot(&scene->camera->pos, &scene->camera->rot, 1);
		all_rot(&mlx->vector, &scene->camera->rot, 1);
		*color = calc_all_lights(mlx, scene);
		all_rot(&scene->camera->pos, &scene->camera->rot, -1);
		all_rot(&mlx->vector, &scene->camera->rot, -1);
}

void	calc_inter(int x, int y, t_mlx *mlx, t_scene *scene)
{
	double	k[2];
	t_obj	*tmp;
	t_int	color;

	mlx->k = 0xFFFFFFFF;
	mlx->cur_obj = NULL;
	tmp = scene->objs;
	while (tmp)
	{
		all_rot(&scene->camera->pos, &scene->camera->rot, 1);
		all_rot(&mlx->vector, &scene->camera->rot, 1);
		calc_curobj(&scene->camera->pos, &mlx->vector, tmp, k);
		all_rot(&scene->camera->pos, &scene->camera->rot, -1);
		all_rot(&mlx->vector, &scene->camera->rot, -1);
		if (k[0] >= 0 && mlx->k > k[0] && (mlx->cur_obj = tmp))
			mlx->k = k[0];
		if (k[1] >= 0 && mlx->k > k[1] && (mlx->cur_obj = tmp))
			mlx->k = k[1];
		tmp = tmp->next;
	}
	if (mlx->cur_obj != NULL)
	{
		calculus(mlx, scene, &color);
		pxl_putimg(mlx, x, y, color);
	}
}

void	calc_ray_xy(int x, int y, t_mlx *mlx, t_scene *scene)
{
	mlx->plane.x = 100;
	mlx->plane.y = (WIN_X / 2.0) - x;
	mlx->plane.z = (WIN_Y / 2.0) - y;
	mlx->vector.x = mlx->plane.x - scene->camera->pos.x;
	mlx->vector.y = mlx->plane.y - scene->camera->pos.z;
	mlx->vector.z = mlx->plane.z - scene->camera->pos.z;
	calc_inter(x, y, mlx, scene);
}

