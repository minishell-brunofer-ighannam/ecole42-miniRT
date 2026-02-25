/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_translation_i.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:30:46 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/25 12:30:48 by brunofer         ###   ########.fr       */
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

void	set_polyhedron_translation_up(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_y += POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_down(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_y -= POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_left(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_x -= POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

void	set_polyhedron_translation_right(t_context *context)
{
	t_state	*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.translate_x += POLYHEDRON_TRANSLATION_INTENSITY;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
