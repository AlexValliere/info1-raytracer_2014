/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_delchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:33:03 by alex              #+#    #+#             */
/*   Updated: 2014/02/04 16:39:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	new_len(char *str, int c)
{
	int		i;
	int		new_len;

	i = 1;
	new_len = 0;
	while (str[i])
	{
		if (str[i] == c)
			++i;
		else
		{
			++new_len;
			++i;
		}
	}
	return (new_len);
}

char		*ft_strdup_delchar(char *str, int c)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc((new_len(str, c) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			++i;
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = 0;
	return (new_str);
}
