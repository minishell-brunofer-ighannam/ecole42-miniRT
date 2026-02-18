/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:08:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 15:13:17 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYHEDRON_H
# define POLYHEDRON_H

# include "math_rt.h"
# include "scene.h"

typedef struct s_ray			t_ray;
typedef struct s_colision		t_colision;

typedef struct s_polyhedron		t_polyhedron;
typedef struct s_texture		t_texture;
typedef struct s_material		t_material;
typedef struct s_plane			t_plane;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cone			t_cone;
typedef enum e_polyhedron_type	t_polyhedron_type;
typedef enum e_pattern_type		t_pattern_type;
typedef struct s_pattern		t_pattern;
typedef struct s_checker		t_checker;

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

struct							s_pattern
{
	t_pattern_type				pattern;
	void						*specs;
};

struct							s_checker
{
	t_vector_3d					color_one;
	t_vector_3d					norm_color_one;
	t_vector_3d					color_two;
	t_vector_3d					norm_color_two;
	double						tile;
};

struct							s_texture
{
	void						*img_texture;
	int							w;
	int							h;
	unsigned char				*data;
	int							bpp;
	int							line_len;
	int							endian;
};

struct							s_material
{
	t_vector_3d					albedo;
	t_vector_3d					norm_albedo;
	double						ka;
	double						kd;
	double						ks;
	double						n;
	double						kr;
	char						*pattern_name;
	t_pattern					pattern;
	bool						has_texture_color;
	bool						has_texture_normal;
	t_texture					texture_color;
	t_texture					texture_normal;
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

struct							s_plane
{
	t_point_3d					point;
	t_vector_3d					normal;
};

struct							s_cylinder
{
	t_point_3d					center;
	t_vector_3d					axis;
	double						radius;
	double						radius_sqrd;
	double						height;
	t_plane						cap_top;
	t_plane						cap_bot;
};

struct							s_cone
{
	t_plane						base;
	t_point_3d					vertex;
	t_vector_3d					axis;
	double						radius;
	double						height;
	double						half_apex_angle;
	double						cos_alpha;
	double						tan_alpha;
	double						sin_alpha;
};

void							ft_normal_polyhedron(t_point_3d pt,
									t_polyhedron polyhedron, t_colision *col);

#endif
