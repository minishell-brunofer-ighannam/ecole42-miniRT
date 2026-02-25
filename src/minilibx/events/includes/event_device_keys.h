/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_device_keys.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:28:37 by valero            #+#    #+#             */
/*   Updated: 2026/01/28 14:18:52 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_DEVICE_KEYS_H
# define EVENT_DEVICE_KEYS_H

typedef enum e_mouse_keys
{
	MOUSE_LEFT_BUTTON = 1,
	MOUSE_MIDDLE_BUTTON = 2,
	MOUSE_RIGHT_BUTTON = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
}	t_mouse_keys;

typedef enum e_keyboard_keys
{
	KEYBOARD_ESC = 65307,
	KEYBOARD_LEFT_SIFT = 65505,
	KEYBOARD_RIGHT_SIFT = 65506,
	KEYBOARD_LEFT_CTRL = 65507,
	KEYBOARD_RIGHT_CTRL = 65508,
	KEYBOARD_LEFT_ALT = 65513,
	KEYBOARD_RIGHT_ALT = 65514,
	KEYBOARD_ARROW_LEFT = 65361,
	KEYBOARD_ARROW_UP = 65362,
	KEYBOARD_ARROW_RIGHT = 65363,
	KEYBOARD_ARROW_DOWN = 65364,
	KEYBOARD_SPACE = 32,
	KEYBOARD_PLUS = 61,
	KEYBOARD_MINUS = 45,
	KEYBOARD_A = 97,
	KEYBOARD_B = 98,
	KEYBOARD_C = 99,
	KEYBOARD_D = 100,
	KEYBOARD_E = 101,
	KEYBOARD_F = 102,
	KEYBOARD_G = 103,
	KEYBOARD_H = 104,
	KEYBOARD_I = 105,
	KEYBOARD_J = 106,
	KEYBOARD_K = 107,
	KEYBOARD_L = 108,
	KEYBOARD_M = 109,
	KEYBOARD_N = 110,
	KEYBOARD_O = 111,
	KEYBOARD_P = 112,
	KEYBOARD_Q = 113,
	KEYBOARD_R = 114,
	KEYBOARD_S = 115,
	KEYBOARD_T = 116,
	KEYBOARD_U = 117,
	KEYBOARD_V = 118,
	KEYBOARD_W = 119,
	KEYBOARD_X = 120,
	KEYBOARD_Y = 121,
	KEYBOARD_Z = 122,
	KEYBOARD_0 = 48,
	KEYBOARD_1 = 49,
	KEYBOARD_2 = 50,
	KEYBOARD_3 = 51,
	KEYBOARD_4 = 52,
	KEYBOARD_5 = 53,
	KEYBOARD_6 = 54,
	KEYBOARD_7 = 55,
	KEYBOARD_8 = 56,
	KEYBOARD_9 = 57,
}	t_keyboard_keys;

#endif
