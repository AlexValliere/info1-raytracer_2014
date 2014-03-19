/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfinal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:17:33 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/19 16:53:00 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTFINAL_H
# define RTFINAL_H
# define WIN_X		1000
# define WIN_Y		700
# define KEY_QUIT	65307
# define BUFF_SIZE	1024

typedef unsigned int u_int;

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
	int				pos[3];
	int				rot[3];
	int				param[4];
	struct s_obj	*next;
}					t_obj;

typedef struct		s_scene
{
	t_obj			*objs;
	t_obj			*spots;
	t_xyz			camera;
	struct s_scene	*next;
	struct s_scene	*prev;
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

void				obj_free(t_obj **list);
void				obj_pushback(t_obj **list, t_type type, int *nbrs);
t_scene				*scene_new(void);
void				scene_free(t_scene **scenes);
void				scene_pushback(t_scene **list, t_scene *new);

int					ft_atoi(const char *str);
u_int				ft_hextoui(const char *str);
void				ft_putnbr(int n);
int					ft_strlen(const char *str);
int					ft_putstr(const char *str);
int					ft_putendl(const char *str);
int					puterror(char *str);
int					gnl(int const fd, char ** line);

#endif /* !RTFINAL_H */
