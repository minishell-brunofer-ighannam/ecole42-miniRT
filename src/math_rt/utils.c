/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:19:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/07 09:57:56 by ighannam         ###   ########.fr       */
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