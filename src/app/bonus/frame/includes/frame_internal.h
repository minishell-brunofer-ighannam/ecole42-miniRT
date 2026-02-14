/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:21:52 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 08:47:13 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_INTERNAL_H
# define FRAME_INTERNAL_H

# include "libft.h"
# include "mlx.h"
# include "../../threads/includes/threads_bonus.h"
# include "frame.h"

void	ft_draw_square(t_context *context, int width, int height);

void	ft_show_frame_info(t_context *context);
bool	ft_process_state(t_context *context);
bool	ft_process_resize_image(t_context *context);
void	ft_handle_camera(t_camera *scene_cam, t_camera_state *state_cam);
void	ft_process_camera_translation(
			t_point_3d *restrict origin,
			t_vector_3d forward, t_camera_state *restrict state_cam);
void	ft_process_camera_rotation(
			t_camera_state *restrict state_cam, t_vector_3d *restrict forward,
			t_vector_3d *restrict right, t_vector_3d *restrict up);

#endif
