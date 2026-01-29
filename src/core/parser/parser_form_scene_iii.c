/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 19:04:46 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"
#include "scene.h"
#include "light.h"
#include "polyhedron.h"

void	ft_include_plane(t_scene **scene, t_parser_node *content)
{
	int i;
	t_cylinder *pl;

	i = 0;
	while ((*scene)->polyhedron[i])
		i++;
	pl = ft_calloc(1, sizeof(t_sphere));
	pl->center = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	pl->orientation = ft_new_vector_3d(ft_atod(content->splited_args[2][0]),
			ft_atod(content->splited_args[2][1]),
			ft_atod(content->splited_args[2][2]));
	pl->material = ft_form_material_pl(content);
	(*scene)->polyhedron[i]->type = PLANE;
	(*scene)->polyhedron[i]->specs = pl;
	//incluir função de destroy do pl
}

t_material ft_form_material_pl(t_parser_node *content)
{
	t_material material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = ft_new_vector_3d(ft_atoi(content->splited_args[3][0]),
		ft_atoi(content->splited_args[3][1]),
		ft_atoi(content->splited_args[3][2]));
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
	return (material);
}