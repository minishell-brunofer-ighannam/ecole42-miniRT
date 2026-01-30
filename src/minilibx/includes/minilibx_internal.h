/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:39:08 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 17:55:48 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_INTERNAL_H
# define MINILIBX_INTERNAL_H

# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "minilibx.h"

void	ft_resize_image(t_mlx *self, int width, int height);
void	ft_nearest_neighbor_scale(
				t_mlx *self, int width, int height, unsigned int ***new_addr);

#endif
