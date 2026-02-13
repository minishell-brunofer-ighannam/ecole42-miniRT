/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_iii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:31:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/13 20:35:43 by ighannam         ###   ########.fr       */
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

int ft_verify_opt_item_phong(t_parser_node *content, int pos_file, int item)
{
	if (!content->splited_args[pos_file])
		return (0);
	if (item < 3 || item == 4)
	{
		if (!ft_verify_optional_double(content->splited_args[pos_file], 0, 1))
			return (1);
	}
	else if (item == 3)
	{
		if (!ft_verify_optional_double(content->splited_args[pos_file], 0, 500))
			return (1);
	}
	content->opt_phong[item] = ft_atod(content->splited_args[pos_file][0]);
	return (2);
}

bool	ft_verify_mat_opt(t_parser_node *content, int pos_file)
{
	int item;
	int verify;

	item = 0;
	while (item < 5)
	{
		verify = ft_verify_opt_item_phong(content, pos_file, item);
		if (verify == 0)
			return (true);
		else if (verify == 1)
			return (false);
		item++;
		pos_file++;
	}
	if (content->splited_args[pos_file])
	{
		content->pattern_name = content->splited_args[pos_file][0];
		if (content->splited_args[pos_file + 1])
		{
			content->file_texture_color = content->splited_args[pos_file + 1][0];
			if (content->splited_args[pos_file + 2])
				content->file_texture_normal = content->splited_args[pos_file + 2][0];	
		}
	}
	return (true);
}
bool	ft_verify_list_scene(t_linkedlist *input_list)
{
	t_linkedlist_node	*first_node;

	first_node = input_list->first;
	if (ft_count_items_scene(first_node, "C") != 1
		|| ft_count_items_scene(first_node, "L") > 1
		|| ft_count_items_scene(first_node, "A") > 1
		|| ft_count_items_scene(first_node, "B") > 1)
	{
		printf("Error\nError: wrong number of C, L, A or B identified\n");
		input_list->destroy(&input_list, ft_free_content_parser_node);
		return (false);
	}
	if (!ft_verify_duplicated_patterns(input_list))
	{
		printf("Error\nError: duplicated patterns identified\n");
		input_list->destroy(&input_list, ft_free_content_parser_node);
		return (false);
	}
	return (true);
}
