/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callbacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:31:11 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:17:49 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../context.h"
#include "includes/events_callbacks_internal_bonus.h"

static int			ft_mouse_btn_press_callback(int key, int x, int y,
						void *param);
static int			ft_mouse_btn_release_callback(int key, int x, int y,
						void *param);
static int			ft_mouse_move_callback(int x, int y, void *param);

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
	return (1);
}

static int	ft_mouse_btn_release_callback(int key, int x, int y, void *param)
{
	t_context	*context;

	context = param;
	(void)x;
	(void)y;
	context->events.state.set.keys(context, key, false);
	return (1);
}

static int	ft_mouse_move_callback(int x, int y, void *param)
{
	t_context	*context;
	t_events	*events;

	context = param;
	events = &context->events;
	ft_update_spatial_gestures(&events->gestures, context, x, y);
	return (1);
}
