/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 23:15:59 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:01 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstswap(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_list;

	if (*lst_a && *lst_b)
	{
		tmp_list = ft_lstnew((*lst_a)->content, (*lst_a)->content_size);
		if (tmp_list)
		{
			tmp_list->next = (*lst_b)->next;
			(*lst_a)->content = (*lst_b)->content;
			(*lst_a)->content_size = (*lst_b)->content_size;
			(*lst_b) = tmp_list;
		}
	}
}
