/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d_ops_iii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:03:50 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/14 18:04:06 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt_internal.h"
#include "math_rt.h"

t_vector_3d	ft_rotate_around_axis(
				t_vector_3d local_x, t_vector_3d axis, double angle)
{
	t_vector_3d	result;
	t_vector_3d	axis_parallel;
	t_vector_3d	local_y;
	double		cos_a;
	double		sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	axis_parallel = ft_vec_mult(axis, ft_vec_dot(axis, local_x));
	local_y = ft_cross(axis, local_x);
	result = ft_vec_add(ft_vec_mult(local_x, cos_a),
			ft_vec_mult(local_y, sin_a));
	result = ft_vec_add(result, axis_parallel);
	return (result);
}
