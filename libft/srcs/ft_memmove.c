/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:11:03 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:11:03 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	s2_len;
	char	*tmp;

	if (s2)
	{
		s2_len = ft_strlen(s2);
		tmp = malloc(s2_len);
		ft_memcpy(tmp, s2, n);
		ft_memcpy(s1, tmp, n);
		return (s1);
	}
	else
		return (NULL);
}
