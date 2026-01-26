/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:19:54 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 08:12:31 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal.h"
#include "../includes/minilibx.h"

void	on_key_press(t_mlx mlx, int (*callback)(int key, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref, KEY_PRESS_EVENT, KEY_PRESS_MASK, (int (*)())callback, param);
}

void	on_key_release(t_mlx mlx, int (*callback)(int key, void *param), void *param)
{
	mlx_hook(mlx.window.win_ref,
		KEY_RELEASE_EVENT, KEY_RELEASE_MASK, (int (*)())callback, param);
}
