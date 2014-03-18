/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 23:19:50 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:50:22 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

void	ft_dlst_del(t_dlist **dlist)
{
	t_node	*temp;
	t_node	*del;

	if (*dlist != NULL)
	{
		temp = (*dlist)->head;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			free(del);
		}
		free(*dlist);
		*dlist = NULL;
	}
}
