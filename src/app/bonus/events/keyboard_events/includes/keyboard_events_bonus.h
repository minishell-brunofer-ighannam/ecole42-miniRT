/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 10:25:53 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KEYBOARD_EVENTS_BONUS_H
# define KEYBOARD_EVENTS_BONUS_H

# include <stdio.h>
# include "../../../../../minilibx/includes/minilibx.h"

typedef struct s_keyboard_callbacks	t_keyboard_callbacks;
struct s_keyboard_callbacks
{
	int	(*key_press)(int key, void *param);
	int	(*key_release)(int key, void *param);
};

t_keyboard_callbacks	ft_new_keyboard_callbacks(void);

#endif
