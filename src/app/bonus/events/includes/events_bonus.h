/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 12:48:00 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H

# include "../callbacks/includes/events_callbacks_bonus.h"
# include "../state/includes/state_bonus.h"
# include "../gestures/includes/gestures_bonus.h"

typedef struct s_events	t_events;
struct s_events
{
	t_events_callbacks	callbacks;
	t_state				state;
	t_gestures			gestures;
};

t_events	ft_new_events(void);

#endif
