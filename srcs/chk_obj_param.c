/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_obj_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:30:41 by apetit            #+#    #+#             */
/*   Updated: 2014/03/26 17:00:28 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<rtfinal.h>

int		check_object_pos(int *nbrs)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (nbrs[i] == -424242)
			return (-1);
		++i;
	}
	return (1);
}

int		check_object_rot(int *nbrs)
{
	int	i;

	i = 3;
	while (i < 6)
	{
		if (nbrs[i] < 0 || nbrs[i] > 360)
			return (-1);
		++i;
	}
	return (1);
}

int		check_object_param(t_type type, int *nbrs, t_int color)
{
	if (check_object_pos(nbrs) == 1)
	{
		if (type == SPOT)
			return (1);
		if (check_object_rot(nbrs) == 1)
		{
			if (type == CAMERA)
				return (1);
			if (color != 0xFFFFFFFF)
			{
				if (nbrs[6] != -424242 && nbrs[7] == -424242 && type != PLANE)
					return (1);
				if (type == PLANE && nbrs[6] == -424242 && nbrs[7] == -424242)
					return (1);
			}
		}
	}
	return (-1);
}
