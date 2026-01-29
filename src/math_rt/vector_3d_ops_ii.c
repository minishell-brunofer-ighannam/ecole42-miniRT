/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d_ops_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 05:17:16 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/29 18:49:54 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_vector_normalize(t_vector_3d *self)
{
	t_vector_3d	vector;

	vector = ft_new_vector_3d(0, 0, 0);
	if (!self)
		return (vector);
	if (!self->module)
		return (vector);
	vector.x = self->x / self->module;
	vector.y = self->y / self->module;
	vector.z = self->z / self->module;
	return (vector);
}

t_vector_3d_methods	ft_vector_3d_methods(void)
{
	t_vector_3d_methods	methods;

	methods.dot_product = ft_vector_dot_product;
	methods.module = ft_vector_module;
	methods.module_squared = ft_vector_module_squared;
	methods.cos_teta = ft_vector_cos_teta;
	methods.sub_vect = ft_vector_sub_vect;
	methods.add_vect = ft_vector_add_vect;
	methods.mult_scalar = ft_vector_mult_scalar;
	methods.div_scalar = ft_vector_div_scalar;
	methods.normalize = ft_vector_normalize;
	return (methods);
}

bool ft_is_normalized_3d_vector(double x, double y, double z, double eps)
{
	double len;

	len = x * x + y * y + z * z;
	if (len < 1.0 - eps || len > 1.0 + eps)
		return (false);
	return (true);
}
