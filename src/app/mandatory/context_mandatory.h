/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:10:59 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 14:04:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_MANDATORY_H
# define CONTEXT_MANDATORY_H

# include "../../minilibx/includes/minilibx.h"
# include "events/includes/events_bonus.h"
# include "frame/includes/frame_bonus.h"
# include "scene.h"

typedef struct s_context			t_context;
typedef struct s_scene				t_scene;

typedef struct s_context_callbacks	t_context_callbacks;
struct								s_context_callbacks
{
	bool							(*is_process_stopped)(t_context * self);
	bool							(*is_app_running)(t_context * self);
	void							(*stop_app)(t_context *self);
};

typedef struct s_context			t_context;
struct								s_context
{
	t_mlx							mlx;
	t_scene							*scene;
	t_context_callbacks				callbacks;
	bool							stop_app;
};

typedef struct s_window_info		t_window_info;
struct								s_window_info
{
	int								width;
	int								height;
	const char						*name;
};

t_window_info	ft_new_window_info(int width, int height,
					const char *name);
t_context		ft_new_context(t_window_info window,
					void *scene,
					void *(*create_callbacks)(t_context *context));
bool			ft_is_app_running(t_context *self);
void			ft_stop_app(t_context *self);
bool			ft_is_process_stopped(t_context *self);

#endif
