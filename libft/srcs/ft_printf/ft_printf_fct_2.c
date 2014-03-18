/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fct_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 23:50:36 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:49:25 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

void	ft_printf_o(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	ft_putnbr_base(n, OCTAL_BASE);
}

void	ft_printf_x(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	ft_putnbr_base(n, HEXA_BASE_MIN);
}

void	ft_printf_X(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	ft_putnbr_base(n, HEXA_BASE_CAP);
}

void	ft_printf_u(va_list list)
{
	unsigned int	n;

	n = va_arg(list, unsigned int);
	ft_putnbr_uint(n);
}
