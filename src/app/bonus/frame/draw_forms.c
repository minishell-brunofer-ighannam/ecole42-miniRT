/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:19:03 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 12:32:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

void	ft_draw_square(t_context *context, int width, int height)
{
	int	center_x;
	int	center_y;
	int	loop_x;
	int	loop_y;

	if (context->events.state.window.width != context->mlx.window.width
		|| context->events.state.window.height != context->mlx.window.height)
		return ;
	center_x = context->events.state.window.width / 2;
	center_y = context->events.state.window.height / 2;
	center_x += context->events.state.scene.camera.translate_x;
	center_y += context->events.state.scene.camera.translate_y;
	loop_x = -1;
	while (++loop_x < context->events.state.window.width)
	{
		loop_y = -1;
		while (++loop_y < context->events.state.window.height)
		{
			if (loop_x > center_x - width && loop_x < center_x + width
				&& loop_y > center_y - height && loop_y < center_y + height)
				*context->mlx.frame_buffer[loop_x][loop_y] = 0x00FF0000;
			else
				*context->mlx.frame_buffer[loop_x][loop_y] = 0x00000000;
		}
	}
}
