/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfinal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:17:33 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 19:47:02 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTFINAL_H
# define RTFINAL_H
# define WIN_X		1000
# define WIN_Y		700
# define KEY_QUIT	65307
# define BUFF_SIZE	1024
# include <stdlib.h>

typedef unsigned int u_int;

typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_xyz
{
	int				x;
	int				y;
	int				z;
}					t_xyz;

typedef enum		e_type
{
	SPHERE,
	SPOT
}					t_type;

typedef struct		s_obj
{
	t_type			type;
	t_xyz			pos;
	t_xyz			rot;
	void			*data;
}					t_obj;

typedef struct		s_sphere
{
	int				radius;
}					t_sphere;

typedef struct		s_scene
{
	t_list			*objs;
	t_list			*spots;
	t_xyz			camera;
}					t_scene;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				x;
	int				y;
	int				bpp;
	int				sline;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	t_img			screen;
}					t_mlx;

void				pxl_putimg(t_mlx *mlx, int x, int y, u_int color);
int					get_keypress(int keycode, t_mlx *mlx);
int					get_expose(t_mlx *mlx);

void				parse_file(int fd, t_scene **scenes);

void				lst_pushback(t_list **list, void *data, size_t size);
void				lst_free(t_list **list);

int					ft_strlen(const char *str);
int					ft_putstr(const char *str);
int					puterror(char *str);
int					gnl(int const fd, char ** line);

#endif /* !RTFINAL_H */
