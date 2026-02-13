/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/13 12:15:33 by ighannam         ###   ########.fr       */
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
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->scene.camera.has_changes)
	{
		if (context->scene->camera.forward.z > 0)
		{
			context->scene->camera.origin.x -= state->scene.camera.translate_x;
		}
		else
			context->scene->camera.origin.x += state->scene.camera.translate_x;
		context->scene->camera.origin.y += state->scene.camera.translate_y;
		context->scene->camera.origin.z += state->scene.camera.translate_z;
		state->scene.camera.translate_x = 0;
		state->scene.camera.translate_y = 0;
		state->scene.camera.translate_z = 0;
		

		double angle = state->scene.camera.rotate_y * 0.2 * (M_PI / 180.0);
		double cos_a = cos(angle);
		double sin_a = sin(angle);
		t_vector_3d f = context->scene->camera.forward;
		context->scene->camera.forward.x = f.x * cos_a + f.z * sin_a;
		context->scene->camera.forward.z = -f.x * sin_a + f.z * cos_a;
		
		angle = state->scene.camera.rotate_x * 0.2 * (M_PI / 180.0);
		cos_a = cos(angle);
		sin_a = sin(angle);
		f = context->scene->camera.forward;
		context->scene->camera.forward.y = f.y * cos_a - f.z * sin_a;
		context->scene->camera.forward.z = f.y * sin_a + f.z * cos_a;
		
		angle = state->scene.camera.rotate_z * 0.2 * (M_PI / 180.0);
		cos_a = cos(angle);
		sin_a = sin(angle);
		f = context->scene->camera.forward;
		context->scene->camera.forward.x = f.x * cos_a - f.y * sin_a;
		context->scene->camera.forward.y = f.x * sin_a + f.y * cos_a;
				

		state->scene.camera.rotate_y = 0;
		state->scene.camera.rotate_z = 0;
		state->scene.camera.rotate_x = 0;

		ft_camera_init(&context->scene->camera, context);
		state->scene.camera.has_changes = false;
	}
	
	//(void)state;
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
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
		if ((double)context->mlx.window.height > 0)
			context->scene->camera.aspect = (double)context->mlx.window.width / (double)context->mlx.window.height;
		gettimeofday(&last_resize, NULL);
		//printf("resize::made\n");
	}
	if (state->has_changes && state->window.has_changes)
	{
		gettimeofday(&time_now, NULL);
		if (((time_now.tv_sec - last_resize.tv_sec) * 1000 + (time_now.tv_usec - last_resize.tv_usec) / 1000) > 1)
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
				printf("broadcast::made\n");
				pthread_cond_broadcast(&parallel->flow_ctrl->cond_window_resize);
			}
		}
	}
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
	return (is_render_allowed);
}
