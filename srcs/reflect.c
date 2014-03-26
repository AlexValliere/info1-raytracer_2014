/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:01:44 by ptran             #+#    #+#             */
/*   Updated: 2014/03/26 17:02:58 by ptran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <rtfinal.h>

t_xyz				ft_reflect(t_xyz *vec, t_xyz *nor)
{
	//double			s;
	//double			n;
//	double			u;
	t_xyz			ref;
	//double			n1;
	//double			n2;

	//double			alpha;
//	u = vec->x * nor->x + vec->y * nor->y + vec->z * nor->z;
//	n = pow(nor->x, 2) + pow(nor->y, 2) + pow(nor->z, 2);
	//alpha = pow(2, (s / n));
	ref.x = vec->x - 2 * vec->x * nor->x;
	ref.y = vec->y - 2 * vec->x * nor->y;
	ref.z = vec->z - 2 * vec->x * nor->z;


	/*
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
	*/

	return (ref);

}

t_int				new_col(t_int ref, t_int obj_col, double reflect)
{
	t_int			color1;
	t_int			color2;
	t_int			final;

	color1 = mult_color(ref, reflect);
	color2 = mult_color(obj_col, (1 - reflect));
	final = add_2color(color1, color2);
	return (final);
}

t_int				calc_reflect(t_mlx *mlx, t_scene *scene, t_xyz *pos, t_xyz light2)
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
	get_normal(&normal, &light2, tmp);
	reflect = ft_reflect(&light2, &normal);
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
		color = new_col(obj->color, color, 0.1);
	return (color);
}

