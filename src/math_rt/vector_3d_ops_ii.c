/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d_ops_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 05:17:16 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/09 11:28:34 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_vec_norm(t_vector_3d self)
{
	t_vector_3d	vector;
	double module;

	vector = ft_new_vector_3d(0, 0, 0);
	module = ft_vec_mod(self);
	if (module <= 1e-9)
		return (vector);
	vector.x = self.x / module;
	vector.y = self.y / module;
	vector.z = self.z / module;
	return (vector);
}

bool ft_is_normalized_3d_vector(double x, double y, double z, double eps)
{
	double len;

	len = x * x + y * y + z * z;
	if (len < 1.0 - eps || len > 1.0 + eps)
		return (false);
	return (true);
}

t_point_3d ft_point_add_vect(t_point_3d p, t_vector_3d v)
{
	t_point_3d res;

    res.x = p.x + v.x;
    res.y = p.y + v.y;
    res.z = p.z + v.z;
    return (res);
}

t_vector_3d ft_cross_product(t_vector_3d v1, t_vector_3d v2)
{
	t_vector_3d result;

	result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

t_vector_3d ft_component_wise_product(t_vector_3d v1, t_vector_3d v2)
{
	t_vector_3d v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	v3.z = v1.z * v2.z;
	return (v3);
}
