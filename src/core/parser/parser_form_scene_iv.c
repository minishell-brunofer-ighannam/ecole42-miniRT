/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:21:43 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/25 17:19:34 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

t_pattern	ft_form_pattern(t_parser_node *content)
{
	t_pattern	pattern;
	t_checker	*checker;

	if (!content)
	{
		pattern.pattern = NO_PATTERN;
		return (pattern);
	}
	if (content->pattern_type == CHECKER)
	{
		checker = ft_calloc(1, sizeof(t_checker));
		pattern.pattern = CHECKER;
		checker->color_one = content->color_one;
		checker->norm_color_one = ft_new_vector_3d(content->color_one.x / 255.0,
				content->color_one.y / 255.0, content->color_one.z / 255.0);
		checker->color_two = content->color_two;
		checker->norm_color_two = ft_new_vector_3d(content->color_two.x / 255.0,
				content->color_two.y / 255.0, content->color_two.z / 255.0);
		checker->tile = content->tile;
		pattern.specs = checker;
		return (pattern);
	}
	printf("Pattern type out of scope. No pattern applied.");
	pattern.pattern = NO_PATTERN;
	return (pattern);
}

void	ft_include_pattern(t_linkedlist *input_list, t_material *material)
{
	t_linkedlist_node	*node;

	node = input_list->first;
	if (!material->pattern_name)
	{
		material->pattern = ft_form_pattern(NULL);
		return ;
	}
	while (node)
	{
		if (!ft_strcmp(((t_parser_node *)node->content)->splited_line[0], "p"))
		{
			if (!ft_strcmp(((t_parser_node *)node->content)->pattern_name,
					material->pattern_name))
			{
				material->pattern = ft_form_pattern(
						(t_parser_node *)node->content);
				return ;
			}
		}
		node = node->next;
	}
	printf("Pattern not found. No pattern applied. --> %s\n",
		material->pattern_name);
}
