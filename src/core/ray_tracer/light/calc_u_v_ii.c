/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_u_v_ii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:13:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 12:04:08 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_internal.h"

void	ft_calc_u_v_cy(t_colision *col)
{
	t_vector_3d	cp;
	t_cylinder	*cy;
	double		h;
	t_vector_3d	proj;
	t_vector_3d	r;

	cy = col->polyhedron.specs;
	cp = ft_sub_point(col->colision_point, cy->center);
	h = ft_vec_dot(cp, cy->axis);
	proj = ft_vec_mult(cy->axis, h);
	r = ft_vec_norm(ft_vec_sub(cp, proj));
	col->u = 0.5 + atan2(ft_vec_dot(r, col->dir_u), ft_vec_dot(r, col->dir_v))
		/ (2 * M_PI);
	col->v = (h + cy->height / 2.0) / cy->height;
	col->v = fmod(col->v, 1.0);
	if (col->v < 0)
		col->v += 1.0;
	col->u_norm = fmod(col->u, 1.0);
	col->v_norm = fmod(col->v, 1.0);
	if (col->u_norm < 0)
		col->u_norm += 1.0;
	if (col->v_norm < 0)
		col->v_norm += 1.0;
	if (col->section >= 1)
		ft_calc_u_v_circle(col, cp, cy->axis, cy->radius);
}

void	ft_calc_u_v_circle(t_colision *col, t_vector_3d cp, t_vector_3d axis,
		double radius)
{
	t_vector_3d	planar;
	double		angle;
	double		radius_pt;
	double		x;
	double		y;

	planar = ft_vec_sub(cp, ft_vec_mult(axis, ft_vec_dot(cp, axis)));
	x = ft_vec_dot(planar, col->dir_u);
	y = ft_vec_dot(planar, col->dir_v);
	angle = atan2(y, x);
	radius_pt = sqrt(x * x + y * y);
	col->u = 0.5 + angle / (2 * M_PI);
	col->v = radius_pt / radius;
	col->u_norm = fmod(col->u, 1.0);
	col->v_norm = fmod(col->v, 1.0);
	if (col->u_norm < 0)
		col->u_norm += 1.0;
	if (col->v_norm < 0)
		col->v_norm += 1.0;
}

void	ft_calc_u_v_cn(t_colision *col)
{
	t_vector_3d	cp;
	t_cone		*cn;
	double		h;
	t_vector_3d	proj;
	t_vector_3d	r;

	cn = col->polyhedron.specs;
	cp = ft_sub_point(col->colision_point, cn->vertex);
	h = ft_vec_dot(cp, cn->axis);
	proj = ft_vec_mult(cn->axis, h);
	r = ft_vec_norm(ft_vec_sub(cp, proj));
	col->u = 0.5 + atan2(ft_vec_dot(r, col->dir_v), ft_vec_dot(r, col->dir_u))
		/ (2 * M_PI);
	col->v = (h + cn->height / 2.0) / cn->height;
	col->v = fmod(col->v, 1.0);
	if (col->v < 0)
		col->v += 1.0;
	col->u_norm = fmod(col->u, 1.0);
	col->v_norm = fmod(col->v, 1.0);
	if (col->u_norm < 0)
		col->u_norm += 1.0;
	if (col->v_norm < 0)
		col->v_norm += 1.0;
	if (col->section == 0)
		ft_calc_u_v_circle(col, cp, cn->axis, cn->radius);
}
