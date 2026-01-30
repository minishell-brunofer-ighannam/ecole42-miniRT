/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:10:59 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 09:07:12 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "events/includes/events_bonus.h"
# include "frame/includes/frame.h"
# include "../../minilibx/includes/minilibx.h"

typedef struct s_context	t_context;
struct s_context
{
	t_mlx		mlx;
	t_events	events;
	t_frame		frame;
	void		*scene;
};

t_context	ft_new_context(int width, int height, const char *name, void *scene);

#endif
