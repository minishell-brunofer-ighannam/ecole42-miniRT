/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:44:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/08 13:49:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../threads/includes/threads_bonus.h"
#include "../gestures/includes/gestures_bonus.h"
#include "includes/state_internal_bonus.h"
#include "debug.h"

static void	set_window(t_state *self, int width, int height);
static void	set_keys(t_state *self, int key, bool value);

t_set_state	ft_new_set_state(void)
{
	t_set_state	setter;

	setter.camera_rotation = ft_new_camera_rotation();
	setter.camera_translation = ft_new_camera_translation();
	setter.window = set_window;
	setter.keys = set_keys;
	return (setter);
}

static void	set_window(t_state *self, int width, int height)
{
	if (!self)
		return ;
	LOCK(&self->parallel->flow_ctrl->mutex_set_state);
	if (self->window.width == width && self->window.height == height)
	{
		UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
		return ;
	}
	if (!self->window.has_changes)
	{
		if (!self->has_changes)
			self->has_changes = true;
		self->window.has_changes = true;
	}
	if (self->window.width != width)
		self->window.width = width;
	if (self->window.height != height)
		self->window.height = height;
	self->window.ratio = (double)width / (double)height;
	printf("window::resize[%d, %d]\n", width, height);
	UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
	usleep(300);
}

static void	set_keys(t_state *self, int key, bool value)
{
	t_pressed_keys	*keys;

	LOCK(&self->parallel->flow_ctrl->mutex_set_state);
	keys = &self->pressed_keys;
	if (!self->has_changes)
		self->has_changes = true;
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
	UNLOCK(&self->parallel->flow_ctrl->mutex_set_state);
}

void	set_camera_changed_flag(t_state *self)
{
	if (!self->scene.camera.has_changes)
	{
		if (!self->scene.has_changes)
		{
			self->has_changes = true;
			self->scene.has_changes = true;
		}
		else if (!self->has_changes)
			self->has_changes = true;
		self->scene.camera.has_changes = true;
	}
}
