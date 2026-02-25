/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:05:37 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:05:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_INTERNAL_H
# define EVENTS_INTERNAL_H

# include "event_device_keys.h"
# include "event_x11.h"
# include "events.h"
# include "mlx.h"
# include <X11/Xlib.h>

void	on_mouse_button_press(t_mlx mlx, int (*callback)(int key, int x, int y,
				void *param), void *param);
void	on_mouse_button_release(t_mlx mlx, int (*callback)(int key, int x,
				int y, void *param), void *param);
void	on_mouse_move(t_mlx mlx, int (*callback)(int x, int y, void *param),
			void *param);
void	on_key_press(t_mlx mlx, int (*callback)(int key, void *param),
			void *param);
void	on_key_release(t_mlx mlx, int (*callback)(int key, void *param),
			void *param);
void	on_close_window(t_mlx mlx, int (*callback)(void *param), void *param);
void	on_resize_window(t_mlx mlx, int (*callback)(void *param, XEvent *event),
			void *param);
void	on_loop(t_mlx mlx, int (*callback)(void *param), void *param);

#endif
