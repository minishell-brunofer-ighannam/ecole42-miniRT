/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:29:42 by brunofer          #+#    #+#             */
/*   Updated: 2026/02/03 17:59:09 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/threads_internal_bonus.h"

static bool	ft_init_cond(t_flow_ctrl *flow);
static bool	ft_init_mutext(t_flow_ctrl *flow);
void		*ft_destroy_flow_control(t_flow_ctrl **self_ref);

t_flow_ctrl	*ft_new_flow_control(void)
{
	t_flow_ctrl	*flow;
	bool		cond_ok;
	bool		mutex_ok;

	flow = ft_calloc(1, sizeof(t_flow_ctrl));
	ft_bzero(flow, sizeof(t_flow_ctrl));
	cond_ok = ft_init_cond(flow);
	mutex_ok = ft_init_mutext(flow);
	if (!cond_ok || !mutex_ok)
	{
		free(flow);
		return (NULL);
	}
	flow->destroy = ft_destroy_flow_control;
	return (flow);
}

static bool	ft_init_cond(t_flow_ctrl *flow)
{

	if (pthread_cond_init(&flow->cond_frame_ready, NULL))
		return (false);
	if (pthread_cond_init(&flow->cond_window_resize, NULL))
	{
		pthread_cond_destroy(&flow->cond_frame_ready);
		return (false);
	}
	return (true);
}

static bool	ft_init_mutext(t_flow_ctrl *flow)
{

	if (pthread_mutex_init(&flow->mutex_app_run, NULL))
		return (false);
	if (pthread_mutex_init(&flow->mutex_frame_parts_ready, NULL))
	{
		pthread_mutex_destroy(&flow->mutex_app_run);
		return (false);
	}
	if (pthread_mutex_init(&flow->mutex_frame_ready, NULL))
	{
		pthread_mutex_destroy(&flow->mutex_app_run);
		pthread_mutex_destroy(&flow->mutex_frame_parts_ready);
		return (false);
	}
	if (pthread_mutex_init(&flow->mutex_set_state, NULL))
	{
		pthread_mutex_destroy(&flow->mutex_app_run);
		pthread_mutex_destroy(&flow->mutex_frame_parts_ready);
		pthread_mutex_destroy(&flow->mutex_frame_ready);
		return (false);
	}
	return (true);
}

void	*ft_destroy_flow_control(t_flow_ctrl **self_ref)
{
	t_flow_ctrl	*self;

	if (!self_ref || !*self_ref)
		return (NULL);
	self = *self_ref;
	pthread_cond_destroy(&self->cond_frame_ready);
	pthread_cond_destroy(&self->cond_window_resize);
	pthread_mutex_destroy(&self->mutex_app_run);
	pthread_mutex_destroy(&self->mutex_frame_parts_ready);
	pthread_mutex_destroy(&self->mutex_frame_ready);
	pthread_mutex_destroy(&self->mutex_set_state);
	free(self);
	*self_ref = NULL;
	return (NULL);
}
