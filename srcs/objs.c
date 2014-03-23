/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:49:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/23 19:26:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<rtfinal.h>
#include		<math.h>

static double	to_radian(int degree)
{
	return (M_PI * (double)degree / 180.0);
}

t_obj			*obj_new(t_type type, int *nbrs, u_int color)
{
	t_obj		*new;

	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->type = type;
	new->color = color;
	new->pos.x = nbrs[0];
	new->pos.y = nbrs[1];
	new->pos.z = nbrs[2];
	new->rot.x = to_radian(nbrs[3]);
	new->rot.y = to_radian(nbrs[4]);
	new->rot.z = to_radian(nbrs[5]);
	new->param[0] = nbrs[6];
	new->param[1] = nbrs[7];
	new->param[2] = nbrs[8];
	new->param[3] = nbrs[9];
	new->next = NULL;
	return (new);
}

void			obj_pushback(t_obj **list, t_type type,
							int *nbrs, u_int color)
{
	t_obj		*new;
	t_obj		*tmp;

	if ((new = obj_new(type, nbrs, color)) == NULL)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			obj_free(t_obj **list)
{
	int			fix;
	t_obj		*tmp;
	t_obj		*tmp2;

	if (*list == NULL)
		return ;
	fix = 0;
	tmp = *list;
	while ((tmp != *list || !fix) && (fix = 1))
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
