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

#include "context.h"
#include "includes/frame_internal_bonus.h"

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
	is_render_allowed = ft_process_resize_image(context);
	if (is_render_allowed)
		ft_render_frame(context);
	return (1);
}

static void	ft_render_frame(t_context *context)
{
	if (context->callbacks.is_frame_ready(context))
	{
		context->mlx.display_image(context->mlx);
		ft_process_state(context);
		ft_show_frame_info(context);
		context->callbacks.set_frame_ready(context, false);
	}
}
