/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:19:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 00:54:19 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

bool ft_double_is_equal(double a, double b, double eps)
{
    return (fabs(a - b) < eps);
}

int clamp_int(int i)
{
    if (i < 0)
        return 0;
    if (i > 255)
        return 255;
    return i;
}

// inline double	sqrdd(double num)
// {
// 	return (num * num);
// }

// inline double	sqrdvec(t_vector_3d vect)
// {
// 	return (ft_vector_dot_product(vect, vect));
// }
