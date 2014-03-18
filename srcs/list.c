/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:12:11 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 16:16:14 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<list.h>

static void		*ft_memcpy(void *data, size_t size)
{
	u_int		i;
	char		*new;
	char		*tmp;

	if ((new = malloc(size)) == NULL)
		return (NULL);
	tmp = data;
	i = -1;
	while (++i < size)
		new[i] = tmp[i];
	return (new);
}

static t_list	*lst_new(void *data, size_t size)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->data = ft_memcpy(data, size)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	new->next = new;
	new->prev = new;
	return (new);
}

void			lst_pushback(t_list **list, void *data, size_t size)
{
	t_list		*new;
	t_list		*tmp;

	if ((new = lst_new(data, size)) == NULL)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next != *list)
			tmp = tmp->next;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		new->next = *list;
	}
}

void			lst_free(t_list **list)
{
	int			fix;
	t_list		*tmp;
	t_list		*tmp2;

	fix = 0;
	tmp = *list;
	while ((tmp != *list || !fix) && (fix = 1))
	{
		tmp2 = tmp->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
