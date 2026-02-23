/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/23 16:15:09 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "context.h"

static void	*ft_create_context_callbacks(t_context *context)
{
	context->callbacks.is_process_stopped = ft_is_process_stopped;
	context->callbacks.is_app_running = ft_is_app_running;
	context->callbacks.stop_app = ft_stop_app;
	context->callbacks.is_frame_ready = ft_is_frame_ready;
	context->callbacks.set_frame_parts_ready = ft_set_frame_parts_ready;
	context->callbacks.set_frame_ready = ft_set_frame_ready;
	context->callbacks.is_window_resized = ft_is_window_resized;
	return (NULL);
}

static void	ft_setup_mlx_events(t_context *context)
{
	t_mlx		*mlx;
	t_events	*events;

	mlx = &context->mlx;
	events = &context->events;
	mlx->events.key_press(*mlx, events->callbacks.keyboard.key_press, context);
	mlx->events.key_release(
		*mlx, events->callbacks.keyboard.key_release, context);
	mlx->events.mouse_btn_press(
		*mlx, events->callbacks.mouse.btn_press, context);
	mlx->events.mouse_btn_release(
		*mlx, events->callbacks.mouse.btn_release, context);
	mlx->events.mouse_move(
		*mlx, events->callbacks.mouse.btn_move_callback, context);
	mlx->events.loop(*mlx, (int (*)())context->frame.run, context);
	mlx->events.window_resize(*mlx, events->callbacks.window.resize, context);
	mlx->events.window_close(*mlx, events->callbacks.window.close, context);
}

static void	ft_destroy_app(t_context *context)
{
	t_mlx		*mlx;
	t_events	*events;
	t_parallel	*parallel;
	t_scene		*scene;

	mlx = &context->mlx;
	events = &context->events;
	parallel = context->parallel;
	scene = context->scene;
	events->state.destroy(context);
	parallel->destroy(&parallel);
	mlx->destroy(*mlx);
	scene->destroy(scene);
}

int	main(int argc, char **argv)
{
	t_context		context;
	t_window_info	window;
	t_scene			*scene;

	window = ft_new_window_info(500, 500, "brunofer&ighannam:miniRT");
	if (argc >= 4)
	{
		window.width = ft_atoi(argv[2]);
		if (argv[3])
			window.height = ft_atoi(argv[3]);
	}
	context = ft_new_context(window, NULL, ft_create_context_callbacks);
	ft_setup_mlx_events(&context);
	scene = ft_parser(argv[1], &context);
	if (!scene)
		return (1);
	ft_camera_init(&scene->camera, &context);
	context.scene = scene;
	ft_parallelize(&context, ft_camera_ray_loop);
	context.mlx.loop(context.mlx);
	ft_destroy_app(&context);
	return (0);
}
