/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:50:52 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:49:44 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	void	(*flag)(va_list);

char			*ft_printf_flags_tab(char *flags_tab);
flag			*ft_printf_flags_tab_fct(flag *flags_tab_fct);
int				ft_printf_match_fct(const char *format, char *flags_tab,
									flag *flags_tab_fct, va_list args);
void			ft_printf_d(va_list list);
void			ft_printf_i(va_list list);
void			ft_printf_c(va_list list);
void			ft_printf_s(va_list list);
void			ft_printf_p(va_list list);
void			ft_printf_o(va_list list);
void			ft_printf_x(va_list list);
void			ft_printf_X(va_list list);
void			ft_printf_u(va_list list);

#endif
