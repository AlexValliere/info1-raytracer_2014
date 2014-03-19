/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:49:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/19 01:07:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<rtfinal.h>

static t_obj	*obj_new(t_type type, int *nbrs)
{
	int			i;
	t_obj		*new;

	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->type = type;
	i = -1;
	while (++i < 10)
	{
		if (i < 3)
			new->pos[i] = nbrs[i];
		else if (i < 6)
			new->rot[i - 3] = nbrs[i];
		else
			new->param[i - 6] = nbrs[i];
	}
	new->next = NULL;
	return (new);
}

void			obj_pushback(t_obj **list, t_type type, int *nbrs)
{
	t_obj		*new;
	t_obj		*tmp;

	if ((new = obj_new(type, nbrs)) == NULL)
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
