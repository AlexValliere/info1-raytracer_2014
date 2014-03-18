/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:33:09 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:13 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next_link;

	if (lst)
	{
		next_link = lst;
		while (next_link->next != NULL)
		{
			(*f)(next_link);
			next_link = next_link->next;
		}
		(*f)(next_link);
	}
}
