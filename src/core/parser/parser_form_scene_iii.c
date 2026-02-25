/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_iii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 12:51:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

void	ft_include_plane(t_scene *scene, t_parser_node *content,
		t_linkedlist *input_list, t_context *context)
{
	t_plane	*pl;

	pl = ft_calloc(1, sizeof(t_plane));
	pl->point = content->origin;
	pl->normal = content->normal;
	scene->polyhedron[scene->count_polyhedron].type = PLANE;
	scene->polyhedron[scene->count_polyhedron].specs = pl;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(
			content, input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

void	ft_include_back_color(t_scene *scene, t_parser_node *content)
{
	t_vector_3d	color;

	color = ft_new_vec_str(content->splited_args[1]);
	scene->color_back = color;
	scene->norm_color_back = ft_new_vector_3d((double)scene->color_back.x
			/ 255.0, (double)scene->color_back.y / 255.0,
			(double)scene->color_back.z / 255.0);
}

void	ft_material_values(t_parser_node *content, t_material *material)
{
	material->ka = KA;
	material->kd = KD;
	material->kr = KR;
	material->ks = KS;
	material->n = N;
	if (content->opt_phong[0] != -1)
		material->ka = content->opt_phong[0];
	if (content->opt_phong[1] != -1)
		material->kd = content->opt_phong[1];
	if (content->opt_phong[2] != -1)
		material->ks = content->opt_phong[2];
	if (content->opt_phong[3] != -1)
		material->n = content->opt_phong[3];
	if (content->opt_phong[4] != -1)
		material->kr = content->opt_phong[4];
	if (content->pattern_name)
		material->pattern_name = content->pattern_name;
}

void	ft_include_cylinder(t_scene *scene, t_parser_node *content,
		t_linkedlist *input_list, t_context *context)
{
	t_cylinder	*cy;
	t_plane		cap_top;
	t_plane		cap_bot;

	cy = ft_calloc(1, sizeof(t_cylinder));
	cy->center = content->origin;
	cy->axis = content->normal;
	cy->radius = content->radius;
	cy->radius_sqrd = cy->radius * cy->radius;
	cy->height = content->height;
	cap_top.normal = cy->axis;
	cap_top.point = ft_point_add_vect(cy->center, ft_vec_mult(cy->axis,
				cy->height / 2.0));
	cap_bot.point = ft_point_add_vect(cy->center, ft_vec_mult(cy->axis,
				-cy->height / 2.0));
	cap_bot.normal = ft_vec_mult(cy->axis, -1.0);
	cy->cap_top = cap_top;
	cy->cap_bot = cap_bot;
	scene->polyhedron[scene->count_polyhedron].type = CYLINDER;
	scene->polyhedron[scene->count_polyhedron].specs = cy;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(
			content, input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

void	ft_include_cone(t_scene *scene, t_parser_node *content,
		t_linkedlist *input_list, t_context *context)
{
	t_cone	*cn;
	t_plane	pl;

	cn = ft_calloc(1, sizeof(t_cone));
	cn->axis = content->normal;
	cn->half_apex_angle = content->half_apex_angle;
	cn->height = content->height;
	cn->vertex = content->origin;
	pl.normal = content->plane_normal;
	pl.point = content->plane_point;
	cn->base = pl;
	cn->cos_alpha = cos(content->half_apex_angle * (M_PI / 180));
	cn->sin_alpha = sin(content->half_apex_angle * (M_PI / 180));
	cn->tan_alpha = tan(content->half_apex_angle * (M_PI / 180));
	cn->radius = cn->tan_alpha * cn->height;
	scene->polyhedron[scene->count_polyhedron].type = CONE;
	scene->polyhedron[scene->count_polyhedron].specs = cn;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(
			content, input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}
