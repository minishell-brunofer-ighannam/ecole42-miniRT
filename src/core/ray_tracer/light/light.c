/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/08 08:49:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

// static t_vector_3d	ft_checker_color_pl(t_colision col);

t_vector_3d	ft_local_color(t_context *context, t_colision col)
{
	t_vector_3d	local_color;
	t_vector_3d	norm_albedo;

	norm_albedo = col.polyhedron.material.norm_albedo;
	// if (col.polyhedron.material.checker)
	// 	norm_albedo = ft_checker_color(col);
	//norm_albedo = ft_checker_color_pl(col);
	local_color = ft_vector_add_vect(ft_ambient_light(context, &col.polyhedron),
			ft_difuse_light(context, &col, -1));
	local_color = ft_component_wise_product(local_color, norm_albedo);
	local_color = ft_vector_add_vect(local_color, ft_specular_light(context,
				&col, -1));
	return (local_color);
}

// static t_vector_3d	ft_checker_color_pl(t_colision col)
// {
// 	t_vector_3d	A;
// 	t_vector_3d	P;
// 	double		u;
// 	double		v;
// 	double		tile;

// 	if (col.polyhedron.type != PLANE)
// 		return (col.polyhedron.material.norm_albedo);
// 	tile = col.polyhedron.material.tile_checker;
// 	P = ft_sub_point(col.colision_point,
// 			((t_plane *)col.polyhedron.specs)->point);
// 	if (fabs(col.normal.y) < 0.999)
// 		A = ft_new_vector_3d(0, 1, 0);
// 	else
// 		A = ft_new_vector_3d(1, 0, 0);
// 	u = ft_vector_dot_product(P, ft_vector_normalize(ft_cross_product(A,
// 					col.normal)));
// 	v = ft_vector_dot_product(P, ft_cross_product(col.normal,
// 				ft_vector_normalize(ft_cross_product(A, col.normal))));
// 	if (((int)floor(u / tile) + (int)floor(v / tile)) % 2 == 0)
// 		return (col.polyhedron.material.norm_albedo);
// 	return (col.polyhedron.material.norm_albedo2);
// }

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron)
{
	t_vector_3d	color;

	color = ft_vector_mult_scalar(context->scene->ambient.norm_color,
			context->scene->ambient.intensity);
	color = ft_vector_mult_scalar(color, polyhedron->material.ka);
	return (color);
}

t_vector_3d	ft_difuse_light(t_context *context, t_colision *col, int i)
{
	t_ray		ray;
	t_colision	light_col;
	double		fact;

	ray.point = ft_point_add_vect(col->colision_point,
			ft_vector_mult_scalar(col->normal, EPS));
	while (++i < context->scene->num_light)
	{
		ray.vector = ft_vector_normalize(ft_sub_point(context->scene->light[i].coord,
					col->colision_point));
		light_col = ft_closest_colision(context->scene, ray);
		if (light_col.colision && light_col.polyhedron.id != col->polyhedron.id
			&& light_col.t < ft_vector_module(ft_sub_point(context->scene->light[i].coord,
					col->colision_point)))
			continue ;
		fact = ft_vector_dot_product(col->normal, ray.vector);
		if (fact < 0)
			fact = 0;
		col->color_dif = ft_vector_add_vect(col->color_dif,
				ft_vector_mult_scalar(ft_vector_mult_scalar(ft_vector_mult_scalar(context->scene->light[i].norm_color,
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

	V = ft_vector_normalize(ft_sub_point(context->scene->camera.origin,
				col->colision_point));
	while (++i < context->scene->num_light)
	{
		L = ft_vector_normalize(ft_sub_point(context->scene->light[i].coord,
					col->colision_point));
		R = ft_vector_sub_vect(ft_vector_mult_scalar(col->normal, 2
					* ft_vector_dot_product(col->normal, L)), L);
		fact = ft_vector_dot_product(R, V);
		if (fact < 0)
			fact = 0;
		fact = pow(fact, col->polyhedron.material.n);
		I_l = context->scene->light[i].norm_color;
		col->color_spec = ft_vector_add_vect(col->color_spec,
				ft_vector_mult_scalar(ft_vector_mult_scalar(I_l,
						col->polyhedron.material.ks), fact));
	}
	return (col->color_spec);
}
