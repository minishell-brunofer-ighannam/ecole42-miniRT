/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_callbacks_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/02 18:18:24 by brunofer         ###   ########.fr       */
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
