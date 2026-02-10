/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_polyhedron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:32:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

void	ft_polyhedron_colision(t_polyhedron polyhedron, t_ray ray, t_colision *col)
{
	if (polyhedron.type == SPHERE)
		ft_colision_sp(&polyhedron, ray, col);
	else if (polyhedron.type == CYLINDER)
		ft_colision_cy(&polyhedron, ray, col);
	else if (polyhedron.type == PLANE)
		ft_colision_pl(&polyhedron, ray, col);
	else if (polyhedron.type == CONE)
		ft_colision_co(&polyhedron, ray, col);
}
