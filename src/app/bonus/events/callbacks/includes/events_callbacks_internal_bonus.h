/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_callbacks_internal_bonus.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:22:09 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 21:55:47 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_CALLBACKS_INTERNAL_BONUS_H
# define EVENTS_CALLBACKS_INTERNAL_BONUS_H

# include "libft.h"
# include "mlx.h"
# include "events_callbacks_bonus.h"

t_keyboard_callbacks	ft_new_keyboard_callbacks(void);
t_mouse_callbacks		new_mouse_callbacks(void);
t_window_callbacks		ft_new_window_callbacks(void);

#endif
