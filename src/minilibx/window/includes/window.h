/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:09:12 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 11:34:37 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H


typedef struct s_mlx_window	t_mlx_window;

struct s_mlx_window
{
	void		*mlx_ref;
	void		*win_ref;
	const char	*name;
	int			width;
	int			height;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*(*display_image)(t_mlx_window self);
	void		*(*destroy)(t_mlx_window self);
};

t_mlx_window	new_mlx_window(int width, int height, const char *name);

#endif
