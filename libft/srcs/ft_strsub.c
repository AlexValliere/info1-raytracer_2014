/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2014/02/21 17:31:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*p_ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = start;
	if (len > (ft_strlen(s) - start))
		ret = 0;
	else
	{
		ret = (char *)malloc((len + 1) * sizeof(char));
		ft_bzero(ret, len + 1);
		p_ret = ret;
		while (i < (start + len))
		{
			*p_ret = *(s + i);
			++p_ret;
			++i;
		}
		*p_ret = '\0';
	}
	return (ret);
}
