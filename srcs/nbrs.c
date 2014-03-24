/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:33:06 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/24 18:32:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<rtfinal.h>

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		sign;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	nb = 0;
	sign = (str[i] == '-' ? -1 : 1);
	i = (str[i] == '-' || str[i] == '+' ? i : i - 1);
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0') * sign;
	}
	return (nb);
}

t_int		ft_hextoui(const char *str)
{
	t_int	i;
	t_int	nb;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	nb = 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		nb *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			nb += (str[i] - '0');
		else
			nb += (str[i] - 'A' + 10);
		++i;
	}
	return (nb);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		write(1, "-", 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	c = n + '0';
	write(1, &c, 1);
}
