/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:13:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 09:07:04 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

t_context	ft_new_context(int width, int height, const char *name, void *scene)
{
	t_context	context;

	context.mlx = ft_new_mlx(width, height, name);
	context.events = ft_new_events();
	context.frame = ft_new_frame();
	context.scene = scene;
	return (context);
}
