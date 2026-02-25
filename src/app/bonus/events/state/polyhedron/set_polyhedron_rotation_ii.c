/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_rotation_ii.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:22:16 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"
#include "threads_bonus.h"

void	set_polyhedron_rotation_spatial(t_context *context,
		t_spatial_gesture *gesture)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	if (gesture->diff.y)
		state->scene.polyhedron.rotate_x += gesture->diff.y;
	if (gesture->diff.x)
		state->scene.polyhedron.rotate_y += gesture->diff.x;
	if (gesture->diff.z)
		state->scene.polyhedron.rotate_z += gesture->diff.z;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_rotation_diag_right(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_z += POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_rotation_diag_left(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_z -= POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
