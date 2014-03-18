/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 18:44:58 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	<stdlib.h>
#include	<rtfinal.h>
#include	<parser.h>

#include <unistd.h>
#include <fcntl.h>

void		get_scenes(t_scene **scenes, int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	*scenes = NULL;
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr(":\n");
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_putstr("Error: can't open file\n");
		else
		{
			while (gnl(fd, &line) > 0)
			{
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
			close(fd);
		}
	}
}

int			main(int ac, char **av)
{
	t_mlx	mlx;
	t_scene	*scenes;

	if (ac < 2)
		return (ft_putstr("usage : ./raytracer MAP1 [MAP2 [...] ]\n"));
	get_scenes(&scenes, ac, av);
	if (scenes == NULL)
		return (ft_putstr("Error: no valid scene to use\n"));
	if (!(mlx.ptr = mlx_init()))
		return (puterror("mlx_init"));
	mlx.screen.ptr = mlx_new_image(mlx.ptr, WIN_X, WIN_Y);
	mlx.screen.data = mlx_get_data_addr(mlx.screen.ptr, &mlx.screen.bpp,
										&mlx.screen.sline, &mlx.screen.endian);
	mlx.screen.bpp = mlx.screen.bpp >> 3;
	// code here
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "RT = H2SO4");
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_key_hook(mlx.win, &get_keypress, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
