/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_rotation_ii.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 17:04:13 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"

void	set_camera_rotation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	if (gesture->diff.y)
		self->scene.camera.rotate_x += gesture->diff.y;
	if (gesture->diff.x)
		self->scene.camera.rotate_y += gesture->diff.x;
	if (gesture->diff.z)
		self->scene.camera.rotate_z += gesture->diff.z;
	printf("camera::rotation[%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}

void	set_camera_rotation_diag_right(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.translate_z += CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_right [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}

void	set_camera_rotation_diag_left(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.translate_z -= CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->diagonal_left [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}
