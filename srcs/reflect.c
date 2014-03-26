/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:01:44 by ptran             #+#    #+#             */
/*   Updated: 2014/03/26 14:10:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <rtfinal.h>

t_xyz				ft_reflect(t_xyz *vec, t_xyz *nor)
{
	double			u;
	t_xyz			ref;
	double			n1;
	double			n2;

	n1 = norme_vector(vec);
	n2 = norme_vector(nor);
	vec->x = vec->x / n1;
	vec->y = vec->y / n1;
	vec->z = vec->z / n1;
	nor->x = nor->x / n2;
	nor->y = nor->y / n2;
	nor->z = nor->z / n2;
	u = ((vec->x * nor->x) + (vec->y * nor->y) + (vec->z * nor->z));
	ref.x = vec->x - (2.0 * nor->x * u);
	ref.y = vec->y - (2.0 * nor->y * u);
	ref.z = vec->z - (2.0 * nor->z * u);
	return (ref);
}

t_int				new_col(t_int ref, t_int obj_col, double reflect)
{
	return (add_2color(mult_color(ref, reflect),
	 mult_color(obj_col, (1 - reflect))));
}

t_int				calc_reflect(t_mlx *mlx, t_scene *scene, t_xyz *pos)
{
	double			k[2];
	t_obj			*tmp;
	t_int			color;
	t_xyz			reflect;
	t_xyz			normal;
	t_obj			*obj;

	obj = NULL;
	mlx->k = 0xFFFFFFFF;
	tmp = scene->objs;
	get_normal(&normal, pos, tmp);
	reflect = ft_reflect(&mlx->vector, &normal);
	color = mlx->cur_obj->color;
	while (tmp)
	{
		if (tmp != mlx->cur_obj)
		{
			calc_curobj(pos, &reflect, tmp, k);
			if (k[0] >= 0 && mlx->k > k[0] && (obj = tmp))
				mlx->k = k[0];
			if (k[1] >= 0 && mlx->k > k[1] && (obj = tmp))
				mlx->k = k[1];
		}
		tmp = tmp->next;
	}
	if (obj != NULL)
		color = new_col(obj->color, color, 0.3);
	return (color);
}
