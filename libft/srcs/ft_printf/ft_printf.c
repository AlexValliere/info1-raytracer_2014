/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:45:48 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:49:19 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list args;
	char	*flags_tab;
	flag	*flags_tab_fct;
	int		i;

	flags_tab = NULL;
	flags_tab_fct = NULL;
	va_start(args, format);
	flags_tab = ft_printf_flags_tab(flags_tab);
	flags_tab_fct = ft_printf_flags_tab_fct(flags_tab_fct);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			i = i + ft_printf_match_fct(format + i, flags_tab,
										flags_tab_fct, args);
		else
			ft_putchar(format[i]);
		++i;
	}
	va_end(args);
	return (i + 1);
}
