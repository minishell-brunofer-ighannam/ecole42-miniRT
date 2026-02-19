/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:27:24 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/16 11:27:37 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/camera_state_internal_bonus.h"

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
