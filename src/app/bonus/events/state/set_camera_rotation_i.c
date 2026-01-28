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

#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"

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

void	set_camera_rotation_up(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.rotate_x += CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->up [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}

void	set_camera_rotation_down(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.rotate_x -= CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->down [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}

void	set_camera_rotation_left(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.rotate_y -= CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->left [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}

void	set_camera_rotation_right(t_state *self)
{
	if (!self)
		return ;
	set_camera_changed_flag(self);
	self->scene.camera.rotate_y += CAMERA_ROTATION_INTENSITY;
	printf("camera::rotation->right [%d, %d, %d]\n", self->scene.camera.rotate_x, self->scene.camera.rotate_y, self->scene.camera.rotate_z);
}
