/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:25:56 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 11:16:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "colision_internal.h"

void	ft_colision_pl(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
		t_colision *restrict col)
{
	t_plane	*restrict	pl;

	pl = polyhedron->specs;
	col->t = ft_colision_plane_normal(ray, pl->point, pl->normal);
}

double	ft_colision_plane_normal(t_ray *restrict ray, t_point_3d point,
		t_vector_3d normal)
{
	t_vector_3d	oc;
	double		denom;
	double		t;

	denom = ft_vec_dot(normal, ray->vector);
	if (fabs(denom) < EPS)
		return (INFINITY);
	oc = ft_sub_point(point, ray->point);
	t = ft_vec_dot(oc, normal) / denom;
	if (t > EPS)
		return (t);
	return (INFINITY);
}
