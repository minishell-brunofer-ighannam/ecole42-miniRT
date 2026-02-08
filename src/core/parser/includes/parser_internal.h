/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:51 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/07 09:28:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "data_structures.h"
# include "math_rt.h"
# include "parser.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_parser_node	t_parser_node;

struct							s_parser_node
{
	char						*line;
	char						**splited_line;
	int							num_args_line;
	char						***splited_args;
};

int								ft_open_file(char *file);
t_linkedlist					*ft_read_file(int fd);
t_parser_node					*ft_generate_node(char *line);
void							ft_free_content_parser_node(void *arg);
int								ft_count_size_splited(char **splited);
bool							ft_verify_double_between(char *str,
									double ref_one, double ref_two, double eps);
bool							ft_verify_int_between(char *str, int ref_one,
									int ref_two);
t_scene							*ft_form_scene(t_linkedlist *input_list);
void							ft_include_camera(t_scene *scene,
									t_parser_node *content);
void							ft_include_light(t_scene *scene,
									t_parser_node *content);
void							ft_include_ambient(t_scene *scene,
									t_parser_node *content);
void							ft_include_sphere(t_scene *scene,
									t_parser_node *content);
t_material						ft_form_material_sp(t_parser_node *content);
void							ft_include_cylinder(t_scene *scene,
									t_parser_node *content);
t_material						ft_form_material_cy(t_parser_node *content);
void							ft_include_plane(t_scene *scene,
									t_parser_node *content);
t_material						ft_form_material_pl(t_parser_node *content);
bool							ft_verify_line(char *line,
									t_linkedlist **input_list);
bool							ft_verify_camera(t_parser_node *content_node);
bool							ft_verify_ambient(t_parser_node *content_node);
bool							ft_verify_light(t_parser_node *content_node);
bool							ft_verify_sphere(t_parser_node *content_node);
bool							ft_verify_mat_opt_sp(t_parser_node *content);
bool							ft_verify_cylinder(t_parser_node *content_node);
bool							ft_verify_mat_opt_cy(t_parser_node *content);
bool							ft_verify_plane(t_parser_node *content_node);
bool							ft_verify_mat_opt_pl(t_parser_node *content);
bool							ft_verify_list_scene(t_linkedlist *input_list);
int								ft_count_items_scene(t_linkedlist_node *node,
									char *type);
bool							ft_verify_color(char **str);
bool							ft_verify_coords(char **str);
bool							ft_verify_normal_vector(char **str);
char							*ft_remove_newline(char *line);
bool							ft_verify_optional_double(char **arg,
									double min, double max);
void							ft_include_items_scene(t_linkedlist_node *node,
									t_scene *scene);
void							ft_include_default_values(t_material *material);
void							ft_include_back_color(t_scene *scene,
									t_parser_node *content);
bool							ft_verify_back_color(t_parser_node *content_node);

#endif
