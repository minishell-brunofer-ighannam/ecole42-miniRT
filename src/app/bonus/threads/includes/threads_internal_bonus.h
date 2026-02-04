/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_internal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:31:34 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/04 11:34:56 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_INTERNAL_BONUS_H
# define THREADS_INTERNAL_BONUS_H

# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "threads_bonus.h"

t_thread	*ft_new_thread(
				t_context *context, t_flow_ctrl *flow_ctrl,
				int id, int n_threads);
t_flow_ctrl	*ft_new_flow_control(void);
void		*ft_thread_routine(t_thread *thread);
void		ft_recalculate_thread_chunck(t_thread *thread);

#endif
