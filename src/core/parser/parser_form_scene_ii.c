/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:00 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 13:11:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

void	ft_include_sphere(t_scene *scene, t_parser_node *content, t_linkedlist *input_list)
{
	t_sphere	*sp;

	sp = ft_calloc(1, sizeof(t_sphere));
	sp->center = content->origin;
	sp->radius = content->radius;
	scene->polyhedron[scene->count_polyhedron].type = SPHERE;
	scene->polyhedron[scene->count_polyhedron].specs = sp;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content, input_list);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

t_material	ft_form_material(t_parser_node *content, t_linkedlist *input_list)
{
	t_material	material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = content->color;
	material.norm_albedo = ft_new_vector_3d(content->color.x / 255.0,
			content->color.y / 255.0, content->color.z / 255.0);
	ft_material_values(content, &material);
	ft_include_pattern(input_list, &material);
	return (material);
}


void ft_include_pattern(t_linkedlist *input_list, t_material *material)
{
	t_linkedlist_node *node;

	node = input_list->first;
	if (!material->pattern_name)
	{
		material->pattern = ft_form_pattern(NULL);
		return ;
	}
	while (node)
	{
		if (!ft_strcmp(((t_parser_node *)node->content)->splited_line[0], "p"))
		{
			if (!ft_strcmp(((t_parser_node *)node->content)->pattern_name, material->pattern_name))
				material->pattern = ft_form_pattern((t_parser_node *)node->content);
		}
		node = node->next;	
	}
	printf("Pattern not found. No pattern applied.");
}

t_pattern ft_form_pattern(t_parser_node *content)
{
	t_pattern pattern;
	t_checker *checker;

	if (!content)
	{
		pattern.pattern = NO_PATTERN;
		return (pattern);
	}
	if (content->pattern_type == CHECKER)
	{
		checker = ft_calloc(1, sizeof(t_checker));
		pattern.pattern = CHECKER;
		checker->color_one = content->color_one;
		checker->color_two = content->color_two;
		checker->tile = content->tile;
		pattern.specs = checker;
		return (pattern);
	}
	printf("Pattern type out of scope. No pattern applied.");
	pattern.pattern = NO_PATTERN;
	return (pattern);
}

void ft_material_values(t_parser_node *content, t_material *material)
{
	material->ka = KA;
	material->kd = KD;
	material->kr = KR;
	material->ks = KS;
	material->n = N;
	if (content->opt_phong[0] != -1)
		material->ka = content->opt_phong[0];
	if (content->opt_phong[1] != -1)
		material->kd = content->opt_phong[1];
	if (content->opt_phong[2] != -1)
		material->ks = content->opt_phong[2];
	if (content->opt_phong[3] != -1)
		material->n = content->opt_phong[3];
	if (content->opt_phong[4] != -1)
		material->kr = content->opt_phong[4];
	if (content->pattern_name)
		material->pattern_name = content->pattern_name;
}

void	ft_include_cylinder(t_scene *scene, t_parser_node *content, t_linkedlist *input_list)
{
	t_cylinder	*cy;

	cy = ft_calloc(1, sizeof(t_cylinder));
	cy->center = content->origin;
	cy->axis = content->normal;
	cy->radius = content->radius;
	cy->height = content->height;
	scene->polyhedron[scene->count_polyhedron].type = CYLINDER;
	scene->polyhedron[scene->count_polyhedron].specs = cy;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content, input_list);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

void ft_include_cone(t_scene *scene, t_parser_node *content, t_linkedlist *input_list)
{
	t_cone *cn;
	t_plane pl;

	cn = ft_calloc(1, sizeof(t_cone));
	cn->axis = content->normal;
	cn->half_apex_angle = content->half_apex_angle;
	cn->height = content->height;
	cn->vertex = content->origin;
	pl.normal = content->plane_normal;
	pl.point = content->plane_point;
	cn->base = pl;
	cn->cos_alpha = content->cos_half_apex_angle;
	scene->polyhedron[scene->count_polyhedron].type = CONE;
	scene->polyhedron[scene->count_polyhedron].specs = cn;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content, input_list);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}
