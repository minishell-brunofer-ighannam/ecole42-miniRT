/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:13:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/01 09:03:37 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

t_context	ft_new_context(
				t_window_info window, void *scene,
				void *(*create_callbacks)(t_context *context))
{
	t_context	context;

	context.mlx = ft_new_mlx(window.width, window.height, window.name);
	context.events = ft_new_events();
	context.frame = ft_new_frame();
	context.scene = scene;
	context.parallel = NULL;
	create_callbacks(&context);
	return (context);
}

t_window_info	ft_new_window_info(int width, int height, const char *name)
{
	t_window_info	info;

	info.width = width;
	info.height = height;
	info.name = name;
	return (info);
}
