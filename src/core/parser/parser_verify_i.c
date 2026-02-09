/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:29:39 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 17:35:52 by ighannam         ###   ########.fr       */
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
	else if (!ft_strcmp(content_node->splited_line[0], "cn"))
		return (ft_verify_cone(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "B"))
		return (ft_verify_back_color(content_node));
	else if (!ft_strcmp(content_node->splited_line[0], "p"))
		return (ft_verify_pattern(content_node));
	return (true);
}

bool	ft_verify_pattern(t_parser_node *content_node)
{
	if (!ft_strcmp(content_node->splited_args[2][0], "CHECKER"))
	{
		if (content_node->num_args_line < 6
			|| !ft_verify_color(content_node->splited_args[3])
			|| !ft_verify_color(content_node->splited_args[4])
			|| !ft_verify_double_between(content_node->splited_args[5][0], 0, 0,
				0))
			return (false);
		content_node->pattern_type = CHECKER;
		content_node->pattern_name = content_node->splited_args[1][0];
		content_node->color_one = ft_new_vec_str(content_node->splited_args[3]);
		content_node->color_two = ft_new_vec_str(content_node->splited_args[4]);
		content_node->tile = ft_atod(content_node->splited_args[5][0]);
		return (true);
	}
	return (false);
}

bool	ft_verify_back_color(t_parser_node *content_node)
{
	if (content_node->num_args_line < 2
		|| !ft_verify_color(content_node->splited_args[1]))
		return (false);
	content_node->color_back = ft_new_vec_str(content_node->splited_args[1]);
	return (true);
}

bool	ft_verify_camera(t_parser_node *content_node)
{
	if (content_node->num_args_line < 4 ||
		!ft_verify_coords(content_node->splited_args[1])
		// || !ft_verify_normal_vector(content_node->splited_args[2])
		|| ft_count_size_splited(content_node->splited_args[3]) != 1
			|| !ft_verify_double_between(content_node->splited_args[3][0], 0,
				180, 1e-6))
		return (false);
	content_node->normal = ft_vec_norm(ft_new_vec_str(content_node->splited_args[2]));
	content_node->origin = ft_new_point_str(content_node->splited_args[1]);
	content_node->fov = ft_atod(content_node->splited_args[3][0]);
	return (true);
}

bool	ft_verify_ambient(t_parser_node *content_node)
{
	if (content_node->num_args_line < 3
		|| ft_count_size_splited(content_node->splited_args[1]) != 1
		|| !ft_verify_double_between(content_node->splited_args[1][0], 0, 1,
			1e-6) || !ft_verify_color(content_node->splited_args[2]))
		return (false);
	content_node->intensity = ft_atod(content_node->splited_args[1][0]);
	content_node->color = ft_new_vec_str(content_node->splited_args[2]);
	return (true);
}
