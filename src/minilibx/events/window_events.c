/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:18:50 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 13:19:50 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal.h"
#include "../includes/minilibx.h"

void	on_close_window(t_mlx mlx, int (*callback)(void *param), void *param)
{
	mlx_hook(mlx.window.win_ref, DESTROY_NOTIFY_EVENT, NO_EVENT_MASK, (int (*)())callback, param);
}

void	on_resize_window(t_mlx mlx, int (*callback)(void *param, XEvent *event), void *param)
{
	mlx_hook(mlx.window.win_ref, CONFIGURE_NOTIFY_EVENT, STRUCTURE_NOTIFY_MASK, (int (*)())callback, param);
}
