/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_between.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:48:33 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 09:39:54 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/math_rt.h"

bool	ft_is_between_int(int ref_one, int ref_two, int eval)
{
	if (ref_one <= ref_two)
	{
		if (eval >= ref_one && eval <= ref_two)
			return (true);
		return (false);
	}
	if (eval >= ref_two && eval <= ref_one)
		return (true);
	return (false);
}

bool	ft_is_between_double(double ref_one, double ref_two,
		double eval, double eps)
{
	double	min;
	double	max;

	if (eps < 0)
		eps = -eps;
	if (ref_one < ref_two)
	{
		min = ref_one;
		max = ref_two;
	}
	else
	{
		min = ref_two;
		max = ref_one;
	}
	if (eval + eps < min || eval - eps > max)
		return (false);
	return (true);
}
