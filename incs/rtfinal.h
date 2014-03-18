/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfinal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:17:33 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 14:31:38 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTFINAL_H
# define RTFINAL_H
# define WIN_X		1000
# define WIN_Y		700
# define KEY_QUIT	65307
typedef unsigned int u_int;
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
void				ft_putstr(const char *str);
int					puterror(char *str);
int					get_keypress(int keycode, t_mlx *mlx);
int					get_expose(t_mlx *mlx);
#endif /* !RTFINAL_H */
