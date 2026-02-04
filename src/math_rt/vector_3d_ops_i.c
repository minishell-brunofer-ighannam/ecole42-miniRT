/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d_ops_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:58:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/03 18:31:32 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_vector_sub_vect(t_vector_3d self, t_vector_3d other)
{
	t_vector_3d	vector;

	vector.x = self.x - other.x;
	vector.y = self.y - other.y;
	vector.z = self.z - other.z;
	return (vector);
}

t_vector_3d	ft_vector_add_vect(t_vector_3d self, t_vector_3d other)
{
	t_vector_3d	vector;

	vector.x = self.x + other.x;
	vector.y = self.y + other.y;
	vector.z = self.z + other.z;
	return (vector);
}

t_vector_3d	ft_vector_mult_scalar(t_vector_3d self, double scalar)
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
	module_self = ft_vector_module(self);
	module_other = ft_vector_module(other);
	return (dot_product / (module_self * module_other));
}
