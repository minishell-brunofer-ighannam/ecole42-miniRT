/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_translation_ii.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/08 12:42:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../threads/includes/threads_bonus.h"
#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"
#include "debug.h"

void	set_camera_translation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	LOCK(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	if (gesture->diff.x)
		self->scene.camera.translate_x += gesture->diff.x;
	if (gesture->diff.y)
		self->scene.camera.translate_y += gesture->diff.y;
	if (gesture->diff.z)
		self->scene.camera.translate_z += gesture->diff.z;
	printf("camera::translation[%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_front(t_state *self)
{
	if (!self)
		return ;
	LOCK(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_z += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->front [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_translation_back(t_state *self)
{
	if (!self)
		return ;
	LOCK(&self->parallel->flow_ctrl->mutex_set_state);
	set_camera_changed_flag(self);
	self->scene.camera.translate_z -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->back [%.0f, %.0f, %.0f]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
	UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
}
