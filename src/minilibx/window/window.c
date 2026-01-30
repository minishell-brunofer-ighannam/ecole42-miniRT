/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:15:24 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 18:13:28 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/window_internal.h"

static void	*ft_mlx_display_image(t_mlx_window self);
static void	*ft_mlx_window_destroy(t_mlx_window window);

t_mlx_window	new_mlx_window(int width, int height, const char *name)
{
	t_mlx_window	window;

	window.width = width;
	window.height = height;
	window.ratio = (double)width / (double)height;
	window.name = name;
	window.mlx_ref = mlx_init();
	window.win_ref = mlx_new_window(window.mlx_ref, width, height, (char *)name);
	window.img = mlx_new_image(window.mlx_ref, width, height);
	window.addr = mlx_get_minilib_layer_addr(window.img, &window.bits_per_pixel,
			&window.line_length, &window.endian);
	window.display_image = ft_mlx_display_image;
	window.destroy = ft_mlx_window_destroy;
	return (window);
}

static void	*ft_mlx_display_image(t_mlx_window self)
{
	mlx_put_image_to_window(self.mlx_ref, self.win_ref, self.img, 0, 0);
	return (NULL);
}

static void	*ft_mlx_window_destroy(t_mlx_window self)
{
	mlx_destroy_window(self.mlx_ref, self.win_ref);
	mlx_destroy_image(self.mlx_ref, self.img);
	mlx_destroy_display(self.mlx_ref);
	free(self.mlx_ref);
	return (NULL);
}
