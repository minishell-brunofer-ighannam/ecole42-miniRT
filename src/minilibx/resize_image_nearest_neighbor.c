/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_nearest_neighbor.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:54:54 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 18:03:09 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_internal.h"

static void	ft_get_nearest_neighbor(
				int new_idx[2], int (*old_idx)[2],
				double old_size[2], double new_size[2]);

void	ft_nearest_neighbor_scale(
				t_mlx *self, int width, int height, unsigned int ***new_addr)
{
	double			old_size[2];
	double			new_size[2];
	int				new[2];
	int				old[2];

	*new_addr = ft_calloc(width + 1, sizeof(unsigned int *));
	if (!*new_addr)
		return ;
	old_size[0] = self->window.width;
	old_size[1] = self->window.height;
	new_size[0] = width;
	new_size[1] = height;
	new[0] = -1;
	while (++new[0] < width)
	{
		(*new_addr)[new[0]] = ft_calloc(height, sizeof(unsigned int));
		if (!(*new_addr)[new[0]])
			return ((void)ft_destroy_char_matrix((void *)&(*new_addr)));
		new[1] = -1;
		while (++new[1] < height)
		{
			ft_get_nearest_neighbor(new, &old, old_size, new_size);
			(*new_addr)[new[0]][new[1]] = *self->frame_buffer[old[0]][old[1]];
		}
	}
}

static void	ft_get_nearest_neighbor(
				int new_idx[2], int (*old_idx)[2],
				double old_size[2], double new_size[2])
{
	double	new_x;
	double	new_y;

	new_x = (double)new_idx[0];
	new_y = (double)new_idx[1];
	if (new_size[0] == 0)
		new_size[0] = 1e-9;
	if (new_size[1] == 0)
		new_size[1] = 1e-9;
	(*old_idx)[0] = (int)((new_x + 0.5) * (old_size[0] / new_size[0]));
	(*old_idx)[1] = (int)((new_y + 0.5) * (old_size[1] / new_size[1]));
	if ((*old_idx)[0] >= (int)old_size[0])
		(*old_idx)[0] = (int)old_size[0] - 1;
	if ((*old_idx)[1] >= (int)old_size[1])
		(*old_idx)[1] = (int)old_size[1] - 1;
	if ((*old_idx)[0] < 0)
		(*old_idx)[0] = 0;
	if ((*old_idx)[1] < 0)
		(*old_idx)[1] = 0;
}
