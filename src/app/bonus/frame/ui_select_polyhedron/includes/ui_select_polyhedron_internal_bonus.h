/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_select_polyhedron_internal_bonus.h              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:26:46 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/19 15:16:37 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SELECT_POLYHEDRON_INTERNAL_BONUS_H
# define UI_SELECT_POLYHEDRON_INTERNAL_BONUS_H

# include "ui_select_polyhedron_bonus.h"

typedef struct s_ui_dimension			t_ui_dimension;
struct s_ui_dimension
{
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
};

typedef enum e_ui_text_align			t_ui_text_align;
enum e_ui_text_align
{
	TEXT_ALIGN_START,
	TEXT_ALIGN_CENTER,
	TEXT_ALIGN_END,
};

typedef enum e_ui_align					t_ui_align;
enum e_ui_align
{
	UI_ALIGN_START,
	UI_ALIGN_CENTER,
	UI_ALIGN_END,
};

typedef enum e_ui_justify				t_ui_justify;
enum e_ui_justify
{
	UI_JUSTIFY_START,
	UI_JUSTIFY_CENTER,
	UI_JUSTIFY_END,
};

typedef struct s_ui_section				t_ui_section;
struct s_ui_section
{
	t_ui_section	*parent;
	t_ui_dimension	dimension;
	t_ui_align		ui_align;
	t_ui_justify	ui_justify;
	int				neighbors_amount;
	int				gb_color;
};

typedef struct s_ui_text				t_ui_text;
struct s_ui_text
{
	t_ui_section	soure_section;
	int				txt_color;
	int				txt_len;
	char			*txt;
};

typedef struct s_ui_component_header	t_ui_component_header;
struct s_ui_component_header
{
	t_ui_section	main;
};

typedef struct s_ui_component_container	t_ui_component_container;
struct s_ui_component_container
{
	t_ui_section			main;
	t_ui_component_header	header;
};

typedef struct s_polyedron_ui			t_polyedron_ui;
struct s_polyedron_ui
{
	t_ui_section	container;
};

#endif
