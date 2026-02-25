/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_polyhedron_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:46:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 12:31:42 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_POLYHEDRON_BONUS_H
# define STATE_POLYHEDRON_BONUS_H

typedef struct s_context					t_context;
typedef struct s_state						t_state;
typedef struct s_scene						t_scene;
typedef struct s_polyhedron_state_component	t_polyhedron_state_component;

void			ft_unselect_polyhedron(t_context *context);
void			ft_select_polyhedron(
					t_context *context, t_scene *scene, int x, int y);
void			ft_polyhedron_material(t_state *state, double *prop, bool add);
void			ft_polyhedron_component(t_state *state,
					t_polyhedron_state_component *component, bool add);
t_set_movement	ft_new_polyhedron_rotation(void);
t_set_movement	ft_new_polyhedron_translation(void);

#endif
