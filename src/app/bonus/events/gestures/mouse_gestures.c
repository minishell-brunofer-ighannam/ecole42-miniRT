/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_gestures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:21:47 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 17:56:01 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/gestures_internal_bonus.h"
#include "context.h"

void		ft_low_pass_filter(t_spatial_gesture *self, int x, int y);
void		calibrate_diff_y(double *diff);
static void	lalt_ldrag_handler(
				t_spatial_gesture *self, t_context *context, int x, int y);
static void	lctrl_mouse_move_handler(
				t_spatial_gesture *self, t_context *context, int x, int y);
static void	lctrl_ldrag_handler(
				t_spatial_gesture *self, t_context *context, int x, int y);

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
				t_spatial_gesture *self, t_context *context, int x, int y)
{
	t_pressed_keys	keys;

	keys = context->events.state.pressed_keys;
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
		// self->diff.x /= state->window.ratio;
		self->last_pos.x = x;
	}
	if (self->last_pos.y != y)
	{
		self->diff.y = y - self->last_pos.y;
		calibrate_diff_y(&self->diff.y);
		// self->diff.y /= state->window.ratio;
		self->last_pos.y = y;
	}

	self->state_setter(context, self);
}

static void	lctrl_ldrag_handler(
				t_spatial_gesture *self, t_context *context, int x, int y)
{
	t_pressed_keys	keys;

	keys = context->events.state.pressed_keys;
	if (!keys.left_ctrl || !keys.left_mouse_btn || keys.left_alt
		|| keys.left_shift || keys.right_alt || keys.right_ctrl
		|| keys.right_shift || keys.right_mouse_btn || keys.middle_mouse_btn)
		return ;
	self->diff.z = x + y - self->last_pos.z;
	calibrate_diff(&self->diff.z);
	self->last_pos.z = x + y;
	self->state_setter(context, self);
}

static void	lalt_ldrag_handler(
				t_spatial_gesture *self, t_context *context, int x, int y)
{
	t_pressed_keys	keys;

	keys = context->events.state.pressed_keys;
	if (!keys.left_alt || !keys.left_mouse_btn || keys.left_ctrl
		|| keys.left_shift || keys.right_alt || keys.right_ctrl
		|| keys.right_shift || keys.right_mouse_btn || keys.middle_mouse_btn)
		return ;
	if (self->last_pos.x == x && self->last_pos.y == y)
		return ;
	if (self->last_pos.x != x)
	{
		self->diff.x = (double)x - self->last_pos.x;
		calibrate_diff(&self->diff.x);
		self->last_pos.x = x;
	}
	if (self->last_pos.y != y)
	{
		self->diff.y = (double)y - self->last_pos.y;
		calibrate_diff_y(&self->diff.y);
		self->last_pos.y = y;
	}
	// ft_low_pass_filter(self, x, y);
	// calibrate_diff(&self->diff.x);
	// calibrate_diff_y(&self->diff.y);
	self->state_setter(context, self);
}

void	calibrate_diff(double *diff)
{
	if (*diff < 2 && *diff > -2)
		*diff *= 0.5;
	if (*diff > 50 || *diff < -50)
	{
		if (*diff > 0)
			*diff = 1;
		else
			*diff = -1;
	}
}

void	calibrate_diff_y(double *diff)
{
	if (*diff < 2 && *diff > -2)
		*diff *= 0.05;
	if (*diff > 50 || *diff < -50)
	{
		if (*diff > 0)
			*diff = 1;
		else
			*diff = -1;
	}
}


void	ft_low_pass_filter(t_spatial_gesture *self, int x, int y)
{
	double	delta_x;
	double	delta_y;
	double	alpha;

	alpha = 0.05;
	delta_x = self->last_pos.x - (double)x;
	delta_y = self->last_pos.y - (double)y;

	if (fabs(delta_x) > fabs(delta_y))
		delta_y = 0;
	else
		delta_x = 0;

	self->diff.x += alpha * (delta_x - self->diff.x);
	self->diff.y += alpha * (delta_y - self->diff.y);

	self->last_pos.x = x;
	self->last_pos.y = y;
}
