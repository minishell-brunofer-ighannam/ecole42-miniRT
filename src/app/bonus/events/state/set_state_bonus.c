/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 23:39:39 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_internal_bonus.h"

static void	set_window(t_context *context, int width, int height);
static void	set_keys(t_context *context, int key, bool value);

t_set_state	ft_new_set_state(void)
{
	t_set_state	setter;

	setter.camera_rotation = ft_new_camera_rotation();
	setter.camera_translation = ft_new_camera_translation();
	setter.polyhedron_rotation = ft_new_polyhedron_rotation();
	setter.polyhedron_translation = ft_new_polyhedron_translation();
	setter.unselect_polyhedron = ft_unselect_polyhedron;
	setter.select_polyhedron = ft_select_polyhedron;
	setter.window = set_window;
	setter.keys = set_keys;
	return (setter);
}

static void	set_window(t_context *context, int width, int height)
{
	t_state			*state;

	if (!context)
		return ;
	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	printf("window::resize[%d, %d]\n", width, height);
	if (state->window.width == width && state->window.height == height)
	{
		pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
		return ;
	}
	if (!state->window.has_changes)
	{
		if (!state->has_changes)
			state->has_changes = true;
		state->window.has_changes = true;
	}
	if (state->window.width != width)
		state->window.width = width;
	if (state->window.height != height)
		state->window.height = height;
	printf("window::resize[%d, %d]\n", width, height);
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}

static void	set_keys(t_context *context, int key, bool value)
{
	t_pressed_keys	*keys;
	t_state			*state;

	state = &context->events.state;
	pthread_mutex_lock(&state->parallel->flow_ctrl->mutex_set_state);
	keys = &state->pressed_keys;
	if (!state->has_changes)
		state->has_changes = true;
	if (!keys->has_changes)
		keys->has_changes = true;
	if (key == KEYBOARD_LEFT_ALT && keys->left_alt != value)
		keys->left_alt = value;
	else if (key == KEYBOARD_RIGHT_ALT && keys->right_alt != value)
		keys->right_alt = value;
	else if (key == KEYBOARD_LEFT_CTRL && keys->left_ctrl != value)
		keys->left_ctrl = value;
	else if (key == KEYBOARD_RIGHT_CTRL && keys->right_ctrl != value)
		keys->right_ctrl = value;
	else if (key == KEYBOARD_LEFT_SIFT && keys->left_shift != value)
		keys->left_shift = value;
	else if (key == KEYBOARD_RIGHT_SIFT && keys->right_shift != value)
		keys->right_shift = value;
	else if (key == MOUSE_LEFT_BUTTON && keys->left_mouse_btn != value)
		keys->left_mouse_btn = value;
	else if (key == MOUSE_RIGHT_BUTTON && keys->right_mouse_btn != value)
		keys->right_mouse_btn = value;
	else if (key == MOUSE_MIDDLE_BUTTON && keys->middle_mouse_btn != value)
		keys->middle_mouse_btn = value;
	pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
}
