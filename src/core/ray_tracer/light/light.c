/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/14 10:20:23 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vector_3d	ft_local_color(t_context *context, t_colision col)
{
	t_vector_3d	local_color;
	t_vector_3d	norm_albedo;
	double		tile;

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
	local_color = ft_vec_add(ft_ambient_light(context, &col.polyhedron),
			ft_difuse_light(context, &col, -1));
	local_color = ft_component_wise_product(local_color, norm_albedo);
	local_color = ft_vec_add(local_color, ft_specular_light(context, &col, -1));
	//local_color = ft_vec_mult(local_color, 100);
	return (local_color);
}

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron)
{
	t_vector_3d	color;

	color = ft_vec_mult(context->scene->ambient.norm_color,
			context->scene->ambient.intensity);
	color = ft_vec_mult(color, polyhedron->material.ka);
	return (color);
}

t_vector_3d	ft_difuse_light(t_context *context, t_colision *col, int i)
{
	t_ray		ray;
	t_colision	light_col;
	double		fact;

	ray.point = ft_point_add_vect(col->colision_point,
			ft_vec_mult(col->normal, EPS));
	while (++i < context->scene->num_light)
	{
		ray.vector = ft_vec_norm(ft_vec_norm(ft_sub_point(context->scene->light[i].coord,
					col->colision_point)));
		light_col = ft_closest_colision(context->scene, &ray);
		// if (light_col.colision && light_col.t > EPS && light_col.t < ft_vec_mod(ray.vector))
    	// 	continue;
		fact = ft_vec_dot(col->normal, ray.vector);
		if (fact < 0)
			fact *= -1;

		// fact = fmax(0.0, fact);

		col->color_dif = ft_vec_add(col->color_dif,
				ft_vec_mult(ft_vec_mult(ft_vec_mult(context->scene->light[i].norm_color,
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

	V = ft_vec_norm(ft_sub_point(context->scene->camera.origin,
				col->colision_point));
	while (++i < context->scene->num_light)
	{
		L = ft_vec_norm(ft_sub_point(context->scene->light[i].coord,
					col->colision_point));
		R = ft_vec_sub(ft_vec_mult(col->normal, 2
					* ft_vec_dot(col->normal, L)), L);
		fact = ft_vec_dot(R, V);
		if (fact < 0)
			fact *= -1;
		fact = pow(fact, col->polyhedron.material.n);
		I_l = context->scene->light[i].norm_color;
		col->color_spec = ft_vec_add(col->color_spec,
				ft_vec_mult(ft_vec_mult(I_l,
						col->polyhedron.material.ks), fact));
	}
	return (col->color_spec);
}
