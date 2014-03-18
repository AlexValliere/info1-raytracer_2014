/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 02:19:24 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 18:06:21 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

int	ft_is_int(char const *str)
{
	int		nbr;
	char	*tmp;
	int		is_int;
	int		if_plus;

	is_int = 0;
	if (str)
	{
		if_plus = (str[0] == '+') ? 1 : 0;
		nbr = ft_atoi(str);
		tmp = ft_itoa(nbr);
		if (ft_strcmp(tmp, str + if_plus) == 0)
			is_int = 1;
	}
	return (is_int);
}
