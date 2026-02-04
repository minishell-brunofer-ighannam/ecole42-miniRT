/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:28:36 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 07:28:45 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../context.h"
#include "includes/frame_internal.h"

static int	ft_run_frame(t_context *context);
static void	ft_render_frame(t_context *context);

t_frame	ft_new_frame(void)
{
	t_frame	frame;

	frame.run = ft_run_frame;
	return (frame);
}

static int	ft_run_frame(t_context *context)
{
	bool	is_render_allowed;

	gettimeofday(&context->frame.frame_start, NULL);
	if (!context->events.state.window.has_changes)
		ft_draw_square(context, 100, 100);
	is_render_allowed = ft_process_resize_image(context);
	if (is_render_allowed)
		ft_render_frame(context);
	// else
		// printf("nao renerizou!");
	return (1);
}

void	ft_simulate_expensive_prossessing(int threads_amount, int ops_per_pixel, t_context *context)
{
	double		baskara;
	int			pixels;
	int			pixels_per_thread;
	int			math_operations;
	static int	first_call = 0;

	pixels = context->events.state.window.width * context->events.state.window.height;
	pixels_per_thread = pixels / threads_amount;
	if (!first_call)
	{
		printf("\n\n--------------- Grafical Simulation ---------------\n");
		printf("Window size: %dx%d - [Total of %d pixels]\n", context->events.state.window.width, context->events.state.window.height, pixels);
		printf("Calculus amount per pixel: %d\n", ops_per_pixel);
		printf("Calculus total: %d\n", ops_per_pixel * pixels);
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

static void	ft_render_frame(t_context *context)
{
	context->mlx.display_image(context->mlx);
	ft_process_state(context);
	ft_show_frame_info(context);
	context->callbacks.set_frame_ready(context, false);
}
