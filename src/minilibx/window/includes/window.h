/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:09:12 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:05:07 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_mlx_window	t_mlx_window;

struct						s_mlx_window
{
	void					*mlx_ref;
	void					*win_ref;
	const char				*name;
	int						width;
	int						height;
	double					ratio;
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	void					*(*display_image)(t_mlx_window self);
	void					*(*destroy)(t_mlx_window self);
};

t_mlx_window				new_mlx_window(int width, int height,
								const char *name);

#endif
