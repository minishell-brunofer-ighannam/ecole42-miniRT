/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/08 13:52:06 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../context.h"
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
	LOCK(&parallel->flow_ctrl->mutex_set_state);
	(void)state;
	UNLOCK(&parallel->flow_ctrl->mutex_set_state);
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
	LOCK(&parallel->flow_ctrl->mutex_set_state);
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
		//printf("resize::made\n");
	}
	if (state->has_changes && state->window.has_changes)
	{
		gettimeofday(&time_now, NULL);
		if (((time_now.tv_sec - last_resize.tv_sec) * 1000 + (time_now.tv_usec - last_resize.tv_usec) / 1000) > 5)
		{
			printf("threads_sleepping: %u\n", parallel->flow_ctrl->threads_sleepping);
			if (parallel->flow_ctrl->threads_sleepping && parallel->flow_ctrl->frame_parts_ready)
			{
				parallel->flow_ctrl->frame_parts_ready = 0;
				pthread_cond_broadcast(&parallel->flow_ctrl->cond_frame_ready);
			}
			if (parallel->flow_ctrl->threads_sleepping == parallel->n_threads)
			{
				state->window.has_changes = false;
				parallel->flow_ctrl->threads_sleepping = 0;
				usleep(500);
				printf("broadcast::made\n");
				pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
				usleep(500);				
			}
		}
	}
	UNLOCK(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}
