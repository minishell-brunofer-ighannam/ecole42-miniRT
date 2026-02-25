/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:54:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 12:48:57 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal_bonus.h"

t_events	ft_new_events(void)
{
	t_events	events;

	events.callbacks = ft_new_events_callbacks();
	events.state = ft_new_state();
	events.gestures = ft_new_gestures(&events.state);
	return (events);
}
