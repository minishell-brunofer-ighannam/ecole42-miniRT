/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_gestures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:55:20 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 13:59:59 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"

static void	w_handler(t_discrete_gesture *gest, t_state *state, int key);
static void	a_handler(t_discrete_gesture *gest, t_state *state, int key);
static void	s_handler(t_discrete_gesture *gest, t_state *state, int key);
static void	d_handler(t_discrete_gesture *gest, t_state *state, int key);

void	init_wasd_gestures(t_state *state, t_gestures *gest)
{
	gest->w.state_setter = state->set.camera_translation.discrete.front;
	gest->w.handler = w_handler;
	gest->a.state_setter = state->set.camera_translation.discrete.left;
	gest->a.handler = a_handler;
	gest->s.state_setter = state->set.camera_translation.discrete.back;
	gest->s.handler = s_handler;
	gest->d.state_setter = state->set.camera_translation.discrete.right;
	gest->d.handler = d_handler;
}

static void	w_handler(t_discrete_gesture *gest, t_state *state, int key)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (key != KEYBOARD_W || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(state);
}

static void	a_handler(t_discrete_gesture *gest, t_state *state, int key)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (key != KEYBOARD_A || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(state);
}

static void	s_handler(t_discrete_gesture *gest, t_state *state, int key)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (key != KEYBOARD_S || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(state);
}

static void	d_handler(t_discrete_gesture *gest, t_state *state, int key)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (key != KEYBOARD_D || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(state);
}
