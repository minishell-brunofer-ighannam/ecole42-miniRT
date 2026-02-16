/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:30:25 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/15 09:24:12 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "colision_internal.h"
#include "ray_tracer.h"

static void	ft_form_colision(t_polyhedron polyhedron, t_ray *restrict ray,
				t_colision *col);

t_colision	ft_closest_colision(t_scene *restrict scene, t_ray *restrict ray)
{
	int				i;
	double			closest_t;
	int				closest_section;
	t_polyhedron	closest_polyhedron;
	t_colision		col;

	ft_bzero(&col, sizeof(t_colision));
	col.t = INFINITY;
	closest_t = INFINITY;
	closest_section = 0;
	i = -1;
	while (++i < scene->num_polyhedron)
	{
		ft_polyhedron_colision(scene->polyhedron[i], ray, &col);
		if (col.t > EPS && col.t < closest_t)
		{
			closest_t = col.t;
			closest_section = col.section;
			closest_polyhedron = scene->polyhedron[i];
		}
	}
	col.t = closest_t;
	col.section = closest_section;
	ft_form_colision(closest_polyhedron, ray, &col);
	return (col);
}

static void	ft_form_colision(t_polyhedron polyhedron, t_ray *restrict ray,
		t_colision *col)
{
	if (!isinf(col->t))
	{
		col->colision = true;
		col->polyhedron = polyhedron;
		col->colision_point = ft_ray_at(ray, col->t);
		col->ray = *ray;
		ft_normal_polyhedron(col->colision_point, polyhedron, col);
		if (ft_vec_dot(col->normal, ray->vector) > 0)
    		col->normal = ft_vec_mult(col->normal, -1);
		col->color_dif = ft_new_vector_3d(0.0, 0.0, 0.0);
		col->color_spec = ft_new_vector_3d(0.0, 0.0, 0.0);

	}
}
