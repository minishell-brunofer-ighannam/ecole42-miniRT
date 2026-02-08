/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_callbacks_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/08 12:34:13 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"


bool	ft_is_window_resized(t_context *self)
{
	bool		is_window_resize;
	t_parallel	*parallel;

	parallel = self->parallel;
	LOCK(&parallel->flow_ctrl->mutex_set_state);
	is_window_resize = self->events.state.window.has_changes;
	UNLOCK(&parallel->flow_ctrl->mutex_set_state);
	return (is_window_resize);
}

bool	ft_is_process_stopped(t_context *self)
{
	t_parallel	*parallel;
	bool		window_change;
	bool		app_stopped;

	window_change = false;
	parallel = self->parallel;
	LOCK(&parallel->flow_ctrl->mutex_set_state);
	if (self->events.state.window.has_changes)
		window_change = true;
	app_stopped = self->events.state.stop_app;
	UNLOCK(&parallel->flow_ctrl->mutex_set_state);
	return (window_change || app_stopped);
}
