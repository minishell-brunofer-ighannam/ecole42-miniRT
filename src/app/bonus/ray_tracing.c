/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:23:10 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/03 17:29:59 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

void	*ft_ray_tracing(t_context *context, int row_start, int row_end)
{
	int		column;
	double	baskara;
	int		calculus_per_pixel;
	int		curr_calculus;

	calculus_per_pixel = 50;
	while (row_start <= row_end)
	{
		column = -1;
		while (++column < context->mlx.window.width)
		{
			curr_calculus = -1;
			while (++curr_calculus < calculus_per_pixel)
				baskara = (-10 + (10 * 10 - 40 * 40 * -0.5 * 4)) / (2 * 40);
		}
		row_start++;
	}
	(void)baskara;
	return (NULL);
}
