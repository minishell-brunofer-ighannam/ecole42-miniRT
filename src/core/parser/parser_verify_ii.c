/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:30:22 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 14:37:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_light(t_parser_node *content_node)
{
	if (content_node->num_args_line < 3
		|| !ft_verify_coords(content_node->splited_args[1])
		|| ft_count_size_splited(content_node->splited_args[2]) != 1
		|| !ft_verify_double_between(content_node->splited_args[2][0], 0, 1,
		1e-6))
		return (false);
	content_node->origin = ft_new_point_str(content_node->splited_args[1]);
	content_node->intensity = ft_atod(content_node->splited_args[2][0]);
	if ((content_node->splited_args[3]
			&& ft_count_size_splited(content_node->splited_args[3]) != 3)
		|| (content_node->splited_args[3]
			&& !ft_verify_color(content_node->splited_args[3])))
		return (false);
	if (content_node->splited_args[3])
		content_node->color = ft_new_vec_str(content_node->splited_args[3]);
	return (true);
}

bool	ft_verify_cylinder(t_parser_node *cont)
{
	int	i;

	i = -1;
	while (++i < 5)
		cont->opt_phong[i] = -1;
	if (cont->num_args_line < 6 || !ft_verify_coords(cont->splited_args[1])
		|| !ft_verify_normal_vector(cont->splited_args[2])
		|| ft_count_size_splited(cont->splited_args[3]) != 1
		|| !ft_verify_double_between(cont->splited_args[3][0], 0, 0, 0)
		|| ft_count_size_splited(cont->splited_args[4]) != 1
		|| !ft_verify_double_between(cont->splited_args[4][0], 0, 0, 0)
		|| !ft_verify_color(cont->splited_args[5]) || !ft_verify_mat_opt(cont,
		6, 0))
		return (false);
	cont->color = ft_new_vec_str(cont->splited_args[5]);
	cont->height = ft_atod(cont->splited_args[4][0]);
	cont->origin = ft_new_point_str(cont->splited_args[1]);
	cont->normal = ft_vec_norm(ft_new_vec_str(cont->splited_args[2]));
	cont->radius = ft_atod(cont->splited_args[3][0]) / 2.0;
	return (true);
}

bool	ft_verify_plane(t_parser_node *content_node)
{
	int	i;

	i = -1;
	while (++i < 5)
		content_node->opt_phong[i] = -1;
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| !ft_verify_normal_vector(content_node->splited_args[2])
		|| !ft_verify_color(content_node->splited_args[3])
		|| !ft_verify_mat_opt(content_node, 4, 0))
		return (false);
	content_node->origin = ft_new_point_str(content_node->splited_args[1]);
	content_node->normal = ft_new_vec_str(content_node->splited_args[2]);
	content_node->color = ft_new_vec_str(content_node->splited_args[3]);
	return (true);
}

bool	ft_verify_cone(t_parser_node *cont)
{
	int	i;

	i = -1;
	while (++i < 5)
		cont->opt_phong[i] = -1;
	if (cont->num_args_line < 6 || !ft_verify_coords(cont->splited_args[1])
		|| !ft_verify_normal_vector(cont->splited_args[2])
		|| ft_count_size_splited(cont->splited_args[3]) != 1
		|| !ft_verify_double_between(cont->splited_args[3][0], 0, 0, 0)
		|| ft_count_size_splited(cont->splited_args[4]) != 1
		|| !ft_verify_double_between(cont->splited_args[4][0], 0, 0, 0)
		|| !ft_verify_color(cont->splited_args[5]) || !ft_verify_mat_opt(cont,
			6, 0))
		return (false);
	cont->color = ft_new_vec_str(cont->splited_args[5]);
	cont->height = ft_atod(cont->splited_args[4][0]);
	cont->origin = ft_new_point_str(cont->splited_args[1]);
	cont->normal = ft_vec_norm(ft_new_vec_str(cont->splited_args[2]));
	cont->half_apex_angle = ft_atod(cont->splited_args[3][0]) / 2.0;
	cont->plane_normal = cont->normal;
	cont->plane_point = ft_point_add_vect(cont->origin,
			ft_vec_mult(cont->plane_normal, cont->height));
	return (true);
}

bool	ft_verify_sphere(t_parser_node *content_node)
{
	int	i;

	i = -1;
	while (++i < 5)
		content_node->opt_phong[i] = -1;
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| ft_count_size_splited(content_node->splited_args[2]) != 1
		|| !ft_verify_double_between(content_node->splited_args[2][0], 0, 0, 0)
		|| !ft_verify_color(content_node->splited_args[3])
		|| !ft_verify_mat_opt(content_node, 4, 0))
		return (false);
	content_node->radius = ft_atod(content_node->splited_args[2][0]) / 2.0;
	content_node->origin = ft_new_point_str(content_node->splited_args[1]);
	content_node->color = ft_new_vec_str(content_node->splited_args[3]);
	return (true);
}
