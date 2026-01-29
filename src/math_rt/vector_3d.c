/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:02:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/29 18:53:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_new_vector_3d(double x, double y, double z)
{
	t_vector_3d	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.m = ft_vector_3d_methods();
	return (vector);
}

double	ft_vector_dot_product(t_vector_3d *self, t_vector_3d *other)
{
	return ((self->x * other->x) + (self->y * other->y) + (self->z * other->z));
}

double	ft_vector_module(t_vector_3d *self)
{
	return (
		ft_sqtr_newton((self->x * self->x) + (self->y * self->y) + (self->z * self->z), 1e-6)
	);
}

double	ft_vector_module_squared(t_vector_3d *self)
{
	return ((self->x * self->x) + (self->y * self->y) + (self->z * self->z));
}
