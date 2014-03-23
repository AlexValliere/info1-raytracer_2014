/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfinal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:36:36 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/23 16:30:09 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTFINAL_H
# define RTFINAL_H
# define WIN_X		1000
# define WIN_Y		700
# define KEY_QUIT	65307
# define KEY_RIGHT	65363
# define KEY_LEFT	65361
# define BUFF_SIZE	1024
# define NB_OBJ		6

typedef unsigned int u_int;

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef enum		e_type
{
	SPHERE,
	CONE,
	CYLIND,
	PLANE,
	SPOT,
	CAMERA
}					t_type;

typedef struct		s_obj
{
	t_type			type;
	t_xyz			pos;
	t_xyz			rot;
	u_int			color;
	int				param[4];
	struct s_obj	*next;
}					t_obj;

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

typedef struct		s_scene
{
	t_obj			*objs;
	t_obj			*spots;
	t_obj			*camera;
	t_img			img;
	struct s_scene	*next;
	struct s_scene	*prev;
}					t_scene;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	t_scene			*scenes;
	t_scene			*cur_scene;
	t_obj			*cur_obj;
	t_xyz			plane;
	t_xyz			vector;
	double			k;
}					t_mlx;

void				calc_sphere(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj);
void				calc_cylinder(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj);
void				calc_cone(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj);
void				calc_plane(t_xyz *eye, t_xyz *vector, double *k, t_obj *obj);

u_int				mult_color(u_int color, double perc);
u_int				add_2color(u_int color1, u_int color2);

int					light_nb(t_obj *spots);
u_int				calc_light(t_mlx *mlx, t_scene *scene, t_obj *spot);
u_int				calc_all_lights(t_mlx *mlx, t_scene *scene);

void				move_eye(t_xyz *eye, t_xyz *vector, t_obj *tmp, int invert);
void				all_rot(t_xyz *xyz, t_xyz *rot, int invert);
void				calc_rtv1(t_mlx *mlx, t_scene *scene);
void				calc_curobj(t_xyz *eye, t_xyz *vector,
								t_obj *obj, double *k);

void				pxl_putimg(t_mlx *mlx, int x, int y, u_int color);
int					get_keypress(int keycode, t_mlx *mlx);
int					get_expose(t_mlx *mlx);

void				parse_file(int fd, t_mlx *mlx);

t_scene				*scene_new(t_mlx *mlx);
void				scene_free(t_scene **scenes);
void				scene_pushback(t_scene **list, t_scene *new);
t_obj				*obj_new(t_type type, int *nbrs, u_int color);
void				obj_free(t_obj **list);
void				obj_pushback(t_obj **list, t_type type,
								int *nbrs, u_int color);

int					ft_atoi(const char *str);
u_int				ft_hextoui(const char *str);
void				ft_putnbr(int n);
int					ft_strlen(const char *str);
int					ft_putstr(const char *str);
int					ft_putendl(const char *str);
int					puterror(char *str);
int					gnl(int const fd, char ** line);

#endif /* !RTFINAL_H */
