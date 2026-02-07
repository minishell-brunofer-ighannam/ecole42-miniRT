/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_callbacks_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/07 14:47:44 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"


bool	ft_is_window_resized(t_context *self)
{
	bool		is_window_resize;
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	is_window_resize = self->events.state.window.has_changes;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_window_resize);
}

bool	ft_is_process_stopped(t_context *self)
{
	t_parallel	*parallel;
	bool		window_change;
	bool		app_stopped;

	window_change = false;
	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (self->events.state.window.has_changes)
		window_change = true;
	app_stopped = self->events.state.stop_app;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (window_change || app_stopped);
}
