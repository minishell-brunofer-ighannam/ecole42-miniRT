/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:31:43 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 11:51:33 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "colision_internal.h"

void	ft_colision_sp(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
		t_colision *restrict col)
{
	t_vector_3d				oc;
	double					half_b;
	double					c;
	t_sphere	*restrict	sp;

	sp = polyhedron->specs;
	oc = ft_sub_point(ray->point, sp->center);
	half_b = ft_vec_dot(ray->vector, oc);
	c = ft_vec_dot(oc, oc) - sp->radius * sp->radius;
	col->t = ft_solve_quadratic_normalized(half_b, c);
}

double	ft_solve_quadratic_normalized(double half_b, double c)
{
	double	delta;
	double	t;

	delta = half_b * half_b - c;
	if (delta < 0.0)
		return (INFINITY);
	delta = sqrt(delta);
	t = (-half_b - delta);
	if (t < EPS)
	{
		t = (-half_b + delta);
		if (t < EPS)
			return (INFINITY);
	}
	return (t);
}
