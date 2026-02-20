/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:32:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 18:58:55 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTURES_BONUS_H
# define GESTURES_BONUS_H

# include <stdbool.h>
# include "../../state/includes/state_bonus.h"

typedef struct s_discrete_gesture	t_discrete_gesture;
struct s_discrete_gesture
{
	bool	active;
	void	(*handler)(t_discrete_gesture *self,
			t_context *context, int key, int *position);
	void	(*state_setter)(t_context *context);
};

typedef struct s_spatial_position	t_spatial_position;
struct s_spatial_position
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_spatial_gesture	t_spatial_gesture;
struct s_spatial_gesture
{
	bool				active;
	t_spatial_position	last_pos;
	t_spatial_position	diff;
	void				(*handler)(t_spatial_gesture *self,
			t_context *context, int x, int y);
	void				(*state_setter)(t_context *context,
			t_spatial_gesture *gesture);
};

typedef struct s_gestures			t_gestures;
struct s_gestures
{
	t_spatial_gesture	lctrl_ldrag;
	t_spatial_gesture	lalt_ldrag;
	t_spatial_gesture	lctrl_mouse_move;
	t_discrete_gesture	w;
	t_discrete_gesture	a;
	t_discrete_gesture	s;
	t_discrete_gesture	d;
	t_discrete_gesture	lshift_lmouseclick;
	t_discrete_gesture	lshift_rmouseclick;
	t_discrete_gesture	lshift_num_0_9;
	t_discrete_gesture	lshift_lalt_num_0_9;
	t_discrete_gesture	lshift_rgb;
	t_discrete_gesture	lshift_lalt_rgb;
};

t_gestures	ft_new_gestures(t_state *state);
void		ft_update_spatial_gestures(
				t_gestures *gest, t_context *context, int x, int y);
void		ft_update_discrete_gestures(
				t_gestures *gest, t_context *context, int key, int *position);

#endif
