/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:10:59 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 11:22:16 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "events/includes/events_bonus.h"
# include "frame/includes/frame.h"
# include "../../minilibx/includes/minilibx.h"
# include "scene.h"

typedef struct s_context			t_context;
typedef struct s_scene				t_scene;

typedef struct s_context_callbacks	t_context_callbacks;
struct s_context_callbacks
{
	bool	(*is_process_stopped)(t_context * self);
	bool	(*is_app_running)(t_context * self);
	void	(*stop_app)(t_context *self);
	bool	(*is_frame_ready)(t_context * self);
	void	(*set_frame_ready)(t_context *self, bool status);
	void	(*set_frame_parts_ready)(t_context *self);
	bool	(*is_window_resized)(t_context * self);
};

typedef struct s_context			t_context;
struct s_context
{
	t_mlx				mlx;
	t_events			events;
	t_frame				frame;
	void				*parallel;
	t_scene				*scene;
	t_context_callbacks	callbacks;
};

typedef struct s_window_info		t_window_info;
struct s_window_info
{
	int			width;
	int			height;
	const char	*name;
};

t_window_info	ft_new_window_info(int width, int height, const char *name);
t_context		ft_new_context(
					t_window_info window, void *scene,
					void *(*create_callbacks)(t_context *context));





#endif
