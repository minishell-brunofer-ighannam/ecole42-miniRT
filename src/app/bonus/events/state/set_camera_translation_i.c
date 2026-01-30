/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_translation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 12:24:28 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	set_camera_changed_flag(self);
	self->scene.camera.translate_y += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->up [%d, %d, %d]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
}

void	set_camera_translation_down(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.translate_y -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->down [%d, %d, %d]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
}

void	set_camera_translation_left(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.translate_x -= CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->left [%d, %d, %d]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
}

void	set_camera_translation_right(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.translate_x += CAMERA_TRANSLATION_INTENSITY;
	printf("camera::translation->right [%d, %d, %d]\n", self->scene.camera.translate_x, self->scene.camera.translate_y, self->scene.camera.translate_z);
}
