/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_x11.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:01:56 by valero            #+#    #+#             */
/*   Updated: 2026/01/25 19:07:57 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_X11_H
# define EVENT_X11_H

typedef enum e_x11_event_ids	t_x11_event_ids;
enum e_x11_event_ids
{
	KEY_PRESS_EVENT			= 2,
	KEY_RELEASE_EVENT		= 3,
	BUTTON_PRESS_EVENT		= 4,
	BUTTON_RELEASE_EVENT	= 5,
	MOTION_NOTIFY_EVENT		= 6,
	ENTER_NOTIFY_EVENT		= 7,
	LEAVE_NOTIFY_EVENT		= 8,
	FOCUS_IN_EVENT			= 9,
	FOCUS_OUT_EVENT			= 10,
	KEYMAP_NOTIFY_EVENT		= 11,
	EXPOSE_EVENT			= 12,
	GRAPHICS_EXPOSE_EVENT	= 13,
	NO_EXPOSE_EVENT			= 14,
	VISIBILITY_NOTIFY_EVENT	= 15,
	CREATE_NOTIFY_EVENT		= 16,
	DESTROY_NOTIFY_EVENT	= 17,
	UNMAP_NOTIFY_EVENT		= 18,
	MAP_NOTIFY_EVENT		= 19,
	MAP_REQUEST_EVENT		= 20,
	REPARENT_NOTIFY_EVENT	= 21,
	CONFIGURE_NOTIFY_EVENT	= 22,
	CONFIGURE_REQUEST_EVENT	= 23,
	GRAVITY_NOTIFY_EVENT	= 24,
	RESIZE_REQUEST_EVENT	= 25,
	CIRCULATE_NOTIFY_EVENT	= 26,
	CIRCULATE_REQUEST_EVENT	= 27,
	PROPERTY_NOTIFY_EVENT	= 28,
	SELECTION_CLEAR_EVENT	= 29,
	SELECTION_REQUEST_EVENT	= 30,
	SELECTION_NOTIFY_EVENT	= 31,
	COLORMAP_NOTIFY_EVENT	= 32,
	CLIENT_MESSAGE_EVENT	= 33,
	MAPPING_NOTIFY_EVENT	= 34,
	GENERIC_EVENT_EVENT		= 35,
	LAST_EVENT_EVENT		= 36
};

typedef enum e_x11_event_masks	t_x11_event_masks;
enum e_x11_event_masks
{
	NO_EVENT_MASK				= 0L,
	KEY_PRESS_MASK				= (1L << 0),
	KEY_RELEASE_MASK			= (1L << 1),
	BUTTON_PRESS_MASK			= (1L << 2),
	BUTTON_RELEASE_MASK			= (1L << 3),
	ENTER_WINDOW_MASK			= (1L << 4),
	LEAVE_WINDOW_MASK			= (1L << 5),
	POINTER_MOTION_MASK			= (1L << 6),
	POINTER_MOTION_HINT_MASK	= (1L << 7),
	BUTTON1_MOTION_MASK			= (1L << 8),
	BUTTON2_MOTION_MASK			= (1L << 9),
	BUTTON3_MOTION_MASK			= (1L << 10),
	BUTTON4_MOTION_MASK			= (1L << 11),
	BUTTON5_MOTION_MASK			= (1L << 12),
	BUTTON_MOTION_MASK			= (1L << 13),
	KEYMAP_STATE_MASK			= (1L << 14),
	EXPOSURE_MASK				= (1L << 15),
	VISIBILITY_CHANGE_MASK		= (1L << 16),
	STRUCTURE_NOTIFY_MASK		= (1L << 17),
	RESIZE_REDIRECT_MASK		= (1L << 18),
	SUBSTRUCTURE_NOTIFY_MASK	= (1L << 19),
	SUBSTRUCTURE_REDIRECT_MASK	= (1L << 20),
	FOCUS_CHANGE_MASK			= (1L << 21),
	PROPERTY_CHANGE_MASK		= (1L << 22),
	COLORMAP_CHANGE_MASK		= (1L << 23),
	OWNER_GRAB_BUTTON_MASK		= (1L << 24)
};

#endif
