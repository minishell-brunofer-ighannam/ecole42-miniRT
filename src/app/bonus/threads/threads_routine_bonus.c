/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:28:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 16:24:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

static bool			ft_verify_parts_ready(t_parallel *parallel);

static inline void	ft_set_frames_ready(t_parallel *parallel)
{
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (parallel->flow_ctrl->frame_parts_ready < parallel->n_threads)
		parallel->flow_ctrl->frame_parts_ready++;
	while (parallel->flow_ctrl->frame_parts_ready > 0)
	{
		pthread_cond_wait(&parallel->flow_ctrl->cond_frame_ready,
			&parallel->flow_ctrl->mutex_set_state);
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
}

static inline void	ft_await_resize(t_parallel *parallel, t_state *state)
{
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	while (state->window.has_changes)
	{
		parallel->flow_ctrl->threads_sleepping++;
		pthread_cond_wait(&parallel->flow_ctrl->cond_window_resize,
			&parallel->flow_ctrl->mutex_set_state);
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
}

static void	ft_await_threads_finish(t_parallel *parallel, t_mlx *mlx)
{
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	parallel->flow_ctrl->threads_finished++;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	usleep(10000);
	while (ft_verify_parts_ready(parallel))
	{
		pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
		if (parallel->flow_ctrl->frame_parts_ready)
		{
			pthread_cond_broadcast(&parallel->flow_ctrl->cond_frame_ready);
			parallel->flow_ctrl->frame_parts_ready--;
		}
		if (parallel->flow_ctrl->threads_sleepping)
		{
			pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
			parallel->flow_ctrl->threads_sleepping--;
		}
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
		usleep(10000);
	}
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (parallel->flow_ctrl->threads_finished == parallel->n_threads)
		mlx_loop_end(mlx->window.mlx_ref);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
}

static bool	ft_verify_parts_ready(t_parallel *parallel)
{
	bool	not_all_ready;

	not_all_ready = true;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	not_all_ready = parallel->flow_ctrl->threads_finished < parallel->n_threads;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (not_all_ready);
}

void	*ft_thread_routine(t_thread *thread)
{
	t_parallel	*parallel;
	t_context	*context;
	t_mlx		*mlx;

	if (!thread)
		return (NULL);
	context = thread->context;
	parallel = thread->context->parallel;
	mlx = &context->mlx;
	while (context->callbacks.is_app_running(context))
	{
		usleep(10000);
		ft_await_resize(parallel, &context->events.state);
		if (context->callbacks.is_process_stopped(context))
			continue ;
		if (ft_recalculate_thread_chunck(thread, mlx, parallel))
			continue ;
		parallel->ray_tracing(context, thread->range_start, thread->range_end);
		usleep(10000);
		if (context->callbacks.is_process_stopped(context))
			continue ;
		ft_set_frames_ready(parallel);
	}
	ft_await_threads_finish(parallel, mlx);
	return (NULL);
}
