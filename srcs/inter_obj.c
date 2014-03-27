/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:26:35 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/27 14:32:23 by ptran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<rtfinal.h>

void		calc_sphere(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y
			+ eye->z * vector->z);
	c = pow(eye->x, 2) + pow(eye->y, 2)
		+ pow(eye->z, 2) - pow(obj->param[0], 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		calc_cylinder(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(vector->x, 2) + pow(vector->y, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y);
	c = pow(eye->x, 2) + pow(eye->y, 2) - pow(obj->param[0], 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		calc_cone(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(vector->x, 2) + pow(vector->y, 2) - pow(vector->z, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y
			- eye->z * vector->z);
	c = pow(eye->x, 2) + pow(eye->y, 2) - pow(eye->z, 2)
	- pow(tan(obj->param[0]), 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		calc_plane(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	(void)obj;
	if (vector->z < 0.000001 && vector->z > -0.000001)
		k[0] = -1;
	else
		k[0] = -eye->z / vector->z;
}

void		ft_transform(t_xyz *normal, t_xyz *p, t_obj *obj)
{
	if (obj->param[1] == 1)
		waves(normal, p);
	else if (obj->param[1] == 2)
		perturbation(normal, p);
	else if (obj->type == PLANE && obj->param[0] == 1)
		waves(normal, p);
	else if (obj->type == PLANE && obj->param[0] == 2)
		perturbation(normal, p);
}
