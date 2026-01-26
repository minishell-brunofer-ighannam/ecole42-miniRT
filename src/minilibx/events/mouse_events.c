/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:09:30 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 08:13:35 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal.h"
#include "../includes/minilibx.h"

void	on_mouse_button_press(t_mlx mlx, int (*callback)(int key, int x, int y, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref, BUTTON_PRESS_EVENT, BUTTON_PRESS_MASK, (int (*)())callback, param);
}

void	on_mouse_button_release(t_mlx mlx, int (*callback)(int key, int x, int y, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref,
		BUTTON_RELEASE_EVENT, BUTTON_RELEASE_MASK, (int (*)())callback, param);
}

void	on_mouse_move(t_mlx mlx, int (*callback)(int x, int y, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref,
		MOTION_NOTIFY_EVENT, POINTER_MOTION_MASK, (int (*)())callback, param);
}
