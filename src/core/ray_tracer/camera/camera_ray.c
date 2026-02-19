/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:02 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/19 00:35:56 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"
#include "light.h"

static bool		color_pixel(t_context *context, int x, int y, int color);
t_vector_3d		ft_reflexion(t_context *context, int depth, t_ray ray);

void	*ft_camera_ray_loop(t_context *context, int start, int end)
{
	int			i;
	int			j;
	int			color;
	t_vector_3d	vect_color;

	i = -1;
	j = start - 1;
	while (++j <= end)
	{
		i = -1;
		while (++i < context->mlx.window.width)
		{
			if (context->callbacks.is_process_stopped(context))
				return (NULL);
			vect_color = ft_reflexion(context, 0, ft_camera_ray(&context->mlx,
						&context->scene->camera, i, j));
			if (context->callbacks.is_process_stopped(context))
				return (NULL);
			color = ft_vector_to_int_color(vect_color);
			if (color_pixel(context, i, j, color))
				return (NULL);
		}
	}
	return (NULL);
}

t_ray	ft_camera_ray(t_mlx *restrict mlx,
			t_camera *restrict camera, int x, int y)
{
	double		screen_x;
	double		screen_y;
	t_vector_3d	dir;
	t_ray		ray;

	if (mlx->window.width > 0)
		screen_x = (2 * (x + 0.5) / mlx->window.width) - 1;
	else
		screen_x = 1;
	if (mlx->window.height > 0)
		screen_y = 1 - 2 * ((y + 0.5) / mlx->window.height);
	else
		screen_y = 1;
	screen_x *= camera->aspect * camera->scale;
	screen_y *= camera->scale;
	dir = ft_vec_norm(ft_vec_add(ft_vec_add(ft_vec_mult(camera->right,
						screen_x), ft_vec_mult(camera->up, screen_y)),
				camera->forward));
	ray.point = camera->origin;
	ray.vector = dir;
	return (ray);
}

static bool	color_pixel(t_context *context, int x, int y, int color)
{
	if (context->callbacks.is_process_stopped(context))
		return (true);
	*context->mlx.frame_buffer[x][y] = color;
	return (false);
}

int	ft_vector_to_int_color(t_vector_3d color)
{
	int	r;
	int	g;
	int	b;

	r = clamp_int((color.x * 255 + 0.5));
	g = clamp_int((color.y * 255 + 0.5));
	b = clamp_int((color.z * 255 + 0.5));
	return ((r << 16) | (g << 8) | b);
}

t_vector_3d	ft_reflexion(t_context *context, int depth, t_ray ray)
{
	t_colision	col;
	t_ray		reflected_ray;

	if (context->callbacks.is_process_stopped(context))
		return (ft_new_vector_3d(0, 0, 0));
	col = ft_closest_colision(context->scene, &ray);
	if (!col.colision)
		return (context->scene->norm_color_back);
	col.color_local = ft_local_color(context, col);
	if (depth > 10 || col.polyhedron.material.kr <= 0.0
		|| isnan(ft_vec_mod(ray.vector)) || isinf(ft_vec_mod(ray.vector)))
		return (col.color_local);
	if (ft_vec_dot(ray.vector, col.normal) > 0)
		col.normal = ft_vec_mult(col.normal, -1);
	col.normal = ft_vec_norm(col.normal);
	reflected_ray.vector = ft_vec_norm(ft_vec_sub(ray.vector,
				ft_vec_mult(col.normal, 2.0
					* ft_vec_dot(ray.vector, col.normal))));
	reflected_ray.point = ft_point_add_vect(col.colision_point,
			ft_vec_mult(col.normal, 1e-4));
	col.color_reflexive = ft_reflexion(context, depth + 1, reflected_ray);
	col.color_final = ft_vec_add(ft_vec_mult(col.color_local, (1
					- col.polyhedron.material.kr)),
			ft_vec_mult(col.color_reflexive, col.polyhedron.material.kr));
	return (col.color_final);
}
