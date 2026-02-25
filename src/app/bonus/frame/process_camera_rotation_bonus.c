/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_camera_rotation_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:16:03 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/25 14:05:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/frame_internal_bonus.h"

static inline void	ft_normalize_cam_base(
						t_vector_3d *forward,
						t_vector_3d *right, t_vector_3d *up)
{
	*forward = ft_vec_norm(*forward);
	*right = ft_vec_norm(ft_cross(*forward, *up));
	*up = ft_vec_norm(ft_cross(*right, *forward));
}

void	ft_process_camera_rotation(
			t_camera_state *restrict state_cam, t_vector_3d *restrict forward,
			t_vector_3d *restrict right, t_vector_3d *restrict up)
{
	double	angle;
	double	radians;

	radians = 0.2 * (M_PI / 180.0);
	angle = -(state_cam->rotate_y * radians);
	*forward = ft_rotate_around_axis(*forward, *up, angle);
	ft_normalize_cam_base(forward, right, up);
	angle = -(state_cam->rotate_x * radians);
	*forward = ft_rotate_around_axis(*forward, *right, angle);
	ft_normalize_cam_base(forward, right, up);
	angle = state_cam->rotate_z * radians;
	*right = ft_rotate_around_axis(*right, *forward, angle);
	*up = ft_rotate_around_axis(*up, *forward, angle);
	ft_normalize_cam_base(forward, right, up);
	state_cam->rotate_y = 0;
	state_cam->rotate_z = 0;
	state_cam->rotate_x = 0;
}
