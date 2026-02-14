/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_iv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:11:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/14 15:43:11 by ighannam         ###   ########.fr       */
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

bool	ft_verify_duplicated_patterns(t_linkedlist *input_list)
{
	t_linkedlist_node	*node_one;
	t_linkedlist_node	*node_two;

	if (!input_list || !input_list->first || !input_list->first->next)
		return (false);
	node_one = input_list->first;
	node_two = input_list->first->next;
	while (node_one && node_two)
	{
		while (node_two)
		{
			if (!ft_strcmp(((t_parser_node *)node_one->content)->splited_line[0],
					"p")
				&& !ft_strcmp(((t_parser_node *)node_two->content)->splited_line[0],
					"p"))
			{
				if (!ft_strcmp(((t_parser_node *)node_one->content)->pattern_name,
						((t_parser_node *)node_two->content)->pattern_name))
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
