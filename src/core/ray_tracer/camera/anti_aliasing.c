/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:38:10 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 12:38:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_ray.h"
#include "camera_ray_internal.h"

t_vector_3d	ft_antialiasing(t_context *context, int x, int y)
{
	int			i;
	t_vector_3d	color;

	i = -1;
	color = ft_new_vector_3d(0, 0, 0);
	if (AA < 5)
	{
		color = ft_reflexion(context, 0, ft_camera_ray(context, x, y, 0));
		return (color);
	}
	while (++i < AA)
		color = ft_vec_add(color, ft_reflexion(context, 0,
					ft_camera_ray(context, x, y, (double)rand() / RAND_MAX)));
	color = ft_vector_div_scalar(color, AA);
	return (color);
}
