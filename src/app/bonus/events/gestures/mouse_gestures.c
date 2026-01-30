/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_gestures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:21:47 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 18:21:27 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"

static void	lalt_ldrag_handler(
				t_spatial_gesture *self, t_state *state, int x, int y);
static void	lctrl_mouse_move_handler(
				t_spatial_gesture *self, t_state *state, int x, int y);
static void	lctrl_ldrag_handler(
				t_spatial_gesture *self, t_state *state, int x, int y);

void	init_mouse_gestures(t_state *state, t_gestures *gest)
{
	gest->lalt_ldrag.state_setter = state->set.camera_translation.spatial;
	gest->lalt_ldrag.handler = lalt_ldrag_handler;
	gest->lctrl_mouse_move.state_setter = state->set.camera_rotation.spatial;
	gest->lctrl_mouse_move.handler = lctrl_mouse_move_handler;
	gest->lctrl_ldrag.state_setter = state->set.camera_rotation.spatial;
	gest->lctrl_ldrag.handler = lctrl_ldrag_handler;
}

static void	lctrl_mouse_move_handler(
				t_spatial_gesture *self, t_state *state, int x, int y)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (!keys.left_ctrl || keys.left_alt || keys.left_shift || keys.right_alt
		|| keys.right_ctrl || keys.right_shift || keys.left_mouse_btn
		|| keys.right_mouse_btn || keys.middle_mouse_btn)
		return ;
	if (self->last_pos.x == x && self->last_pos.y == y)
		return ;
	if (self->last_pos.x != x)
	{
		self->diff.x = x - self->last_pos.x;
		calibrate_diff(&self->diff.x);
		self->last_pos.x = x;
	}
	if (self->last_pos.y != y)
	{
		self->diff.y = y - self->last_pos.y;
		self->diff.y *= state->window.ratio;
		calibrate_diff(&self->diff.y);
		self->last_pos.y = y;
	}
	self->state_setter(state, self);
}

static void	lctrl_ldrag_handler(
				t_spatial_gesture *self, t_state *state, int x, int y)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (!keys.left_ctrl || !keys.left_mouse_btn || keys.left_alt
		|| keys.left_shift || keys.right_alt || keys.right_ctrl
		|| keys.right_shift || keys.right_mouse_btn || keys.middle_mouse_btn)
		return ;
	self->diff.z = x + y - self->last_pos.z;
	calibrate_diff(&self->diff.z);
	self->last_pos.z = x + y;
	self->state_setter(state, self);
}

static void	lalt_ldrag_handler(
				t_spatial_gesture *self, t_state *state, int x, int y)
{
	t_pressed_keys	keys;

	keys = state->pressed_keys;
	if (!keys.left_alt || !keys.left_mouse_btn || keys.left_ctrl
		|| keys.left_shift || keys.right_alt || keys.right_ctrl
		|| keys.right_shift || keys.right_mouse_btn || keys.middle_mouse_btn)
		return ;
	if (self->last_pos.x == x && self->last_pos.y == y)
		return ;
	if (self->last_pos.x != x)
	{
		self->diff.x = x - self->last_pos.x;
		calibrate_diff(&self->diff.x);
		self->last_pos.x = x;
	}
	if (self->last_pos.y != y)
	{
		self->diff.y = y - self->last_pos.y;
		self->diff.y *= state->window.ratio;
		calibrate_diff(&self->diff.y);
		self->last_pos.y = y;
	}
	self->state_setter(state, self);
}

void	calibrate_diff(int *diff)
{
	if (*diff > 40 || *diff < -40)
	{
		if (*diff > 0)
			*diff = 1;
		else
			*diff = -1;
	}
}
