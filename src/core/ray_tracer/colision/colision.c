/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:30:25 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 13:50:37 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "colision_internal.h"
#include "ray_tracer.h"

static void	ft_form_colision(t_polyhedron polyhedron, t_ray ray,
				t_colision *col);

t_colision	ft_closest_colision(t_scene *scene, t_ray ray)
{
	int				i;
	double			closest_t;
	t_polyhedron	closest_polyhedron;
	t_colision		col;

	i = 0;
	ft_bzero(&col, sizeof(t_colision));
	col.t = INFINITY;
	closest_t = INFINITY;
	while (i < scene->num_polyhedron)
	{
		ft_polyhedron_colision(scene->polyhedron[i], ray, &col);
		if (col.t > EPS && col.t < closest_t)
		{
			closest_t = col.t;
			closest_polyhedron = scene->polyhedron[i];
		}
		i++;
	}
	ft_form_colision(closest_polyhedron, ray, &col);
	return (col);
}

static void	ft_form_colision(t_polyhedron polyhedron, t_ray ray,
		t_colision *col)
{
	if (!isinf(col->t))
	{
		col->colision = true;
		col->polyhedron = polyhedron;
		col->colision_point = ft_ray_at(ray, col->t);
		col->ray = ray;
		ft_normal_polyhedron(col->colision_point, polyhedron, col);
		col->color_dif = ft_new_vector_3d(0.0, 0.0, 0.0);
		col->color_spec = ft_new_vector_3d(0.0, 0.0, 0.0);
	}
}
