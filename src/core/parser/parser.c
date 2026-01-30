/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:07:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/30 12:55:32 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

t_scene	*ft_parser(char *file)
{
	t_scene			*scene;
	int				fd;
	t_linkedlist	*input_list;

	fd = ft_open_file(file);
	if (fd <= 0)
		return (NULL);
	input_list = ft_read_file(fd);
	if (!input_list || !ft_verify_list_scene(input_list))
		return (NULL);
	scene = ft_form_scene(input_list);
	if (!scene)
		return (NULL);
	return (scene);
}

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nError");
		return (0);
	}
	return (fd);
}

t_linkedlist	*ft_read_file(int fd)
{
	char			*line;
	t_linkedlist	*input_list;

	input_list = ft_new_linkedlist();
	line = ft_remove_newline(get_next_line(fd));
	while (line)
	{
		if (!(*line))
			free(line);
		else
		{
			if (!ft_verify_line(line, &input_list))
			{
				printf("Error\nError in line: %s\n", line);
				input_list->destroy(&input_list, ft_free_content_parser_node);
				return (NULL);
			}
		}
		line = ft_remove_newline(get_next_line(fd));
	}
	return (input_list);
}

t_parser_node	*ft_generate_node(char *line)
{
	t_parser_node	*node_content;
	int				i;

	if (!line)
		return (NULL);
	node_content = ft_calloc(1, sizeof(t_parser_node));
	node_content->line = line;
	node_content->splited_line = ft_split(line, ' ');
	node_content->num_args_line = ft_count_size_splited(node_content->splited_line);
	node_content->splited_args = ft_calloc(node_content->num_args_line + 1,
			sizeof(char **));
	i = 0;
	while (i < node_content->num_args_line)
	{
		node_content->splited_args[i] = ft_split(node_content->splited_line[i],
				',');
		i++;
	}
	node_content->splited_args[i] = NULL;
	return (node_content);
}

void	ft_free_content_parser_node(void *arg)
{
	t_parser_node		*node_content;

	if (!arg)
		return ;
	node_content = (t_parser_node *)(arg);
	free(node_content->line);
	ft_destroy_char_matrix(&(node_content->splited_line));
	ft_destroy_char_tensor(&(node_content->splited_args));
	free(node_content);
}
