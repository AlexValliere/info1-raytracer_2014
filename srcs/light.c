/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:35:37 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/26 14:10:37 by gabtoubl         ###   ########.fr       */
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
		*normal = (t_xyz){0, 0, 100};
	else if (obj->type == HYPERB)
		*normal = (t_xyz){p->x, p->y, - (obj->param[0] * M_PI / 180.0) * p->z};
	else if (obj->type == PARAB)
		*normal = (t_xyz){p->x, p->y, - (obj->param[0] * M_PI / 180.0)};
}

t_int		calc_light(t_mlx *mlx, t_scene *scene, t_obj *spot, double *shade)
{
	t_xyz	p;
	t_xyz	light;
	t_xyz	normal;
	double	cos_a;
	t_int	color[2];

	move_eye(&scene->camera->pos, &mlx->vector, mlx->cur_obj, -1);
	p = (t_xyz){scene->camera->pos.x + mlx->k * mlx->vector.x,
				scene->camera->pos.y + mlx->k * mlx->vector.y,
				scene->camera->pos.z + mlx->k * mlx->vector.z};
	light = (t_xyz){spot->pos.x - p.x, spot->pos.y - p.y, spot->pos.z - p.z};
	move_eye(&scene->camera->pos, &mlx->vector, mlx->cur_obj, 1);
	color[0] = mlx->cur_obj->color;//calc_reflect(mlx, scene, &p);
	get_normal(&normal, &p, mlx->cur_obj);
	cos_a = (normal.x * light.x + normal.y * light.y + normal.z * light.z)
		/ (norme_vector(&normal) * norme_vector(&light));
	color[0] = (cos_a >= 0 && cos_a <= 1)
		? mult_color(color[0], cos_a) : 0;
	*shade += shadow_cast(mlx, &spot->pos);
	return (color[0]);
}

t_int		calc_all_lights(t_mlx *mlx, t_scene *scene)
{
	t_int	color;
	t_obj	*tmp;
	double	shade;
	double	nb_l;

	nb_l = light_nb(scene->spots);
	shade = 0;
	tmp = scene->spots;
	while (tmp)
	{
		if (tmp == scene->spots)
			color = calc_light(mlx, scene, tmp, &shade);
		else
			color = add_2color(color, calc_light(mlx, scene, tmp, &shade));
		tmp = tmp->next;
	}
	color = mult_color(color, 1.0 / sqrt(nb_l));
	color = mult_color(color, 1.0 - 0.4 * shade / nb_l); 
	return (color);
}
