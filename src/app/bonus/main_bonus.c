/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 13:29:27 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "../../minilibx/includes/minilibx.h"
#include "events/includes/events_bonus.h"

static int	fake_loop_callback(void *param)
{
	(void)param;
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_events	events;
	int			width;
	int			height;

	width = 500;
	height = 500;
	if (argc >= 2)
	{
		width = ft_atoi(argv[1]);
		if (argv[2])
			height = ft_atoi(argv[2]);
	}
	printf("[BONUS] --> argv: %s\n", argv[1]);

	mlx = ft_new_mlx(width, height, "brunofer&ighannam:miniRT");
	events = ft_new_events();

	mlx.events.key_press(mlx, events.callbacks.keyboard.key_press, NULL);
	mlx.events.key_release(mlx, events.callbacks.keyboard.key_release, NULL);
	mlx.events.mouse_btn_press(mlx, events.callbacks.mouse.btn_press, NULL);
	mlx.events.mouse_btn_release(mlx, events.callbacks.mouse.btn_release, NULL);
	mlx.events.mouse_move(mlx, events.callbacks.mouse.btn_move_callback, NULL);
	mlx.events.loop(mlx, fake_loop_callback, NULL);
	mlx.events.window_resize(mlx, events.callbacks.window.resize, NULL);
	mlx.events.window_close(mlx, events.callbacks.window.close, &mlx);
	mlx.loop(mlx);
	mlx.destroy(mlx);
	return (0);
}
