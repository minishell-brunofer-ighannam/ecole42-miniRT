/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures_internal_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:22:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 17:28:17 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTURES_INTERNAL_BONUS_H
# define GESTURES_INTERNAL_BONUS_H

# include <stdio.h>
# include "libft.h"
# include "../../../../../minilibx/includes/minilibx.h"
# include "gestures_bonus.h"

void	calibrate_diff(double *diff);
void	init_wasd_gestures(t_state *state, t_gestures *gest);
void	init_mouse_gestures(t_state *state, t_gestures *gest);
void	init_select_gestures(t_state *state, t_gestures *gest);
void	init_number_gestures(t_state *state, t_gestures *gest);
void	init_rgb_gestures(t_state *state, t_gestures *gest);

#endif
