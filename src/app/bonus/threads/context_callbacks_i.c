/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_callbacks_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/04 11:29:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"


bool	ft_is_app_running(t_context *self)
{
	bool		stop_app;
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_app_run);
	stop_app = self->events.state.stop_app;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_app_run);
	return (!stop_app);
}

void	ft_stop_app(t_context *self)
{
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_app_run);
	self->events.state.stop_app = true;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_app_run);
}

bool	ft_is_frame_ready(t_context *self)
{
	bool		is_frame_ready;
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_ready);
	is_frame_ready = parallel->flow_ctrl->is_frame_ready;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_ready);
	return (is_frame_ready);
}

void	ft_set_frame_ready(t_context *self, bool status)
{
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_ready);
	parallel->flow_ctrl->is_frame_ready = status;
	if (!status)
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_frame_ready);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_ready);
	if (!status)
	{
		pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_parts_ready);
		parallel->flow_ctrl->frame_parts_ready = 0;
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	}
}

void	ft_set_frame_parts_ready(t_context *self)
{
	bool		is_ready;
	t_parallel	*parallel;

	parallel = self->parallel;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	parallel->flow_ctrl->frame_parts_ready++;
	is_ready = parallel->flow_ctrl->frame_parts_ready == parallel->n_threads;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	if (is_ready)
		ft_set_frame_ready(self, true);
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_frame_parts_ready);
	while (parallel->flow_ctrl->frame_parts_ready > 0)
		pthread_cond_wait(&parallel->flow_ctrl->cond_frame_ready,
			&parallel->flow_ctrl->mutex_frame_parts_ready);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_frame_parts_ready);
}
