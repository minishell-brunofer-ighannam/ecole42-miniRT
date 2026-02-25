/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 13:00:06 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

bool	ft_process_state(t_context *context)
{
	t_state		*state;
	bool		is_render_allowed;
	t_parallel	*parallel;

	if (!context)
		return (false);
	is_render_allowed = true;
	parallel = context->parallel;
	state = &context->events.state;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->scene.camera.has_changes)
		ft_handle_camera(&context->scene->camera, &state->scene.camera);
	if (state->scene.polyhedron.has_changes)
		ft_handle_polyhedron(&state->scene.polyhedron);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}

static inline void	ft_perform_resize(
						t_context *context, bool *is_render_allowed,
						struct timeval *last_resize)
{
	t_state					*state;

	state = &context->events.state;
	*is_render_allowed = false;
	context->mlx.resize_image(&context->mlx, state->window.width,
		state->window.height);
	context->mlx.display_image(context->mlx);
	if ((double)context->mlx.window.height > 0)
		context->scene->camera.aspect = (double)context->mlx.window.width
			/ (double)context->mlx.window.height;
	gettimeofday(last_resize, NULL);
}

static inline void	ft_make_threads_run_again(
						t_parallel *parallel, t_state *state)
{
	if (parallel->flow_ctrl->threads_sleepping
		&& parallel->flow_ctrl->frame_parts_ready)
	{
		parallel->flow_ctrl->frame_parts_ready = 0;
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_frame_ready);
	}
	if (parallel->flow_ctrl->threads_sleepping == parallel->n_threads)
	{
		state->window.has_changes = false;
		parallel->flow_ctrl->threads_sleepping = 0;
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
	}
}

bool	ft_process_resize_image(t_context *context)
{
	t_state					*state;
	bool					is_render_allowed;
	t_parallel				*parallel;
	static struct timeval	last_resize = {0, 0};
	struct timeval			time_now;

	if (!context)
		return (false);
	parallel = context->parallel;
	is_render_allowed = true;
	state = &context->events.state;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->has_changes && state->window.has_changes
		&& context->mlx.window.width != state->window.width
		&& context->mlx.window.height != state->window.height)
		ft_perform_resize(context, &is_render_allowed, &last_resize);
	if (state->has_changes && state->window.has_changes)
	{
		gettimeofday(&time_now, NULL);
		if (((time_now.tv_sec - last_resize.tv_sec) * 1000 + (time_now.tv_usec
					- last_resize.tv_usec) / 1000) > 1)
			ft_make_threads_run_again(parallel, state);
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}
