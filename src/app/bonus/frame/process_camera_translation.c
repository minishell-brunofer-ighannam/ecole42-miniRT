/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_camera_translation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:08:51 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/14 18:33:19 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/frame_internal.h"

static inline bool	ft_is_x_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.z >= 0 && cam_forward.z >= 0)
		|| (cam_forward.y < 0 && cam_forward.y < 0))
		return (true);
	return (false);
}

static inline bool	ft_is_y_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.z >= 0 && cam_forward.z >= 0)
		|| (cam_forward.x < 0 && cam_forward.x < 0))
		return (true);
	return (false);
}

static inline bool	ft_is_z_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.x >= 0 && cam_forward.x >= 0)
		|| (cam_forward.y < 0 && cam_forward.y < 0))
		return (true);
	return (false);
}

void	ft_process_camera_translation(
			t_point_3d *restrict origin,
			t_vector_3d forward, t_camera_state *restrict state_cam)
{
	origin->x += (forward.x * state_cam->translate_z);
	origin->y += (forward.y * state_cam->translate_z);
	origin->z += (forward.z * state_cam->translate_z);
	if (ft_is_x_inverse(forward))
		origin->x -= state_cam->translate_x;
	else
		origin->x += state_cam->translate_x;
	if (ft_is_y_inverse(forward))
		origin->y -= state_cam->translate_y;
	else
		origin->y += state_cam->translate_y;
	if (ft_is_z_inverse(forward))
		origin->z -= (forward.z * state_cam->translate_z);
	else
		origin->z += (forward.z * state_cam->translate_z);
	state_cam->translate_x = 0;
	state_cam->translate_y = 0;
	state_cam->translate_z = 0;
}
