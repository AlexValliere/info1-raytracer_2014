/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/21 17:13:46 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<fcntl.h>
#include	<mlx.h>
#include	<rtfinal.h>

static void	get_scenes(t_mlx *mlx, int ac, char **av)
{
	int		i;
	int		fd;

	mlx->scenes = NULL;
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr(":\n");
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_putstr("Error: can't open file\n");
		else
			parse_file(fd, mlx);
	}
}

void		calc_all_scenes(t_mlx *mlx)
{
	int		fix;
	t_scene	*tmp;

	fix = 0;
	tmp = mlx->scenes;
	while ((tmp != mlx->scenes || !fix) && (fix = 1))
	{
		mlx->cur_scene = tmp;
		calc_rtv1(mlx, tmp);
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac < 2)
		return (ft_putstr("usage : ./raytracer MAP1 [MAP2 [...] ]\n"));
	if (!(mlx.ptr = mlx_init()))
		return (puterror("mlx_init"));
	get_scenes(&mlx, ac, av);
	if (mlx.scenes == NULL)
		return (ft_putstr("Error: no valid scene to use\n"));
	calc_all_scenes(&mlx);
	mlx.cur_scene = mlx.scenes;
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "RT = H2SO4");
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_key_hook(mlx.win, &get_keypress, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
