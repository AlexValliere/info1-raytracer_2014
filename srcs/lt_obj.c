/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lt_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:40:33 by apetit            #+#    #+#             */
/*   Updated: 2014/03/27 16:48:04 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<rtfinal.h>

static void	set_k_neg(double *k)
{
	k[0] = -1;
	k[1] = -1;
}

void		calc_ltspher(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_xyz	p;

	a = pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y
			+ eye->z * vector->z);
	c = pow(eye->x, 2) + pow(eye->y, 2)
		+ pow(eye->z, 2) - pow(obj->param[0], 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
	p = (t_xyz){-4242, -4242, -4242};
	if ((k[0] > 0 && k[1] <= 0) || (k[0] > 0 && k[1] > 0 && k[0] <= k[1]))
		p = (t_xyz){eye->x + k[0] * vector->x, eye->y + k[0] * vector->y,
			eye->z + k[0] * vector->z};
	else if (k[0] > 0 && k[1] > 0 && k[0] >= k[1])
		p = (t_xyz){eye->x + k[1] * vector->x, eye->y + k[1] * vector->y,
			eye->z + k[1] * vector->z};
	if (p.z != -4242 && p.z >= obj->param[2] && obj->param[2] != -424242)
		set_k_neg(k);
	if (p.z != -4242 && p.z <= obj->param[3] && obj->param[3] != -424242)
		set_k_neg(k);
}

void		calc_ltcylin(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_xyz	p;

	a = pow(vector->x, 2) + pow(vector->y, 2);
	b = 2 * (eye->x * vector->x + eye->y * vector->y);
	c = pow(eye->x, 2) + pow(eye->y, 2) - pow(obj->param[0], 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
	if ((k[0] > 0 && k[1] <= 0) || (k[0] > 0 && k[1] > 0 && k[0] <= k[1]))
		p = (t_xyz){eye->x + k[0] * vector->x, eye->y + k[0] * vector->y,
			eye->z + k[0] * vector->z};
	else if (k[0] > 0 && k[1] > 0 && k[0] >= k[1])
		p = (t_xyz){eye->x + k[1] * vector->x, eye->y + k[1] * vector->y,
			eye->z + k[1] * vector->z};
	if (p.z != -4242 && p.z >= obj->param[2] * 2 && obj->param[2] != -424242)
		set_k_neg(k);
	if (p.z != -4242 && p.z <= obj->param[3] * 2 && obj->param[3] != -424242)
		set_k_neg(k);
}
