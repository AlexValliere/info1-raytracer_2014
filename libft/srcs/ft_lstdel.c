/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:13:20 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:23 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*last_link;
	t_list	*next_link;

	while ((*alst)->next != NULL)
	{
		last_link = *alst;
		next_link = (*alst)->next;
		(*del)(last_link->content, last_link->content_size);
		free(last_link);
		last_link = NULL;
		*alst = next_link;
	}
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
