/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:29 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 11:51:48 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLISION_INTERNAL_H
# define COLISION_INTERNAL_H

# include "colision.h"

// SPHERE
void	ft_colision_sp(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
			t_colision *restrict col);
double	ft_solve_quadratic_normalized(double half_b, double c);

// PLANE
void	ft_colision_pl(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
			t_colision *restrict col);
double	ft_colision_plane_normal(t_ray *restrict ray, t_point_3d point,
			t_vector_3d normal);

// CYLINDER
void	ft_colision_cy(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
			t_colision *restrict col);
double	ft_colision_cy_body(t_cylinder *restrict cy, t_ray *restrict ray);
double	ft_colision_cy_caps(t_cylinder *cy, t_ray *ray, t_colision *col);

// CONE
void	ft_colision_co(t_polyhedron *restrict polyhedron, t_ray *restrict ray,
			t_colision *restrict col);

// POLYHEDRON
void	ft_polyhedron_colision(t_polyhedron polyhedron, t_ray *restrict ray,
			t_colision *restrict col);

#endif