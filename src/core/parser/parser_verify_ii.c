/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:30:22 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 18:58:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_material_optional_sp(t_parser_node *content_node)
{
	if ((content_node->splited_args[4]
			&& ft_count_size_splited(content_node->splited_args[4]) != 1
			&& !ft_verify_double_between(content_node->splited_args[4][0], 0, 1,
				1e-6)) || (content_node->splited_args[5]
			&& ft_count_size_splited(content_node->splited_args[5]) != 1
			&& !ft_verify_double_between(content_node->splited_args[5][0], 0, 1,
				1e-6)) || (content_node->splited_args[6]
			&& ft_count_size_splited(content_node->splited_args[6]) != 1
			&& !ft_verify_double_between(content_node->splited_args[6][0], 0, 1,
				1e-6)) || (content_node->splited_args[7]
			&& ft_count_size_splited(content_node->splited_args[7]) != 1
			&& !ft_verify_double_between(content_node->splited_args[7][0], 0, 0,
				0)) || (content_node->splited_args[8]
			&& ft_count_size_splited(content_node->splited_args[8]) != 1
			&& !ft_verify_double_between(content_node->splited_args[8][0], 0, 1,
				1e-6)))
		return (false);
	return (true);
}

bool	ft_verify_cylinder(t_parser_node *content_node)
{
	if (content_node->num_args_line < 6
		|| !ft_verify_coords(content_node->splited_args[1])
		|| !ft_verify_normal_vector(content_node->splited_args[2])
		|| ft_count_size_splited(content_node->splited_args[3]) != 1
		|| !ft_verify_double_between(content_node->splited_args[3][0], 0, 0, 0)
		|| ft_count_size_splited(content_node->splited_args[4]) != 1
		|| !ft_verify_double_between(content_node->splited_args[4][0], 0, 0, 0)
		|| !ft_verify_color(content_node->splited_args[5])
		|| !ft_verify_material_optional_cy(content_node))
		return (false);
	return (true);
}

bool	ft_verify_material_optional_cy(t_parser_node *content_node)
{
	if ((content_node->splited_args[6]
			&& ft_count_size_splited(content_node->splited_args[6]) != 1
			&& !ft_verify_double_between(content_node->splited_args[6][0], 0, 1,
				1e-6)) || (content_node->splited_args[7]
			&& ft_count_size_splited(content_node->splited_args[7]) != 1
			&& !ft_verify_double_between(content_node->splited_args[7][0], 0, 1,
				1e-6)) || (content_node->splited_args[8]
			&& ft_count_size_splited(content_node->splited_args[8]) != 1
			&& !ft_verify_double_between(content_node->splited_args[8][0], 0, 1,
				1e-6)) || (content_node->splited_args[9]
			&& ft_count_size_splited(content_node->splited_args[9]) != 1
			&& !ft_verify_double_between(content_node->splited_args[9][0], 0, 0,
				0)) || (content_node->splited_args[10]
			&& ft_count_size_splited(content_node->splited_args[10]) != 1
			&& !ft_verify_double_between(content_node->splited_args[10][0], 0,
				1, 1e-6)))
		return (false);
	return (true);
}

bool	ft_verify_plane(t_parser_node *content_node)
{
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| !ft_verify_normal_vector(content_node->splited_args[2])
		|| !ft_verify_color(content_node->splited_args[3])
		|| !ft_verify_material_optional_pl(content_node))
		return (false);
	return (true);
}

bool	ft_verify_material_optional_pl(t_parser_node *content_node)
{
	if ((content_node->splited_args[4]
			&& ft_count_size_splited(content_node->splited_args[4]) != 1
			&& !ft_verify_double_between(content_node->splited_args[4][0], 0, 1,
				1e-6)) || (content_node->splited_args[5]
			&& ft_count_size_splited(content_node->splited_args[5]) != 1
			&& !ft_verify_double_between(content_node->splited_args[5][0], 0, 1,
				1e-6)) || (content_node->splited_args[6]
			&& ft_count_size_splited(content_node->splited_args[6]) != 1
			&& !ft_verify_double_between(content_node->splited_args[6][0], 0, 1,
				1e-6)) || (content_node->splited_args[7]
			&& ft_count_size_splited(content_node->splited_args[7]) != 1
			&& !ft_verify_double_between(content_node->splited_args[7][0], 0, 0,
				0)) || (content_node->splited_args[8]
			&& ft_count_size_splited(content_node->splited_args[8]) != 1
			&& !ft_verify_double_between(content_node->splited_args[8][0], 0, 1,
				1e-6)))
		return (false);
	return (true);
}
