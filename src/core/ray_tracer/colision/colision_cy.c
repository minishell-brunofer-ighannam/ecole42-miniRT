/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:34:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 15:08:52 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

void	ft_colision_cy(t_polyhedron *polyhedron, t_ray ray, t_colision *col)
{
	t_cylinder	*cy;
	double		t_body;
	double		t_cap;

	cy = polyhedron->specs;
	t_body = ft_colision_cy_body(cy, ray);
	t_cap = ft_colision_cy_caps(cy, ray);
	if (isinf(t_body) || t_body < 0)
		col->t = t_cap;
	else if (isinf(t_cap) || t_cap < 0)
		col->t = t_body;
	else if (t_body < t_cap)
		col->t = t_body;
	else
		col->t = t_cap;
}

double	ft_colision_cy_body(t_cylinder *cy, t_ray ray)
{
	t_vector_3d	oc;
	t_vector_3d	d_perp;
	t_vector_3d	oc_perp;
	double		a;
	double		t;

	oc = ft_sub_point(ray.point, cy->center);
	d_perp = ft_vec_sub(ray.vector, ft_vec_mult_scal(cy->axis,
				ft_vector_dot_product(ray.vector, cy->axis)));
	oc_perp = ft_vec_sub(oc, ft_vec_mult_scal(cy->axis,
				ft_vector_dot_product(oc, cy->axis)));
	a = ft_vector_dot_product(d_perp, d_perp);
	if (a < EPS)
		return (INFINITY);
	t = ft_solve_quadratic_normalized(ft_vector_dot_product(oc_perp, d_perp)
			/ a, (ft_vector_dot_product(oc_perp, oc_perp) - cy->radius
				* cy->radius) / a);
	if (t < 0)
		return (INFINITY);
	a = ft_vector_dot_product(ft_sub_point(ft_ray_at(ray, t), cy->center),
			cy->axis);
	if (a < 0.0 || a > cy->height)
		return (INFINITY);
	return (t);
}

double	ft_colision_cy_caps(t_cylinder *cy, t_ray ray)
{
	double		t_min;
	double		t;
	t_point_3d	cap_center;
	t_point_3d	p;

	t_min = INFINITY;
	t = ft_colision_plane_normal(ray, cy->center,
			ft_vec_mult_scal(cy->axis, -1));
	if (t > EPS)
	{
		p = ft_ray_at(ray, t);
		if (ft_vector_dot_product(ft_sub_point(p, cy->center), ft_sub_point(p,
					cy->center)) <= cy->radius * cy->radius)
			t_min = t;
	}
	cap_center = ft_point_add_vect(cy->center, ft_vec_mult_scal(cy->axis,
				cy->height));
	t = ft_colision_plane_normal(ray, cap_center, cy->axis);
	if (t > EPS)
	{
		p = ft_ray_at(ray, t);
		if (ft_vector_dot_product(ft_sub_point(p, cap_center), ft_sub_point(p,
					cap_center)) <= cy->radius * cy->radius)
		{
			if (t_min < 0 || t < t_min)
				t_min = t;
		}
	}
	return (t_min);
}
