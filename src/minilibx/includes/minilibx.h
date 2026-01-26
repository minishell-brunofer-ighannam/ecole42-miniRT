/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:38:24 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 15:36:00 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "../events/includes/events.h"
# include "../window/includes/window.h"

typedef struct s_mlx	t_mlx;
struct s_mlx
{
	t_mlx_window	window;
	t_mlx_events	events;
	unsigned int	***(*create_pixel_mapper)(t_mlx self);
	void			*(*display_image)(t_mlx self);
	void			*(*loop)(t_mlx self);
	void			*(*destroy)(t_mlx self);
};

t_mlx	ft_new_mlx(int width, int height, const char *name);

#endif
