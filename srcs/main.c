/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/19 17:16:39 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<fcntl.h>
#include	<mlx.h>
#include	<rtfinal.h>

static void	get_scenes(t_scene **scenes, int ac, char **av)
{
	int		i;
	int		fd;

	*scenes = NULL;
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr(":\n");
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_putstr("Error: can't open file\n");
		else
			parse_file(fd, scenes);
	}
}

static void		init_all(t_mlx *mlx) /* a virer */
{
	mlx->eye = (t_xyz){-500, 0, 0};
	mlx->eyerot = (t_xyz){0, 0, 0};
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac < 2)
		return (ft_putstr("usage : ./raytracer MAP1 [MAP2 [...] ]\n"));
	get_scenes(&mlx.scenes, ac, av);
	if (mlx.scenes == NULL)
		return (ft_putstr("Error: no valid scene to use\n"));
	if (!(mlx.ptr = mlx_init()))
		return (puterror("mlx_init"));
	mlx.screen.ptr = mlx_new_image(mlx.ptr, WIN_X, WIN_Y);
	mlx.screen.data = mlx_get_data_addr(mlx.screen.ptr, &mlx.screen.bpp,
										&mlx.screen.sline, &mlx.screen.endian);
	mlx.screen.bpp = mlx.screen.bpp >> 3;
	init_all(&mlx); /* a virer */
	calc_rtv1(&mlx);
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "RT = H2SO4");
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_key_hook(mlx.win, &get_keypress, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
