/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_polyhedron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:32:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 14:39:22 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

void	ft_polyhedron_colision(
			t_polyhedron polyhedron, t_ray *restrict ray, t_colision *restrict col)
{
	if (polyhedron.type == SPHERE)
		ft_colision_sp(&polyhedron, ray, col);
	else if (polyhedron.type == CYLINDER)
		ft_colision_cy(&polyhedron, ray, col);
	else if (polyhedron.type == PLANE)
		ft_colision_pl(&polyhedron, ray, col);
	else if (polyhedron.type == CONE)
		ft_colision_co(&polyhedron, ray, col);
	else
		col->t = INFINITY;
}
