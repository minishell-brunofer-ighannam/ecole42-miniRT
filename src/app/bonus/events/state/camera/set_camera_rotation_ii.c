/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_rotation_ii.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/16 11:21:45 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/camera_state_internal_bonus.h"

void	set_camera_rotation_spatial(t_context *context, t_spatial_gesture *gesture)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	if (gesture->diff.y)
		state->scene.camera.rotate_x += gesture->diff.y;
	if (gesture->diff.x)
		state->scene.camera.rotate_y += gesture->diff.x;
	if (gesture->diff.z)
		state->scene.camera.rotate_z += gesture->diff.z;
	printf("camera::rotation[%.0f, %.0f, %.0f]\n", state->scene.camera.rotate_x, state->scene.camera.rotate_y, state->scene.camera.rotate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_diag_right(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_z += CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_right [%.0f, %.0f, %.0f]\n", state->scene.camera.rotate_x, state->scene.camera.rotate_y, state->scene.camera.rotate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_diag_left(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_z -= CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_left [%.0f, %.0f, %.0f]\n", state->scene.camera.rotate_x, state->scene.camera.rotate_y, state->scene.camera.rotate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
