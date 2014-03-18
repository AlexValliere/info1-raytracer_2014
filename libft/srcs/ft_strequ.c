/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:14:04 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	char	*p_s1;
	char	*p_s2;
	size_t	i;

	if (s1 && s2)
	{
		p_s1 = (char *)s1;
		p_s2 = (char *)s2;
		i = 0;
		while (p_s1[i])
		{
			if (p_s1[i] != p_s2[i])
				return (0);
			++i;
		}
		if (p_s1[i] != p_s2[i])
			return (0);
		return (1);
	}
	else
		return (0);
}
