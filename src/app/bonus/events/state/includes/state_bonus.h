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

# include "../camera/includes/camera_state_bonus.h"
# include "../polyhedron/includes/state_polyhedron_bonus.h"
# include "math_rt.h"
# include <stdbool.h>

typedef struct s_context					t_context;
typedef struct s_polyhedron					t_polyhedron;
typedef struct s_parallel					t_parallel;
typedef struct s_spatial_gesture			t_spatial_gesture;

typedef struct s_pressed_keys				t_pressed_keys;
typedef struct s_camera_state				t_camera_state;
typedef struct s_polyhedron_state			t_polyhedron_state;
typedef struct s_polyhedron_state_material	t_polyhedron_state_material;
typedef struct s_polyhedron_state_component	t_polyhedron_state_component;
typedef struct s_scene_state				t_scene_state;
typedef struct s_window_state				t_window_state;
typedef struct s_state						t_state;
typedef struct s_set_state					t_set_state;

struct										s_pressed_keys
{
	bool									has_changes;
	bool									left_ctrl;
	bool									left_shift;
	bool									left_alt;
	bool									right_ctrl;
	bool									right_shift;
	bool									right_alt;
	bool									left_mouse_btn;
	bool									right_mouse_btn;
	bool									middle_mouse_btn;
};

struct										s_camera_state
{
	bool									has_changes;
	double									translate_x;
	double									translate_y;
	double									translate_z;
	double									rotate_x;
	double									rotate_y;
	double									rotate_z;
};

struct										s_polyhedron_state_material
{
	t_vector_3d								albedo;
	double									ka;
	double									kd;
	double									ks;
	double									n;
	double									kr;
};

struct										s_polyhedron_state_component
{
	char									*name;
	double									value;
	double									variation_size;
};

struct										s_polyhedron_state
{
	bool									has_changes;
	t_polyhedron							*selected;
	double									translate_x;
	double									translate_y;
	double									translate_z;
	double									rotate_x;
	double									rotate_y;
	double									rotate_z;
	t_polyhedron_state_component			*components;
	int										n_components;
	t_polyhedron_state_material				material;
};

struct										s_scene_state
{
	bool									has_changes;
	t_camera_state							camera;
	t_polyhedron_state						polyhedron;
};

struct										s_window_state
{
	bool									has_changes;
	int										width;
	int										height;
	double									ratio;
};

typedef struct s_set_mov_discrete			t_set_mov_discrete;
struct										s_set_mov_discrete
{
	void									(*up)(t_context *context);
	void									(*down)(t_context *context);
	void									(*front)(t_context *context);
	void									(*back)(t_context *context);
	void									(*left)(t_context *context);
	void									(*right)(t_context *context);
};

typedef struct s_set_movement				t_set_movement;
struct										s_set_movement
{
	t_set_mov_discrete						discrete;
	void									(*spatial)(t_context *context,
										t_spatial_gesture *gesture);
};

struct										s_set_state
{
	void									(*window)(t_context *context,
											int width, int height);
	void									(*keys)(t_context *context, int key,
											bool value);
	t_set_movement							camera_translation;
	t_set_movement							camera_rotation;
	void									(*select_polyhedron)(t_context *context,
											int x, int y);
	void									(*unselect_polyhedron)(t_context *context);
	t_set_movement							polyhedron_translation;
	t_set_movement							polyhedron_rotation;
};

struct										s_state
{
	bool									has_changes;
	bool									stop_app;
	t_pressed_keys							pressed_keys;
	t_scene_state							scene;
	t_window_state							window;
	t_set_state								set;
	t_parallel								*parallel;
	void									*(*destroy)(t_context *context);
};

t_state										ft_new_state(void);

#endif
