/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 14:25:25 by bruno-valer      ###   ########.fr       */
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

static void	*ft_crate_context_callbacks(t_context *context)
{
	context->callbacks.is_app_running = ft_is_app_running;
	context->callbacks.stop_app = ft_stop_app;
	context->callbacks.is_frame_ready = ft_is_frame_ready;
	context->callbacks.set_frame_parts_ready = ft_set_frame_parts_ready;
	context->callbacks.set_frame_ready = ft_set_frame_ready;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_mlx			*mlx;
	t_events		*events;
	t_context		context;
	t_window_info	window;

	window = ft_new_window_info(500, 500, "brunofer&ighannam:miniRT");
	if (argc >= 2)
	{
		window.width = ft_atoi(argv[1]);
		if (argv[2])
			window.height = ft_atoi(argv[2]);
	}
	printf("[BONUS] --> argv: %s\n", argv[1]);
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
	mlx->events.window_close(*mlx, events->callbacks.window.close, mlx);
	mlx->loop(*mlx);
	mlx->destroy(*mlx);
	return (0);
}
