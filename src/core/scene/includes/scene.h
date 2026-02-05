/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 17:38:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "polyhedron.h"

#define WIDTH 500
#define HEIGHT 500

typedef struct s_polyhedron		t_polyhedron;
typedef struct s_light t_light;
typedef struct s_ambient t_ambient;
typedef struct s_scene	t_scene;
typedef struct s_camera t_camera;

struct s_camera
{
    t_point_3d origin;
    t_vector_3d forward;
    double horizontal_fov;
    t_vector_3d right;
    t_vector_3d up;
    double scale;
    double aspect;
};

struct s_light
{
    t_point_3d coord;
    double intensity;
    t_vector_3d color;
    t_vector_3d norm_color;
};

struct s_ambient
{
    double intensity;
    t_vector_3d color;
    t_vector_3d norm_color;    
};

struct					s_scene
{
	t_camera			camera;
	t_ambient			ambient;
	t_light				*light;
	int					num_light;
	t_polyhedron		*polyhedron;
	int					num_polyhedron;
	int					count_polyhedron;
	int					count_light;
	void				(*destroy)(t_scene *self);
};



void					ft_print_scene(t_scene *scene);
void					ft_destroy_scene(t_scene *scene);

#endif