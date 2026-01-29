/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqtr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:06:35 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 11:10:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/math_rt.h"

double ft_sqtr_newton(double n, double eps)
{
    double	x;
	double	diff;

	if (n < 0.0)
		return (-1.0);
	if (n == 0.0)
		return (0.0);
	x = 1.0;
    if (n > 1.0)
	    x = n;
	diff = 1.0;
	while (diff > eps)
	{
		x = 0.5 * (x + n / x);
		diff = x * x - n;
		if (diff < 0.0)
			diff = -diff;
	}
	return (x);
}
