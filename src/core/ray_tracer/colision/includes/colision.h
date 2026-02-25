/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:05 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 11:14:01 by ighannam         ###   ########.fr       */
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
	double					u;
	double					v;
	double					u_norm;
	double					v_norm;
	t_vector_3d				dir_u;
	t_vector_3d				dir_v;
};

t_colision					ft_closest_colision(t_scene *restrict scene,
								t_ray *restrict ray);

#endif
