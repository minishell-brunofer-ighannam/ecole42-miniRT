/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:05:37 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:09:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "X11/Xlib.h"
# include "event_device_keys.h"
# include "event_x11.h"

typedef struct s_mlx		t_mlx;
typedef struct s_mlx_events	t_mlx_events;
struct						s_mlx_events
{
	void					(*mouse_btn_press)(t_mlx mlx,
			int (*callback)(int key, int x, int y, void *param),
			void *param);
	void					(*mouse_btn_release)(t_mlx mlx,
			int (*callback)(int key, int x, int y, void *param),
			void *param);
	void					(*mouse_move)(t_mlx mlx, int (*callback)(int x,
				int y, void *param), void *param);
	void					(*key_press)(t_mlx mlx, int (*callback)(int key,
				void *param), void *param);
	void					(*key_release)(t_mlx mlx, int (*callback)(int key,
				void *param), void *param);
	void					(*window_close)(t_mlx mlx, int (*callback)(),
			void *param);
	void					(*window_resize)(t_mlx mlx,
			int (*callback)(void *param, XEvent *event),
			void *param);
	void					(*loop)(t_mlx mlx, int (*callback)(void *param),
			void *param);
};

t_mlx_events				new_mlx_events(void);

#endif
