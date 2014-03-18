/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:20 by apetit            #+#    #+#             */
/*   Updated: 2014/03/07 15:07:46 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define CMP_STR(x, str, i) ft_strcmp(x, ft_strsub(str, i, i + ft_strlen(x)))
# define OBJECT_NODE(x) ((t_object *)(x->data))
# define SPOT_NODE(x) ((t_spot *)(x->data))

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos;

typedef enum		s_object_type
{
	circle,
	cylinder,
	plane,
	square,
	rectangle
}					t_object_type;

typedef struct		s_object
{
	t_object_type	type;
	void			*data;
}					t_object;

typedef struct		s_circle
{
	t_pos			pos;
	int				radius;
}					t_circle;

typedef struct		s_cam
{
	int				screen_width;
	int				screen_height;
	t_pos			pos;
}					t_cam;

typedef struct		s_scenery
{
	t_dlist			*objects;
	t_dlist			*spots;
	t_cam			cam;
}					t_scenery;

int		ft_parser(t_scenery **scenery, char *mapfile);

#endif /* !PARSER_H */
