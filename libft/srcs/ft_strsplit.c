/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:46:48 by apetit            #+#    #+#             */
/*   Updated: 2014/02/04 15:19:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

static char	**ft_return_null_str(void)
{
	char	**ret;

	ret = (char **)malloc(1 * sizeof(char *));
	ret[0] = (char *)malloc(1 * sizeof(char));
	ret[0] = '\0';
	return (ret);
}

static int	str_split_len(char const *s, char c, size_t i)
{
	int		str_len;

	str_len = 0;
	if (s && i < ft_strlen(s))
	{
		while (s[i] != '\0' && s[i] != (char)c)
		{
			++i;
			++str_len;
		}
	}
	return (str_len);
}

static int	ft_number_of_words(char const *s, char c)
{
	size_t	i;
	int		number_of_words;

	i = 0;
	number_of_words = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == (char)c)
			++i;
		if (s[i] != '\0' && s[i] != (char)c)
		{
			i = i + str_split_len(s, c, i) + 1;
			++number_of_words;
		}
	}
	return (number_of_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		number_of_words;
	size_t	i;

	if (!s)
		return (ft_return_null_str());
	number_of_words = ft_number_of_words(s, c);
	if (number_of_words > 0)
	{
		ret = (char **)malloc(number_of_words * (sizeof(char *) + 1));
		if (!ret)
			return (NULL);
		i = 0;
		number_of_words = 0;
		while (i < ft_strlen(s))
		{
			while (s[i] == c)
				++i;
			ret[number_of_words++] = ft_strsub(s, i, str_split_len(s, c, i));
			i = i + str_split_len(s, c, i) + 1;
		}
		ret[number_of_words] = '\0';
		return (ret);
	}
	return (ft_return_null_str());
}
