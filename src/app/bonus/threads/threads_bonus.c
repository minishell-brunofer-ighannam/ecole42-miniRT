/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:28:33 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 16:49:48 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

void	*ft_thread_destroy(t_thread **self_ref);

t_thread	*ft_new_thread(t_context *context, t_flow_ctrl *flow_ctrl, int id, int n_threads)
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
	thread->error = pthread_create(&thread->thread, NULL, ft_thread_routine, thread);
	if (thread->error)
		return (thread->destroy(&thread));
	return (thread);
}

void	ft_recalculate_thread_chunck(t_thread *thread)
{
	t_context	*context;
	t_parallel	*parallel;

	context = thread->context;
	parallel = context->parallel;
	if (context->mlx.window.height <= parallel->n_threads)
		thread->chunck = 1;
	else
		thread->chunck = context->mlx.window.height / parallel->n_threads;
	thread->range_start = thread->id * thread->chunck;
	if (thread->id == parallel->n_threads - 1)
		thread->range_end = context->mlx.window.height - 1;
	else
		thread->range_end = thread->range_start + thread->chunck - 1;
}

t_parallel	*ft_parallelize(t_context *context)
{
	t_parallel	*parallel;

	if (!context)
		return (NULL);
	parallel = ft_calloc(1, sizeof(t_parallel));
	context->parallel = parallel;
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
