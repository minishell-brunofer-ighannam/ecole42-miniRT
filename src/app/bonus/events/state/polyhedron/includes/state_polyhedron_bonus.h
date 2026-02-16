/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_polyhedron_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:46:40 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 21:36:39 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_POLYHEDRON_BONUS_H
# define STATE_POLYHEDRON_BONUS_H

void			ft_unselect_polyhedron(t_state *self);
void			ft_select_polyhedron(t_state *self,
					t_context *context, int x, int y);
void			ft_polyhedron_material(t_state *state, int *prop, bool add);
void			ft_polyhedron_component(t_state *state,
					t_polyhedron_state_component *component, bool add);
t_set_movement	ft_new_polyhedron_rotation(void);
t_set_movement	ft_new_polyhedron_translation(void);

#endif
