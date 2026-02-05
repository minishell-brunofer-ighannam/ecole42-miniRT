/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:34:21 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 15:47:00 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"

t_vector_3d ft_normal_polyhedron(t_point_3d pt, t_polyhedron polyhedron)
{
    if (polyhedron.type == SPHERE)
        return (ft_sp_normal((t_sphere *)polyhedron.specs, pt));
    else if (polyhedron.type == PLANE)
        return (((t_plane *)polyhedron.specs)->normal);
    else
        return (ft_cy_normal((t_cylinder *)polyhedron.specs, pt));
}

