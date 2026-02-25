/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:39:08 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:05:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_INTERNAL_H
# define MINILIBX_INTERNAL_H

# include "libft.h"
# include "minilibx.h"
# include "mlx.h"
# include <stdio.h>

void	ft_resize_image(t_mlx *self, int width, int height);
void	ft_nearest_neighbor_scale(t_mlx *self, int width, int height,
			unsigned int ***new_addr);

#endif
