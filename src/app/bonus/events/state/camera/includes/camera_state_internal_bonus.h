/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_state_internal_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:18:07 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 10:20:38 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_STATE_INTERNAL_BONUS_H
# define CAMERA_STATE_INTERNAL_BONUS_H

# include "camera_state_bonus.h"

# define CAMERA_TRANSLATION_INTENSITY 1
# define CAMERA_ROTATION_INTENSITY 1

void	set_camera_changed_flag(t_state *self);
void	set_camera_translation_spatial(t_context *context,
			t_spatial_gesture *gesture);
void	set_camera_translation_up(t_context *context);
void	set_camera_translation_down(t_context *context);
void	set_camera_translation_left(t_context *context);
void	set_camera_translation_right(t_context *context);
void	set_camera_translation_front(t_context *context);
void	set_camera_translation_back(t_context *context);

void	set_camera_rotation_spatial(t_context *context,
			t_spatial_gesture *gesture);
void	set_camera_rotation_up(t_context *context);
void	set_camera_rotation_down(t_context *context);
void	set_camera_rotation_left(t_context *context);
void	set_camera_rotation_right(t_context *context);
void	set_camera_rotation_diag_right(t_context *context);
void	set_camera_rotation_diag_left(t_context *context);

#endif
