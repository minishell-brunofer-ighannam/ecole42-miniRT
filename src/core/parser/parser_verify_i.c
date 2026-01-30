/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:29:39 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 18:52:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_line(char *line, t_linkedlist **input_list)
{
	t_parser_node	*content_node;

	content_node = ft_generate_node(line);
	if (!content_node || !content_node->splited_line
		|| !content_node->splited_args || !content_node->num_args_line)
		return (false);
	(*input_list)->push(*input_list, content_node);
	if (!ft_strcmp(content_node->splited_line[0], "C"))
		return (ft_verify_camera(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "A"))
		return (ft_verify_ambient(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "L")
		|| !ft_strcmp(content_node->splited_line[0], "l"))
		return (ft_verify_light(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "sp"))
		return (ft_verify_sphere(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "pl"))
		return (ft_verify_plane(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "cy"))
		return (ft_verify_cylinder(content_node));
	return (true);
}

bool	ft_verify_camera(t_parser_node *content_node)
{
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| !ft_verify_normal_vector(content_node->splited_args[2])
		|| ft_count_size_splited(content_node->splited_args[3]) != 1
		|| !ft_verify_double_between(content_node->splited_args[3][0], 0, 180,
		1e-6))
		return (false);
	return (true);
}

bool	ft_verify_ambient(t_parser_node *content_node)
{
	if (content_node->num_args_line < 3
		|| ft_count_size_splited(content_node->splited_args[1]) != 1
		|| !ft_verify_double_between(content_node->splited_args[1][0], 0, 1,
		1e-6) || !ft_verify_color(content_node->splited_args[2]))
		return (false);
	return (true);
}

bool	ft_verify_light(t_parser_node *content_node)
{
	if (content_node->num_args_line < 3
		|| !ft_verify_coords(content_node->splited_args[1])
		|| ft_count_size_splited(content_node->splited_args[2]) != 1
		|| !ft_verify_double_between(content_node->splited_args[2][0], 0, 1,
		1e-6))
		return (false);
	if ((content_node->splited_args[3]
			&& ft_count_size_splited(content_node->splited_args[3]) != 3)
		|| (content_node->splited_args[3]
			&& !ft_verify_color(content_node->splited_args[3])))
		return (false);
	return (true);
}
