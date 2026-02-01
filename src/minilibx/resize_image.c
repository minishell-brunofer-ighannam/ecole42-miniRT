/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:25:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/31 13:03:35 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_internal.h"

static void	ft_recreate_image(
				t_mlx *self, int width, int height, unsigned int **new_addr);

void	ft_resize_image(t_mlx *self, int width, int height)
{
	unsigned int	**new_addr;

	if (!self || (self->window.width == width && self->window.height == height))
		return ;
	ft_nearest_neighbor_scale(self, width, height, &new_addr);
	ft_destroy_char_matrix((void *)&self->frame_buffer);
	mlx_destroy_image(self->window.mlx_ref, self->window.img);
	ft_recreate_image(self, width, height, new_addr);
}

static void	ft_recreate_image(
				t_mlx *self, int width, int height, unsigned int **new_addr)
{
	int	i;
	int	j;

	self->window.width = width;
	self->window.height = height;
	self->window.ratio = (double)width / (double)height;
	self->window.img = mlx_new_image(self->window.mlx_ref, width, height);
	self->window.addr = mlx_get_minilib_layer_addr(
			self->window.img, &self->window.bits_per_pixel,
			&self->window.line_length, &self->window.endian);
	self->frame_buffer = self->create_pixel_mapper(*self);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			*self->frame_buffer[i][j] = new_addr[i][j];
		free(new_addr[i]);
	}
	free(new_addr);
}
