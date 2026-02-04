/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_polyhedron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:32:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/03 15:36:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

double ft_polyhedron_colision(t_polyhedron polyhedron, t_ray ray)
{
    if (polyhedron.type == SPHERE)
        return (ft_colision_sp(&polyhedron, ray));
    else if (polyhedron.type == CYLINDER)
        return (ft_colision_cy(&polyhedron, ray));
    else if (polyhedron.type == PLANE)
        return (ft_colision_pl(&polyhedron, ray));
    return (INFINITY);
}
