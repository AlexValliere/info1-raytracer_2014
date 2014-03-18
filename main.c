/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 14:14:32 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<mlx.h>
#include		<stdlib.h>
#include		"rtfinal.h"
#include		"parser/includes/parser.h"

void	ft_print_objects(t_scenery *scenery)
{
	t_node			*tmp;

	if (ft_dlst_len(scenery->objects) > 0)
	{
		tmp = scenery->objects->head;
		while (tmp != NULL)
		{
			if (OBJECT_NODE(tmp)->type == circle)
				ft_printf("CIRCLE\n");
			tmp = tmp->next;
		}
	}
}

t_scenery		*ft_get_scenery(char *mapfile)
{
	t_scenery	*scenery;

	scenery = NULL;
	scenery = malloc(sizeof(t_scenery));
	if (scenery != NULL)
	{
		ft_parser(&scenery, mapfile);
		ft_print_objects(scenery);
	}
	else
		ft_printf("Cannot allocate memory to scenery.\n");
	return (scenery);
}

int				main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_scenery	*scenery;

	if (argc == 2)
	{
		scenery = ft_get_scenery(argv[1]);
		if (scenery != NULL)
		{
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
		}
	}
	else
		ft_printf("usage : %s path_to_mapfile\n", argv[0]);
	return (0);
}
