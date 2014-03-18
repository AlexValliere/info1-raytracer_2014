/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 23:28:32 by apetit            #+#    #+#             */
/*   Updated: 2014/01/02 00:43:27 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

char	*ft_printf_flags_tab(char *flags_tab)
{
	flags_tab = malloc(9 * sizeof(char));
	flags_tab[0] = 'd';
	flags_tab[1] = 'i';
	flags_tab[2] = 'c';
	flags_tab[3] = 's';
	flags_tab[4] = 'p';
	flags_tab[5] = 'o';
	flags_tab[6] = 'x';
	flags_tab[7] = 'X';
	flags_tab[8] = 'u';
	return (flags_tab);
}

flag	*ft_printf_flags_tab_fct(flag *flags_tab_fct)
{
	flags_tab_fct = malloc(9 * sizeof(flag));
	flags_tab_fct[0] = ft_printf_d;
	flags_tab_fct[1] = ft_printf_i;
	flags_tab_fct[2] = ft_printf_c;
	flags_tab_fct[3] = ft_printf_s;
	flags_tab_fct[4] = ft_printf_p;
	flags_tab_fct[5] = ft_printf_o;
	flags_tab_fct[6] = ft_printf_x;
	flags_tab_fct[7] = ft_printf_X;
	flags_tab_fct[8] = ft_printf_u;
	return (flags_tab_fct);
}

int		ft_printf_match_fct(const char *format, char *flags_tab,
							flag *flags_tab_fct, va_list args)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while ((format[i] != flags_tab[j]) && (flags_tab[j] != '\0'))
		++j;
	if (flags_tab[j] != '\0')
		flags_tab_fct[j](args);
	else
	{
		ft_putchar('%');
		ft_putchar(format[i]);
	}
	return (i);
}
