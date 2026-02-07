/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/07 12:49:58 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../context.h"
#include "includes/frame_internal.h"

bool	ft_process_state(t_context *context)
{
	t_state	*state;
	bool	is_render_allowed;


	if (!context)
		return (false);
	is_render_allowed = true;
	state = &context->events.state;
	if (state->has_changes && state->window.has_changes)
	{
		is_render_allowed = false;
		context->mlx.resize_image(&context->mlx, state->window.width, state->window.height);
		context->mlx.display_image(context->mlx);
		state->window.has_changes = false;

	}
	return (is_render_allowed);
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
	{
		is_render_allowed = false;
		context->mlx.resize_image(&context->mlx, state->window.width, state->window.height);
		context->mlx.display_image(context->mlx);
		// REALIZAR TODAS A S ALTERAÇÕES NA SCENE (relacionadas a window resize) AQUI
		context->scene->camera.aspect = (double)context->mlx.window.width / (double)context->mlx.window.height;
		gettimeofday(&last_resize, NULL);
		printf("resize::made\n");
	}
	if (state->has_changes && state->window.has_changes)
	{
		gettimeofday(&time_now, NULL);
		if (((time_now.tv_sec - last_resize.tv_sec) * 1000 + (time_now.tv_usec - last_resize.tv_usec) / 1000) > 1000)
		{
			state->window.has_changes = false;
			printf("broadcast::made\n");
			pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
		}
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}
