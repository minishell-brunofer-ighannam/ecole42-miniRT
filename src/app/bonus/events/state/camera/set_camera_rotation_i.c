/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_rotation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 09:25:58 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestures_bonus.h"
#include "includes/camera_state_internal_bonus.h"
#include "threads_bonus.h"

t_set_movement	ft_new_camera_rotation(void)
{
	t_set_movement	mov;

	mov.spatial = set_camera_rotation_spatial;
	mov.discrete.up = set_camera_rotation_up;
	mov.discrete.down = set_camera_rotation_down;
	mov.discrete.right = set_camera_rotation_right;
	mov.discrete.left = set_camera_rotation_left;
	mov.discrete.front = set_camera_rotation_diag_right;
	mov.discrete.back = set_camera_rotation_diag_left;
	return (mov);
}

void	set_camera_rotation_up(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.rotate_x += CAMERA_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_down(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.rotate_x -= CAMERA_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_left(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.rotate_y -= CAMERA_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_right(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.rotate_y += CAMERA_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
