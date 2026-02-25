/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_translation_ii.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:31:29 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/25 12:31:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	set_polyhedron_translation_spatial(
			t_context *context, t_spatial_gesture *gesture)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	if (gesture->diff.x)
		state->scene.polyhedron.translate_x += gesture->diff.x;
	if (gesture->diff.y)
		state->scene.polyhedron.translate_y += gesture->diff.y;
	if (gesture->diff.z)
		state->scene.polyhedron.translate_z += gesture->diff.z;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_front(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_z += POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_back(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_z -= POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
