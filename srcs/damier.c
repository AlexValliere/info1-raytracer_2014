/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 13:29:57 by qde-vial          #+#    #+#             */
/*   Updated: 2014/03/25 13:41:14 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <rtfinal.h>

void		calc_dam(t_obj *obj, double *k)
{
	if ((obj->pos.x >= 0.0 && obj->pos.y >= 0.0)
			|| (obj->pos.x < 0.0 && obj->pos.y < 0.0))
	{
		if (((int)fabs(obj->pos.x) % 100 <= 50
					&& (int)fabs(obj->pos.y) % 100 <= 50)
				|| ((int)fabs(obj->pos.x) % 100 > 50
					&& (int)fabs(obj->pos.y) % 100 > 50))
			k[0] = -1;
	}
	else
	{
		if (((int)fabs(obj->pos.x) % 100 <= 50 && (int)fabs(obj->pos.y)
		 % 100 <= 50) || ((int)fabs(obj->pos.x) % 100 > 50 &&
		 (int)fabs(obj->pos.y) % 100 > 50))
			;
		else
			k[0] = -1;
	}
}
