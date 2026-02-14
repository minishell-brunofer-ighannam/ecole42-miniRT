/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/13 16:54:03 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

void	ft_include_plane(t_scene *scene, t_parser_node *content, t_linkedlist *input_list, t_context *context)
{
	t_plane	*pl;

	pl = ft_calloc(1, sizeof(t_plane));
	pl->point = content->origin;
	pl->normal = content->normal;
	scene->polyhedron[scene->count_polyhedron].type = PLANE;
	scene->polyhedron[scene->count_polyhedron].specs = pl;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content, input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

void	ft_include_back_color(t_scene *scene, t_parser_node *content)
{
	t_vector_3d	color;

	color = ft_new_vec_str(content->splited_args[1]);
	scene->color_back = color;
}
