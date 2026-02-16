/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_rotation_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:18:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 09:25:58 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

t_set_movement	ft_new_polyhedron_rotation(void)
{
	t_set_movement	mov;

	mov.spatial = set_polyhedron_rotation_spatial;
	mov.discrete.up = set_polyhedron_rotation_up;
	mov.discrete.down = set_polyhedron_rotation_down;
	mov.discrete.right = set_polyhedron_rotation_right;
	mov.discrete.left = set_polyhedron_rotation_left;
	mov.discrete.front = set_polyhedron_rotation_diag_right;
	mov.discrete.back = set_polyhedron_rotation_diag_left;
	return (mov);
}

void	set_polyhedron_rotation_up(t_state *self)
{
	pthread_mutex_t	*mutex_set_state;

	if (!self)
		return ;
	mutex_set_state = &self->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.rotate_x += POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->up [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_down(t_state *self)
{
	pthread_mutex_t	*mutex_set_state;

	if (!self)
		return ;
	mutex_set_state = &self->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.rotate_x -= POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->down [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_left(t_state *self)
{
	pthread_mutex_t	*mutex_set_state;

	if (!self)
		return ;
	mutex_set_state = &self->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.rotate_y -= POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->left [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(mutex_set_state);
}

void	set_polyhedron_rotation_right(t_state *self)
{
	pthread_mutex_t	*mutex_set_state;

	if (!self)
		return ;
	mutex_set_state = &self->parallel->flow_ctrl->mutex_set_state;
	pthread_mutex_lock(mutex_set_state);
	set_polyhedron_changed_flag(self);
	self->scene.polyhedron.rotate_y += POLYHEDRON_ROTATION_INTENSITY;
	printf("polyhedron::rotation->right [%.0f, %.0f, %.0f]\n", self->scene.polyhedron.rotate_x, self->scene.polyhedron.rotate_y, self->scene.polyhedron.rotate_z);
	pthread_mutex_unlock(mutex_set_state);

}
