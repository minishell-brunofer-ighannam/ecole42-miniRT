/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:41:14 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/25 12:42:17 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

inline double	ft_add_clamp(double n1, double n2, double min, double max)
{
	double	result;

	if (!n2)
		return (n1);
	result = n1 + n2;
	if (result < min)
		return (min);
	if (result > max)
		return (max);
	return (result);
}

inline double	ft_clamp(double number, double min, double max)
{
	if (number < min)
		return (min);
	if (number > max)
		return (max);
	return (number);
}
