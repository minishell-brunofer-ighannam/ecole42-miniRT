/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:28:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/07 13:10:03 by bruno-valer      ###   ########.fr       */
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
		{
			// printf("thrad[%d/%d]::sleepping...\n", thread->id, parallel->n_threads - 1);
			pthread_cond_wait(&parallel->flow_ctrl->cond_window_resize,
				&parallel->flow_ctrl->mutex_set_state);
			printf("thrad[%d/%d]::window_change::awake...\n", thread->id, parallel->n_threads - 1);
		}
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
		if (context->callbacks.is_process_stopped(context))
			continue ;
		ft_recalculate_thread_chunck(thread);
		if (context->mlx.window.height < (int)parallel->n_threads
			&& thread->id > context->mlx.window.height)
			continue ;

		parallel->ray_tracing(context, thread->range_start, thread->range_end);
		if (context->callbacks.is_process_stopped(context))
			continue ;
		// context->callbacks.set_frame_parts_ready(context);
		pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_parts_ready);
		if (parallel->flow_ctrl->frame_parts_ready < parallel->n_threads)
			parallel->flow_ctrl->frame_parts_ready++;
		while (parallel->flow_ctrl->frame_parts_ready > 0)
		{
			pthread_cond_wait(&parallel->flow_ctrl->cond_frame_ready,
				&parallel->flow_ctrl->mutex_frame_parts_ready);
			printf("thrad[%d/%d]::frame_ready::awake...\n", thread->id, parallel->n_threads - 1);
		}
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	}
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	parallel->flow_ctrl->threads_finished++;
	if (parallel->flow_ctrl->threads_finished == parallel->n_threads)
		mlx_loop_end(context->mlx.window.mlx_ref);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	return (NULL);
}
