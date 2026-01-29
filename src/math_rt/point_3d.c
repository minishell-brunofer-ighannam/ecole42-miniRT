/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:31:51 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/29 18:53:39 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/math_rt_internal.h"

static t_vector_3d	ft_sub_point(t_point_3d *self, t_point_3d *other);

t_point_3d	ft_new_point(double x, double y, double z)
{
	t_point_3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.sub_point = ft_sub_point;
	return (point);
}

static t_vector_3d	ft_sub_point(t_point_3d *self, t_point_3d *other)
{
	t_vector_3d	vector;

	vector.x = self->x - other->x;
	vector.y = self->y - other->y;
	vector.z = self->z - other->z;
	return (vector);
}
