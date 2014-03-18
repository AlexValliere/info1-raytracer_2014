/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:35 by apetit            #+#    #+#             */
/*   Updated: 2014/03/18 14:46:38 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <libft.h>
#include <parser.h>

int		ft_mapfile_exists(char *mapfile)
{
	int					fd;

	fd = open(mapfile, O_RDONLY);
	if (fd != -1)
		return (1);
	else
	{
		ft_printf("Error : %s\n", strerror(errno));
		return (-1);
	}
}

int		ft_parser_line_is_a_com(char *line)
{
	if (line[0] == '#')
		return (1);
	else
		return (0);
}

int		ft_parser_line_is_a_screen(char *line)
{
	int					i;

	if (ft_strlen(line) > 2)
	{
		if (line[0] != '[' || line[ft_strlen(line) - 1] != ']')
			return (0);
		i = 1;
		while (line[i] && ft_isdigit(line[i]))
			++i;
		if (i == 0 || line[i] != ',')
			return (0);
		if (line[++i] && line[i++] != ' ')
			return (0);
		if (!(line[i] && ft_isdigit(line[i]) && line[i - 1] == ' '))
			return (0);
		while (line[i] && ft_isdigit(line[i]))
			++i;
		if (line[i] != ']')
			return (0);
		return (1);
	}
	return (0);
}

int		ft_parser_line_is_an_object(char *line)
{
	t_object_type	object_type;

	if (CMP_STR("CIRCLE", line, 0) == 0)
		object_type = circle;
	else if (CMP_STR("CYLINDER", line, 0) == 0)
		object_type = cylinder;
	else if (CMP_STR("PLANE", line, 0) == 0)
		object_type = plane;
	else if (CMP_STR("SQUARE", line, 0) == 0)
		object_type = square;
	else if (CMP_STR("RECTANGLE", line, 0) == 0)
		object_type = rectangle;
	else if (CMP_STR("CONE", line, 0) == 0)
		object_type = rectangle;
	else
		return (0);
	return (object_type);
}

int		ft_strcountsp(char *str)
{
	int			i;
	int			nbr_space;

	i = 0;
	nbr_space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			++nbr_space;
		++i;
	}
	return (nbr_space);
}

int		ft_parser_line_is_a_valid_circle(char *line)
{
	char		*new_line;
	int			i;

	new_line = ft_strdel_double_sp(ft_strdup_tabtosp(line));
	i = ft_strlen("circle");
	if (!new_line[i] || new_line[i++] != ' ')
		return (0);
	while (ft_isdigit(new_line[i]))
		++i;
	if (new_line[i++] != ' ')
		return (0);
	while (ft_isdigit(new_line[i]))
		++i;
	if (new_line[i++] != ' ')
		return (0);
	while (ft_isdigit(new_line[i]))
		++i;
	if (new_line[i++] != ' ')
		return (0);
	while (ft_isdigit(new_line[i]))
		++i;
	if (new_line[i])
		return (0);
	return (1);
}

int		ft_parser_line_is_a_valid_object(char *line, t_object_type object_type)
{
	if (object_type == circle)
	{
		if (ft_parser_line_is_a_valid_circle(line))
			return (object_type);
	}
	return (-1);
}

int		ft_parser_check_line(char *line)
{
	t_object_type	object_type;

	if (ft_parser_line_is_a_com(line))
		return (0);
	else if (ft_parser_line_is_a_screen(line))
		return (1);
	else if (ft_parser_line_is_an_object(line) >= 0)
	{
		object_type = ft_parser_line_is_an_object(line);
		if (ft_parser_line_is_a_valid_object(line, object_type) != -1)
			return (2);
	}
	return (-1);
}

int		ft_init_scenery(t_scenery **scenery)
{
	*scenery = malloc(sizeof(t_scenery));
	if (*scenery != NULL)
	{
		(*scenery)->objects = NULL;
		(*scenery)->spots = NULL;
		(*scenery)->objects = ft_dlst_new();
		(*scenery)->spots = ft_dlst_new();
		if ((*scenery)->objects != NULL && (*scenery)->spots != NULL)
			return (0);
	}
	ft_printf("Error while initiliazing objects dlist and spots dlist.\n");
	return (-1);
}

int		ft_parser_add_circle(t_scenery **scenery, char *object_data)
{
	t_object_type	object_type;
	t_object		*object;
	t_pos			pos;
	char			**split_data;
	size_t			sizeof_dlist;

	object_type = circle,
	object = NULL;
	object = malloc(sizeof(t_object));
	object->type = object_type;
	object->data = NULL;
	object->data = malloc(sizeof(t_circle));
	split_data = NULL;
	split_data = ft_strsplit(object_data, ' ');
	if (object->data != NULL && split_data != NULL)
	{
		sizeof_dlist = ft_dlst_len((*scenery)->objects);
		pos.x = ft_atoi(split_data[1]);
		pos.y = ft_atoi(split_data[2]);
		pos.z = ft_atoi(split_data[3]);
		((t_circle *)(object->data))->pos = pos;
		((t_circle *)(object->data))->radius = ft_atoi(split_data[4]);
		(*scenery)->objects = ft_dlst_append((*scenery)->objects,
										object, sizeof(object));
		if (ft_dlst_len((*scenery)->objects) == sizeof_dlist + 1)
			return (0);
		else
			ft_printf("Circle object was not added to dlist.\n");
	}
	ft_printf("Error while adding circle object.\n");
	return (-1);
}

int		ft_parser_add_object(t_scenery **scenery, char *object)
{
	if (ft_parser_line_is_a_valid_circle(object))
		return (ft_parser_add_circle(&(*scenery), object));
	else
		return (-1);
	return (0);
}

int		ft_parser(t_scenery **scenery, char *mapfile)
{
	int					fd;
	char				*buffer;

	if (ft_mapfile_exists(mapfile))
	{
		fd = open(mapfile, O_RDONLY);
		if (fd != -1 && ft_init_scenery(&(*scenery)) != -1)
		{
			while (get_next_line(fd, &buffer) > 0)
			{
				if (ft_parser_check_line(buffer) == 2)
					ft_parser_add_object(&(*scenery), buffer);
			}
		}
		else
			return (-1);
	}
	return (0);
}
