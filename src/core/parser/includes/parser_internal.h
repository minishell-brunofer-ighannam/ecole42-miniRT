/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:51 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 14:58:12 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "context.h"
# include "data_structures.h"
# include "math_rt.h"
# include "mlx.h"
# include "parser.h"
# include "scene.h"
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
	t_vector_3d					color;
	t_vector_3d					normal;
	t_point_3d					origin;
	double						height;
	double						opt_phong[5];
	char						*pattern_name;
	t_pattern_type				pattern_type;
	t_vector_3d					color_one;
	t_vector_3d					color_two;
	double						tile;
	t_vector_3d					color_back;
	double						fov;
	double						intensity;
	double						radius;
	double						half_apex_angle;
	double						cos_half_apex_angle;
	double						sin_half_apex_angle;
	double						tan_half_apex_angle;
	t_vector_3d					plane_normal;
	t_point_3d					plane_point;
	char						*file_texture_color;
	char						*file_texture_normal;
};

int							ft_open_file(char *file);
t_linkedlist				*ft_read_file(int fd);
t_parser_node				*ft_generate_node(char *line);
void						ft_free_content_parser_node(void *arg);
int							ft_count_size_splited(char **splited);
bool						ft_verify_double_between(char *str,
								double ref_one, double ref_two,
								double eps);
bool						ft_verify_int_between(char *str, int ref_one,
								int ref_two);

t_scene						*ft_form_scene(t_linkedlist *input_list,
								t_context *context);
void						ft_include_numbers_scene(t_scene *scene,
								t_linkedlist *input_list);
void						ft_include_camera(t_scene *scene,
								t_parser_node *content);
void						ft_include_light(t_scene *scene,
								t_parser_node *content);
void						ft_include_ambient(t_scene *scene,
								t_parser_node *content);
void						ft_include_sphere(t_scene *scene,
								t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);
void						ft_include_cylinder(t_scene *scene,
								t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);
void						ft_include_cone(t_scene *scene,
								t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);
t_material					ft_form_material(t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);
void						ft_include_plane(t_scene *scene,
								t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);

bool						ft_verify_line(char *line,
								t_linkedlist **input_list);
bool						ft_verify_camera(t_parser_node *content_node);
bool						ft_verify_ambient(t_parser_node *content_node);
bool						ft_verify_light(t_parser_node *content_node);
bool						ft_verify_sphere(t_parser_node *content_node);
bool						ft_verify_cylinder(t_parser_node *cont);
bool						ft_verify_plane(t_parser_node *content_node);
bool						ft_verify_cone(t_parser_node *cont);
bool						ft_verify_list_scene(t_linkedlist *input_list);
int							ft_count_items_scene(t_linkedlist_node *node,
								char *type);
bool						ft_verify_color(char **str);
bool						ft_verify_coords(char **str);
bool						ft_verify_normal_vector(char **str);
char						*ft_remove_newline(char *line);
bool						ft_verify_optional_double(char **arg,
								double min, double max);
void						ft_include_items_scene(t_linkedlist_node *node,
								t_scene *scene, t_linkedlist *input_list,
								t_context *context);
void						ft_material_values(t_parser_node *content,
								t_material *material);
void						ft_include_back_color(t_scene *scene,
								t_parser_node *content);
bool						ft_verify_back_color(t_parser_node *content_node);
t_point_3d					ft_new_point_str(char **splited);
t_vector_3d					ft_new_vec_str(char **splited);
bool						ft_verify_pattern(t_parser_node *content_node);
int							ft_verify_opt_item_phong(t_parser_node *content,
								int pos_file, int item);
bool						ft_verify_mat_opt(t_parser_node *content,
								int pos_file, int item);
bool						ft_verify_duplicated_patterns(
								t_linkedlist *input_list,
								t_linkedlist_node *node_one,
								t_linkedlist_node *node_two);
t_material					ft_form_material(t_parser_node *content,
								t_linkedlist *input_list,
								t_context *context);
void						ft_include_pattern(t_linkedlist *input_list,
								t_material *material);
t_pattern					ft_form_pattern(t_parser_node *content);
void						ft_include_color_map(t_parser_node *content,
								t_material *material, t_context *context);
void						ft_include_normal_map(t_parser_node *content,
								t_material *material, t_context *context);
bool						ft_verify_objects(t_parser_node *content_node);

#endif
