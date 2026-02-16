/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:00 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/15 09:23:42 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"
#include "mlx.h"

void	ft_include_sphere(t_scene *scene, t_parser_node *content,
		t_linkedlist *input_list, t_context *context)
{
	t_sphere	*sp;

	sp = ft_calloc(1, sizeof(t_sphere));
	sp->center = content->origin;
	sp->radius = content->radius;
	scene->polyhedron[scene->count_polyhedron].type = SPHERE;
	scene->polyhedron[scene->count_polyhedron].specs = sp;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content,
			input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

t_material	ft_form_material(t_parser_node *content, t_linkedlist *input_list,
		t_context *context)
{
	t_material	material;
	t_texture	texture_color;
	t_texture texture_normal;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = content->color;
	material.norm_albedo = ft_new_vector_3d(content->color.x / 255.0,
			content->color.y / 255.0, content->color.z / 255.0);
	ft_material_values(content, &material);
	ft_include_pattern(input_list, &material);
	if (content->file_texture_color)
	{
		texture_color.img_texture = mlx_xpm_file_to_image(context->mlx.window.mlx_ref,
				content->file_texture_color, &texture_color.w,
				&texture_color.h);
		if (texture_color.img_texture)
		{
			material.has_texture_color = true;
			texture_color.data = (unsigned char *)mlx_get_minilib_layer_addr(texture_color.img_texture,
					&texture_color.bpp, &texture_color.line_len,
					&material.texture_color.endian);
			material.texture_color = texture_color;
		}
	}
	if (content->file_texture_normal)
	{
		texture_normal.img_texture = mlx_xpm_file_to_image(context->mlx.window.mlx_ref,
				content->file_texture_normal, &texture_normal.w,
				&texture_normal.h);
		if (texture_normal.img_texture)
		{
			material.has_texture_normal = true;
			texture_normal.data = (unsigned char *)mlx_get_minilib_layer_addr(texture_normal.img_texture,
					&texture_normal.bpp, &texture_normal.line_len,
					&material.texture_normal.endian);
			material.texture_normal = texture_normal;
		}

	}
	return (material);
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
				material->pattern = ft_form_pattern((t_parser_node *)node->content);
				return ;
			}
		}
		node = node->next;
	}
	printf("Pattern not found. No pattern applied. --> %s\n",
		material->pattern_name);
}

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
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content,
			input_list, context);
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
	cn->cos_alpha = content->cos_half_apex_angle;
	cn->sin_alpha = content->sin_half_apex_angle;
	cn->tan_alpha = content->tan_half_apex_angle;
	scene->polyhedron[scene->count_polyhedron].type = CONE;
	scene->polyhedron[scene->count_polyhedron].specs = cn;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(content,
			input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}
