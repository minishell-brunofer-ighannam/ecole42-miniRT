/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:07:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/13 15:28:23 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

t_scene	*ft_parser(char *file, t_context *context)
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
	scene = ft_form_scene(input_list, context);
	if (!scene)
		return (NULL);
	return (scene);
}

int	ft_open_file(char *file)
{
	int	fd;
	int	len;

	if (!file)
	{
		printf("Error\nError: file name required. Check README.\n");
		return (0);
	}
	len = ft_strlen(file);
	if (len < 4 || file[len - 3] != '.' || file[len - 2] != 'r' || file[len
			- 1] != 't')
	{
		printf("Error\nError: file extension incorrect. Check README.\n");
		return (0);
	}
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
				input_list->destroy(&(input_list), ft_free_content_parser_node);
				get_next_line(-1);
				return (NULL);
			}
		}
		line = ft_remove_newline(get_next_line(fd));
	}
	return (input_list);
}

t_parser_node	*ft_generate_node(char *line)
{
	t_parser_node	*content;
	int				i;

	if (!line)
		return (NULL);
	content = ft_calloc(1, sizeof(t_parser_node));
	content->line = line;
	content->splited_line = ft_split(line, ' ');
	content->num_args_line = ft_count_size_splited(content->splited_line);
	content->splited_args = ft_calloc(content->num_args_line + 1,
			sizeof(char **));
	i = 0;
	while (i < content->num_args_line)
	{
		content->splited_args[i] = ft_split(content->splited_line[i],
				',');
		i++;
	}
	content->splited_args[i] = NULL;
	return (content);
}

void	ft_free_content_parser_node(void *arg)
{
	t_parser_node	*node_content;

	if (!arg)
		return ;
	node_content = (t_parser_node *)(arg);
	free(node_content->line);
	ft_destroy_char_matrix(&(node_content->splited_line));
	ft_destroy_char_tensor(&(node_content->splited_args));
	free(node_content);
}
