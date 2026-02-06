/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/06 15:35:46 by ighannam         ###   ########.fr       */
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
	t_state		*state;
	bool		is_render_allowed;
	t_parallel	*parallel;

	if (!context)
		return (false);
	parallel = context->parallel;
	is_render_allowed = true;
	state = &context->events.state;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->has_changes && state->window.has_changes)
	{
		is_render_allowed = false;
		context->mlx.resize_image(&context->mlx, state->window.width, state->window.height);
		context->mlx.display_image(context->mlx);
		state->window.has_changes = false;
		pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}
