/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:08:00 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 12:03:49 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_INTERNAL_H
# define LIGHT_INTERNAL_H

# include "light.h"

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron);
t_vector_3d	ft_difuse_light(t_context *context, t_colision *col, int i,
				t_vector_3d normal);
t_vector_3d	ft_specular_light(t_context *context, t_colision *col, int i,
				t_vector_3d normal);

t_vector_3d	ft_norm_albedo_checker(t_colision *col);
t_vector_3d	ft_norm_albedo_map(t_colision *col, int x, int y);
void		ft_update_normal(t_colision *col, int x, int y, t_vector_3d normal);

void		ft_calc_u_v(t_colision *col);
void		ft_calc_u_v_pl(t_colision *col);
void		ft_calc_u_v_sp(t_colision *col);
void		ft_calc_dir_u_v(t_colision *col);
void		ft_calc_u_v_cy(t_colision *col);
void		ft_calc_u_v_circle(t_colision *col, t_vector_3d CP,
				t_vector_3d axis, double radius);
void		ft_calc_u_v_cn(t_colision *col);

#endif