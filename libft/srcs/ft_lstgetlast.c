/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:28:47 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:16 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

t_list	*ft_lstgetlast(t_list *lst)
{
	t_list	*next_link;

	next_link = NULL;
	if (lst)
	{
		next_link = lst;
		while (next_link->next != NULL)
			next_link = next_link->next;
	}
	return (next_link);
}
