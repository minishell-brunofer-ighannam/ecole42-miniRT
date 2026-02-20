/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callbacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:31:11 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 19:05:13 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../context.h"
#include "includes/events_callbacks_internal_bonus.h"

static int	ft_mouse_btn_press_callback(int key, int x, int y, void *param);
static int	ft_mouse_btn_release_callback(int key, int x, int y, void *param);
static int	ft_mouse_move_callback(int x, int y, void *param);

t_mouse_callbacks	new_mouse_callbacks(void)
{
	t_mouse_callbacks	callbacks;

	callbacks.btn_move_callback = ft_mouse_move_callback;
	callbacks.btn_press = ft_mouse_btn_press_callback;
	callbacks.btn_release = ft_mouse_btn_release_callback;
	return (callbacks);
}

static int	ft_mouse_btn_press_callback(int key, int x, int y, void *param)
{
	t_context	*context;
	t_events	*events;
	int			*pos;

	pos = ft_calloc(2, sizeof(int));
	context = param;
	events = &context->events;
	pos[0] = x;
	pos[1] = y;
	context->events.state.set.keys(context, key, true);
	ft_update_discrete_gestures(&events->gestures, context, key, pos);
	free(pos);
	// printf("mouse[%d] pressed at x:%d, y:%d\n", key, x, y);
	return (1);
}

static int	ft_mouse_btn_release_callback(int key, int x, int y, void *param)
{
	t_context	*context;

	context = param;

	(void)x;
	(void)y;
	context->events.state.set.keys(context, key, false);
	// printf("mouse[%d] released at x:%d, y:%d\n", key, x, y);
	return (1);
}

static int	ft_mouse_move_callback(int x, int y, void *param)
{
	t_context	*context;
	t_events	*events;

	context = param;
	events = &context->events;
	ft_update_spatial_gestures(&events->gestures, context, x, y);
	// printf("mouse moved -> x:%d, y:%d\n", x, y);
	return (1);
}

