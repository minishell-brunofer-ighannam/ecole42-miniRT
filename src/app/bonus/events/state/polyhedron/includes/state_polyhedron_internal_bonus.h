/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_polyhedron_internal_bonus.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:46:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/16 11:29:11 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_POLYHEDRON_INTERNAL_BONUS_H
# define STATE_POLYHEDRON_INTERNAL_BONUS_H

# include "state_polyhedron_bonus.h"

# define POLYHEDRON_TRANSLATION_INTENSITY 1
# define POLYHEDRON_ROTATION_INTENSITY 1

void	set_polyhedron_changed_flag(t_state *self);

void	set_polyhedron_rotation_up(t_context *context);
void	set_polyhedron_rotation_down(t_context *context);
void	set_polyhedron_rotation_left(t_context *context);
void	set_polyhedron_rotation_right(t_context *context);
void	set_polyhedron_rotation_spatial(t_context *context,
			t_spatial_gesture *gesture);
void	set_polyhedron_rotation_diag_right(t_context *context);
void	set_polyhedron_rotation_diag_left(t_context *context);

void	set_polyhedron_translation_up(t_context *context);
void	set_polyhedron_translation_down(t_context *context);
void	set_polyhedron_translation_left(t_context *context);
void	set_polyhedron_translation_right(t_context *context);
void	set_polyhedron_translation_spatial(t_context *context,
			t_spatial_gesture *gesture);
void	set_polyhedron_translation_front(t_context *context);
void	set_polyhedron_translation_back(t_context *context);

#endif
