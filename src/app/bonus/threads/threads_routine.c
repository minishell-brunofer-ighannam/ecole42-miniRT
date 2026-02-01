/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:28:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 17:33:31 by bruno-valer      ###   ########.fr       */
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
		ft_recalculate_thread_chunck(thread);
		if (context->mlx.window.height < parallel->n_threads
			&& thread->id > context->mlx.window.height)
			continue ;
		parallel->ray_tracing(context, thread->range_start, thread->range_end);
		context->callbacks.set_frame_parts_ready(context);
	}
}
