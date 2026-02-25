/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:19:16 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:04:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx.h"
#include "includes/events_internal.h"

void	on_loop(t_mlx mlx, int (*callback)(void *param), void *param)
{
	mlx_loop_hook(mlx.window.mlx_ref, (int (*)())callback, param);
}
