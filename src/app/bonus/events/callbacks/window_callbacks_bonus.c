/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_callbacks_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:37:28 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/04 11:34:18 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../context.h"
#include "includes/events_callbacks_internal_bonus.h"

static int	ft_window_resize(void *param, XEvent *event);
static int	ft_close_window(t_context *context);

t_window_callbacks	ft_new_window_callbacks(void)
{
	t_window_callbacks	callbacks;

	callbacks.close = ft_close_window;
	callbacks.resize = ft_window_resize;
	return (callbacks);
}

static int	ft_window_resize(void *param, XEvent *event)
{
	t_context	*context;
	t_events	*events;
	int			width;
	int			height;

	context = param;
	events = &context->events;
	width = event->xconfigure.width;
	height = event->xconfigure.height;
	events->state.set.window(&events->state, width, height);
	// printf("new width: %d, new height: %d\n", width, height);
	return (1);
}

static int	ft_close_window(t_context *context)
{
	context->callbacks.stop_app(context);
	// mlx_loop_end(context->mlx.window.mlx_ref);
	return (1);
}
