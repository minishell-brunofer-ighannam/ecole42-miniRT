/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_rotation_ii.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/16 11:12:36 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	set_polyhedron_rotation_spatial(t_context *context, t_spatial_gesture *gesture)
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
	printf("polyhedron::rotation[%.0f, %.0f, %.0f]\n", state->scene.polyhedron.rotate_x, state->scene.polyhedron.rotate_y, state->scene.polyhedron.rotate_z);
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
	printf("polyhedron::rotation->diagonal_right [%.0f, %.0f, %.0f]\n", state->scene.polyhedron.rotate_x, state->scene.polyhedron.rotate_y, state->scene.polyhedron.rotate_z);
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
	printf("polyhedron::rotation->diagonal_left [%.0f, %.0f, %.0f]\n", state->scene.polyhedron.rotate_x, state->scene.polyhedron.rotate_y, state->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
