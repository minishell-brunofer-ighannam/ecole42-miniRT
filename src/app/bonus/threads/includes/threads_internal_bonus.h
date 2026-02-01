/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_internal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:31:34 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 16:50:15 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_INTERNAL_BONUS_H
# define THREADS_INTERNAL_BONUS_H

# include "libft.h"
# include "threads_bonus.h"

void	*ft_thread_routine(t_thread *thread);
void	ft_recalculate_thread_chunck(t_thread *thread);

#endif
