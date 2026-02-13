/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/13 18:46:58 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../context.h"
#include "includes/frame_internal.h"

static inline bool	ft_is_x_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.z >= 0 && cam_forward.z >= 0)
		|| (cam_forward.y < 0 && cam_forward.y < 0))
		return (true);
	return (false);
}

static inline bool	ft_is_y_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.z >= 0 && cam_forward.z >= 0)
		|| (cam_forward.x < 0 && cam_forward.x < 0))
		return (true);
	return (false);
}

static inline bool	ft_is_z_inverse(t_vector_3d cam_forward)
{
	if ((cam_forward.x >= 0 && cam_forward.x >= 0)
		|| (cam_forward.y < 0 && cam_forward.y < 0))
		return (true);
	return (false);
}

static inline t_vector_3d	rotate_axis(t_vector_3d v, t_vector_3d axis, double angle)
{
	t_vector_3d	result;
	double		cos_a;
	double		sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = v.x * cos_a
		+ (axis.y * v.z - axis.z * v.y) * sin_a
		+ axis.x * (axis.x * v.x + axis.y * v.y + axis.z * v.z) * (1 - cos_a);

	result.y = v.y * cos_a
		+ (axis.z * v.x - axis.x * v.z) * sin_a
		+ axis.y * (axis.x * v.x + axis.y * v.y + axis.z * v.z) * (1 - cos_a);

	result.z = v.z * cos_a
		+ (axis.x * v.y - axis.y * v.x) * sin_a
		+ axis.z * (axis.x * v.x + axis.y * v.y + axis.z * v.z) * (1 - cos_a);

	return (result);
}

bool	ft_process_state(t_context *context)
{
	t_state		*state;
	bool		is_render_allowed;
	t_parallel	*parallel;
	double		angle;


	if (!context)
		return (false);
	is_render_allowed = true;
	parallel = context->parallel;
	state = &context->events.state;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->scene.camera.has_changes)
	{
		context->scene->camera.origin.x += (context->scene->camera.forward.x * state->scene.camera.translate_z);
		context->scene->camera.origin.y += (context->scene->camera.forward.y * state->scene.camera.translate_z);
		context->scene->camera.origin.z += (context->scene->camera.forward.z * state->scene.camera.translate_z);
		if (ft_is_x_inverse(context->scene->camera.forward))
			context->scene->camera.origin.x -= state->scene.camera.translate_x;
		else
			context->scene->camera.origin.x += state->scene.camera.translate_x;
		if (ft_is_y_inverse(context->scene->camera.forward))
			context->scene->camera.origin.y -= state->scene.camera.translate_y;
		else
			context->scene->camera.origin.y += state->scene.camera.translate_y;
		if (ft_is_z_inverse(context->scene->camera.forward))
			context->scene->camera.origin.z -= (context->scene->camera.forward.z * state->scene.camera.translate_z);
		else
			context->scene->camera.origin.z += (context->scene->camera.forward.z * state->scene.camera.translate_z);
		state->scene.camera.translate_x = 0;
		state->scene.camera.translate_y = 0;
		state->scene.camera.translate_z = 0;

		angle = -(state->scene.camera.rotate_y * 0.2 * (M_PI / 180.0));
		context->scene->camera.forward = rotate_axis(context->scene->camera.forward, context->scene->camera.up, angle);

		context->scene->camera.forward = ft_vec_norm(context->scene->camera.forward);
		context->scene->camera.right = ft_vec_norm(ft_cross_product(context->scene->camera.forward, context->scene->camera.up));
		context->scene->camera.up = ft_vec_norm(ft_cross_product(context->scene->camera.right, context->scene->camera.forward));

		angle = -(state->scene.camera.rotate_x * 0.2 * (M_PI / 180.0));
		context->scene->camera.forward = rotate_axis(context->scene->camera.forward, context->scene->camera.right, angle);

		context->scene->camera.forward = ft_vec_norm(context->scene->camera.forward);
		context->scene->camera.right = ft_vec_norm(ft_cross_product(context->scene->camera.forward, context->scene->camera.up));
		context->scene->camera.up = ft_vec_norm(ft_cross_product(context->scene->camera.right, context->scene->camera.forward));

		angle = state->scene.camera.rotate_z * 0.2 * (M_PI / 180.0);
		context->scene->camera.right = rotate_axis(context->scene->camera.right, context->scene->camera.forward, angle);
		context->scene->camera.up = rotate_axis(context->scene->camera.up, context->scene->camera.forward, angle);

		context->scene->camera.forward = ft_vec_norm(context->scene->camera.forward);
		context->scene->camera.right = ft_vec_norm(ft_cross_product(context->scene->camera.forward, context->scene->camera.up));
		context->scene->camera.up = ft_vec_norm(ft_cross_product(context->scene->camera.right, context->scene->camera.forward));

		state->scene.camera.rotate_y = 0;
		state->scene.camera.rotate_z = 0;
		state->scene.camera.rotate_x = 0;
		// ft_camera_init(&context->scene->camera, context);

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
