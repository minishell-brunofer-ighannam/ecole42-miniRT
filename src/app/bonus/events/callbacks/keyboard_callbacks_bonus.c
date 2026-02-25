/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_callbacks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:00:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 11:12:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/events_callbacks_internal_bonus.h"

static int	ft_key_press(int key, void *param);
static int	ft_key_release(int key, void *param);

t_keyboard_callbacks	ft_new_keyboard_callbacks(void)
{
	t_keyboard_callbacks	callbacks;

	callbacks.key_press = ft_key_press;
	callbacks.key_release = ft_key_release;
	return (callbacks);
}

static int	ft_key_press(int key, void *param)
{
	t_context	*context;
	t_events	*events;
	int			*pos;

	pos = malloc(2 * sizeof(int));
	ft_memset(pos, -1, 2 * sizeof(int));
	context = param;
	events = &context->events;
	if (key == KEYBOARD_ESC)
		context->callbacks.stop_app(context);
	context->events.state.set.keys(context, key, true);
	ft_update_discrete_gestures(&events->gestures, context, key, pos);
	free(pos);
	return (1);
}

static int	ft_key_release(int key, void *param)
{
	t_context	*context;

	context = param;
	context->events.state.set.keys(context, key, false);
	return (1);
}
