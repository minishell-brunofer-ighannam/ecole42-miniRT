/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_gestures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:33:43 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 11:21:41 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"
#include "context.h"

static void	lshift_num_0_9(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2]);
static void	lshift_lalt_num_0_9(
				t_discrete_gesture *self, t_context *context,
				int key, int position[2]);
static void	ft_handle_components(int key, t_state *state, bool add);

void	init_number_gestures(t_state *state, t_gestures *gest)
{
	(void)state;
	gest->lshift_num_0_9.handler = lshift_num_0_9;
	gest->lshift_lalt_num_0_9.handler = lshift_lalt_num_0_9;
}

static void	lshift_num_0_9(
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
	if (key == KEYBOARD_1)
		ft_polyhedron_material(state, &material->ka, true);
	else if (key == KEYBOARD_2)
		ft_polyhedron_material(state, &material->kd, true);
	else if (key == KEYBOARD_3)
		ft_polyhedron_material(state, &material->ks, true);
	else if (key == KEYBOARD_4)
		ft_polyhedron_material(state, &material->n, true);
	else if (key == KEYBOARD_5)
		ft_polyhedron_material(state, &material->kr, true);
	else
		ft_handle_components(key, state, true);
}

static void	lshift_lalt_num_0_9(
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
	if (key == KEYBOARD_1)
		ft_polyhedron_material(state, &material->ka, false);
	else if (key == KEYBOARD_2)
		ft_polyhedron_material(state, &material->kd, false);
	else if (key == KEYBOARD_3)
		ft_polyhedron_material(state, &material->ks, false);
	else if (key == KEYBOARD_4)
		ft_polyhedron_material(state, &material->n, false);
	else if (key == KEYBOARD_5)
		ft_polyhedron_material(state, &material->kr, false);
	else
		ft_handle_components(key, state, false);
}

static void	ft_handle_components(int key, t_state *state, bool add)
{
	t_polyhedron_state	*poly_state;

	poly_state = &state->scene.polyhedron;
	if (key == KEYBOARD_6 && poly_state->n_components > 0)
		ft_polyhedron_component(state, &poly_state->components[0], add);
	else if (key == KEYBOARD_7 && poly_state->n_components > 1)
		ft_polyhedron_component(state, &poly_state->components[1], add);
	else if (key == KEYBOARD_8 && poly_state->n_components > 2)
		ft_polyhedron_component(state, &poly_state->components[2], add);
}
