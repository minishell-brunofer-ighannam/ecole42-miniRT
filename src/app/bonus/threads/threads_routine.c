/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:28:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/03 17:50:56 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

void	*ft_thread_routine(t_thread *thread)
{
	t_parallel	*parallel;
	t_context	*context;

	if (!thread)
		return (NULL);
	context = thread->context;
	parallel = thread->context->parallel;
	while (context->callbacks.is_app_running(context))
	{
		pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
		while (context->events.state.window.has_changes)
			pthread_cond_wait(&parallel->flow_ctrl->cond_window_resize,
				&parallel->flow_ctrl->mutex_set_state);
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);

		ft_recalculate_thread_chunck(thread);
		if (context->mlx.window.height < (int)parallel->n_threads
			&& thread->id > context->mlx.window.height)
			continue ;
		parallel->ray_tracing(context, thread->range_start, thread->range_end);
		context->callbacks.set_frame_parts_ready(context);
	}
	return (NULL);
}
