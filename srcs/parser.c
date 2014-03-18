/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:35 by apetit            #+#    #+#             */
/*   Updated: 2014/03/18 19:53:13 by gabtoubl         ###   ########.fr       */
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
		printf("obj found : %s\n", type == SPHERE ? "SPHERE" : "NOPE");
		return (1);
	}
	ft_putstr("Error with line: \"");
	ft_putstr(line);
	ft_putstr("\"\n");
	return (-1);
}

void		parse_file(int fd, t_scene **scenes)
{
	char	*buffer;

	(void)scenes;
	while (gnl(fd, &buffer) > 0)
	{
		check_line(buffer);
		free(buffer);
	}
	close(fd);
}
