/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:41:02 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:10 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element)
	{
		if (content && content_size > 0)
		{
			element->content = malloc(content_size + 1);
			ft_memcpy(element->content, content, ft_strlen(content) + 1);
			element->content_size = content_size;
		}
		else
		{
			element->content = NULL;
			element->content_size = 0;
		}
		element->next = NULL;
	}
	else
		element = NULL;
	return (element);
}
