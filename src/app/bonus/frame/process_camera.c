/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:59:13 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/23 14:18:00 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

void	ft_handle_camera(t_camera *scene_cam, t_camera_state *state_cam)
{
	ft_process_camera_translation(
		&scene_cam->origin, scene_cam->forward, state_cam);
	ft_process_camera_rotation(
		state_cam, &scene_cam->forward, &scene_cam->right, &scene_cam->up);
	state_cam->has_changes = false;
}
