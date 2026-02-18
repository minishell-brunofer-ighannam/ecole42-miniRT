/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_u_v_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:09:42 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 17:45:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_internal.h"

void	ft_calc_u_v(t_colision *col)
{
	ft_calc_dir_u_v(col);
	if (col->polyhedron.type == PLANE)
		ft_calc_u_v_pl(col);
	else if (col->polyhedron.type == SPHERE)
		ft_calc_u_v_sp(col);
	else if (col->polyhedron.type == CYLINDER)
		ft_calc_u_v_cy(col);
	else if (col->polyhedron.type == CONE)
		ft_calc_u_v_cn(col);
}

void	ft_calc_u_v_pl(t_colision *col)
{
	t_vector_3d	p;
	t_plane		*pl;

	pl = col->polyhedron.specs;
	p = ft_sub_point(col->colision_point, pl->point);
	col->u = ft_vec_dot(p, col->dir_u);
	col->v = ft_vec_dot(p, col->dir_v);
	col->u_norm = fmod(col->u, 1.0);
	col->v_norm = fmod(col->v, 1.0);
	if (col->u_norm < 0)
		col->u_norm += 1.0;
	if (col->v_norm < 0)
		col->v_norm += 1.0;
}

void	ft_calc_u_v_sp(t_colision *col)
{
	col->u = 0.5 + atan2(col->normal.z, col->normal.x) / (2 * M_PI);
	col->v = 0.5 - asin(col->normal.y) / M_PI;
	col->u_norm = fmod(col->u, 1.0);
	col->v_norm = fmod(col->v, 1.0);
	if (col->u_norm < 0)
		col->u_norm += 1.0;
	if (col->v_norm < 0)
		col->v_norm += 1.0;
}

void	ft_calc_dir_u_v(t_colision *col)
{
	t_vector_3d	a;
	t_vector_3d	n;

	if (col->polyhedron.type == PLANE)
		n = col->normal;
	else if (col->polyhedron.type == SPHERE)
	{
		col->dir_u = ft_vec_norm(ft_sub_point(col->colision_point,
					((t_sphere *)col->polyhedron.specs)->center));
		if (ft_vec_mod(col->dir_u) < EPS)
			col->dir_u = ft_new_vector_3d(1, 0, 0);
		col->dir_v = ft_cross(col->normal, col->dir_u);
		return ;
	}
	else if (col->polyhedron.type == CYLINDER)
		n = ((t_cylinder *)col->polyhedron.specs)->axis;
	else if (col->polyhedron.type == CONE)
		n = ((t_cone *)col->polyhedron.specs)->axis;
	if (fabs(n.y) < 0.999)
		a = ft_new_vector_3d(0, 1, 0);
	else
		a = ft_new_vector_3d(1, 0, 0);
	col->dir_u = ft_vec_norm(ft_cross(a, n));
	col->dir_v = ft_vec_norm(ft_cross(n, col->dir_u));
}
