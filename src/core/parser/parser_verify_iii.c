/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_iii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:31:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 18:57:28 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_sphere(t_parser_node *content_node)
{
	if (content_node->num_args_line < 4
		|| !ft_verify_coords(content_node->splited_args[1])
		|| ft_count_size_splited(content_node->splited_args[2]) != 1
		|| !ft_verify_double_between(content_node->splited_args[2][0], 0, 0, 0)
		|| !ft_verify_color(content_node->splited_args[3])
		|| !ft_verify_mat_opt_sp(content_node))
		return (false);
	return (true);
}

bool	ft_verify_mat_opt_sp(t_parser_node *content)
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
