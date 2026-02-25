/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_form_scene_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:00 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 15:48:35 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "mlx.h"
#include "parser.h"
#include "parser_internal.h"
#include "polyhedron.h"
#include "scene.h"

void	ft_include_ambient(t_scene *scene, t_parser_node *content)
{
	scene->ambient.intensity = content->intensity;
	scene->ambient.color = content->color;
	scene->ambient.norm_color = ft_new_vector_3d(content->color.x / 255.0,
			content->color.y / 255.0, content->color.z / 255.0);
}

void	ft_include_sphere(t_scene *scene, t_parser_node *content,
		t_linkedlist *input_list, t_context *context)
{
	t_sphere	*sp;

	sp = ft_calloc(1, sizeof(t_sphere));
	sp->center = content->origin;
	sp->radius = content->radius;
	scene->polyhedron[scene->count_polyhedron].type = SPHERE;
	scene->polyhedron[scene->count_polyhedron].specs = sp;
	scene->polyhedron[scene->count_polyhedron].material = ft_form_material(
			content, input_list, context);
	scene->polyhedron[scene->count_polyhedron].id = scene->count_polyhedron;
	scene->count_polyhedron++;
}

t_material	ft_form_material(t_parser_node *content, t_linkedlist *input_list,
		t_context *context)
{
	t_material	material;

	ft_bzero(&material, sizeof(t_material));
	material.albedo = content->color;
	material.norm_albedo = ft_new_vector_3d(content->color.x / 255.0,
			content->color.y / 255.0, content->color.z / 255.0);
	ft_material_values(content, &material);
	ft_include_pattern(input_list, &material);
	if (content->file_texture_color)
		ft_include_color_map(content, &material, context);
	if (content->file_texture_normal)
		ft_include_normal_map(content, &material, context);
	return (material);
}

void	ft_include_color_map(t_parser_node *content, t_material *material,
		t_context *context)
{
	t_texture	texture_color;

	texture_color.img_texture = mlx_xpm_file_to_image(
			context->mlx.window.mlx_ref,
			content->file_texture_color, &texture_color.w, &texture_color.h);
	if (texture_color.img_texture)
	{
		material->has_texture_color = true;
		texture_color.data = (unsigned char *)mlx_get_minilib_layer_addr(
				texture_color.img_texture,
				&texture_color.bpp, &texture_color.line_len,
				&material->texture_color.endian);
		material->texture_color = texture_color;
	}
	else
		printf("Color map \"%s\" not found. Color map not applied.\n",
			content->file_texture_color);
}

void	ft_include_normal_map(t_parser_node *content, t_material *material,
		t_context *context)
{
	t_texture	texture_normal;

	texture_normal.img_texture = mlx_xpm_file_to_image(
			context->mlx.window.mlx_ref,
			content->file_texture_normal,
			&texture_normal.w, &texture_normal.h);
	if (texture_normal.img_texture)
	{
		material->has_texture_normal = true;
		texture_normal.data = (unsigned char *)mlx_get_minilib_layer_addr(
				texture_normal.img_texture,
				&texture_normal.bpp, &texture_normal.line_len,
				&material->texture_normal.endian);
		material->texture_normal = texture_normal;
	}
	else
		printf("Normal map \"%s\" not found. Normal map not applied.\n",
			content->file_texture_normal);
}
