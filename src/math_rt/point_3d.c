/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:31:51 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 17:47:12 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

t_point_3d	ft_new_point(double x, double y, double z)
{
	t_point_3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vector_3d	ft_sub_point(t_point_3d self, t_point_3d other)
{
	t_vector_3d	vector;

	vector.x = self.x - other.x;
	vector.y = self.y - other.y;
	vector.z = self.z - other.z;
	return (vector);
}

bool	ft_point_is_equal(t_point_3d a, t_point_3d b, double eps)
{
	return (ft_double_is_equal(a.x, b.x, eps)
		&& ft_double_is_equal(a.y, b.y, eps)
		&& ft_double_is_equal(a.z, b.z, eps));
}
