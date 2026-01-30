/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_iv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:11:24 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 19:01:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

bool	ft_verify_list_scene(t_linkedlist *input_list)
{
	t_linkedlist_node	*first_node;

	first_node = input_list->first;
	if (ft_count_items_scene(first_node, "C") != 1
		|| ft_count_items_scene(first_node, "L") > 1
		|| ft_count_items_scene(first_node, "A") > 1)
	{
		printf("Error\nError: wrong number of C, L or A identified\n");
		input_list->destroy(&input_list, ft_free_content_parser_node);
		return (false);
	}
	return (true);
}

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
	return (count);
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
