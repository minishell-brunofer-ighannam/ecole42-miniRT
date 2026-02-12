/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:34:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/12 14:05:58 by ighannam         ###   ########.fr       */
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
	t_cap = ft_colision_cy_caps(cy, ray, col);
	if (isinf(t_body) || t_body < EPS)
		col->t = t_cap;
	else if (isinf(t_cap) || t_cap < EPS || t_body < t_cap)
	{
		col->t = t_body;
		col->section = 0;
	}
	else
		col->t = INFINITY;
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
	if (a < -cy->height / 2.0 || a > cy->height / 2.0)
		return (INFINITY);
	return (t);
}

static double ft_check_cap(t_ray ray, t_point_3d center, t_vector_3d axis, double radius)
{
	double		t;
	t_point_3d	p;

	t = ft_colision_plane_normal(ray, center,
			ft_vec_mult_scal(axis, -1));
	if (t > EPS)
	{
		p = ft_ray_at(ray, t);
		if (ft_vector_dot_product(ft_sub_point(p, center), ft_sub_point(p,
					center)) <= radius * radius)
			return (t);
	}
	return (INFINITY);
}

double	ft_colision_cy_caps(t_cylinder *cy, t_ray ray, t_colision *col)
{
	double		t1;
	double		t2;

	t1 = ft_check_cap(ray, cy->cap_top.point, cy->cap_top.normal, cy->radius);
	t2 = ft_check_cap(ray,cy->cap_bot.point, cy->cap_bot.normal, cy->radius);
	if (isinf(t1) && isinf(t2))
        return (INFINITY);
	if (!isinf(t1) && t1 > EPS && (isinf(t2) || t1 < t2))
	{
		col->section = 1;
        return (t1);
	}
	if (t2 > EPS)
	{
		col->section = 2;
        return (t2);
	}
	return (INFINITY);
}
