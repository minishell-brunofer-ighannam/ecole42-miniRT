/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/23 16:54:31 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"
#include "context.h"

static void	*ft_create_context_callbacks(t_context *context)
{
	context->callbacks.is_process_stopped = ft_is_process_stopped;
	context->callbacks.is_app_running = ft_is_app_running;
	context->callbacks.stop_app = ft_stop_app;
	return (NULL);
}

static int	ft_mlx_key_press(int key, void *param)
{
	t_context	*context;

	context = param;
	if (key == KEYBOARD_ESC)
		context->stop_app = true;
	return (1);
}

static int	ft_mlx_close(void *param)
{
	t_context	*context;

	context = param;
	context->stop_app = true;
	return (1);
}

static int	ft_loop_app(void *param)
{
	t_context	*context;
	int			start_line;
	static int	end_line;

	start_line = end_line;
	end_line++;
	context = param;
	if (context->stop_app)
		mlx_loop_end(context->mlx.window.mlx_ref);
	if (end_line < context->mlx.window.height)
		ft_camera_ray_loop(context, start_line, end_line);
	context->mlx.display_image(context->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context		context;
	t_window_info	window;
	t_scene			*scene;

	(void)argc;
	window = ft_new_window_info(1280, 720, "brunofer&ighannam:miniRT");
	context = ft_new_context(window, NULL, ft_create_context_callbacks);
	context.mlx.events.key_press(context.mlx, ft_mlx_key_press, &context);
	context.mlx.events.window_close(context.mlx, ft_mlx_close, &context);
	context.mlx.events.loop(context.mlx, ft_loop_app, &context);
	scene = ft_parser(argv[1], &context);
	if (!scene)
		return (1);
	ft_camera_init(&scene->camera, &context);
	context.scene = scene;
	context.mlx.loop(context.mlx);
	context.mlx.destroy(context.mlx);
	context.scene->destroy(context.scene);
}
