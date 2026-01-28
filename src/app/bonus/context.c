/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:13:13 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 13:16:32 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

t_context	ft_new_context(int width, int height, const char *name)
{
	t_context	context;

	context.mlx = ft_new_mlx(width, height, name);
	context.events = ft_new_events();
	return (context);
}
