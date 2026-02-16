/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_rotation_ii.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 21:09:07 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	set_polyhedron_rotation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	if (gesture->diff.y)
		self->scene.polyhedron.rotate_x += gesture->diff.y;
	if (gesture->diff.x)
		self->scene.polyhedron.rotate_y += gesture->diff.x;
	if (gesture->diff.z)
		self->scene.polyhedron.rotate_z += gesture->diff.z;
	printf("polyhedron::rotation[%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_rotation_diag_right(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_z += POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->diagonal_right [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_rotation_diag_left(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_z -= POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->diagonal_left [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}
