/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyhedron.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:08:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 17:19:44 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "math_rt.h"

typedef struct s_polyhedron t_polyhedron;
typedef struct s_material t_material;
typedef struct s_plane t_plane;
typedef struct s_sphere t_sphere;
typedef struct s_cylinder t_cylinder;
typedef enum e_polyhedron_type t_polyhedron_type;

enum e_polyhedron_type
{
    PLANE,
    SPHERE,
    CYLINDER
};

struct s_polyhedron
{
    t_polyhedron_type type;
    void *specs;
};

struct s_material
{
    t_vector_3d albedo;
    double ka; //coeficiente ambiente do material - entre 0 e 1
    double kd; //coeficiente difuso do material - entre 0 e 1
    double ks; //coeficiente especular - entre 0 e 1
    double n; //shininess
    double kr; //coeficiente de reflexão - entre 0 e 1
};

struct s_sphere
{
    t_point_3d center;
    double radius;
    t_material material;
};

struct s_cylinder
{
    t_point_3d center;
    t_vector_3d orientation;
    double radius;
    double height;
    t_material material;
};

struct s_plane
{
    t_point_3d point;
    t_vector_3d orientation;
    t_material material;
};


#endif