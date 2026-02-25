/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:19:54 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:04:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx.h"
#include "includes/events_internal.h"

void	on_key_press(t_mlx mlx, int (*callback)(int key, void *param),
		void *param)
{
	mlx_hook(mlx.window.win_ref, KEY_PRESS_EVENT, KEY_PRESS_MASK,
		(int (*)())callback, param);
}

void	on_key_release(t_mlx mlx, int (*callback)(int key, void *param),
		void *param)
{
	mlx_hook(mlx.window.win_ref, KEY_RELEASE_EVENT, KEY_RELEASE_MASK,
		(int (*)())callback, param);
}
