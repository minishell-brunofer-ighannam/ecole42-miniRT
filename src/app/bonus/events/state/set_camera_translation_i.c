/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_translation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/02 18:06:19 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../threads/includes/threads_bonus.h"
#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"

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

void	set_camera_translation_up(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_y += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->up [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_down(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_y -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->down [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_left(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_x -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->left [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_right(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_x += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->right [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}
