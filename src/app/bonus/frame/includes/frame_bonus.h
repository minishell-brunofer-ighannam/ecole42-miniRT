/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:26:30 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/25 16:31:40 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_BONUS_H
# define FRAME_BONUS_H

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
