/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d_ops_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:58:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/11 16:26:21 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_vec_sub(t_vector_3d self, t_vector_3d other)
{
	t_vector_3d	vector;

	vector.x = self.x - other.x;
	vector.y = self.y - other.y;
	vector.z = self.z - other.z;
	return (vector);
}

t_vector_3d	ft_vec_add(t_vector_3d self, t_vector_3d other)
{
	t_vector_3d	vector;

	vector.x = self.x + other.x;
	vector.y = self.y + other.y;
	vector.z = self.z + other.z;
	return (vector);
}

t_vector_3d	ft_vec_mult_scal(t_vector_3d self, double scalar)
{
	t_vector_3d	vector;

	vector.x = self.x * scalar;
	vector.y = self.y * scalar;
	vector.z = self.z * scalar;
	return (vector);
}

t_vector_3d	ft_vector_div_scalar(t_vector_3d self, double scalar)
{
	t_vector_3d	vector;

	if (scalar < 1e-6)
		scalar = 1e-6;
	vector.x = self.x / scalar;
	vector.y = self.y / scalar;
	vector.z = self.z / scalar;
	return (vector);
}

double	ft_vector_cos_teta(t_vector_3d self, t_vector_3d other)
{
	double	dot_product;
	double module_self;
	double module_other;

	dot_product = ft_vector_dot_product(self, other);
	module_self = ft_vec_mod(self);
	module_other = ft_vec_mod(other);
	return (dot_product / (module_self * module_other));
}
