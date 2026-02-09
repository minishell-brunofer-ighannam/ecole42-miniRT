/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:34:21 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 11:28:34 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"

static t_vector_3d ft_sp_normal(t_sphere *sp, t_point_3d pt);
static t_vector_3d	ft_cy_normal(t_cylinder *cy, t_point_3d p);

t_vector_3d ft_normal_polyhedron(t_point_3d pt, t_polyhedron polyhedron)
{
    if (polyhedron.type == SPHERE)
        return (ft_sp_normal((t_sphere *)polyhedron.specs, pt));
    else if (polyhedron.type == PLANE)
        return (((t_plane *)polyhedron.specs)->normal);
    else
        return (ft_cy_normal((t_cylinder *)polyhedron.specs, pt));
}

static t_vector_3d ft_sp_normal(t_sphere *sp, t_point_3d pt)
{
    t_vector_3d normal;

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
