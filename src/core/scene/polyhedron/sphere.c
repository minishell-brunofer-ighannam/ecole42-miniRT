/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:07:28 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 15:39:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"


t_vector_3d ft_sp_normal(t_sphere *sp, t_point_3d pt)
{
    t_vector_3d normal;

    normal = ft_vector_normalize(ft_sub_point(pt, sp->center));
    return (normal);
}
