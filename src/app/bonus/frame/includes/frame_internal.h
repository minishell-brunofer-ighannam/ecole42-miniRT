/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:21:52 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 08:47:13 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_INTERNAL_H
# define FRAME_INTERNAL_H

# include "../../threads/includes/threads_bonus.h"
# include "frame.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_ui_dimension	t_ui_dimension;
struct							s_ui_dimension
{
	int							start_x;
	int							end_x;
	int							start_y;
	int							end_y;
};

typedef struct s_ui_text		t_ui_text;
struct							s_ui_text
{
	int							start;
	int							color;
	char						*content;
};

typedef struct s_ui_section		t_ui_section;
struct							s_ui_section
{
	t_ui_dimension				dimension;
	int							color;
};

typedef struct s_ui_header		t_ui_header;
struct							s_ui_header
{
	t_ui_section				main;
};

typedef struct s_ui_container	t_ui_container;
struct							s_ui_container
{
	t_ui_section				main;
	t_ui_header					header;
};

typedef struct s_polyedron_ui	t_polyedron_ui;
struct							s_polyedron_ui
{
	t_ui_section				container;
};

void			ft_draw_square(t_context *context, int width,
					int height);

void			ft_show_frame_info(t_context *context);
bool			ft_process_state(t_context *context);
bool			ft_process_resize_image(t_context *context);
void			ft_handle_camera(t_camera *scene_cam,
					t_camera_state *state_cam);
void			ft_handle_polyhedron(t_polyhedron_state *state_polyhedron);
void			ft_process_camera_translation(t_point_3d *restrict origin,
					t_vector_3d forward,
					t_camera_state *restrict state_cam);
void			ft_process_camera_rotation(t_camera_state *restrict state_cam,
					t_vector_3d *restrict forward,
					t_vector_3d *restrict right,
					t_vector_3d *restrict up);
void			ft_sow_selected_polyedron_ui(t_context *context);

#endif
