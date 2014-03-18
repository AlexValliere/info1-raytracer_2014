/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartab2inc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 23:53:47 by alex              #+#    #+#             */
/*   Updated: 2014/02/06 00:42:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	**ft_chartab2inc(char **tab)
{
	char	**new_tab;
	int		len;

	len = 0;
	new_tab = NULL;
	while (tab[len])
		++len;
	if (len != 0)
	{
		new_tab = (char **)malloc((len + 2) * sizeof(char *));
		if (new_tab != NULL)
		{
			len = 0;
			while (tab[len])
			{
				new_tab[len] = ft_strdup(tab[len]);
				free(tab[len]);
				++len;
			}
			new_tab[len + 1] = 0;
			free(tab);
		}
	}
	return (new_tab);
}
