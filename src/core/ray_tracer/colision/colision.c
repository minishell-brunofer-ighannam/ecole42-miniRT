/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:30:25 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/07 08:59:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "colision_internal.h"
#include "ray_tracer.h"

static t_colision	ft_form_colision(t_polyhedron polyhedron, t_ray ray,
						double t);

t_colision	ft_closest_colision(t_scene *scene, t_ray ray)
{
	int				i;
	double			t;
	double			closest_t;
	t_polyhedron	closest_polyhedron;

	i = 0;
	t = INFINITY;
	closest_t = INFINITY;
	while (i < scene->num_polyhedron)
	{
		t = ft_polyhedron_colision(scene->polyhedron[i], ray);
		if (t > EPS && t < closest_t)
		{
			closest_t = t;
			closest_polyhedron = scene->polyhedron[i];
		}
		i++;
	}
	return (ft_form_colision(closest_polyhedron, ray, closest_t));
}

static t_colision	ft_form_colision(t_polyhedron polyhedron, t_ray ray,
		double t)
{
	t_colision	colision;

	ft_bzero(&colision, sizeof(t_colision));
	if (!isinf(t))
	{
		colision.colision = true;
		colision.polyhedron = polyhedron;
		colision.colision_point = ft_ray_at(ray, t);
		colision.ray = ray;
		colision.t = t;
		colision.normal = ft_normal_polyhedron(colision.colision_point,
				polyhedron);
		colision.color_dif = ft_new_vector_3d(0.0, 0.0, 0.0);
		colision.color_spec = ft_new_vector_3d(0.0, 0.0, 0.0);
	}
	return (colision);
}
