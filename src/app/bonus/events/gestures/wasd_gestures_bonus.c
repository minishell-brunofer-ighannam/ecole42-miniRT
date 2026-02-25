/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_gestures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:55:20 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 11:22:12 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/gestures_internal_bonus.h"

static void	w_handler(t_discrete_gesture *gest, t_context *context, int key,
				int position[2]);
static void	a_handler(t_discrete_gesture *gest, t_context *context, int key,
				int position[2]);
static void	s_handler(t_discrete_gesture *gest, t_context *context, int key,
				int position[2]);
static void	d_handler(t_discrete_gesture *gest, t_context *context, int key,
				int position[2]);

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

static void	w_handler(t_discrete_gesture *gest, t_context *context, int key,
		int position[2])
{
	t_pressed_keys	keys;

	(void)position;
	keys = context->events.state.pressed_keys;
	if (key != KEYBOARD_W || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(context);
}

static void	a_handler(t_discrete_gesture *gest, t_context *context, int key,
		int position[2])
{
	t_pressed_keys	keys;

	(void)position;
	keys = context->events.state.pressed_keys;
	if (key != KEYBOARD_A || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(context);
}

static void	s_handler(t_discrete_gesture *gest, t_context *context, int key,
		int position[2])
{
	t_pressed_keys	keys;

	(void)position;
	keys = context->events.state.pressed_keys;
	if (key != KEYBOARD_S || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(context);
}

static void	d_handler(t_discrete_gesture *gest, t_context *context, int key,
		int position[2])
{
	t_pressed_keys	keys;

	(void)position;
	keys = context->events.state.pressed_keys;
	if (key != KEYBOARD_D || keys.left_alt || keys.left_ctrl || keys.left_shift
		|| keys.right_alt || keys.right_ctrl || keys.right_shift)
		return ;
	gest->state_setter(context);
}
