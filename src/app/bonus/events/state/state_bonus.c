/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:54:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/28 10:05:00 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/state_internal_bonus.h"

t_state	ft_new_state(void)
{
	t_state	state;

	ft_bzero(&state, sizeof(t_state));
	state.set = ft_new_set_state();
	return (state);
}
