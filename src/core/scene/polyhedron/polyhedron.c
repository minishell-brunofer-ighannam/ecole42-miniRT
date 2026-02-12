/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:34:21 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 11:22:54 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"
#include "colision.h"

static void	ft_sp_normal(t_sphere *sp, t_point_3d pt, t_colision *col);
static void	ft_cy_normal(t_cylinder *cy, t_point_3d p, t_colision *col);
void		ft_co_normal(t_cone *co, t_point_3d p, t_colision *col);

void	ft_normal_polyhedron(t_point_3d pt, t_polyhedron polyhedron, t_colision *col)
{
	if (polyhedron.type == SPHERE)
		ft_sp_normal((t_sphere *)polyhedron.specs, pt, col);
	else if (polyhedron.type == PLANE)
		col->normal = ((t_plane *)polyhedron.specs)->normal;
	else if (polyhedron.type == CONE)
		ft_co_normal((t_cone *)polyhedron.specs, pt, col);
	else
		ft_cy_normal((t_cylinder *)polyhedron.specs, pt, col);
}

static void	ft_sp_normal(t_sphere *sp, t_point_3d pt, t_colision *col)
{
	col->normal = ft_vec_norm(ft_sub_point(pt, sp->center));
}

static void	ft_cy_normal(t_cylinder *cy, t_point_3d p, t_colision *col)
{
	double		y;
	t_point_3d	proj;

	y = ft_vector_dot_product(ft_sub_point(p, cy->center), cy->axis);
	proj = ft_point_add_vect(cy->center, ft_vec_mult_scal(cy->axis, y));
	col->normal = ft_vec_norm(ft_sub_point(p, proj));
}

void	ft_co_normal(t_cone *co, t_point_3d p, t_colision *col)
{
	t_vector_3d	vp;
	t_vector_3d	axis_projection;
	t_vector_3d	normal;

	if (col->section == 0)
	{
		col->normal = co->base.normal;
		return ;
	}
	vp = ft_sub_point(p, co->vertex);
	axis_projection = ft_vec_mult_scal(
			co->axis, ft_vector_dot_product(vp, co->axis));
	normal = ft_vec_sub(
			ft_vec_mult_scal(vp, sqrdd(co->cos_alpha)), axis_projection);
	col->normal = ft_vec_norm(normal);
}
