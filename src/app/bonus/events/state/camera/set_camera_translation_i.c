/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_translation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/16 11:22:42 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/camera_state_internal_bonus.h"

t_set_movement	ft_new_camera_translation(void)
{
	t_set_movement	mov;

	mov.spatial = set_camera_translation_spatial;
	mov.discrete.up = set_camera_translation_up;
	mov.discrete.down = set_camera_translation_down;
	mov.discrete.right = set_camera_translation_right;
	mov.discrete.left = set_camera_translation_left;
	mov.discrete.front = set_camera_translation_front;
	mov.discrete.back = set_camera_translation_back;
	return (mov);
}

void	set_camera_translation_up(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_y += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->up [%.0f, %.0f, %.0f]\n", state->scene.camera.translate_x, state->scene.camera.translate_y, state->scene.camera.translate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_down(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_y -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->down [%.0f, %.0f, %.0f]\n", state->scene.camera.translate_x, state->scene.camera.translate_y, state->scene.camera.translate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_left(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_x -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->left [%.0f, %.0f, %.0f]\n", state->scene.camera.translate_x, state->scene.camera.translate_y, state->scene.camera.translate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_right(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(state);
	state->scene.camera.translate_x += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->right [%.0f, %.0f, %.0f]\n", state->scene.camera.translate_x, state->scene.camera.translate_y, state->scene.camera.translate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
