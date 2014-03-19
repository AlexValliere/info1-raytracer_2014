/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:39:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/19 00:55:26 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<rtfinal.h>

t_scene			*scene_new(void)
{
	t_scene		*new;

	if ((new = (t_scene *)malloc(sizeof(t_scene))) == NULL)
		return (NULL);
	new->spots = NULL;
	new->objs = NULL;
	new->camera = (t_xyz){0, 0, 0};
	new->next = new;
	new->prev = new;
	return (new);
}

void			scene_pushback(t_scene **list, t_scene *new)
{
	if (!*list)
		*list = new;
	else
	{
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		new->next = *list;
	}
}

void			scene_free(t_scene **list)
{
	int			fix;
	t_scene		*tmp;
	t_scene		*tmp2;

	fix = 0;
	tmp = *list;
	while ((tmp != *list || !fix) && (fix = 1))
	{
		tmp2 = tmp->next;
		obj_free(&(tmp->spots));
		obj_free(&(tmp->objs));
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
