/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:54:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 19:10:05 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/state_internal_bonus.h"

static void	*ft_destroy_state(t_context	*context);

t_state	ft_new_state(void)
{
	t_state	state;

	ft_bzero(&state, sizeof(t_state));
	state.set = ft_new_set_state();
	state.destroy = ft_destroy_state;
	return (state);
}

static void	*ft_destroy_state(t_context	*context)
{
	ft_unselect_polyhedron(context);
	return (NULL);
}
