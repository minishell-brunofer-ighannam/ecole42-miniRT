/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:25:29 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 20:46:17 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "colision.h"
#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

void	ft_polyhedron_material(t_state *state, int *prop, bool add)
{
	pthread_mutex_t		*mutex_set_state;

	mutex_set_state = &state->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	if (!state || !state->scene.polyhedron.selected)
	{
		pthread_mutex_unlock(mutex_set_state);
		return ;
	}
	if (add)
		*prop += 1;
	else
		*prop -= 1;
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
	if (add)
		component->value += component->variation_size;
	else
		component->value -= component->variation_size;
	pthread_mutex_unlock(mutex_set_state);
}
