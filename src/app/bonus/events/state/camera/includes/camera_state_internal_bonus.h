/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_state_internal_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:18:07 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 15:44:55 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_STATE_INTERNAL_BONUS_H
# define CAMERA_STATE_INTERNAL_BONUS_H

# include "camera_state_bonus.h"

# define CAMERA_TRANSLATION_INTENSITY 1
# define CAMERA_ROTATION_INTENSITY 1

void			set_camera_changed_flag(t_state *self);
void			set_camera_translation_spatial(t_state *self,
					t_spatial_gesture *gesture);
void			set_camera_translation_up(t_state *self);
void			set_camera_translation_down(t_state *self);
void			set_camera_translation_left(t_state *self);
void			set_camera_translation_right(t_state *self);
void			set_camera_translation_front(t_state *self);
void			set_camera_translation_back(t_state *self);

void			set_camera_rotation_spatial(t_state *self,
					t_spatial_gesture *gesture);
void			set_camera_rotation_up(t_state *self);
void			set_camera_rotation_down(t_state *self);
void			set_camera_rotation_left(t_state *self);
void			set_camera_rotation_right(t_state *self);
void			set_camera_rotation_diag_right(t_state *self);
void			set_camera_rotation_diag_left(t_state *self);

#endif
