/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:35 by apetit            #+#    #+#             */
/*   Updated: 2014/03/24 18:33:08 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<rtfinal.h>

static void	ft_putepur(char *line)
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

t_type		is_an_object(char *line)
{
	char	*valid[NB_OBJ] = {"SPHERE", "CONE", "CYLIND", "PLANE",
							  "PARAB", "HYPERB", "SPOT", "CAMERA"};
	int		i;
	int		j;

	i = -1;
	while (++i < NB_OBJ)
	{
		j = 0;
		while (valid[i][j] == line[j] && line[j])
			++j;
		if (!valid[i][j] && (!line[j] || line[j] == '\t'))
			return (i);
	}
	return (NO_TYPE);
}

t_int		get_nbrs(char *line, int *nbrs)
{
	int		i;
	int		pos;
	t_int	color;

	color = 4000000;
	pos = 0;
	i = 0;
	while (line[i] && line[i] != '\t')
		++i;
	while (line[i])
	{
		while (line[i] == '\t')
			++i;
		if (pos == 6 && color == 4000000)
			color = ft_hextoui(line + i);
		else
			nbrs[pos++] = ft_atoi(line + i);
		while (line[i] && line[i] != '\t')
			++i;
		if (line[i])
			++i;
	}
	while (pos < 10)
		nbrs[pos++] = -424242;
	return (color);
}

int			check_line(char *line, t_scene **new)
{
	t_type	type;
	int		nbrs[10];
	t_int	color;

	if (line[0] == '#')
		return (0);
	else if ((type = is_an_object(line)) != NO_TYPE)
	{
		color = get_nbrs(line, nbrs);
		if (type == SPOT)
			obj_pushback(&((*new)->spots), SPOT, nbrs, color);
		else if (type == CAMERA)
			(*new)->camera = obj_new(CAMERA, nbrs, 0);
		else
			obj_pushback(&((*new)->objs), type, nbrs, color);
		return (1);
	}
	return (-1);
}

void		parse_file(int fd, t_mlx *mlx)
{
	int		ret;
	t_scene	*new;
	char	*buffer;

	new = scene_new(mlx);
	while (gnl(fd, &buffer) > 0)
	{
		if ((ret = check_line(buffer, &new)) == 1)
			ft_putstr("\033[0;32m");
		else if (ret == -1)
			ft_putstr("\033[0;31m");
		ft_putepur(buffer);
		ft_putendl("\033[0m");
		free(buffer);
	}
	ft_putstr("\n");
	if (!new->objs || !new->spots || !new->camera)
		scene_free(&new);
	else
		scene_pushback(&mlx->scenes, new);
	close(fd);
}
