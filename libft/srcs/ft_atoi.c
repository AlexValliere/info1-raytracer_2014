/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:33:29 by apetit            #+#    #+#             */
/*   Updated: 2014/02/23 19:05:00 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

static void	ft_init_atoi_vars_to_null(int *i, int *sign, int *nbr)
{
	*i = 0;
	*sign = 0;
	*nbr = 0;
}

int			ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	ft_init_atoi_vars_to_null(&i, &sign, &nbr);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		++i;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10;
		nbr += str[i] - 48;
		++i;
	}
	nbr = (sign == 1) ? -nbr : nbr;
	return (nbr);
}
