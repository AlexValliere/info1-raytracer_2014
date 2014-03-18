/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:10:55 by apetit            #+#    #+#             */
/*   Updated: 2014/02/05 15:54:24 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/libft.h"

static long		ft_process_waiting(char buffer[BUFF_SIZE], int order)
{
	static long	process_waiting = 0;
	static long	i;

	if (process_waiting == 0)
	{
		i = ft_strlen(buffer);
		while (i >= 0)
		{
			if (buffer[i] == '\n')
				++process_waiting;
			--i;
		}
	}
	if (process_waiting > 0)
	{
		if (order == -1)
		{
			--process_waiting;
			if (process_waiting == 0)
				--process_waiting;
		}
	}
	if (process_waiting == -1 && order == 1)
		++process_waiting;
	return (process_waiting);
}

static char		*ft_save_line_pt2(long * pos, char ** swap, char * buf)
{
	char		*line;
	long		i;

	i = 0;
	line = NULL;
	while (i < (long)ft_strlen(buf) && buf[i] != '\n')
		++i;
	if (buf[i] == '\n')
	{
		pos[0] = i;
		line = NULL;
		line = malloc(sizeof(char *) * (i + 1));
		line = ft_strsub(buf, 0, i);
		*swap = malloc(sizeof(char *) * (ft_strlen(buf) - i));
		*swap = ft_strsub(buf, i + 1, ft_strlen(buf) - i - 1);
		ft_process_waiting(buf, -1);
	}
	return (line);
}

static char		*ft_save_line_pt1(char ** swap, char * buffer)
{
	char		*line;
	long		i;
	static long	eol_pos[1] = {-1};

	line = NULL;
	if (*swap == NULL)
	{
		line = ft_save_line_pt2(eol_pos, &(*swap), buffer);
		i = 0;
	}
	else
	{
		i = 0;
		while (i < (long)ft_strlen(swap[0]) && swap[0][i] != '\n')
			++i;
		if (swap[0][i] == '\n')
		{
			*eol_pos = i;
			line = NULL;
			line = malloc(sizeof(char *) * (i + 1));
			line = ft_strsub(*swap, 0, i);
			*swap = ft_strsub(*swap, i + 1, ft_strlen(*swap) - i - 1);
			ft_process_waiting(buffer, -1);
		}
	}
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	static char	buffer[BUFF_SIZE];
	static char	*swap = NULL;
	static long	pos = 0;

	if (fd == -1)
		return (-1);
	if (pos == 0)
	{
		pos = read(fd, buffer, sizeof(buffer));
		swap = ft_strjoin(swap, buffer);
	}
	while (ft_process_waiting(buffer, 0) <= 0 && pos != 0)
	{
		if (ft_process_waiting(buffer, 0) == -1)
			ft_process_waiting(buffer, 1);
		pos = read(fd, buffer, sizeof(buffer));
		swap = ft_strjoin(swap, buffer);
	}
	if (ft_process_waiting(buffer, 0) > 0 && pos != 0)
	{
		*line = ft_save_line_pt1(&swap, buffer);
		return (1);
	}
	*line = 0;
	return (0);
}
