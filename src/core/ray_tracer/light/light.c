/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/06 13:24:56 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vector_3d	ft_difuse_light(t_context *context, t_colision *col)
{
    t_vector_3d color;
    t_vector_3d normal;
    int i;
    t_ray ray;
    t_colision light_col;
    t_vector_3d I_l;
    double fact;
    double dist_to_light;

    color = ft_new_vector_3d(0,0,0);
    normal = ft_normal_polyhedron(col->colision_point, col->polyhedron);
    i = -1;
    ray.point = ft_point_add_vect(col->colision_point, ft_vector_mult_scalar(normal, EPS));
    while (++i < context->scene->num_light)
    {
        dist_to_light = ft_vector_module(ft_sub_point(context->scene->light[i].coord, col->colision_point));
        ray.vector = ft_vector_normalize(ft_sub_point(context->scene->light[i].coord, col->colision_point));
        light_col = ft_closest_colision(context->scene, ray);
        if (light_col.colision && light_col.polyhedron.id != col->polyhedron.id && light_col.t < dist_to_light)
            continue;
        I_l = ft_vector_mult_scalar(context->scene->light[i].norm_color, context->scene->light[i].intensity);
        fact = ft_vector_dot_product(normal, ray.vector);
        if (fact < 0)
            fact = 0;
        color = ft_vector_add_vect(color, ft_vector_mult_scalar(ft_vector_mult_scalar(I_l,col->polyhedron.material.kd), fact));
    }
    return (color);    
}

t_vector_3d	ft_specular_light(t_context *context, t_colision *col)
{
    t_vector_3d I_l;
    t_vector_3d R;
    t_vector_3d V;
    t_vector_3d L;
    t_vector_3d normal;
    t_vector_3d color;
    int i;
    double fact;

    color = ft_new_vector_3d(0,0,0);
    normal = ft_normal_polyhedron(col->colision_point, col->polyhedron);
    V = ft_vector_normalize(ft_sub_point(context->scene->camera.origin, col->colision_point));
    i = -1;
    while (++i < context->scene->num_light)
    {
        L = ft_vector_normalize(ft_sub_point(context->scene->light[i].coord, col->colision_point));
        R = ft_vector_sub_vect(ft_vector_mult_scalar(normal, 2 * ft_vector_dot_product(normal, L)), L);
        fact = ft_vector_dot_product(R, V);
        if (fact < 0)
            fact = 0;
        fact = pow(fact, col->polyhedron.material.n);
        I_l = context->scene->light[i].norm_color;
        color = ft_vector_add_vect(color, ft_vector_mult_scalar(ft_vector_mult_scalar(I_l, col->polyhedron.material.ks), fact));
    }
    return (color);
}
