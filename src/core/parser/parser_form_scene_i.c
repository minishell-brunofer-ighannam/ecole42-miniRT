/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:26:56 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/07 09:40:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

t_scene	*ft_form_scene(t_linkedlist *input_list)
{
	t_scene				*scene;
	t_linkedlist_node	*node;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->num_light = ft_count_items_scene(input_list->first, "L")
		+ ft_count_items_scene(input_list->first, "l");
	scene->light = ft_calloc(scene->num_light + 1, sizeof(t_light));
	scene->num_polyhedron = ft_count_items_scene(input_list->first, "sp")
		+ ft_count_items_scene(input_list->first, "cy")
		+ ft_count_items_scene(input_list->first, "pl");
	scene->polyhedron = ft_calloc(scene->num_polyhedron + 1,
			sizeof(t_polyhedron));
	node = input_list->first;
	while (node)
	{
		ft_include_items_scene(node, scene);
		node = node->next;
	}
	if (ft_count_items_scene(input_list->first, "B") == 0)
	{
		scene->color_back = ft_new_vector_3d(BACK_COLOR);
		scene->norm_color_back = ft_new_vector_3d((double)scene->color_back.x / 255.0, (double)scene->color_back.y / 255.0, (double)scene->color_back.z / 255.0);
	}
	input_list->destroy(&(input_list), ft_free_content_parser_node);
	scene->destroy = ft_destroy_scene;
	return (scene);
}

void	ft_include_items_scene(t_linkedlist_node *node, t_scene *scene)
{
	t_parser_node	*content;

	content = (t_parser_node *)(node->content);
	if (!ft_strcmp(content->splited_line[0], "C"))
		ft_include_camera(scene, content);
	if (!ft_strcmp(content->splited_line[0], "A"))
		ft_include_ambient(scene, content);
	if (!ft_strcmp(content->splited_line[0], "L")
		|| !ft_strcmp(content->splited_line[0], "l"))
		ft_include_light(scene, content);
	if (!ft_strcmp(content->splited_line[0], "sp"))
		ft_include_sphere(scene, content);
	if (!ft_strcmp(content->splited_line[0], "cy"))
		ft_include_cylinder(scene, content);
	if (!ft_strcmp(content->splited_line[0], "pl"))
		ft_include_plane(scene, content);
	if (!ft_strcmp(content->splited_line[0], "B"))
		ft_include_back_color(scene, content);
}

void	ft_include_camera(t_scene *scene, t_parser_node *content)
{
	t_point_3d	point;
	t_vector_3d	vector;

	scene->camera.horizontal_fov = ft_atod(content->splited_args[3][0]);
	point = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	scene->camera.origin = point;
	vector = ft_new_vector_3d(ft_atod(content->splited_args[2][0]),
			ft_atod(content->splited_args[2][1]),
			ft_atod(content->splited_args[2][2]));
	scene->camera.forward = ft_vector_normalize(vector);
}

void	ft_include_light(t_scene *scene, t_parser_node *content)
{
	t_point_3d	position;
	t_vector_3d	vector_color;
	char		*intensity;

	intensity = content->splited_args[2][0];
	scene->light[scene->count_light].intensity = ft_atod(intensity);
	position = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	scene->light[scene->count_light].coord = position;
	vector_color = ft_new_vector_3d(ft_atoi(content->splited_args[3][0]),
			ft_atoi(content->splited_args[3][1]),
			ft_atoi(content->splited_args[3][2]));
	scene->light[scene->count_light].color = vector_color;
	scene->light[scene->count_light].norm_color = ft_new_vector_3d(vector_color.x
			/ 255.0, vector_color.y / 255.0, vector_color.z / 255.0);
	scene->count_light++;
}

void	ft_include_ambient(t_scene *scene, t_parser_node *content)
{
	t_vector_3d	vector_color;

	scene->ambient.intensity = ft_atod(content->splited_args[1][0]);
	vector_color = ft_new_vector_3d(ft_atoi(content->splited_args[2][0]),
			ft_atoi(content->splited_args[2][1]),
			ft_atoi(content->splited_args[2][2]));
	scene->ambient.color = vector_color;
	scene->ambient.norm_color = ft_new_vector_3d(vector_color.x / 255.0,
			vector_color.y / 255.0, vector_color.z / 255.0);
}
