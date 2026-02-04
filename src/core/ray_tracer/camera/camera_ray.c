/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:02 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/04 12:26:26 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"


static t_ray	ft_camera_ray(t_context *context, t_camera camera, int x, int y);
static void	color_pixel(t_context *context, int x, int y, int color);

void	*ft_camera_ray_loop(t_context *context, int start, int end)
{
	int			i;
	int			j;
	t_ray		ray;
	t_colision	col;
	int			color;

	i = 0;
	j = start;
	while (j <= end)
	{
		i = 0;
		while (i < context->mlx.window.width)
		{
			ray = ft_camera_ray(context, context->scene->camera, i, j);
			col = ft_closest_colision(context->scene, ray);
			if (col.colision)
				color = 0XFF0000;
			else
				color = 0XFFFFFF;
			color_pixel(context, i, j, color);
			i++;
		}
		j++;
	}
	return (NULL);
}

static t_ray	ft_camera_ray(t_context *context, t_camera camera, int x, int y)
{
	double		screen_x;
	double		screen_y;
	double		ndc_x;
	double		ndc_y;
	t_vector_3d	dir;
	t_ray		ray;

	ndc_x = (x + 0.5) / context->mlx.window.width;
	ndc_y = (y + 0.5) / context->mlx.window.height;
	screen_x = 2 * ndc_x - 1;
	screen_y = 1 - 2 * ndc_y;
	screen_x *= camera.aspect * camera.scale;
	screen_y *= camera.scale;
	dir = ft_vector_normalize(ft_vector_add_vect(ft_vector_add_vect(ft_vector_mult_scalar(camera.right,
						screen_x), ft_vector_mult_scalar(camera.up, screen_y)),
				camera.forward));
	ray.point = camera.origin;
	ray.vector = dir;
	return (ray);
}

static void	color_pixel(t_context *context, int x, int y, int color)
{
	t_parallel *parallel;

	// ESSA FUNCAO É SÓ PARA TESTE
	parallel = context->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (!context->events.state.window.has_changes)
		*context->mlx.frame_buffer[x][y] = color;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);

}
