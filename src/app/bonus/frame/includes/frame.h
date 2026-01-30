/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:21:20 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 08:49:18 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include <sys/time.h>
# include <stdbool.h>
# include "../../events/includes/events_bonus.h"

typedef struct s_context	t_context;

typedef struct s_frame		t_frame;
struct s_frame
{
	struct timeval	frame_start;
	int				(*run)(t_context *context);
};

t_frame	ft_new_frame(void);

#endif
