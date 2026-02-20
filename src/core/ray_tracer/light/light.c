/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 18:10:56 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_internal.h"

t_vector_3d	ft_local_color(t_context *context, t_colision col)
{
	t_vector_3d	local_color;
	t_vector_3d	norm_albedo;
	t_vector_3d	norm;

	if (col.polyhedron.material.pattern.pattern == CHECKER
		|| col.polyhedron.material.has_texture_color
		|| col.polyhedron.material.has_texture_normal)
		ft_calc_u_v(&col);
	if (col.polyhedron.material.has_texture_normal)
		ft_update_normal(&col, 0, 0, col.normal);
	norm = col.normal;
	if (ft_vec_dot(norm, col.ray.vector) > 0)
		norm = ft_vec_mult(norm, -1);
	if (col.polyhedron.material.has_texture_color)
		norm_albedo = ft_norm_albedo_map(&col, 0, 0);
	else if (col.polyhedron.material.pattern.pattern == CHECKER)
		norm_albedo = ft_norm_albedo_checker(&col);
	else
		norm_albedo = col.polyhedron.material.norm_albedo;
	local_color = ft_vec_add(ft_ambient_light(context, &col.polyhedron),
			ft_difuse_light(context, &col, -1, norm));
	local_color = ft_component_wise_product(local_color, norm_albedo);
	local_color = ft_vec_add(local_color, ft_specular_light(context, &col, -1,
				norm));
	return (local_color);
}

t_vector_3d	ft_norm_albedo_checker(t_colision *col)
{
	double		tile;
	t_checker	*checker;

	checker = (t_checker *)col->polyhedron.material.pattern.specs;
	tile = checker->tile;
	if (isnan(col->u) || isnan(col->v) || isinf(col->u) || isinf(col->v))
		return (checker->norm_color_one);
	else if (((int)floor(col->u * tile) + (int)floor(col->v * tile)) % 2 == 0)
		return (checker->norm_color_one);
	return (checker->norm_color_two);
}

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron)
{
	t_vector_3d	color;

	color = ft_vec_mult(context->scene->ambient.norm_color,
			context->scene->ambient.intensity);
	color = ft_vec_mult(color, polyhedron->material.ka);
	return (color);
}

t_vector_3d	ft_difuse_light(t_context *context, t_colision *col, int i,
		t_vector_3d normal)
{
	t_ray		ray;
	t_colision	l_col;
	double		fact;
	t_vector_3d	l_dir;

	ray.point = ft_point_add_vect(col->colision_point, ft_vec_mult(normal,
				EPS));
	while (++i < context->scene->num_light)
	{
		l_dir = ft_sub_point(context->scene->light[i].coord, ray.point);
		ray.vector = ft_vec_norm(l_dir);
		l_col = ft_closest_colision(context->scene, &ray);
		if (l_col.colision && l_col.t > EPS && l_col.t < (ft_vec_mod(l_dir)
				+ EPS))
			continue ;
		fact = ft_vec_dot(normal, ray.vector);
		if (fact < 0)
			fact *= -1;
		col->color_dif = ft_vec_add(col->color_dif,
				ft_vec_mult(ft_vec_mult(ft_vec_mult(
							context->scene->light[i].norm_color,
							context->scene->light[i].intensity),
						col->polyhedron.material.kd), fact));
	}
	return (col->color_dif);
}

t_vector_3d	ft_specular_light(t_context *context, t_colision *col, int i,
		t_vector_3d normal)
{
	double		fact;
	t_colision	l_col;
	t_ray		ray;
	t_vector_3d	l_dir;

	ray.point = ft_point_add_vect(col->colision_point, ft_vec_mult(normal,
				EPS));
	while (++i < context->scene->num_light)
	{
		l_dir = ft_sub_point(context->scene->light[i].coord, ray.point);
		ray.vector = ft_vec_norm(l_dir);
		l_col = ft_closest_colision(context->scene, &ray);
		if (l_col.colision && l_col.t > EPS && l_col.t < (ft_vec_mod(l_dir)
				+ EPS))
			continue ;
		fact = ft_vec_dot(normal, ray.vector);
		if (fact <= 0.0)
			continue ;
		fact = pow(fact, col->polyhedron.material.n);
		col->color_spec = ft_vec_add(col->color_spec,
				ft_vec_mult(ft_vec_mult(context->scene->light[i].norm_color,
						col->polyhedron.material.ks), fact));
	}
	return (col->color_spec);
}
