/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 19:09:18 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "light.h"
# include "polyhedron.h"

typedef struct s_scene	t_scene;

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