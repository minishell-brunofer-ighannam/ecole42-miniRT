/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_translation_ii.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 15:45:40 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	set_polyhedron_translation_spatial(t_state *self, t_spatial_gesture *gesture)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	if (gesture->diff.x)
		self->scene.polyhedron.translate_x += gesture->diff.x;
	if (gesture->diff.y)
		self->scene.polyhedron.translate_y += gesture->diff.y;
	if (gesture->diff.z)
		self->scene.polyhedron.translate_z += gesture->diff.z;
	printf("polyhedron::translation[%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_front(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_z += POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->front [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_back(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_z -= POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->back [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}
