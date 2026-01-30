/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:25:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 13:35:13 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_internal.h"

static void	ft_get_nearest_neighbor(
				int new_idx[2], int (*old_idx)[2],
				double old_size[2], double new_size[2]);

void	ft_resize_image(t_mlx *self, int width, int height)
{
	unsigned int	**new_addr;
	double			old_size[2];
	double			new_size[2];
	int				new_idx[2];
	int				old_idx[2];

	if (!self || (self->window.width == width && self->window.height == height))
		return ;
	new_addr = ft_calloc(width + 1, sizeof(unsigned int *));
	if (!new_addr)
		return ;
	old_size[0] = self->window.width;
	old_size[1] = self->window.height;
	new_size[0] = width;
	new_size[1] = height;
	new_idx[0] = -1;
	while (++new_idx[0] < width)
	{
		new_addr[new_idx[0]] = ft_calloc(height, sizeof(unsigned int));
		new_idx[1] = -1;
		while (++new_idx[1] < height)
		{
			ft_get_nearest_neighbor(new_idx, &old_idx, old_size, new_size);
			new_addr[new_idx[0]][new_idx[1]] = *self->frame_buffer[old_idx[0]][old_idx[1]];
		}
	}
	while (--self->window.width >= 0)
		free(self->frame_buffer[self->window.width]);
	free(self->frame_buffer);
	mlx_destroy_image(self->window.mlx_ref, self->window.img);
	self->window.width = width;
	self->window.height = height;
	self->window.img = mlx_new_image(self->window.mlx_ref, width, height);
	self->window.addr = mlx_get_minilib_layer_addr(
			self->window.img, &self->window.bits_per_pixel,
			&self->window.line_length, &self->window.endian);
	self->frame_buffer = self->create_pixel_mapper(*self);
	printf("width: %d, height: %d\n", width, height);
	int i = -1;
	int j;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			*self->frame_buffer[i][j] = new_addr[i][j];
		free(new_addr[i]);
	}
	free(new_addr);
}

static void	ft_get_nearest_neighbor(
				int new_idx[2], int (*old_idx)[2],
				double old_size[2], double new_size[2])
{
	if (new_size[0] == 0)
		new_size[0] = 1e-9;
	if (new_size[1] == 0)
		new_size[1] = 1e-9;
	(*old_idx)[0] = (int)(((double)new_idx[0] + 0.5) * (old_size[0] / new_size[0]));
	(*old_idx)[1] = (int)(((double)new_idx[1] + 0.5) * (old_size[1] / new_size[1]));

	if ((*old_idx)[0] >= (int)old_size[0])
		(*old_idx)[0] = (int)old_size[0] - 1;
	if ((*old_idx)[1] >= (int)old_size[1])
		(*old_idx)[1] = (int)old_size[1] - 1;

	if ((*old_idx)[0] < 0)
		(*old_idx)[0] = 0;
	if ((*old_idx)[1] < 0)
		(*old_idx)[1] = 0;
}
