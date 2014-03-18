/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:33:29 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:18:09 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;
	const char	*p;

	if (c == '\0')
		return (ft_strchr (s, '\0'));
	found = NULL;
	while ((p = ft_strchr (s, c)) != NULL)
	{
		found = p;
		s = p + 1;
	}
	return ((char *)found);
}
