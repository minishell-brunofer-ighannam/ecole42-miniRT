/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:25:29 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 20:42:26 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "colision.h"
#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	ft_polyhedron_material(t_state *state, double *prop, bool add)
{
	pthread_mutex_t		*mutex_set_state;

	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	if (!state || !state->scene.polyhedron.selected)
	{
		pthread_mutex_unlock(mutex_set_state);
		return ;
	}
	set_polyhedron_changed_flag(state);
	if (add)
		*prop += 0.1;
	else
		*prop -= 0.1;
	pthread_mutex_unlock(mutex_set_state);
}

void	ft_polyhedron_component(t_state *state,
			t_polyhedron_state_component *component, bool add)
{
	pthread_mutex_t		*mutex_set_state;

	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	if (!state || !state->scene.polyhedron.selected)
	{
		pthread_mutex_unlock(mutex_set_state);
		return ;
	}
	set_polyhedron_changed_flag(state);
	if (add)
		component->value += component->variation_size;
	else
		component->value -= component->variation_size;
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_changed_flag(t_state *self)
{
	if (!self->scene.polyhedron.has_changes)
	{
		if (!self->scene.has_changes)
		{
			self->has_changes = true;
			self->scene.has_changes = true;
		}
		else if (!self->has_changes)
			self->has_changes = true;
		self->scene.polyhedron.has_changes = true;
	}
}
