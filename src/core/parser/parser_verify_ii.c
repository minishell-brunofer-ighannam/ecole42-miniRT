/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:30:22 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/06 14:43:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_optional_double(char **arg, double min, double max)
{
	if (!arg)
		return (true);
	if (ft_count_size_splited(arg) != 1)
		return (false);
	return (ft_verify_double_between(arg[0], min, max, 1e-6));
}

bool	ft_verify_cylinder(t_parser_node *content_node)
{
	if (content_node->num_args_line < 6
		|| !ft_verify_coords(content_node->splited_args[1])
		// || !ft_verify_normal_vector(content_node->splited_args[2])
		|| ft_count_size_splited(content_node->splited_args[3]) != 1
		|| !ft_verify_double_between(content_node->splited_args[3][0], 0, 0, 0)
		|| ft_count_size_splited(content_node->splited_args[4]) != 1
		|| !ft_verify_double_between(content_node->splited_args[4][0], 0, 0, 0)
		|| !ft_verify_color(content_node->splited_args[5])
		|| !ft_verify_mat_opt_cy(content_node))
		return (false);
	return (true);
}

bool	ft_verify_mat_opt_cy(t_parser_node *content)
{
	if (!content->splited_args[6] || !content->splited_args[7]
		|| !content->splited_args[8] || !content->splited_args[9]
		|| !content->splited_args[10])
		return (true);
	if (!ft_verify_optional_double(content->splited_args[6], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[7], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[8], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[9], 0, 0)
		|| !ft_verify_optional_double(content->splited_args[10], 0, 1))
		return (false);
	return (true);
}

bool	ft_verify_plane(t_parser_node *content_node)
{
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| !ft_verify_normal_vector(content_node->splited_args[2])
		|| !ft_verify_color(content_node->splited_args[3])
		|| !ft_verify_mat_opt_pl(content_node))
		return (false);
	return (true);
}

bool	ft_verify_mat_opt_pl(t_parser_node *content)
{
	if (!content->splited_args[4] || !content->splited_args[5]
		|| !content->splited_args[6] || !content->splited_args[7]
		|| !content->splited_args[8])
		return (true);
	if (!ft_verify_optional_double(content->splited_args[4], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[5], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[6], 0, 1)
		|| !ft_verify_optional_double(content->splited_args[7], 0, 0)
		|| !ft_verify_optional_double(content->splited_args[8], 0, 1))
		return (false);
	return (true);
}
