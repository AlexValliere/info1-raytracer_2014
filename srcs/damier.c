/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptran <ptran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 13:29:57 by qde-vial          #+#    #+#             */
/*   Updated: 2014/03/27 17:00:03 by ptran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <rtfinal.h>

void		calc_dam(t_obj *obj, t_xyz *p)
{
	if (((int)fabs(p->x) % 100 >= 50 && (int)fabs(p->y) % 100 >= 50) ||
		((int)fabs(p->x) % 100 <= 50 && (int)fabs(p->y) % 100 <= 50))
		obj->color = 0x000000;
	else
		obj->color = 0xFFFFFF;
}

void		calc_rings(t_obj *obj, t_xyz *p)
{
	double d;

	d = sqrt(pow((double)p->x, 2) + pow((double)p->y, 2));
	if ((int)d % 100 < 50)
		obj->color = 0xFFFF00;
}
