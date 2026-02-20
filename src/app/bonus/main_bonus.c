/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/20 15:38:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "../../minilibx/includes/minilibx.h"
#include "events/includes/events_bonus.h"
#include "threads/includes/threads_bonus.h"
#include "context.h"
#include "ray_tracing.h"
#include "parser.h"
#include "scene.h"
#include "camera.h"
#include "ray_tracer.h"
#include "math_rt.h"
#include "colision.h"

static void	*ft_crate_context_callbacks(t_context *context)
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

int	main(int argc, char **argv)
{
	t_mlx			*mlx;
	t_events		*events;
	t_context		context;
	t_window_info	window;
	t_parallel		*parallel;
	t_scene *scene;


	window = ft_new_window_info(500, 500, "brunofer&ighannam:miniRT");
	if (argc >= 4)
	{
		window.width = ft_atoi(argv[2]);
		if (argv[3])
			window.height = ft_atoi(argv[3]);
	}
	printf("[BONUS] --> argv: %s\n", argv[2]);
	context = ft_new_context(window, NULL, ft_crate_context_callbacks);
	mlx = &context.mlx;
	events = &context.events;
	mlx->events.key_press(*mlx, events->callbacks.keyboard.key_press, &context);
	mlx->events.key_release(*mlx, events->callbacks.keyboard.key_release, &context);
	mlx->events.mouse_btn_press(*mlx, events->callbacks.mouse.btn_press, &context);
	mlx->events.mouse_btn_release(*mlx, events->callbacks.mouse.btn_release, &context);
	mlx->events.mouse_move(*mlx, events->callbacks.mouse.btn_move_callback, &context);
	mlx->events.loop(*mlx, (int (*)())context.frame.run, &context);
	mlx->events.window_resize(*mlx, events->callbacks.window.resize, &context);
	mlx->events.window_close(*mlx, events->callbacks.window.close, &context);

	scene = ft_parser(argv[1], &context);
	if (!scene)
		return (1);

	ft_camera_init(&scene->camera, &context);
	context.scene = scene;

	parallel = ft_parallelize(&context, ft_camera_ray_loop);
	mlx->loop(*mlx);
	events->state.destroy(&context);
	parallel->destroy(&parallel);
	mlx->destroy(*mlx);
	scene->destroy(scene);
	return (0);
}
