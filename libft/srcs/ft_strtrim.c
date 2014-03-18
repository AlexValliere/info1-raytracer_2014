/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:01:21 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:22:11 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static char	*ft_ret_null_str(void)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

static int		ft_strtrim_p1(char const *s, int i, int order)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (order == 1)
			++i;
		else
			--i;
	}
	return (i);
}

static void	ft_strtrim_p2(char const *s, size_t *i)
{
	i[1] = i[0];
	i[0] = ft_strlen(s) - 1;
	i[2] = ft_strtrim_p1(s, i[0], -1);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	char	*p_ret;
	size_t	i[3];

	i[0] = 0;
	if (s)
	{
		i[0] = ft_strtrim_p1(s, i[0], 1);
		if (s[i[0]] == '\0')
			return (ft_ret_null_str());
		else
			ft_strtrim_p2(s, i);
		i[0] = 0;
		ret = malloc((i[2] - i[1] + 1) * sizeof(char));
		p_ret = ret;
		while ((i[1] + i[0]) <= i[2])
		{
			p_ret[i[0]] = s[i[1] + i[0]];
			++i[0];
		}
		p_ret[i[0]] = '\0';
	}
	else
		return (ft_ret_null_str());
	return (ret);
}
