/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:20:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 12:14:02 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal.h"

t_mlx_events	new_mlx_events(void)
{
	t_mlx_events	events;

	events.window_close = on_close_window;
	events.key_press = on_key_press;
	events.key_release = on_key_release;
	events.loop = on_loop;
	events.mouse_btn_press = on_mouse_button_press;
	events.mouse_btn_release = on_mouse_button_release;
	events.mouse_move = on_mouse_move;
	events.window_resize = on_resize_window;
	return (events);
}
