/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:40:54 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 11:47:19 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"
#include "light.h"

t_colision	ft_trace_ray(t_scene *scene, t_mlx *mlx, int x, int y)
{
	t_ray	ray;

	ray = ft_camera_ray(&mlx, &scene->camera, x, y);
	return (ft_closest_colision(scene, &ray));
}
