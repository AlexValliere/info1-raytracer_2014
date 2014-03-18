/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2013/12/08 16:15:54 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*p_ret;
	size_t	i;

	p_ret = 0;
	i = 0;
	if (s && f)
	{
		ret = malloc(ft_strlen(s) * sizeof(char));
		p_ret = ret;
		while (i < ft_strlen(s))
		{
			*p_ret = (*f)(*(s + i));
			++p_ret;
			++i;
		}
		return (ret);
	}
	else
		return (NULL);
}
