/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:11:03 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:11:07 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*p_s1;
	const char	*p_s2;
	size_t		i;

	p_s1 = s1;
	p_s2 = s2;
	i = 0;
	while (i < n)
	{
		*p_s1 = *p_s2;
		++p_s1;
		++p_s2;
		++i;
	}
	return (s1);
}
