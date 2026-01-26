/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:19:16 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 08:13:03 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/events_internal.h"
#include "../includes/minilibx.h"

void	on_loop(t_mlx mlx, int (*callback)(void *param), void *param)
{
	mlx_loop_hook(mlx.window.mlx_ref, (int (*)())callback, param);
}
