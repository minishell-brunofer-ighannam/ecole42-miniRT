/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 12:13:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"
#include "scene.h"
#include "light.h"
#include "polyhedron.h"

void	ft_include_plane(t_scene *scene, t_parser_node *content)
{
	t_plane *pl;

	pl = ft_calloc(1, sizeof(t_plane));
	pl->point = ft_new_point(ft_atod(ft_strdup(content->splited_args[1][0])),
			ft_atod(ft_strdup(content->splited_args[1][1])),
			ft_atod(ft_strdup(content->splited_args[1][2])));
	pl->orientation = ft_new_vector_3d(ft_atod(ft_strdup(content->splited_args[2][0])),
			ft_atod(ft_strdup(content->splited_args[2][1])),
			ft_atod(ft_strdup(content->splited_args[2][2])));
	pl->material = ft_form_material_pl(content);
	scene->polyhedron[scene->count_polyhedron].type = PLANE;
	scene->polyhedron[scene->count_polyhedron].specs = pl;
	//incluir função de destroy do pl
	scene->count_polyhedron++;
}

t_material ft_form_material_pl(t_parser_node *content)
{
	t_material material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = ft_new_vector_3d(ft_atoi(ft_strdup(content->splited_args[3][0])),
		ft_atoi(ft_strdup(content->splited_args[3][1])),
		ft_atoi(ft_strdup(content->splited_args[3][2])));
	if (!content->splited_args[4] || !content->splited_args[5]
		|| !content->splited_args[6] || !content->splited_args[7]
		|| !content->splited_args[8])
		return (material);
	if (content->splited_args[4])
		material.ka = ft_atod(ft_strdup(content->splited_args[4][0]));
	if (content->splited_args[5])
		material.kd = ft_atod(ft_strdup(content->splited_args[5][0]));
	if (content->splited_args[6])
		material.ks = ft_atod(ft_strdup(content->splited_args[6][0]));
	if (content->splited_args[7])
		material.n = ft_atod(ft_strdup(content->splited_args[7][0]));
	if (content->splited_args[8])
		material.kr = ft_atod(ft_strdup(content->splited_args[8][0]));
	return (material);
}