/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_translation_ii.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 14:43:44 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"

void	set_camera_translation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	if (gesture->diff.x)
		self->scene.camera.translate_x += gesture->diff.x;
	if (gesture->diff.y)
		self->scene.camera.translate_y += gesture->diff.y;
	if (gesture->diff.z)
		self->scene.camera.translate_z += gesture->diff.z;
	printf("camera::translation[%d, %d, %d]\n", gesture->diff.x, gesture->diff.y, gesture->diff.z);
}

void	set_camera_translation_front(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	printf("camera::translation->front\n");
	self->scene.camera.translate_z += CAMERA_TRANSLATION_INTENSITY;
}

void	set_camera_translation_back(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	printf("camera::translation->back\n");
	self->scene.camera.translate_z -= CAMERA_TRANSLATION_INTENSITY;
}
