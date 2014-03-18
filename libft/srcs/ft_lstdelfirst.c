/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 00:14:08 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:20 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdelfirst(t_list **alst)
{
	t_list	*tmp_list;

	tmp_list = NULL;
	if (ft_lstsize(*alst) > 1)
	{
			tmp_list = (*alst)->next;
			ft_memdel(&((*alst)->content));
			(*alst)->next = NULL;
			*alst = tmp_list;
	}
	else
	{
		ft_memdel(&((*alst)->content));
		(*alst)->next = NULL;
		*alst = NULL;
	}
}
