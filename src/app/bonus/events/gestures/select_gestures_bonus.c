/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_gestures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:33:43 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 12:26:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"
#include "context.h"

static void	lshift_lmouseclick_handler(
				t_discrete_gesture *self, t_context *context,
				int key, int *position);
static void	lshift_rmouseclick_handler(
				t_discrete_gesture *self, t_context *context,
				int key, int *position);

void	init_select_gestures(t_state *state, t_gestures *gest)
{
	(void)state;
	gest->lshift_lmouseclick.handler = lshift_lmouseclick_handler;
	gest->lshift_rmouseclick.handler = lshift_rmouseclick_handler;
}

static void	lshift_lmouseclick_handler(
				t_discrete_gesture *self, t_context *context,
				int key, int *position)
{
	t_pressed_keys	keys;

	(void)key;
	(void)self;
	keys = context->events.state.pressed_keys;
	if (!keys.left_shift || !keys.left_mouse_btn || keys.right_mouse_btn
		|| keys.left_alt || keys.left_ctrl || keys.right_alt || keys.right_ctrl
		|| keys.right_shift)
		return ;
	ft_select_polyhedron(context, context->scene, position[0], position[1]);
}

static void	lshift_rmouseclick_handler(
				t_discrete_gesture *self, t_context *context,
				int key, int *position)
{
	t_pressed_keys	keys;

	(void)position;
	(void)key;
	(void)self;
	keys = context->events.state.pressed_keys;
	if (!keys.left_shift || !keys.right_mouse_btn || keys.left_mouse_btn
		|| keys.left_alt || keys.left_ctrl || keys.right_alt || keys.right_ctrl
		|| keys.right_shift)
		return ;
	ft_unselect_polyhedron(context);
}
