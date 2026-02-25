/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_between.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:48:33 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 13:20:02 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

inline bool	ft_is_between_int(int ref_one, int ref_two, int eval)
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

inline bool	ft_is_between_double(double ref_one, double ref_two,
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

inline double	ft_min(double n1, double n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

inline double	ft_max(double n1, double n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
