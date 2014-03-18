/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:07:18 by apetit            #+#    #+#             */
/*   Updated: 2014/02/21 17:36:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str != '\0')
		++str;
	return (str - s);
}
