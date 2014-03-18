/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:20:32 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:05 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next_link;
	int		nbr_element;

	next_link = NULL;
	nbr_element = 0;
	if (lst)
	{
		next_link = lst;
		++nbr_element;
		while (next_link->next != NULL)
		{
			++nbr_element;
			next_link = next_link->next;
		}
	}
	return (nbr_element);
}
