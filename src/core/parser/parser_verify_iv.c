/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_iv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:11:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 14:54:30 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

int	ft_count_items_scene(t_linkedlist_node *node, char *type)
{
	t_parser_node	*content;
	int				count;

	count = 0;
	while (node)
	{
		content = (t_parser_node *)(node->content);
		if (!ft_strcmp(type, content->splited_line[0]))
			count++;
		node = node->next;
	}
	printf("%s : %d\n", type, count);
	return (count);
}

bool	ft_verify_duplicated_patterns(t_linkedlist *input_list,
		t_linkedlist_node *node_one, t_linkedlist_node *node_two)
{
	t_parser_node	*p_node_one;
	t_parser_node	*p_node_two;

	if (!input_list || !input_list->first || !input_list->first->next)
		return (false);
	while (node_one && node_two)
	{
		while (node_two)
		{
			p_node_one = (t_parser_node *)node_one->content;
			p_node_two = (t_parser_node *)node_two->content;
			if (!ft_strcmp(p_node_one->splited_line[0], "p")
				&& !ft_strcmp(p_node_two->splited_line[0], "p"))
			{
				if (!ft_strcmp(p_node_one->pattern_name,
						p_node_two->pattern_name))
					return (false);
			}
			node_two = node_two->next;
		}
		node_one = node_one->next;
		if (node_one)
			node_two = node_one->next;
	}
	return (true);
}

bool	ft_verify_color(char **str)
{
	if (ft_count_size_splited(str) != 3 || !ft_verify_int_between(str[0], 0,
			255) || !ft_verify_int_between(str[1], 0, 255)
		|| !ft_verify_int_between(str[2], 0, 255))
		return (false);
	return (true);
}

bool	ft_verify_coords(char **str)
{
	if (ft_count_size_splited(str) != 3 || !ft_verify_double_between(str[0], 0,
			0, 0) || !ft_verify_double_between(str[1], 0, 0, 0)
		|| !ft_verify_double_between(str[2], 0, 0, 0))
		return (false);
	return (true);
}

bool	ft_verify_normal_vector(char **str)
{
	double	x;
	double	y;
	double	z;

	if (ft_count_size_splited(str) != 3 || !ft_verify_double_between(str[0], 0,
			0, 0) || !ft_verify_double_between(str[1], 0, 0, 0)
		|| !ft_verify_double_between(str[2], 0, 0, 0))
		return (false);
	x = ft_atod(str[0]);
	y = ft_atod(str[1]);
	z = ft_atod(str[2]);
	if (!ft_is_normalized_3d_vector(x, y, z, 1e-6))
		return (false);
	return (true);
}
