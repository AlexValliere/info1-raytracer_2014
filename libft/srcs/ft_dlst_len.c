/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 00:22:45 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:50:35 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

size_t	ft_dlst_len(t_dlist *dlist)
{
	size_t	lenght;

	lenght = 0;
	if (dlist != NULL)
		lenght = dlist->lenght;
	return (lenght);
}
