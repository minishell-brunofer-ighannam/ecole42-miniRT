/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/27 08:31:42 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "../../minilibx/includes/minilibx.h"
#include "events/includes/events_bonus.h"

static void	ft_track_fps(struct timeval curr_time, t_mlx *mlx)
{
	static int				fps = 0;
	char					*fps_str;
	static int				frame_count = 0;
	static struct timeval	start_time = {0, 0};
	unsigned int			time_diff;

	time_diff = (curr_time.tv_sec - start_time.tv_sec) * 1000
		+ ((curr_time.tv_usec - start_time.tv_usec) / 1000);
	frame_count++;
	if (time_diff >= 1000)
	{
		fps = frame_count;
		frame_count = 0;
		start_time = curr_time;
	}
	fps_str = ft_str_addsufix(ft_utoa_base(fps, "0123456789"), "fps", 1);
	fps_str = ft_str_addprefix(fps_str, " | ", 1);
	mlx_string_put(mlx->window.mlx_ref, mlx->window.win_ref,
		35, 10, 0xffffffff, fps_str);
	free(fps_str);
}

static void	ft_track_ms(struct timeval curr_time, t_mlx *mlx)
{
	char					*ms;
	static struct timeval	last_time = {0, 0};
	int						time_diff;

	time_diff = (curr_time.tv_sec - last_time.tv_sec) * 1000
		+ ((curr_time.tv_usec - last_time.tv_usec) / 1000);

	ms = ft_str_addsufix(ft_itoa(time_diff), "ms", 1);
	mlx_string_put(mlx->window.mlx_ref, mlx->window.win_ref,
		10, 10, 0xffffffff, ms);
	free(ms);
	last_time = curr_time;
}

static void	ft_simulate_expensive_prossessing(int threads_amount, int ops_per_pixel)
{
	double		baskara;
	int			pixels;
	int			pixels_per_thread;
	int			math_operations;
	static int	first_call = 0;

	pixels = 1920 * 1080;
	pixels_per_thread = pixels / threads_amount;
	if (!first_call)
	{
		printf("\n\n--------------- Grafical Simulation ---------------\n");
		printf("Window size: 1920x1080 - [Total of %d pixels]\n", pixels);
		printf("Calculus amount per pixel: %d\n", ops_per_pixel);
		printf("Numbers of Threads: %d - [Total of %d pixels per therad]\n", threads_amount, pixels_per_thread);
		printf("\nOBS: Check the ms and fps indices on the opened window.\n\n");
		first_call++;
	}
	while (--pixels_per_thread >= 0)
	{
		math_operations = -1;
		while (++math_operations < ops_per_pixel)
			baskara = (-10 + (10 * 10 - 40 * 40 * -0.5 * 4)) / (2 * 40);
	}
	(void)baskara;
}

static void	ft_render_frame(struct timeval curr_time, t_mlx *mlx)
{
	ft_simulate_expensive_prossessing(10, 200);
	mlx->display_image(*mlx);
	ft_track_fps(curr_time, mlx);
	ft_track_ms(curr_time, mlx);

}

static int	fake_loop_callback(void *param)
{
	t_mlx					*mlx;
	struct timeval			curr_time;

	mlx = param;
	gettimeofday(&curr_time, NULL);
	ft_render_frame(curr_time, mlx);
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
	mlx.events.loop(mlx, fake_loop_callback, &mlx);
	mlx.events.window_resize(mlx, events.callbacks.window.resize, NULL);
	mlx.events.window_close(mlx, events.callbacks.window.close, &mlx);
	mlx.loop(mlx);
	mlx.destroy(mlx);
	return (0);
}
