/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/07 17:25:18 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

void	ft_include_plane(t_scene *scene, t_parser_node *content)
{
	t_plane	*pl;

	pl = ft_calloc(1, sizeof(t_plane));
	pl->point = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	pl->normal = ft_new_vector_3d(ft_atod(content->splited_args[2][0]),
			ft_atod(content->splited_args[2][1]),
			ft_atod(content->splited_args[2][2]));
	scene->polyhedron[scene->count_polyhedron].type = PLANE;
	scene->polyhedron[scene->count_polyhedron].specs = pl;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material_pl(content);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

t_material	ft_form_material_pl(t_parser_node *content)
{
	t_material	material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = ft_new_vector_3d(ft_atoi(content->splited_args[3][0]),
			ft_atoi(content->splited_args[3][1]),
			ft_atoi(content->splited_args[3][2]));
	material.norm_albedo = ft_new_vector_3d(material.albedo.x / 255.0,
			material.albedo.y / 255.0, material.albedo.z / 255.0);
	if (!content->splited_args[4] || !content->splited_args[5]
		|| !content->splited_args[6] || !content->splited_args[7]
		|| !content->splited_args[8])
	{
		ft_include_default_values(&material);	
		return (material);
	}
	if (content->splited_args[4])
		material.ka = ft_atod(content->splited_args[4][0]);
	if (content->splited_args[5])
		material.kd = ft_atod(content->splited_args[5][0]);
	if (content->splited_args[6])
		material.ks = ft_atod(content->splited_args[6][0]);
	if (content->splited_args[7])
		material.n = ft_atod(content->splited_args[7][0]);
	if (content->splited_args[8])
		material.kr = ft_atod(content->splited_args[8][0]);
	material.albedo2 = ft_new_vector_3d(0,0,0);
	material.norm_albedo2 = ft_new_vector_3d(0.0,0.0,0.0);
	material.tile_checker = 1;
	return (material);
}

void	ft_include_back_color(t_scene *scene, t_parser_node *content)
{
	t_vector_3d	color;

	color = ft_new_vector_3d(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	scene->color_back = color;
}
