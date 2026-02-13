/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/13 20:44:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vector_3d	ft_local_color(t_context *context, t_colision col)
{
	t_vector_3d	local_color;
	t_vector_3d	norm_albedo;
	double		tile;
	unsigned char *pixel;
	int x;
	int y;

	if (col.polyhedron.material.pattern.pattern == CHECKER)
	{
		tile = ((t_checker *)col.polyhedron.material.pattern.specs)->tile;
		ft_calc_u_v(&col);
		if (isnan(col.u) || isnan(col.v) || isinf(col.u) || isinf(col.v))
			norm_albedo = ((t_checker *)col.polyhedron.material.pattern.specs)->norm_color_one;
		else if (((int)floor(col.u * tile) + (int)floor(col.v * tile)) % 2 == 0)
			norm_albedo = ((t_checker *)col.polyhedron.material.pattern.specs)->norm_color_one;
		else
			norm_albedo = ((t_checker *)col.polyhedron.material.pattern.specs)->norm_color_two;
	}
	else
		norm_albedo = col.polyhedron.material.norm_albedo;
	if (col.polyhedron.material.has_texture_color)
	{
		x = col.u * (col.polyhedron.material.texture_color.w - 1);
		y = col.v * (col.polyhedron.material.texture_color.h - 1);
		pixel = col.polyhedron.material.texture_color.data + (y *col.polyhedron.material.texture_color.line_len + x * (col.polyhedron.material.texture_color.bpp / 8));
		int blue  = pixel[0];
		int green = pixel[1];
		int red   = pixel[2];
		double r = red / 255.0;
		double g = green / 255.0;
		double b = blue / 255.0;
		norm_albedo = ft_new_vector_3d(r, g, b);
	}
	if (col.polyhedron.material.has_texture_normal)
	{
		x = col.u * (col.polyhedron.material.texture_color.w - 1);
		y = col.v * (col.polyhedron.material.texture_color.h - 1);
		pixel = col.polyhedron.material.texture_color.data + (y *col.polyhedron.material.texture_color.line_len + x * (col.polyhedron.material.texture_color.bpp / 8));
		int blue  = pixel[0];
		int green = pixel[1];
		int red   = pixel[2];
		double r = (red / 255.0) * 2.0 - 1;
		double g = (green / 255.0) * 2.0 - 1;
		double b = (blue / 255.0) * 2.0 - 1;
		t_vector_3d T = ft_vec_norm(ft_cross_product(ft_new_vector_3d(0,1,0), col.normal));
		if (ft_vec_mod)
		{
			/* code */
		}
		
	}
	
	local_color = ft_vec_add(ft_ambient_light(context, &col.polyhedron),
			ft_difuse_light(context, &col, -1));
	local_color = ft_component_wise_product(local_color, norm_albedo);
	local_color = ft_vec_add(local_color, ft_specular_light(context, &col, -1));
	//local_color = ft_vec_mult_scal(local_color, 100);
	return (local_color);
}

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron)
{
	t_vector_3d	color;

	color = ft_vec_mult_scal(context->scene->ambient.norm_color,
			context->scene->ambient.intensity);
	color = ft_vec_mult_scal(color, polyhedron->material.ka);
	return (color);
}

t_vector_3d	ft_difuse_light(t_context *context, t_colision *col, int i)
{
	t_ray		ray;
	t_colision	light_col;
	double		fact;
	t_vector_3d light_dir;
	double light_dist;

	ray.point = ft_point_add_vect(col->colision_point,
			ft_vec_mult_scal(col->normal, EPS));
	while (++i < context->scene->num_light)
	{
		light_dir = ft_sub_point(context->scene->light[i].coord,
					ray.point);
		ray.vector = ft_vec_norm(light_dir);
		light_dist = ft_vec_mod(light_dir);
		light_col = ft_closest_colision(context->scene, &ray);
		if (light_col.colision && light_col.polyhedron.id == col->polyhedron.id && light_col.section != col->section && light_col.t > EPS && light_col.t < light_dist)
			continue;
		fact = ft_vector_dot_product(col->normal, ray.vector);
		if (fact < 0)
			fact *= -1;
		col->color_dif = ft_vec_add(col->color_dif,
				ft_vec_mult_scal(ft_vec_mult_scal(ft_vec_mult_scal(context->scene->light[i].norm_color,
							context->scene->light[i].intensity),
						col->polyhedron.material.kd), fact));
	}
	return (col->color_dif);
}

t_vector_3d	ft_specular_light(t_context *context, t_colision *col, int i)
{
	t_vector_3d	I_l;
	t_vector_3d	R;
	t_vector_3d	V;
	t_vector_3d	L;
	double		fact;
	t_colision	light_col;
	t_ray		ray;
	t_vector_3d light_dir;
	double light_dist;

	V = ft_vec_norm(ft_sub_point(context->scene->camera.origin,
				col->colision_point));
	ray.point = ft_point_add_vect(col->colision_point,
			ft_vec_mult_scal(col->normal, EPS));
	while (++i < context->scene->num_light)
	{
		light_dir = ft_sub_point(context->scene->light[i].coord,
					ray.point);
		ray.vector = ft_vec_norm(light_dir);
		
		light_dist = ft_vec_mod(light_dir);
		light_col = ft_closest_colision(context->scene, &ray);
		if (light_col.colision && light_col.polyhedron.id == col->polyhedron.id && light_col.section != col->section && light_col.t > EPS && light_col.t < light_dist)
			continue;
		L = ray.vector;
		R = ft_vec_sub(ft_vec_mult_scal(col->normal, 2
					* ft_vector_dot_product(col->normal, L)), L);
		fact = ft_vector_dot_product(R, V);
		if (fact < 0)
			fact *= -1;
		fact = pow(fact, col->polyhedron.material.n);
		I_l = context->scene->light[i].norm_color;
		col->color_spec = ft_vec_add(col->color_spec,
				ft_vec_mult_scal(ft_vec_mult_scal(I_l,
						col->polyhedron.material.ks), fact));
	}
	return (col->color_spec);
}
