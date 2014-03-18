/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2013/12/08 16:15:58 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*p_ret;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		ret = malloc(ft_strlen(s) * sizeof(char));
		p_ret = ret;
		while (i < ft_strlen(s))
		{
			*p_ret = (*f)(i, *(s + i));
			++p_ret;
			++i;
		}
		return (ret);
	}
	else
		return (NULL);
}
