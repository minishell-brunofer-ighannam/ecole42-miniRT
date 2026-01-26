/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:00:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/26 11:36:16 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/keyboard_events_internal_bonus.h"

static int	ft_key_press(int key, void *param);
static int	ft_key_release(int key, void *param);

t_keyboard_callbacks	ft_new_keyboard_callbacks(void)
{
	t_keyboard_callbacks	callbacks;

	callbacks.key_press = ft_key_press;
	callbacks.key_release = ft_key_release;
	return (callbacks);
}

static int	ft_key_press(int key, void *param)
{
	(void)param;
	// loop end
	// if (key == KEYBOARD_ESC)
	printf("keyboard[%d] pressed\n", key);
	return (1);
}

static int	ft_key_release(int key, void *param)
{
	(void)param;
	printf("keyboard[%d] released\n", key);
	return (1);
}

