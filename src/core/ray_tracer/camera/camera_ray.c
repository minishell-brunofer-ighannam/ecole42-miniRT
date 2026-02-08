/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:02 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/08 16:17:25 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"
#include "light.h"

static t_ray	ft_camera_ray(t_context *context, t_camera camera, int x,
					int y);
static bool		color_pixel(t_context *context, int x, int y, int color);
int				ft_vector_to_int_color(t_vector_3d color);
int				clamp_int(int v);
t_vector_3d		ft_reflexion(t_context *context, int depth, t_ray ray);

void	*ft_camera_ray_loop(t_context *context, int start, int end)
{
	int			i;
	int			j;
	int			color;
	t_vector_3d vect_color;

	i = 0;
	j = start;
	while (j <= end)
	{
		i = 0;
		while (i < context->mlx.window.width)
		{
			if (context->callbacks.is_process_stopped(context))
				return (NULL);
			vect_color = ft_reflexion(context, 0, ft_camera_ray(context, context->scene->camera, i, j));
			if (context->callbacks.is_process_stopped(context))
				return (NULL);
			color = ft_vector_to_int_color(vect_color);
			if (color_pixel(context, i, j, color))
				return (NULL);
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
	t_vector_3d	dir;
	t_ray		ray;

	screen_x = (2 * (x + 0.5) / context->mlx.window.width) - 1;
	screen_y = 1 - 2 * ((y + 0.5) / context->mlx.window.height);
	screen_x *= camera.aspect * camera.scale;
	screen_y *= camera.scale;
	dir = ft_vector_normalize(ft_vector_add_vect(ft_vector_add_vect(
		ft_vector_mult_scalar(camera.right,	screen_x), ft_vector_mult_scalar(
			camera.up, screen_y)),camera.forward));
	ray.point = camera.origin;
	ray.vector = dir;
	return (ray);
}

static bool	color_pixel(t_context *context, int x, int y, int color)
{

	// ESSA FUNCAO É SÓ PARA TESTE
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
	t_vector_3d	vect_color;
	t_ray		reflected_ray;
	t_vector_3d	vect_color_reflexive;
	t_vector_3d	vect_color_final;

	if (context->callbacks.is_process_stopped(context))
	{
		ft_bzero(&vect_color_final, sizeof(t_vector_3d));
		return (vect_color_final);
	}
	col = ft_closest_colision(context->scene, ray);
	if (col.colision)
		vect_color = ft_local_color(context, col);
	else
		return (context->scene->norm_color_back);
	if (depth > 10 || col.polyhedron.material.kr <= 0.0)
		return (vect_color);
	if (ft_vector_dot_product(ray.vector, col.normal) > 0)
    	col.normal = ft_vector_mult_scalar(col.normal, -1);
	if (ft_vector_module(ray.vector) < 1e-12)
		return (vect_color);
	reflected_ray.vector = ft_vector_normalize(ft_vector_sub_vect(ray.vector,ft_vector_mult_scalar(col.normal, 2.0
					* ft_vector_dot_product(ray.vector, col.normal))));
	reflected_ray.point = ft_point_add_vect(col.colision_point,
			ft_vector_mult_scalar(col.normal, 1e-4));
	if (ft_vector_module(reflected_ray.vector) < 1e-9)
		return (vect_color);
	vect_color_reflexive = ft_reflexion(context, depth + 1, reflected_ray);
	vect_color_final = vect_color;
	vect_color_final = ft_vector_add_vect(ft_vector_mult_scalar(vect_color, (1
					- col.polyhedron.material.kr)),
			ft_vector_mult_scalar(vect_color_reflexive,
				col.polyhedron.material.kr));
	return (vect_color_final);
}
