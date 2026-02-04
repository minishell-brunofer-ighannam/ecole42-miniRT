/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_rotation_ii.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/02 18:05:13 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../threads/includes/threads_bonus.h"
#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"

void	set_camera_rotation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	if (gesture->diff.y)
		self->scene.camera.rotate_x += gesture->diff.y;
	if (gesture->diff.x)
		self->scene.camera.rotate_y += gesture->diff.x;
	if (gesture->diff.z)
		self->scene.camera.rotate_z += gesture->diff.z;
	printf("camera::rotation[%.0f, %.0f, %.0f]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_diag_right(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_z += CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_right [%.0f, %.0f, %.0f]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_rotation_diag_left(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_z -= CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_left [%.0f, %.0f, %.0f]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}
