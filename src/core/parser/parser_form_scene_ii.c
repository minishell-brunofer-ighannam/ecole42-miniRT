/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:00 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 19:04:39 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"
#include "scene.h"
#include "light.h"
#include "polyhedron.h"

void	ft_include_sphere(t_scene **scene, t_parser_node *content)
{
	int i;
	t_sphere *sp;

	i = 0;
	while ((*scene)->polyhedron[i])
		i++;
	sp = ft_calloc(1, sizeof(t_sphere));
	sp->center = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	sp->radius = ft_atod(content->splited_args[2][0]) / 2.0;
	sp->material = ft_form_material_sp(content);
	(*scene)->polyhedron[i]->type = SPHERE;
	(*scene)->polyhedron[i]->specs = sp;
	//incluir função de destroy no sp
}

t_material ft_form_material_sp(t_parser_node *content)
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

void	ft_include_cylinder(t_scene **scene, t_parser_node *content)
{
	int i;
	t_cylinder *cy;

	i = 0;
	while ((*scene)->polyhedron[i])
		i++;
	cy = ft_calloc(1, sizeof(t_sphere));
	cy->center = ft_new_point(ft_atod(content->splited_args[1][0]),
			ft_atod(content->splited_args[1][1]),
			ft_atod(content->splited_args[1][2]));
	cy->orientation = ft_new_vector_3d(ft_atod(content->splited_args[2][0]),
			ft_atod(content->splited_args[2][1]),
			ft_atod(content->splited_args[2][2]));
	cy->radius = ft_atod(content->splited_args[3][0]) / 2.0;
	cy->height = ft_atod(content->splited_args[4][0]);
	cy->material = ft_form_material_cy(content);
	(*scene)->polyhedron[i]->type = CYLINDER;
	(*scene)->polyhedron[i]->specs = cy;
	//incluir função de destroy do cy
}

t_material ft_form_material_cy(t_parser_node *content)
{
	t_material material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = ft_new_vector_3d(ft_atoi(content->splited_args[5][0]),
		ft_atoi(content->splited_args[5][1]),
		ft_atoi(content->splited_args[5][2]));
	if (content->splited_args[6])
		material.ka = ft_atod(content->splited_args[6][0]);
	if (content->splited_args[7])
		material.kd = ft_atod(content->splited_args[7][0]);
	if (content->splited_args[8])
		material.ks = ft_atod(content->splited_args[8][0]);
	if (content->splited_args[9])
		material.n = ft_atod(content->splited_args[9][0]);
	if (content->splited_args[10])
		material.kr = ft_atod(content->splited_args[10][0]);
	return (material);
}
