/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:52:38 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/07 08:39:17 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

static bool	ft_init_threads(t_parallel *parallel, t_context *context);
static void	ft_destroy_threads(t_thread ***threads_ref, unsigned int n_threads);
static void	*ft_destroy_parallelize(t_parallel **self_ref);

t_parallel	*ft_parallelize(t_context *context,
		void *(*ray_tracing)(t_context *context, int row_start, int row_end))
{
	t_parallel	*parallel;

	if (!context)
		return (NULL);
	parallel = ft_calloc(1, sizeof(t_parallel));
	parallel->flow_ctrl = ft_new_flow_control();
	if (!parallel->flow_ctrl)
		return (ft_destroy_parallelize(&parallel));
	context->parallel = parallel;
	context->events.state.parallel = parallel;
	parallel->n_threads = sysconf(_SC_NPROCESSORS_ONLN) / 2;
	parallel->ray_tracing = ray_tracing;
	parallel->destroy = ft_destroy_parallelize;
	if (!ft_init_threads(parallel, context))
		return (ft_destroy_parallelize(&parallel));
	return (parallel);
}

static bool	ft_init_threads(t_parallel *parallel, t_context *context)
{
	unsigned int	n_threads;
	t_flow_ctrl		*flow_ctrl;
	int				i;

	n_threads = parallel->n_threads;
	flow_ctrl = parallel->flow_ctrl;
	parallel->threads = ft_calloc(parallel->n_threads + 1, sizeof(t_thread *));
	i = -1;
	while (++i < (int)parallel->n_threads)
	{
		parallel->threads[i] = ft_new_thread(context, flow_ctrl, i, n_threads);
		if (!parallel->threads[i])
		{
			while (--i >= 0)
				parallel->threads[i]->destroy(&parallel->threads[i]);
			free(parallel->threads);
			parallel->threads = NULL;
			return (false);
		}
	}
	return (true);
}

static void	ft_destroy_threads(t_thread ***threads_ref, unsigned int n_threads)
{
	int			i;
	t_thread	**threads;

	if (!threads_ref || !*threads_ref || !**threads_ref)
		return ;
	threads = *threads_ref;
	i = -1;
	while (++i < (int)n_threads)
		threads[i]->destroy(&threads[i]);
	free(threads);
	*threads_ref = NULL;
}

static void	*ft_destroy_parallelize(t_parallel **self_ref)
{
	t_parallel	*self;

	if (!self_ref || !*self_ref)
		return (NULL);
	self = *self_ref;
	if (self->threads)
		ft_destroy_threads(&self->threads, self->n_threads);
	if (self->flow_ctrl)
		self->flow_ctrl->destroy(&self->flow_ctrl);
	free(self);
	*self_ref = NULL;
	return (NULL);
}
