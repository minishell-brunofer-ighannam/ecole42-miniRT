/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:34:21 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 20:53:07 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"

static t_vector_3d	ft_sp_normal(t_sphere *sp, t_point_3d pt);
static t_vector_3d	ft_cy_normal(t_cylinder *cy, t_point_3d p);
static t_vector_3d	ft_co_normal(t_cone *co, t_point_3d p, int section);

t_vector_3d	ft_normal_polyhedron(t_point_3d pt, t_polyhedron polyhedron)
{
	if (polyhedron.type == SPHERE)
		return (ft_sp_normal((t_sphere *)polyhedron.specs, pt));
	else if (polyhedron.type == PLANE)
		return (((t_plane *)polyhedron.specs)->normal);
	else
		return (ft_cy_normal((t_cylinder *)polyhedron.specs, pt));
}

static t_vector_3d	ft_sp_normal(t_sphere *sp, t_point_3d pt)
{
	t_vector_3d	normal;

    normal = ft_vec_norm(ft_sub_point(pt, sp->center));
    return (normal);
}

static t_vector_3d	ft_cy_normal(t_cylinder *cy, t_point_3d p)
{
	double		y;
	t_point_3d	proj;

	y = ft_vector_dot_product(ft_sub_point(p, cy->center), cy->axis);
	proj = ft_point_add_vect(cy->center, ft_vec_mult_scal(cy->axis, y));
	return (ft_vec_norm(ft_sub_point(p, proj)));
}

static t_vector_3d	ft_co_normal(t_cone *co, t_point_3d p, int section)
{
	double		y;
	t_vector_3d	vp;
	t_vector_3d	axis_projection;
	t_vector_3d	normal;

	if (section == 0)
		return (co->base.normal);
	vp = ft_sub_point(p, co->vertex);
	axis_projection = ft_vector_mult_scalar(
			co->axis, ft_vector_dot_product(vp, co->axis));
	normal = ft_vector_sub_vect(
			ft_vector_mult_scalar(vp, sqrdd(co->cos_alpha)), axis_projection);
	normal = ft_vector_normalize(normal);
	return (normal);
}
