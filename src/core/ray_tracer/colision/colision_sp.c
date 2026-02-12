/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:31:43 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 14:42:22 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

void	ft_colision_sp(t_polyhedron *restrict polyhedron, t_ray *restrict ray, t_colision *restrict col)
{
	t_sphere	*restrict	sp;
	t_vector_3d				oc;
	double					half_b;
	double					c;

	sp = polyhedron->specs;
	oc = ft_sub_point(ray->point, sp->center);
	half_b = ft_vector_dot_product(ray->vector, oc);
	c = ft_vector_dot_product(oc, oc) - sp->radius * sp->radius;
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
