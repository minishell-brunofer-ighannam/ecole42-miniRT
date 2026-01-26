/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 05:21:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 08:21:56 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WINDOW_EVENTS_BONUS_H
# define WINDOW_EVENTS_BONUS_H

# include <X11/Xlib.h>
# include <stdio.h>
# include "../../../../../minilibx/includes/minilibx.h"

typedef struct s_window_callbacks	t_window_callbacks;
struct s_window_callbacks
{
	int	(*close)(t_mlx *mlx);
	int	(*resize)(void *param, XEvent *event);
};

t_window_callbacks	ft_new_window_callbacks(void);

#endif
