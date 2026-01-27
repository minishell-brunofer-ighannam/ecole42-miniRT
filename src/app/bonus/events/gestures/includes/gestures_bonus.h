/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:32:53 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/27 18:21:27 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTURES_BONUS_H
# define GESTURES_BONUS_H

# include <stdbool.h>

typedef struct s_discrete_gesture	t_discrete_gesture;
struct s_discrete_gesture
{
	bool	active;
	void	(*handler)(t_discrete_gesture self, void *state);
};

typedef struct s_spatial_position	t_spatial_position;
struct s_spatial_position
{
	int	x;
	int	y;
};

typedef struct s_spatial_gesture	t_spatial_gesture;
struct s_spatial_gesture
{
	bool				active;
	t_spatial_position	start_pos;
	t_spatial_position	last_pos;
	t_spatial_position	curr_pos;
	t_spatial_position	diff;
	t_spatial_position	end_pos;
	void				(*handler)(t_spatial_gesture self, void *state);
};

typedef struct s_gestures			t_gestures;
struct s_gestures
{
	t_spatial_gesture	ctrl_ldrag;
	t_spatial_gesture	ctrl_rdrag;
	t_discrete_gesture	ctrl_z;
	t_discrete_gesture	ctrl_shift_z;
	t_discrete_gesture	w;
	t_discrete_gesture	a;
	t_discrete_gesture	s;
	t_discrete_gesture	d;
};

t_discrete_gesture	ft_new_discrete_gestures(void);
t_spatial_gesture	ft_new_spatial_gestures(void);

#endif
