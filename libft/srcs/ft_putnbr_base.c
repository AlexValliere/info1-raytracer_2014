/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:37:46 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 19:51:46 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int	start;
	unsigned int	end;

	end = nb % ft_strlen(base);
	start = (nb - end) / ft_strlen(base);
	if (start)
		ft_putnbr_base(start, base);
	ft_putchar(base[end]);
}
