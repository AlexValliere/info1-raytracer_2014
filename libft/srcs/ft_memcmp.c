/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:33:29 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:07:44 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cmp1;
	const unsigned char	*cmp2;

	cmp1 = s1;
	cmp2 = s2;
	while (n)
	{
		--n;
		if (*cmp1 != *cmp2)
			return (*cmp1 - *cmp2);
		else
		{
			++cmp1;
			++cmp2;
		}
	}
	return (0);
}
