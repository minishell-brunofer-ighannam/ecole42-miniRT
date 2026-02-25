/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:28:33 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:22:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

void		*ft_thread_destroy(t_thread **self_ref);

t_thread	*ft_new_thread(t_context *context, t_flow_ctrl *flow_ctrl, int id,
		int n_threads)
{
	t_thread	*thread;
	int			chunck;

	thread = ft_calloc(1, sizeof(t_thread));
	if (!thread)
		return (NULL);
	chunck = context->mlx.window.height / n_threads;
	thread->id = id;
	thread->chunck = chunck;
	thread->context = context;
	thread->flow_ctrl = flow_ctrl;
	thread->range_start = id * chunck;
	if (id == n_threads - 1)
		thread->range_end = context->mlx.window.height - 1;
	else
		thread->range_end = thread->range_start + chunck - 1;
	thread->destroy = ft_thread_destroy;
	thread->error = pthread_create(&thread->thread, NULL,
			(void *(*)())ft_thread_routine, thread);
	if (thread->error)
		return (thread->destroy(&thread));
	return (thread);
}

bool	ft_recalculate_thread_chunck(t_thread *thread, t_mlx *mlx,
		t_parallel *parallel)
{
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (mlx->window.height <= (int)parallel->n_threads)
		thread->chunck = 1;
	else
		thread->chunck = mlx->window.height / parallel->n_threads;
	thread->range_start = thread->id * thread->chunck;
	if (thread->id == (int)parallel->n_threads - 1)
		thread->range_end = mlx->window.height - 1;
	else
		thread->range_end = thread->range_start + thread->chunck - 1;
	if ((mlx->window.height < (int)parallel->n_threads && thread->id
			+ 1 > mlx->window.height) || mlx->window.width < 2)
	{
		pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
		return (true);
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (false);
}

void	*ft_thread_destroy(t_thread **self_ref)
{
	t_thread	*self;

	if (!self_ref || !*self_ref)
		return (NULL);
	self = *self_ref;
	if (!self->error)
		pthread_join(self->thread, NULL);
	free(self);
	*self_ref = NULL;
	return (NULL);
}
