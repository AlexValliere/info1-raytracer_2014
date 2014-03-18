/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2014/02/21 17:36:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static char	*ft_empty_one(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 && !s2)
		ret = 0;
	if (!s2)
	{
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		ft_bzero(ret, ft_strlen(s1) + 1);
		ret = ft_strncpy(ret, s1, ft_strlen(s1));
	}
	else if (!s1)
	{
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
		ft_bzero(ret, ft_strlen(s2) + 1);
		ret = ft_strncpy(ret, s2, ft_strlen(s2) + 1);
	}
	return (ret);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*p_ret;
	size_t	i;

	if ((!s1 && !s2) || (!s2) || (!s1))
		return (ft_empty_one(s1, s2));
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ft_bzero(ret, ft_strlen(s1) + ft_strlen(s2) + 1);
	p_ret = ret;
	i = 0;
	if (ret)
	{
		while (i < ft_strlen(s1))
		{
			p_ret[i] = s1[i];
			++i;
		}
		while (i < ft_strlen(s2) + ft_strlen(s1))
		{
			p_ret[i] = s2[i - ft_strlen(s1)];
			++i;
		}
		p_ret[i] = '\0';
	}
	return (ret);
}
