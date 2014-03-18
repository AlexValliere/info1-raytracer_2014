/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:51:22 by apetit            #+#    #+#             */
/*   Updated: 2014/01/26 20:02:20 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	static int	i = 0;
	char		c;

	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		if (i == 1)
		{
			c = '-';
			write(fd, &c, 1);
			i = 0;
		}
		c = 48 + n;
		write(fd, &c, 1);
	}
}
