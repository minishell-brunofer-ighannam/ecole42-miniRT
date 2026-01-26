/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:50:06 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 11:35:06 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_internal.h"
#include "mlx.h"

static unsigned int	***ft_mlx_create_pixel_mapper(t_mlx self);
static void			*ft_mlx_display_image(t_mlx self);
static void			*ft_mlx_loop(t_mlx self);
static void			*ft_mlx_destroy(t_mlx self);

t_mlx	ft_new_mlx(int width, int height, const char *name)
{
	t_mlx	mlx;

	mlx.events = new_mlx_events();
	mlx.window = new_mlx_window(width, height, name);
	mlx.create_pixel_mapper = ft_mlx_create_pixel_mapper;
	mlx.display_image = ft_mlx_display_image;
	mlx.loop = ft_mlx_loop;
	mlx.destroy = ft_mlx_destroy;
	return (mlx);
}

static unsigned int	***ft_mlx_create_pixel_mapper(t_mlx self)
{
	unsigned int	***mapper;
	int				width;
	int				height;

	mapper = ft_calloc(self.window.width + 1, sizeof(char **));
	if (!mapper)
		return (NULL);
	width = -1;
	while (++width < self.window.width)
	{
		mapper[width] = ft_calloc(self.window.height + 1, sizeof(char *));
		if (!mapper[width])
		{
			while (--width >= 0)
				free(mapper[width]);
			free(mapper);
			return (NULL);
		}
		height = -1;
		while (++height < self.window.height)
			mapper[width][height] = (unsigned int *)(self.window.addr + (
						height * self.window.line_length + width
						* (self.window.bits_per_pixel / 8)));
	}
	return (mapper);
}

static void	*ft_mlx_display_image(t_mlx self)
{
	self.window.display_image(self.window);
	return (NULL);
}

static void	*ft_mlx_loop(t_mlx self)
{
	mlx_loop(self.window.mlx_ref);
	return (NULL);
}

static void	*ft_mlx_destroy(t_mlx self)
{
	self.window.destroy(self.window);
	return (NULL);
}
