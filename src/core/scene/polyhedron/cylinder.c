/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:07:38 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/06 13:19:14 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "polyhedron_internal.h"

t_vector_3d	ft_cy_normal(t_cylinder *cy, t_point_3d p)
{
	double		y;
	t_point_3d	proj;

	y = ft_vector_dot_product(ft_sub_point(p, cy->center), cy->axis);
	proj = ft_point_add_vect(cy->center, ft_vector_mult_scalar(cy->axis, y));
	return (ft_vector_normalize(ft_sub_point(p, proj)));
}
