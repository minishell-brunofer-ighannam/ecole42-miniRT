/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:31:34 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/03 17:46:26 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_BONUS_H
# define THREADS_BONUS_H

# include <pthread.h>
# include "../../context.h"

typedef struct s_flow_ctrl	t_flow_ctrl;
struct s_flow_ctrl
{
	bool			is_frame_ready;
	unsigned int	frame_parts_ready;
	pthread_cond_t	cond_frame_ready;
	pthread_mutex_t	mutex_frame_ready;
	pthread_mutex_t	mutex_frame_parts_ready;
	pthread_mutex_t	mutex_app_run;
	pthread_mutex_t	mutex_set_state;
	pthread_cond_t	cond_window_resize;
	void			*(*destroy)(t_flow_ctrl **self_ref);
};

typedef struct s_thread		t_thread;
struct s_thread
{
	int				id;
	pthread_t		thread;
	int				error;
	int				chunck;
	int				range_start;
	int				range_end;
	t_flow_ctrl		*flow_ctrl;
	t_context		*context;
	void			*(*destroy)(t_thread **self);
};

typedef struct s_parallel	t_parallel;
struct s_parallel
{
	unsigned int	n_threads;
	t_thread		**threads;
	t_flow_ctrl		*flow_ctrl;
	void			*(*ray_tracing)(t_context *context,
			int row_start, int row_end);
	void			*(*destroy)(t_parallel **self);
};

t_parallel	*ft_parallelize(t_context *context,
				void *(*ray_tracing)(t_context *context,
					int row_start, int row_end));

bool		ft_is_window_resized(t_context *self);
bool		ft_is_app_running(t_context *self);
void		ft_stop_app(t_context *self);
bool		ft_is_frame_ready(t_context *self);
void		ft_set_frame_ready(t_context *self, bool status);
void		ft_set_frame_parts_ready(t_context *self);

#endif
