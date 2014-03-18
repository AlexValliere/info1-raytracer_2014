/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:35 by apetit            #+#    #+#             */
/*   Updated: 2014/03/18 20:30:52 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<rtfinal.h>

t_type		is_an_object(char *line)
{
	char	*valid[2] = {"SPHERE", "SPOT"};
	int		i;
	int		j;

	i = -1;
	while (++i < 2)
	{
		j = 0;
		while (valid[i][j] == line[j] && line[j])
			++j;
		if (!valid[i][j] && (!line[j] || line[j] == '\t'))
			return (i);
	}
	return (42);
}

#include <stdio.h>
int			check_line(char *line)
{
	t_type	type;

	if (line[0] == '#')
		return (0);
	else if ((type = is_an_object(line)) != 42)
	{
//		printf("obj found : %s\n", type == SPHERE ? "SPHERE" : "NOPE");
		return (1);
	}
	return (-1);
}

void		ft_putepur(char *line)
{
	int		i;
	int		pos;

	i = 0;
	while (line[i])
	{
		write(1, line + i, 1);
		pos = i;
		while (line[i] == '\t')
			++i;
		if (pos == i)
			++i;
	}
}

void		parse_file(int fd, t_scene **scenes)
{
	int		ret;
	char	*buffer;

	(void)scenes;
	while (gnl(fd, &buffer) > 0)
	{
		if ((ret = check_line(buffer)) > 0)
			ft_putstr("\033[0;32m");
		else if (ret == -1)
			ft_putstr("\033[0;31m");
		ft_putepur(buffer);
		ft_putendl("\033[0m");
		free(buffer);
	}
	ft_putendl("");
	close(fd);
}
