/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_gestures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:51:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 20:55:17 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"
#include "context.h"

static void	lshift_rgb(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2]);
static void	lshift_lalt_rgb(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2]);

void	init_rgb_gestures(t_state *state, t_gestures *gest)
{
	(void)state;
	gest->lshift_rgb.handler = lshift_rgb;
	gest->lshift_lalt_rgb.handler = lshift_lalt_rgb;
}

static void	lshift_rgb(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2])
{
	t_pressed_keys				keys;
	t_state						*state;
	t_polyhedron_state_material	*material;

	(void)position;
	(void)self;
	keys = context->events.state.pressed_keys;
	if (!keys.left_shift || keys.left_mouse_btn || keys.right_mouse_btn
		|| keys.left_alt || keys.left_ctrl || keys.right_alt || keys.right_ctrl
		|| keys.right_shift)
		return ;
	state = &context->events.state;
	material = &state->scene.polyhedron.material;
	if (key == KEYBOARD_R)
		ft_polyhedron_material(state, &material->albedo.x, true);
	else if (key == KEYBOARD_G)
		ft_polyhedron_material(state, &material->albedo.y, true);
	else if (key == KEYBOARD_B)
		ft_polyhedron_material(state, &material->albedo.z, true);
}

static void	lshift_lalt_rgb(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2])
{
	t_pressed_keys				keys;
	t_state						*state;
	t_polyhedron_state_material	*material;

	(void)position;
	(void)self;
	keys = context->events.state.pressed_keys;
	if (!keys.left_shift || !keys.left_alt || keys.left_mouse_btn
		|| keys.right_mouse_btn || keys.left_ctrl || keys.right_alt
		|| keys.right_ctrl || keys.right_shift)
		return ;
	state = &context->events.state;
	material = &state->scene.polyhedron.material;
	if (key == KEYBOARD_R)
		ft_polyhedron_material(state, &material->albedo.x, false);
	else if (key == KEYBOARD_G)
		ft_polyhedron_material(state, &material->albedo.y, false);
	else if (key == KEYBOARD_B)
		ft_polyhedron_material(state, &material->albedo.z, false);
}
