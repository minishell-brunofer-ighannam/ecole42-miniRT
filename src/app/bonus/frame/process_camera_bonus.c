/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_camera_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:59:13 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/25 14:05:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal_bonus.h"

void	ft_handle_camera(t_camera *scene_cam, t_camera_state *state_cam)
{
	ft_process_camera_translation(
		&scene_cam->origin, scene_cam->forward, state_cam);
	ft_process_camera_rotation(
		state_cam, &scene_cam->forward, &scene_cam->right, &scene_cam->up);
	state_cam->has_changes = false;
}
