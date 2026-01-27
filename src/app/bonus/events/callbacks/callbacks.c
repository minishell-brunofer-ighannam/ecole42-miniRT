/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:50:17 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/27 14:52:42 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_callbacks_internal_bonus.h"

t_events_callbacks	ft_new_events_callbacks(void)
{
	t_events_callbacks	callbacks;

	callbacks.mouse = new_mouse_callbacks();
	callbacks.keyboard = ft_new_keyboard_callbacks();
	callbacks.window = ft_new_window_callbacks();
	return (callbacks);
}
