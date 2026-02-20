/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:40:54 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/20 18:08:17 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"
#include "light.h"

t_colision	ft_trace_ray(t_context *context, int x, int y)
{
	t_ray	ray;

	ray = ft_camera_ray(context, x, y, 0.5);
	return (ft_closest_colision(context->scene, &ray));
}
