/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:28:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/08 16:28:18 by ighannam         ###   ########.fr       */
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
		LOCK(&parallel->flow_ctrl->mutex_set_state);
		while (context->events.state.window.has_changes)
		{
			// printf("thread[%d/%d]::sleepping...\n", thread->id, parallel->n_threads - 1);
			parallel->flow_ctrl->threads_sleepping++;
			pthread_cond_wait(&parallel->flow_ctrl->cond_window_resize,
				&parallel->flow_ctrl->mutex_set_state);
			//printf("thread[%d/%d]::window_change::awake...\n", thread->id, parallel->n_threads - 1);
		}
		UNLOCK(&parallel->flow_ctrl->mutex_set_state);
		if (context->callbacks.is_process_stopped(context))
			continue ;
		ft_recalculate_thread_chunck(thread);
		// printf("thread[%d/%d]::chunck_recalc...\n", thread->id, parallel->n_threads - 1);
		if (context->mlx.window.height < (int)parallel->n_threads
			&& thread->id > context->mlx.window.height)
			continue ;
		// printf("thread[%d/%d]::begin_ray_tracing...\n", thread->id, parallel->n_threads - 1);
		usleep(500);
		parallel->ray_tracing(context, thread->range_start, thread->range_end);
		printf("thread[%d/%d]::end_ray_tracing...\n", thread->id, parallel->n_threads - 1);
		if (context->callbacks.is_process_stopped(context))
		{
			printf("thread[%d/%d]::back_to_top...\n", thread->id, parallel->n_threads - 1);
			continue ;
		}
		// context->callbacks.set_frame_parts_ready(context);
		LOCK(&parallel->flow_ctrl->mutex_set_state);
		if (parallel->flow_ctrl->frame_parts_ready < parallel->n_threads)
			parallel->flow_ctrl->frame_parts_ready++;
		while (parallel->flow_ctrl->frame_parts_ready > 0)
		{
			printf("thread[%d/%d]::finish...\n", thread->id, parallel->n_threads - 1);
			pthread_cond_wait(&parallel->flow_ctrl->cond_frame_ready,
				&parallel->flow_ctrl->mutex_set_state);
			printf("thread[%d/%d]::work_again...\n", thread->id, parallel->n_threads - 1);
		}
		UNLOCK(&parallel->flow_ctrl->mutex_set_state);
	}
	LOCK(&parallel->flow_ctrl->mutex_set_state);
	parallel->flow_ctrl->threads_finished++;
	while (parallel->flow_ctrl->frame_parts_ready)
	{
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_frame_ready);
		parallel->flow_ctrl->frame_parts_ready--;
	}
	while (parallel->flow_ctrl->threads_sleepping)
	{
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
		parallel->flow_ctrl->threads_sleepping--;
	}
	if (parallel->flow_ctrl->threads_finished == parallel->n_threads)
		mlx_loop_end(context->mlx.window.mlx_ref);
	UNLOCK(&parallel->flow_ctrl->mutex_set_state);
	return (NULL);
}
