/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 11:47:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "pattern_internal.h"

void ft_calc_u_v(t_colision *col)
{
    if (col->polyhedron.type == PLANE)
        ft_calc_u_v_pl(col);
    else if (col->polyhedron.type == SPHERE)
        ft_calc_u_v_sp(col);
    else if (col->polyhedron.type == CYLINDER)
        ft_calc_u_v_cy(col);
    else if (col->polyhedron.type == CONE)
        ft_calc_u_v_cn(col);
}

void ft_calc_u_v_pl(t_colision *col)
{
    t_vector_3d P;
    t_vector_3d U;
    t_vector_3d V;
    t_vector_3d A;
    t_plane *pl;

    pl = col->polyhedron.specs;
    P = ft_sub_point(col->colision_point, pl->point);
    if (fabs(col->normal.y) < 0.999)
		A = ft_new_vector_3d(0, 1, 0);
	else
		A = ft_new_vector_3d(1, 0, 0);
    U = ft_vec_norm(ft_cross_product(A, col->normal));
    V = ft_vec_norm(ft_cross_product(col->normal, U));    
    col->u = ft_vector_dot_product(P, U);
    col->v = ft_vector_dot_product(P, V);
}

void ft_calc_u_v_sp(t_colision *col)
{
    col->u = 0.5 + atan2(col->normal.z, col->normal.x) / (2 * M_PI);
    col->v = 0.5 - asin(col->normal.y) / M_PI;
}

void ft_calc_u_v_cy(t_colision *col)
{
    t_vector_3d CP;
    t_cylinder *cy;
    double h;
    t_vector_3d proj;
    t_vector_3d R;
    
    cy = col->polyhedron.specs;
    CP = ft_sub_point(col->colision_point, cy->center);
    h = ft_vector_dot_product(CP, cy->axis);
    proj = ft_vec_mult_scal(cy->axis, h);
    R = ft_vec_norm(ft_vec_sub(CP, proj));
    col->u = 0.5 + atan2(R.z, R.x) / (2 * M_PI);
    col->v = h / cy->height;
    col->v = fmod(col->v, 1.0);
}

void ft_calc_u_v_cn(t_colision *col)
{
    t_vector_3d CP;
    t_cone *cn;
    double h;
    t_vector_3d proj;
    t_vector_3d R;
    double r;
    
    cn = col->polyhedron.specs;
    CP = ft_sub_point(col->colision_point, cn->vertex);
    h = ft_vector_dot_product(CP, cn->axis);
    r = h * tan(cn->half_apex_angle);
    proj = ft_vec_mult_scal(cn->axis, h);
    R = ft_vec_norm(ft_vec_sub(CP, proj));
    col->u = 0.5 + atan2(R.z, R.x) / (2 * M_PI);
    col->v = h / cn->height;
    col->v = fmod(col->v, 1.0);
}