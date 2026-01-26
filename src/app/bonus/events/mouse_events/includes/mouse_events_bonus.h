/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 10:25:49 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MOUSE_EVENTS_BONUS_H
# define MOUSE_EVENTS_BONUS_H

# include <stdio.h>
# include "../../../../../minilibx/includes/minilibx.h"

typedef struct s_mouse_callbacks	t_mouse_callbacks;
struct s_mouse_callbacks
{
	int	(*btn_press)(int key, int x, int y, void *param);
	int	(*btn_release)(int key, int x, int y, void *param);
	int	(*btn_move_callback)(int x, int y, void *param);
};

t_mouse_callbacks	new_mouse_callbacks(void);

#endif
