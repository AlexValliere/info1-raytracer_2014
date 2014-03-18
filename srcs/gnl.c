/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:09:29 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 18:20:11 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<stdlib.h>
#include		<rtfinal.h>

static char		*ft_strjoin(char const *s1, char const *s2)
{
	int			s1_len;
	int			s2_len;
	char		*str;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	free((void *)s1);
	free((void *)s2);
	return (str);
}

static int		complete_line(int const fd, char **line)
{
	int			ret;
	char		*new_line;

	new_line = NULL;
	ret = gnl(fd, &new_line);
	if (new_line != NULL)
		*line = ft_strjoin(*line, new_line);
	else if (ret == -1)
		return (-1);
	return (1);
}

int				gnl(int const fd, char **line)
{
	static char	buf[BUFF_SIZE + 1] = {0};
	static int	i = 0;
	int			j;

	if (!buf[i])
	{
		if ((j = read(fd, buf, BUFF_SIZE)) <= 0)
			return (j);
		buf[j] = 0;
		i = 0;
	}
	if ((*line = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	j = 0;
	while (buf[i] && buf[i] != '\n' && j < BUFF_SIZE)
		(*line)[j++] = buf[i++];
	(*line)[j] = 0;
	if (buf[i] == '\n')
		++i;
	else
		return (complete_line(fd, line));
	return (1);
}
