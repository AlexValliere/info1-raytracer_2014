/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:19:31 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 20:05:04 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int			ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			ft_putstr(const char *str)
{
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	return (1);
}

int			ft_putendl(const char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	return (1);
}

int			puterror(char *str)
{
	write(2, "rtv1: error with ", 19);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
