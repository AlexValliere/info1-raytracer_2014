/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/23 16:53:38 by ptran            ###   ########.fr       */
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
	move_eye(eye, vector, obj, -1);
	if (obj->type == SPHERE)
		calc_sphere(eye, vector, k, obj);
	else if (obj->type == CYLIND)
		calc_cylinder(eye, vector, k, obj);
	else if (obj->type == CONE)
		calc_cone(eye, vector, k, obj);
	else if (obj->type == PLANE)
		calc_plane(eye, vector, k, obj);
	move_eye(eye, vector, obj, 1);
}

static void	calc_inter(int x, int y, t_mlx *mlx, t_scene *scene)
{
	double	k[2];
	t_obj	*tmp;
	u_int	color;

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
		all_rot(&scene->camera->pos, &scene->camera->rot, 1);
		all_rot(&mlx->vector, &scene->camera->rot, 1);
		color = calc_light(mlx, mlx->cur_scene->spots);
		all_rot(&scene->camera->pos, &scene->camera->rot, -1);
		all_rot(&mlx->vector, &scene->camera->rot, -1);
/*
		color = add_2color(color, calc_light(mlx, &mlx->spot2));
		color = mult_color(color, 0.7);
		color = shadow_cast(mlx, &mlx->spot, color);
		color = shadow_cast(mlx, &mlx->spot2, color);
*/

		pxl_putimg(mlx, x, y, color);
	}
}

static void	calc_ray_xy(int x, int y, t_mlx *mlx, t_scene *scene)
{
	mlx->plane.x = 100; /* a changer?? */
	mlx->plane.y = (WIN_X / 2.0) - x;
	mlx->plane.z = (WIN_Y / 2.0) - y;
	mlx->vector.x = mlx->plane.x - scene->camera->pos.x;
	mlx->vector.y = mlx->plane.y - scene->camera->pos.z;
	mlx->vector.z = mlx->plane.z - scene->camera->pos.z;
	calc_inter(x, y, mlx, scene);
}

void		calc_rtv1(t_mlx *mlx, t_scene *scene)
{
	int		x;
	int		y;
	int		prev_perc;

	prev_perc = -1;
	ft_putstr("LOADING... [");
	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			calc_ray_xy(x, y, mlx, scene);
			if (100 * (y + x * WIN_Y) / (WIN_X * WIN_Y) > prev_perc + 1)
			{
				prev_perc = 100 * (y + x * WIN_Y) / (WIN_X * WIN_Y);
				ft_putstr("=");
			}
		}
	}
	ft_putstr("]\n");
}
