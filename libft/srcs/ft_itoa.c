/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:49:42 by apetit            #+#    #+#             */
/*   Updated: 2013/12/29 17:08:27 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*result;

	result = malloc(11 * sizeof(char));
	sign = n;
	i = 0;
	result[i] = ft_abs(n % 10) + '0';
	++i;
	while ((n /= 10) != 0)
	{
		result[i] = ft_abs(n % 10) + '0';
		++i;
	}
	if (sign < 0)
	{
		result[i] = '-';
		++i;
	}
	result[i] = '\0';
	result = ft_strrev(result);
	return (result);
}
