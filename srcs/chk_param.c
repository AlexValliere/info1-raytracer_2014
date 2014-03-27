/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:35:25 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/27 15:15:19 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<rtfinal.h>

int		check_object_int_param(int *nbrs, int a, int b)
{
	while (a < b)
	{
		if (nbrs[a] == -424242)
			return (-1);
		++a;
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
	if (check_object_int_param(nbrs, 0, 3) == 1)
	{
		if (type == SPOT)
			return (1);
		if (check_object_rot(nbrs) == 1)
		{
			if (type == CAMERA)
				return (1);
			if (color != 0xFFFFFFFF)
			{
				if (type == LTSPHER && check_object_int_param(nbrs, 6, 10) != 1)
					return (-1);
				if (type != PLANE && check_object_int_param(nbrs, 6, 8) == 1)
					return (1);
				if (type == PLANE && nbrs[6] != -424242 && nbrs[7] == -424242)
					return (1);
			}
		}
	}
	return (-1);
}
