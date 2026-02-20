/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:40:59 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 19:05:46 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"

t_gestures	ft_new_gestures(t_state *state)
{
	t_gestures	gesture;

	ft_bzero(&gesture, sizeof(t_gestures));
	init_wasd_gestures(state, &gesture);
	init_mouse_gestures(state, &gesture);
	init_select_gestures(state, &gesture);
	init_number_gestures(state, &gesture);
	init_rgb_gestures(state, &gesture);
	return (gesture);
}

void	ft_update_spatial_gestures(
			t_gestures *gest, t_context *context, int x, int y)
{
	gest->lalt_ldrag.handler(&gest->lalt_ldrag, context, x, y);
	gest->lctrl_ldrag.handler(&gest->lctrl_ldrag, context, x, y);
	gest->lctrl_mouse_move.handler(&gest->lctrl_mouse_move, context, x, y);
}

void	ft_update_discrete_gestures(
			t_gestures *gest, t_context *context, int key, int *position)
{
	gest->w.handler(&gest->w, context, key, position);
	gest->a.handler(&gest->a, context, key, position);
	gest->s.handler(&gest->s, context, key, position);
	gest->d.handler(&gest->d, context, key, position);
	gest->lshift_lmouseclick.handler(&gest->lshift_lmouseclick, context, key, position);
	gest->lshift_rmouseclick.handler(&gest->lshift_rmouseclick, context, key, position);
	gest->lshift_num_0_9.handler(&gest->lshift_num_0_9, context, key, position);
	gest->lshift_lalt_num_0_9.handler(&gest->lshift_lalt_num_0_9, context, key, position);
	gest->lshift_rgb.handler(&gest->lshift_rgb, context, key, position);
	gest->lshift_lalt_rgb.handler(&gest->lshift_lalt_rgb, context, key, position);
}
