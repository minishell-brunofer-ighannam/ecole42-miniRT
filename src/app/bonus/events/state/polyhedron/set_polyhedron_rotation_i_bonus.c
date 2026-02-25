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

#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"
#include "threads_bonus.h"

t_set_movement	ft_new_polyhedron_rotation(void)
{
	t_set_movement	mov;

	mov.spatial = set_polyhedron_rotation_spatial;
	mov.discrete.up = set_polyhedron_rotation_up;
	mov.discrete.down = set_polyhedron_rotation_down;
	mov.discrete.right = set_polyhedron_rotation_right;
	mov.discrete.left = set_polyhedron_rotation_left;
	mov.discrete.front = set_polyhedron_rotation_diag_right;
	mov.discrete.back = set_polyhedron_rotation_diag_left;
	return (mov);
}

void	set_polyhedron_rotation_up(t_context *context)
{
	pthread_mutex_t	*mutex_set_state;
	t_state			*state;

	if (!context)
		return ;
	state = &context->events.state;
	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.rotate_x += POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_down(t_context *context)
{
	pthread_mutex_t	*mutex_set_state;
	t_state			*state;

	if (!context)
		return ;
	state = &context->events.state;
	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.rotate_x -= POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_left(t_context *context)
{
	pthread_mutex_t	*mutex_set_state;
	t_state			*state;

	if (!context)
		return ;
	state = &context->events.state;
	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.rotate_y -= POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_right(t_context *context)
{
	pthread_mutex_t	*mutex_set_state;
	t_state			*state;

	if (!context)
		return ;
	state = &context->events.state;
	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(state);
	state->scene.polyhedron.rotate_y += POLYHEDRON_ROTATION_INTENSITY;
	pthread_mutex_unlock(mutex_set_state);
}
