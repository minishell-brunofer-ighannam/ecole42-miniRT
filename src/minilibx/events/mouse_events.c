/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:09:30 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:05:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx.h"
#include "includes/events_internal.h"

void	on_mouse_button_press(t_mlx mlx, int (*callback)(int key, int x, int y,
			void *param), void *param)
{
	mlx_hook(mlx.window.win_ref, BUTTON_PRESS_EVENT, BUTTON_PRESS_MASK,
		(int (*)())callback, param);
}

void	on_mouse_button_release(t_mlx mlx, int (*callback)(int key, int x,
			int y, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref, BUTTON_RELEASE_EVENT, BUTTON_RELEASE_MASK,
		(int (*)())callback, param);
}

void	on_mouse_move(t_mlx mlx, int (*callback)(int x, int y, void *param),
		void *param)
{
	mlx_hook(mlx.window.win_ref, MOTION_NOTIFY_EVENT, POINTER_MOTION_MASK,
		(int (*)())callback, param);
}
