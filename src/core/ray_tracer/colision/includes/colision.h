/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:05 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 13:39:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLISION_H
# define COLISION_H

# include "math_rt.h"
# include "polyhedron.h"
# include "ray.h"
# include "ray_tracer.h"

typedef struct s_scene		t_scene;
typedef struct s_colision	t_colision;

struct						s_colision
{
	t_ray					ray;
	t_polyhedron			polyhedron;
	bool					colision;
	double					t;
	int						section;
	t_point_3d				colision_point;
	t_vector_3d				normal;
	t_vector_3d				color_dif;
	t_vector_3d				color_spec;
	t_vector_3d				color_local;
	t_vector_3d				color_reflexive;
	t_vector_3d				color_final;
};

// SPHERE
void						ft_colision_sp(t_polyhedron *polyhedron, t_ray ray,
								t_colision *col);
double						ft_solve_quadratic_normalized(double half_b,
								double c);

// PLANE
void						ft_colision_pl(t_polyhedron *polyhedron, t_ray ray,
								t_colision *col);
double						ft_colision_plane_normal(t_ray ray,
								t_point_3d point, t_vector_3d normal);

// CYLINDER
void						ft_colision_cy(t_polyhedron *polyhedron, t_ray ray,
								t_colision *col);
double						ft_colision_cy_body(t_cylinder *cy, t_ray ray);
double						ft_colision_cy_caps(t_cylinder *cy, t_ray ray);

// CONE
void						ft_colision_co(t_polyhedron *polyhedron, t_ray ray,
								t_colision *col);

// POLYHEDRON
void						ft_polyhedron_colision(t_polyhedron polyhedron,
								t_ray ray, t_colision *col);

t_colision					ft_closest_colision(t_scene *scene, t_ray ray);

#endif
