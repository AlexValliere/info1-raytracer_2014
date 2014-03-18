/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:38:58 by alex              #+#    #+#             */
/*   Updated: 2014/02/05 14:18:22 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strtoupper(char *str)
{
	char	*upper_str;
	int		i;

	i = 0;
	upper_str = NULL;
	if (str)
	{
		while (str[i])
			++i;
		upper_str = malloc((i + 1) * sizeof(char));
		if (upper_str == NULL)
			return (NULL);
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				upper_str[i] = 'A' + (str[i] - 'a');
			else
				upper_str[i] = str[i];
			++i;
		}
		upper_str[i] = 0;
	}
	return (upper_str);
}
