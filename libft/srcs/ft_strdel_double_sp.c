/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_double_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:56:35 by alex              #+#    #+#             */
/*   Updated: 2014/02/06 15:56:09 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	new_len(char *str)
{
	int		i;
	int		new_len;

	i = 1;
	new_len = 0;
	while (str[i])
	{
		if (ft_isspace(str[i - 1]) == 1 && ft_isspace(str[i]) == 1)
			++i;
		else
		{
			++new_len;
			++i;
		}
	}
	return (new_len);
}

char		*ft_strdel_double_sp(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	if (ft_strlen(str) == 1)
		return (str);
	new_str = malloc((new_len(str) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isspace(str[i - 1]) == 1 && ft_isspace(str[i]) == 1)
			++i;
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = 0;
	return (new_str);
}
