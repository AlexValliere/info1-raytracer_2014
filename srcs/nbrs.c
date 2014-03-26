/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:33:06 by cvxfous           #+#    #+#             */
/*   Updated: 2014/03/26 16:17:10 by apetit           ###   ########.fr       */
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
	if (str[i] && str[i] != '\t' && str[i] != '\n')
		return (-424242);
	return (nb);
}

t_int		ft_hextoui(const char *str)
{
	t_int	i;
	t_int	nb;
	int		k;

	k = 0;
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
		++k;
	}
	if ((str[i] && str[i] != '\t' && str[i] != '\n') || k != 6)
		return (0xFFFFFFFF);
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
