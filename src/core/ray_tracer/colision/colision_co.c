/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_co.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:25:56 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 14:46:56 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

static double			ft_colision_cone_body(t_ray *restrict ray, t_cone *restrict cone);
static double			ft_colision_cone_base(t_ray *restrict ray, t_cone *restrict cone);
static double			ft_cone_baskara(double a, double half_b, double c);

void	ft_colision_co(t_polyhedron *restrict polyhedron, t_ray *restrict ray, t_colision *restrict col)
{
	t_cone	*co;
	double	colision_body;
	double	colision_base;

	co = polyhedron->specs;
	colision_body = ft_colision_cone_body(ray, co);
	colision_base = ft_colision_cone_base(ray, co);
	if (isinf(colision_body))
	{
		col->t = colision_base;
		col->section = 0;
	}
	else if (isinf(colision_base))
	{
		col->t = colision_body;
		col->section = 1;
	}
	else if (colision_body < colision_base)
	{
		col->t = colision_body;
		col->section = 1;
	}
	else
	{
		col->t = colision_base;
		col->section = 0;
	}
}

/**
 *
 * # Cone Body Colision
 *
 * to understand the calculus, see
 * https://www.notion.so/Intersec-o-Raio-Cone-2febcec584a680c198c4e276cdbd34cd#6f7fb6da39af4706b245e6b3e5abe94b
 */
static double	ft_colision_cone_body(t_ray *restrict ray, t_cone *restrict cone)
{
	double		half_b;
	t_vector_3d	ov;
	double		d_dot_a;
	double		ov_dot_a;
	double		cos_alpha_sqrd;

	cos_alpha_sqrd = sqrdd(cone->cos_alpha);
	ov = ft_sub_point(ray->point, cone->vertex);
	d_dot_a = ft_vector_dot_product(ray->vector, cone->axis);
	ov_dot_a = ft_vector_dot_product(ov, cone->axis);
	if (d_dot_a <= 0 && ov_dot_a < 0)
		return (INFINITY);
	half_b = ov_dot_a * d_dot_a
		- ft_vector_dot_product(ov, ray->vector) * cos_alpha_sqrd;
	half_b = ft_cone_baskara(sqrdd(d_dot_a) - cos_alpha_sqrd, half_b,
			sqrdd(ov_dot_a) - sqrdvec(ov) * cos_alpha_sqrd);
	if (isinf(half_b) || half_b < -EPS)
		return (INFINITY);
	d_dot_a = ft_vector_dot_product(
			ft_sub_point(ft_ray_at(ray, half_b), cone->vertex), cone->axis);
	if (d_dot_a > cone->height || d_dot_a < 0.0)
		return (INFINITY);
	return (half_b);
}

/**
 *
 * # Cone Base Colision
 *
 * to understand the calculus, see
 * https://www.notion.so/Intersec-o-Raio-Cone-2febcec584a680c198c4e276cdbd34cd#302bcec584a680408b8ccc576ceb4f4d
 */
static double	ft_colision_cone_base(t_ray *restrict ray, t_cone *restrict cone)
{
	double		t;
	t_vector_3d	bp;

	t = ft_colision_plane_normal(ray, cone->base.point, cone->base.normal);
	bp = ft_sub_point(ft_point_add_vect(ray->point, ft_vec_mult_scal(ray->vector, t)), cone->base.point);
	if (ft_vector_dot_product(bp, bp) <= sqrdd(cone->height * cone->tan_alpha))
	{
		if (t < -EPS)
			return (INFINITY);
		return (t);
	}
	return (INFINITY);
}

static double	ft_cone_baskara(double a, double half_b, double c)
{
	double	delta;
	double	sqrt_delta;
	double	minus_b;
	double	result1;
	double	result2;

	if (a < EPS && a > -EPS)
		return (INFINITY);
	delta = half_b * half_b - a * c;
	if (delta < -EPS)
		return (INFINITY);
	sqrt_delta = sqrt(delta) / (a);
	minus_b = -half_b / a;
	if (delta < EPS && delta > -EPS)
		return (minus_b);
	result1 = minus_b - sqrt_delta;
	result2 = minus_b + sqrt_delta;
	if (result1 > EPS && result2 > EPS)
		return (ft_min(result1, result2));
	if (result1 > EPS)
		return (result1);
	if (result2 > EPS)
		return (result2);
	return (INFINITY);
}
