/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_gestures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:33:43 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 21:58:42 by bruno-valer      ###   ########.fr       */
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
	printf("polyhedron.components: %d\n", state->scene.polyhedron.n_components);
	material = &state->scene.polyhedron.material;
	if (key == KEYBOARD_1)
	{
		ft_polyhedron_material(state, &material->ka, true);
		printf("add_material::ka[%f]\n", material->ka);
	}
	else if (key == KEYBOARD_2)
	{
		ft_polyhedron_material(state, &material->kd, true);
		printf("add_material::kd[%f]\n", material->kd);
	}
	else if (key == KEYBOARD_3)
	{
		ft_polyhedron_material(state, &material->kr, true);
		printf("add_material::kr[%f]\n", material->kr);
	}
	else if (key == KEYBOARD_4)
	{
		ft_polyhedron_material(state, &material->ks, true);
		printf("add_material::ks[%f]\n", material->ks);
	}
	else if (key == KEYBOARD_5)
	{
		ft_polyhedron_material(state, &material->n, true);
		printf("add_material::n[%f]\n", material->n);
	}
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
	{
		ft_polyhedron_material(state, &material->ka, false);
		printf("remove_material::ka[%f]\n", material->ka);
	}
	else if (key == KEYBOARD_2)
	{
		ft_polyhedron_material(state, &material->kd, false);
		printf("remove_material::kd[%f]\n", material->kd);
	}
	else if (key == KEYBOARD_3)
	{
		ft_polyhedron_material(state, &material->kr, false);
		printf("remove_material::kr[%f]\n", material->kr);
	}
	else if (key == KEYBOARD_4)
	{
		ft_polyhedron_material(state, &material->ks, false);
		printf("remove_material::ks[%f]\n", material->ks);
	}
	else if (key == KEYBOARD_5)
	{
		ft_polyhedron_material(state, &material->n, false);
		printf("remove_material::n[%f]\n", material->n);
	}
	else
		ft_handle_components(key, state, false);
}

static void	ft_handle_components(int key, t_state *state, bool add)
{
	t_polyhedron_state	*poly_state;

	poly_state = &state->scene.polyhedron;
	if (key == KEYBOARD_6 && poly_state->n_components > 0)
	{
		ft_polyhedron_component(state, &poly_state->components[0], add);
		printf("%s: %f\n", poly_state->components[0].name, poly_state->components[0].value);
	}
	else if (key == KEYBOARD_7 && poly_state->n_components > 1)
	{
		ft_polyhedron_component(state, &poly_state->components[1], add);
		printf("%s: %f\n", poly_state->components[1].name, poly_state->components[1].value);
	}
	else if (key == KEYBOARD_8 && poly_state->n_components > 2)
	{
		ft_polyhedron_component(state, &poly_state->components[2], add);
		printf("%s: %f\n", poly_state->components[2].name, poly_state->components[2].value);
	}
}
