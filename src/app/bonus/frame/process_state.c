/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:02:21 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 13:32:32 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../context.h"
#include "includes/frame_internal.h"

bool	ft_process_state(t_context *context)
{
	t_state	*state;
	bool	is_render_allowed;


	if (!context)
		return (false);
	is_render_allowed = true;
	state = &context->events.state;
	if (state->has_changes && state->window.has_changes)
	{
		is_render_allowed = false;
		context->mlx.resize_image(&context->mlx, state->window.width, state->window.height);
		context->mlx.display_image(context->mlx);
		state->window.has_changes = false;
	}
	return (is_render_allowed);
}
