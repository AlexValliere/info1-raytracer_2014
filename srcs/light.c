/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:35:37 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/23 19:29:27 by ptran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<rtfinal.h>

double		norme_vector(t_xyz *xyz)
{
	double	res;

	res = sqrt(pow(xyz->x, 2) + pow(xyz->y, 2) + pow(xyz->z, 2));
	return (res);
}

void		get_normal(t_xyz *normal, t_xyz *p, t_obj *obj)
{
	if (obj->type == SPHERE)
		*normal = (t_xyz){p->x, p->y, p->z};
	else if (obj->type == CYLIND)
		*normal = (t_xyz){p->x, p->y, 0};
	else if (obj->type == CONE)
		*normal = (t_xyz){p->x, p->y, -0.7 * p->z};
	else if (obj->type == PLANE)
		*normal = (t_xyz){0, 0, 100};
}

u_int		calc_light(t_mlx *mlx, t_obj *spot)
{
	t_xyz	p;
	t_xyz	light;
	t_xyz	normal;
	double	cos_a;
	u_int	new_color;

	move_eye(&mlx->cur_scene->camera->pos, &mlx->vector, mlx->cur_obj, -1);
	p = (t_xyz){mlx->cur_scene->camera->pos.x + mlx->k * mlx->vector.x,
				mlx->cur_scene->camera->pos.y + mlx->k * mlx->vector.y,
				mlx->cur_scene->camera->pos.z + mlx->k * mlx->vector.z};

	new_color = calc_reflect(mlx, mlx->cur_scene, &p);
	move_eye(&mlx->cur_scene->camera->pos, &mlx->vector, mlx->cur_obj, 1);
	light = (t_xyz){spot->pos.x - p.x, spot->pos.y - p.y, spot->pos.z - p.z};
	//new_color = mlx->cur_obj->color;
	get_normal(&normal, &p, mlx->cur_obj);
	cos_a = (normal.x * light.x + normal.y * light.y + normal.z * light.z)
		/ (norme_vector(&normal) * norme_vector(&light));
	new_color = (cos_a >= 0 && cos_a <= 1)
		? mult_color(new_color, cos_a) : 0;
	return (new_color);
}
