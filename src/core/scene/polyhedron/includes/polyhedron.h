/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:08:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 10:52:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYHEDRON_H
# define POLYHEDRON_H

# include "math_rt.h"
# include "scene.h"

typedef struct s_ray			t_ray;
typedef struct s_colision		t_colision;

typedef struct s_polyhedron		t_polyhedron;
typedef struct s_material		t_material;
typedef struct s_plane			t_plane;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cone		t_cone;
typedef enum e_polyhedron_type	t_polyhedron_type;
typedef enum e_pattern_type	t_pattern_type;
typedef struct s_pattern t_pattern;
typedef struct s_checker t_checker;

enum							e_polyhedron_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE
};

enum							e_pattern_type
{
	NO_PATTERN,
	CHECKER
};

struct s_pattern
{
	t_pattern_type pattern;
	void *specs;
};

struct s_checker
{
	t_vector_3d color_one;
	t_vector_3d norm_color_one;
	t_vector_3d color_two;
	t_vector_3d norm_color_two;
	double tile;
};

struct							s_material
{
	t_vector_3d					albedo;
	t_vector_3d					norm_albedo;
	double ka; // coeficiente ambiente do material - entre 0 e 1
	double kd; // coeficiente difuso do material - entre 0 e 1
	double ks; // coeficiente especular - entre 0 e 1
	double n;  // shininess
	double kr; // coeficiente de reflexão - entre 0 e 1
	char *pattern_name;
	t_pattern pattern;
};

struct							s_polyhedron
{
	t_polyhedron_type			type;
	int							id;
	void						*specs;
	t_material					material;
};

struct							s_sphere
{
	t_point_3d					center;
	double						radius;
};

struct							s_cylinder
{
	t_point_3d					center;
	t_vector_3d					axis;
	double						radius;
	double						height;
};

struct							s_cone
{
	t_point_3d					vertex;
	t_vector_3d					axis;
	double						half_apex_angle;
	double						height;
};

struct							s_plane
{
	t_point_3d					point;
	t_vector_3d					normal;
};

t_vector_3d						ft_normal_polyhedron(t_point_3d pt,
									t_polyhedron polyhedron);

#endif