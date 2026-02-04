/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:07:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/04 10:41:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "camera_internal.h"

void	ft_camera_init(t_camera *camera)
{
	camera->forward = ft_vector_normalize(camera->forward);
	camera->up = ft_new_vector_3d(0, 1, 0);
	if (ft_vector_dot_product(camera->forward, camera->up) > 0.999)
		camera->up = ft_new_vector_3d(0, 0, 1);
	camera->right = ft_vector_normalize(ft_cross_product(camera->forward,
				camera->up));
	camera->up = ft_vector_normalize(ft_cross_product(camera->right,
				camera->forward));
    camera->scale = tan((camera->horizontal_fov * M_PI / 180.0) / 2);
    camera->aspect = WIDTH / HEIGHT;
}
