/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures_internal_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:22:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 11:17:34 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTURES_INTERNAL_BONUS_H
# define GESTURES_INTERNAL_BONUS_H

# include <stdio.h>
# include "libft.h"
# include "../../../../../minilibx/includes/minilibx.h"
# include "gestures_bonus.h"

void	calibrate_diff(double *diff, bool is_x);
void	init_wasd_gestures(t_state *state, t_gestures *gest);
void	init_mouse_gestures(t_state *state, t_gestures *gest);
void	init_select_gestures(t_state *state, t_gestures *gest);
void	init_number_gestures(t_state *state, t_gestures *gest);
void	init_rgb_gestures(t_state *state, t_gestures *gest);

#endif
