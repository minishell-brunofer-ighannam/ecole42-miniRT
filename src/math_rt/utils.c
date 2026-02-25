/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:19:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/14 10:20:23 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

inline bool	ft_double_is_equal(double a, double b, double eps)
{
	return (fabs(a - b) < eps);
}

inline int	clamp_int(int i)
{
	if (i < 0)
		return (0);
	if (i > 255)
		return (255);
	return (i);
}

inline double	sqrdd(double num)
{
	return (num * num);
}

inline double	sqrdvec(t_vector_3d vect)
{
	return (ft_vec_dot(vect, vect));
}
