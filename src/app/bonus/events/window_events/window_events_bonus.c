/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:37:28 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 13:11:19 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "includes/window_events_internal_bonus.h"

static int	ft_window_resize(void *param, XEvent *event);
static int	ft_close_window(t_mlx *mlx);

t_window_callbacks	ft_new_window_callbacks(void)
{
	t_window_callbacks	callbacks;

	callbacks.close = ft_close_window;
	callbacks.resize = ft_window_resize;
	return (callbacks);
}

static int	ft_window_resize(void *param, XEvent *event)
{
	int	new_width;
	int	new_height;

	new_width = event->xconfigure.width;
	new_height = event->xconfigure.height;
	printf("new width: %d, new height: %d\n", new_width, new_height);
	// update event status
	(void)param;
	return (1);
}

static int	ft_close_window(t_mlx *mlx)
{
	mlx_loop_end(mlx->window.mlx_ref);
	return (1);
}
