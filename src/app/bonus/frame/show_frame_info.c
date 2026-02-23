/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_frame_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:41:34 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/23 14:17:53 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

static void	ft_track_fps(t_context *context);
static void	ft_track_ms(t_context *context);

void	ft_show_frame_info(t_context *context)
{
	ft_track_fps(context);
	ft_track_ms(context);
}

static void	ft_track_fps(t_context *context)
{
	static int				fps = 0;
	char					*fps_str;
	static int				frame_count = 0;
	static struct timeval	start_time = {0, 0};
	unsigned int			time_diff;

	time_diff = (context->frame.frame_start.tv_sec - start_time.tv_sec) * 1000
		+ ((context->frame.frame_start.tv_usec - start_time.tv_usec) / 1000);
	frame_count++;
	if (time_diff >= 1000)
	{
		fps = frame_count;
		frame_count = 0;
		start_time = context->frame.frame_start;
	}
	fps_str = ft_str_addsufix(ft_utoa_base(fps, "0123456789"), "fps", 1);
	fps_str = ft_str_addprefix(fps_str, " | ", 1);
	mlx_string_put(context->mlx.window.mlx_ref, context->mlx.window.win_ref,
		35, 10, 0x00000000, fps_str);
	free(fps_str);
}

static void	ft_track_ms(t_context *context)
{
	char					*ms;
	static struct timeval	last_time = {0, 0};
	int						time_diff;

	time_diff = (context->frame.frame_start.tv_sec - last_time.tv_sec) * 1000
		+ ((context->frame.frame_start.tv_usec - last_time.tv_usec) / 1000);

	ms = ft_str_addsufix(ft_itoa(time_diff), "ms", 1);
	mlx_string_put(context->mlx.window.mlx_ref, context->mlx.window.win_ref,
		10, 10, 0x00000000, ms);
	free(ms);
	last_time = context->frame.frame_start;
}

