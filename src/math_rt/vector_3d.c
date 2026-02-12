/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:02:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/11 13:13:58 by bruno-valer      ###   ########.fr       */
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
	return (vector);
}

inline double	ft_vector_dot_product(t_vector_3d self, t_vector_3d other)
{
	return ((self.x * other.x) + (self.y * other.y) + (self.z * other.z));
}

inline double	ft_vec_mod(t_vector_3d self)
{
	double	mod;

	mod = sqrt((self.x * self.x) + (self.y * self.y) + (self.z * self.z));
	if (isnan(mod))
		return (INFINITY);
	return (mod);
}

inline double	ft_vec_mod_squared(t_vector_3d self)
{
	return ((self.x * self.x) + (self.y * self.y) + (self.z * self.z));
}
