/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:40:59 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 12:27:58 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"

t_gestures	ft_new_gestures(t_state *state)
{
	t_gestures	gesture;

	ft_bzero(&gesture, sizeof(t_gestures));
	init_wasd_gestures(state, &gesture);
	init_mouse_gestures(state, &gesture);
	return (gesture);
}

void	ft_update_spatial_gestures(
			t_gestures *gest, t_state *state, int x, int y)
{
	gest->lalt_ldrag.handler(&gest->lalt_ldrag, state, x, y);
	gest->lctrl_ldrag.handler(&gest->lctrl_ldrag, state, x, y);
	gest->lctrl_mouse_move.handler(&gest->lctrl_mouse_move, state, x, y);
}

void	ft_update_discrete_gestures(
			t_gestures *gest, t_state *state, int key)
{
	gest->w.handler(&gest->w, state, key);
	gest->a.handler(&gest->a, state, key);
	gest->s.handler(&gest->s, state, key);
	gest->d.handler(&gest->d, state, key);
}
