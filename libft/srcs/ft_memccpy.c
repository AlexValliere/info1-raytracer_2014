/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:33:29 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:07:52 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*p_s1;
	const char	*p_s2;
	size_t		i;

	p_s1 = s1;
	p_s2 = s2;
	i = 0;
	while (i < n && s2)
	{
		if (*p_s2 == (char)c)
		{
			*p_s1 = *p_s2;
			++p_s1;
			return (p_s1);
		}
		*p_s1 = *p_s2;
		++p_s1;
		++p_s2;
		++i;
	}
	return (NULL);
}
