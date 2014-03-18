/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:11:03 by apetit            #+#    #+#             */
/*   Updated: 2013/12/08 16:16:10 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*c_s1;
	char	*c_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	c_s1 = (char *)s1;
	c_s2 = (char *)s2;
	if (s2 == NULL || s1 == NULL || s2[0] == '\0')
		return (c_s1);
	while (c_s1[i] != '\0' && i < n)
	{
		if (c_s1[i] == c_s2[0])
		{
			j = 0;
			while (c_s1[i + j] == c_s2[j] && c_s1[i + j] && (i + j) < n)
				++j;
			if (c_s2[j] == '\0')
				return (&c_s1[i]);
		}
		++i;
	}
	return (NULL);
}
