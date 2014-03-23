/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/23 14:39:18 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<stdlib.h>
#include	<rtfinal.h>
#include 	<pthread.h>

void		move_eye(t_xyz *eye, t_xyz *vector, t_obj *tmp, int invert)
{
	if (invert == 1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
	eye->x += invert * tmp->pos.x;
	eye->y += invert * tmp->pos.y;
	eye->z += invert * tmp->pos.z;
	vector->x += invert * tmp->pos.x;
	vector->y += invert * tmp->pos.y;
	vector->z += invert * tmp->pos.z;
	if (invert == -1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
}

void		calc_curobj(t_xyz *eye, t_xyz *vector, t_obj *obj, double *k)
{
	move_eye(eye, vector, obj, -1);
	if (obj->type == SPHERE)
		calc_sphere(eye, vector, k, obj);
	else if (obj->type == CYLIND)
		calc_cylinder(eye, vector, k, obj);
	else if (obj->type == CONE)
		calc_cone(eye, vector, k, obj);
	else if (obj->type == PLANE)
		calc_plane(eye, vector, k, obj);
	move_eye(eye, vector, obj, 1);
}

static void	calc_inter(int x, int y, t_mlx *mlx, t_scene *scene)
{
	double	k[2];
	t_obj	*tmp;
/*	u_int	color;*/

	(void)x;
	(void)y;
	mlx->k = 0xFFFFFFFF;
	mlx->cur_obj = NULL;
	tmp = scene->objs;
	while (tmp)
	{
		calc_curobj(&mlx->eye, &mlx->vector, tmp, k);
		if (k[0] >= 0 && mlx->k > k[0] && (mlx->cur_obj = tmp))
			mlx->k = k[0];
		if (k[1] >= 0 && mlx->k > k[1] && (mlx->cur_obj = tmp))
			mlx->k = k[1];
		tmp = tmp->next;
	}
	if (mlx->cur_obj != NULL)
		pxl_putimg(mlx, x, y, mlx->cur_obj->color);
}

void		calc_ray_xy(int x, int y, t_mlx *mlx, t_scene *scene)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock (&mutex);
	mlx->plane.x = 100; /* a changer?? */
	mlx->plane.y = (WIN_X / 2.0) - x;
	mlx->plane.z = (WIN_Y / 2.0) - y;
	mlx->vector.x = mlx->plane.x - mlx->eye.x;
	mlx->vector.y = mlx->plane.y - mlx->eye.z;
	mlx->vector.z = mlx->plane.z - mlx->eye.z;
	all_rot(&mlx->vector, &mlx->eyerot, 1);
	calc_inter(x, y, mlx, scene);
	pthread_mutex_unlock (&mutex);
}

#include <string.h>

void		calc_rtv1(t_mlx *mlx, t_scene *scene)
{
	t_thrd	para_th;
	pthread_t		thread[4];

	para_th.mlx = mlx;
	para_th.scene = scene;
	all_rot(&mlx->eye, &mlx->eyerot, 1);
	pthread_create(&thread[0], NULL, &calc_thread1, &para_th);
	pthread_create(&thread[1], NULL, &calc_thread2, &para_th);
	pthread_create(&thread[2], NULL, &calc_thread3, &para_th);
	pthread_create(&thread[3], NULL, &calc_thread4, &para_th);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}
