/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 12:03:14 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H

# include "../keyboard_events/includes/keyboard_events_bonus.h"
# include "../mouse_events/includes/mouse_events_bonus.h"
# include "../window_events/includes/window_events_bonus.h"

typedef struct s_events	t_events;
struct s_events
{
	struct s_events_callbacks
	{
		t_mouse_callbacks		mouse;
		t_keyboard_callbacks	keyboard;
		t_window_callbacks		window;
	} callbacks;

};

t_events	ft_new_events(void);

#endif
