/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_callbacks_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/23 14:02:48 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EVENTS_CALLBACKS_BONUS_H
# define EVENTS_CALLBACKS_BONUS_H

# include <stdio.h>
# include "minilibx.h"

typedef struct s_context			t_context;

typedef struct s_keyboard_callbacks	t_keyboard_callbacks;
struct s_keyboard_callbacks
{
	int	(*key_press)(int key, void *param);
	int	(*key_release)(int key, void *param);
};

typedef struct s_mouse_callbacks	t_mouse_callbacks;
struct s_mouse_callbacks
{
	int	(*btn_press)(int key, int x, int y, void *param);
	int	(*btn_release)(int key, int x, int y, void *param);
	int	(*btn_move_callback)(int x, int y, void *param);
};

typedef struct s_window_callbacks	t_window_callbacks;
struct s_window_callbacks
{
	int	(*close)(t_context *context);
	int	(*resize)(void *param, XEvent *event);
};

typedef struct s_events_callbacks	t_events_callbacks;
struct s_events_callbacks
{
	t_mouse_callbacks		mouse;
	t_keyboard_callbacks	keyboard;
	t_window_callbacks		window;
};

t_events_callbacks	ft_new_events_callbacks(void);

#endif
