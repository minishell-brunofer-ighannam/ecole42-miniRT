/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:31:11 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 10:24:19 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mouse_events_internal_bonus.h"

static int	ft_mouse_btn_press_callback(int key, int x, int y, void *param);
static int	ft_mouse_btn_release_callback(int key, int x, int y, void *param);
static int	ft_mouse_move_callback(int x, int y, void *param);

t_mouse_callbacks	new_mouse_callbacks(void)
{
	t_mouse_callbacks	callbacks;

	callbacks.btn_move_callback = ft_mouse_move_callback;
	callbacks.btn_press = ft_mouse_btn_press_callback;
	callbacks.btn_release = ft_mouse_btn_release_callback;
	return (callbacks);
}

static int	ft_mouse_btn_press_callback(int key, int x, int y, void *param)
{
	(void)param;
	printf("mouse[%d] pressed at x:%d, y:%d\n", key, x, y);
	return (1);
}

static int	ft_mouse_btn_release_callback(int key, int x, int y, void *param)
{
	(void)param;
	printf("mouse[%d] released at x:%d, y:%d\n", key, x, y);
	return (1);
}

static int	ft_mouse_move_callback(int x, int y, void *param)
{
	(void)param;
	printf("mouse moved -> x:%d, y:%d\n", x, y);
	return (1);
}

