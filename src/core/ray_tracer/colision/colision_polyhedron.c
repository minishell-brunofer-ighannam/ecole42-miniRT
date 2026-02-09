/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_polyhedron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:32:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 20:14:01 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

double	ft_polyhedron_colision(t_polyhedron polyhedron, t_ray ray)
{
	if (polyhedron.type == SPHERE)
		return (ft_colision_sp(&polyhedron, ray));
	else if (polyhedron.type == CYLINDER)
		return (ft_colision_cy(&polyhedron, ray));
	else if (polyhedron.type == PLANE)
		return (ft_colision_pl(&polyhedron, ray));
	else if (polyhedron.type == CONE)
		return (ft_colision_co(&polyhedron, ray));
	return (INFINITY);
}
