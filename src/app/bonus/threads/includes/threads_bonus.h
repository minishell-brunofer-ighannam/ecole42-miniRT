/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:31:34 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 17:03:05 by bruno-valer      ###   ########.fr       */
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
	int			n_threads;
	pthread_t	**threads;
	t_flow_ctrl	*flow_ctrl;
	void		*(*ray_tracing)(t_context *context, int row_start, int row_end);
	void		*(*destroy)(t_parallel self);
};


bool	ft_is_app_running(t_context *self);
void	ft_stop_app(t_context *self);
bool	ft_is_frame_ready(t_context *self);
void	ft_set_frame_ready(t_context *self, bool status);
void	ft_set_frame_parts_ready(t_context *self);

#endif
