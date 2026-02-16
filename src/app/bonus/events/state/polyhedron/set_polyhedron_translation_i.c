/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_translation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 15:45:36 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

t_set_movement	ft_new_polyhedron_translation(void)
{
	t_set_movement	mov;

	mov.spatial = set_polyhedron_translation_spatial;
	mov.discrete.up = set_polyhedron_translation_up;
	mov.discrete.down = set_polyhedron_translation_down;
	mov.discrete.right = set_polyhedron_translation_right;
	mov.discrete.left = set_polyhedron_translation_left;
	mov.discrete.front = set_polyhedron_translation_front;
	mov.discrete.back = set_polyhedron_translation_back;
	return (mov);
}

void	set_polyhedron_translation_up(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_y += POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->up [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_down(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_y -= POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->down [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_left(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_x -= POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->left [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_right(t_state *self)
{
	if (!self)
		return ;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.translate_x += POLYHEDRON_TRANSLATION_INTENSITY;
	printf("polyhedron::translation->right [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.translate_x, self->scene.polyhedron.translate_y, self->scene.polyhedron.translate_z);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}
