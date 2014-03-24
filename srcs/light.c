/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:35:37 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/24 18:32:10 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<rtfinal.h>

int			light_nb(t_obj *spots)
{
	int		nb;
	t_obj	*tmp;

	nb = 0;
	tmp = spots;
	while (tmp)
	{
		++nb;
		tmp = tmp->next;
	}
	return (nb);
}

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
		*normal = (t_xyz){100, 0, 0};
}

t_int		calc_light(t_mlx *mlx, t_scene *scene, t_obj *spot)
{
	t_xyz	p;
	t_xyz	light;
	t_xyz	normal;
	double	cos_a;
	t_int	new_color;

	move_eye(&scene->camera->pos, &mlx->vector, mlx->cur_obj, -1);
	p = (t_xyz){scene->camera->pos.x + mlx->k * mlx->vector.x,
				scene->camera->pos.y + mlx->k * mlx->vector.y,
				scene->camera->pos.z + mlx->k * mlx->vector.z};
	move_eye(&scene->camera->pos, &mlx->vector, mlx->cur_obj, 1);
	light = (t_xyz){spot->pos.x - p.x, spot->pos.y - p.y, spot->pos.z - p.z};
	new_color = mlx->cur_obj->color;//calc_reflect(mlx, scene, &p);
	get_normal(&normal, &p, mlx->cur_obj);
	cos_a = (normal.x * light.x + normal.y * light.y + normal.z * light.z)
		/ (norme_vector(&normal) * norme_vector(&light));
	new_color = (cos_a >= 0 && cos_a <= 1)
		? mult_color(new_color, cos_a) : 0;
	return (new_color);
}

t_int		calc_all_lights(t_mlx *mlx, t_scene *scene)
{
	t_int	color;
	t_obj	*tmp;

	tmp = scene->spots;
	while (tmp)
	{
		if (tmp == scene->spots)
			color = calc_light(mlx, scene, tmp);
		else
			color = add_2color(color, calc_light(mlx, scene, tmp));
		tmp = tmp->next;
	}
	color = mult_color(color, 1.0 / light_nb(scene->spots));
	return (color);
}
