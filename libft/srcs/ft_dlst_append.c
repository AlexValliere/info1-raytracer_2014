/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 02:12:52 by apetit            #+#    #+#             */
/*   Updated: 2014/03/07 14:41:55 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

static void	*ft_dlst_cp_new_data(t_node **new, void *data, size_t data_size)
{
	(*new)->data = NULL;
	(*new)->data = malloc(data_size);
	if ((*new)->data != NULL)
		(*new)->data = ft_memcpy((*new)->data, data, data_size);
	return ((*new)->data);
}

t_dlist		*ft_dlst_append(t_dlist *dlist, void *data, size_t data_size)
{
	t_node	*new;

	if (dlist != NULL)
	{
		if ((new = (t_node *)malloc(sizeof(t_node))) != NULL)
		{
			new->data = ft_dlst_cp_new_data(&new, data, data_size);
			new->data_size = data_size;
			new->next = NULL;
			if (dlist->tail == NULL)
			{
				new->prev = NULL;
				dlist->head = new;
				dlist->tail = new;
			}
			else
			{
				dlist->tail->next = new;
				new->prev = dlist->tail;
				dlist->tail = new;
			}
			dlist->lenght++;
		}
	}
	return (dlist);
}
