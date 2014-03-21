/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:39:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/21 16:12:24 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<mlx.h>
#include		<stdlib.h>
#include		<rtfinal.h>

void			scene_set_img(t_mlx *mlx, t_img *img)
{
	img->ptr = mlx_new_image(mlx->ptr, WIN_X, WIN_Y);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
								&img->sline, &img->endian);
	img->bpp = img->bpp >> 3;
}

t_scene			*scene_new(t_mlx *mlx)
{
	t_scene		*new;

	if ((new = (t_scene *)malloc(sizeof(t_scene))) == NULL)
		return (NULL);
	new->spots = NULL;
	new->objs = NULL;
	new->camera = (t_xyz){0, 0, 0};
	scene_set_img(mlx, &new->img);
	new->next = new;
	new->prev = new;
	return (new);
}

void			scene_pushback(t_scene **list, t_scene *new)
{
	if (!*list)
		*list = new;
	else
	{
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		new->next = *list;
	}
}

void			scene_free(t_scene **list)
{
	int			fix;
	t_scene		*tmp;
	t_scene		*tmp2;

	if (*list == NULL)
		return ;
	fix = 0;
	tmp = *list;
	while ((tmp != *list || !fix) && (fix = 1))
	{
		tmp2 = tmp->next;
		obj_free(&(tmp->spots));
		obj_free(&(tmp->objs));
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
