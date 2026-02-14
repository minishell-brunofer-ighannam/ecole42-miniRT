/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:26:56 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/13 16:54:49 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

t_scene	*ft_form_scene(t_linkedlist *input_list, t_context *context)
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
		+ ft_count_items_scene(input_list->first, "pl") + ft_count_items_scene(input_list->first, "cn");
	scene->polyhedron = ft_calloc(scene->num_polyhedron + 1,
			sizeof(t_polyhedron));
	node = input_list->first;
	while (node)
	{
		ft_include_items_scene(node, scene, input_list, context);
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

void	ft_include_items_scene(t_linkedlist_node *node, t_scene *scene, t_linkedlist *input_list, t_context *context)
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
		ft_include_sphere(scene, content, input_list, context);
	if (!ft_strcmp(content->splited_line[0], "cy"))
		ft_include_cylinder(scene, content, input_list, context);
	if (!ft_strcmp(content->splited_line[0], "pl"))
		ft_include_plane(scene, content, input_list, context);
	if (!ft_strcmp(content->splited_line[0], "cn"))
		ft_include_cone(scene, content, input_list, context);
	if (!ft_strcmp(content->splited_line[0], "B"))
		ft_include_back_color(scene, content);
}

void	ft_include_camera(t_scene *scene, t_parser_node *content)
{
	scene->camera.horizontal_fov = content->fov;
	scene->camera.origin = content->origin;
	scene->camera.forward = content->normal;
}

void	ft_include_light(t_scene *scene, t_parser_node *content)
{
	scene->light[scene->count_light].intensity = content->intensity;
	scene->light[scene->count_light].coord = content->origin;
	scene->light[scene->count_light].color = content->color;
	scene->light[scene->count_light].norm_color = ft_new_vector_3d(content->color.x
			/ 255.0, content->color.y / 255.0, content->color.z / 255.0);
	scene->count_light++;
}

void	ft_include_ambient(t_scene *scene, t_parser_node *content)
{
	scene->ambient.intensity = content->intensity;
	scene->ambient.color = content->color;
	scene->ambient.norm_color = ft_new_vector_3d(content->color.x / 255.0,
			content->color.y / 255.0, content->color.z / 255.0);
}
