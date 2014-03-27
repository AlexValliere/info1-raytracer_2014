/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:53:48 by ptran             #+#    #+#             */
/*   Updated: 2014/03/27 15:02:54 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	<math.h>
#include	<rtfinal.h>

void			calc_parab(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	double		R;
	double		delta;

	R = obj->param[0];
	a = pow(vector->x, 2) + pow(vector->y, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y) - tan(R) * vector->z;
	c = pow(eye->x, 2) + pow(eye->y, 2) - tan(R) * eye->z;
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void			calc_hyperb(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	double		R;
	double		delta;

	R = obj->param[0];
	a = pow(vector->x, 2) + pow(vector->y, 2)
		- (pow(vector->z, 2) * (pow(tan(R), 2)));
	b = (2 * vector->x * eye->x) + (2 * vector->y * eye->y)
		- ((2 * vector->z * eye->z) * (pow(tan(R), 2)));
	c = (pow(eye->x, 2) + pow(eye->y, 2)
		- (pow(eye->z, 2) * pow(tan(R), 2)) + HYPER_OPEN);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void			waves(t_xyz *normal, t_xyz *p)
{
	normal->y = normal->y + cos(p->y / 10) * (norme_vector(normal) / 10);
}

void				perturbation(t_xyz *normal, t_xyz *p)
{
	normal->y = normal->y + (cos(p->y / 7)
	* (sqrt(pow(normal->x, 2) + pow(normal->y, 2) + pow(normal->z, 2)) / 2));
}
