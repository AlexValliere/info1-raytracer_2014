/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fct_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 23:50:36 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:49:24 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

void	ft_printf_d(va_list list)
{
	int				n;

	n = va_arg(list, int);
	ft_putnbr(n);
}

void	ft_printf_i(va_list list)
{
	int				n;

	n = va_arg(list, int);
	ft_putnbr(n);
}

void	ft_printf_c(va_list list)
{
	int				c;

	c = va_arg(list, int);
	ft_putchar(c);
}

void	ft_printf_s(va_list list)
{
	char			*str;

	str = va_arg(list, char *);
	ft_putstr(str);
}

void	ft_printf_p(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	ft_putstr("0x");
	ft_putnbr_base(n, HEXA_BASE_CAP);
}
