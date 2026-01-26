/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:54:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 09:17:02 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal_bonus.h"

t_events	ft_new_events(void)
{
	t_events	events;

	events.callbacks.mouse = new_mouse_callbacks();
	events.callbacks.keyboard = ft_new_keyboard_callbacks();
	events.callbacks.window = ft_new_window_callbacks();
	return (events);
}
