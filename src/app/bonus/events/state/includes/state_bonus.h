/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/27 14:53:58 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STATE_BONUS_H
# define STATE_BONUS_H

# include <stdbool.h>

typedef struct s_pressed_keys	t_pressed_keys;
struct s_pressed_keys
{
	bool	has_changes;
	bool	left_ctrl;
	bool	left_shift;
	bool	left_alt;
	bool	right_ctrl;
	bool	right_shift;
	bool	right_alt;
	bool	left_mouse_btn;
	bool	right_mouse_btn;
	bool	middle_mouse_btn;
};

typedef struct s_camera_state	t_camera_state;
struct s_camera_state
{
	bool	has_changes;
	int		translate_up;
	int		translate_down;
	int		translate_front;
	int		translate_back;
	int		translate_left;
	int		translate_right;
	int		rotate_x;
	int		rotate_y;
};

typedef struct s_scene_state	t_scene_state;
struct s_scene_state
{
	bool			has_changes;
	t_camera_state	camera;
};

typedef struct s_window_state	t_window_state;
struct s_window_state
{
	bool	has_changes;
	int		width;
	int		height;
};

typedef struct s_state			t_state;
struct s_state
{
	bool			has_changes;
	t_pressed_keys	pressed_keys;
	t_scene_state	scene;
	t_window_state	window;
};

t_state	ft_new_state(void);

#endif
