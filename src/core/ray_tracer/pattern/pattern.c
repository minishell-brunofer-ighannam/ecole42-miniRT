/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/11 16:55:50 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "pattern_internal.h"

static void ft_calc_dir_u_v(t_colision *col);

void ft_calc_u_v(t_colision *col)
{
    ft_calc_dir_u_v(col);
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
    t_plane *pl;

    pl = col->polyhedron.specs;
    P = ft_sub_point(col->colision_point, pl->point); 
    col->u = ft_vector_dot_product(P, col->dir_u);
    col->v = ft_vector_dot_product(P, col->dir_v);
}

void ft_calc_u_v_sp(t_colision *col)
{
    col->u = 0.5 + atan2(col->normal.z, col->normal.x) / (2 * M_PI);
    col->v = 0.5 - asin(col->normal.y) / M_PI;
}

static void ft_calc_dir_u_v(t_colision *col)
{
    t_vector_3d A;
    t_vector_3d N;

    if (col->polyhedron.type == PLANE)
        N = col->normal;
    else if (col->polyhedron.type == CYLINDER)
        N = ((t_cylinder *)col->polyhedron.specs)->axis;
    else if (col->polyhedron.type == CONE)
        N = ((t_cone *)col->polyhedron.specs)->axis;
    if (fabs(N.y) < 0.999)
        A = ft_new_vector_3d(0, 1, 0);
    else
        A = ft_new_vector_3d(1, 0, 0);
    col->dir_u = ft_vec_norm(ft_cross_product(A, N));
    col->dir_v = ft_vec_norm(ft_cross_product(N, col->dir_u));    
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
    col->u = 0.5 + atan2(ft_vector_dot_product(R, col->dir_u), ft_vector_dot_product(R, col->dir_v)) / (2 * M_PI);
    col->v = (h + cy->height / 2.0) / cy->height;;
    col->v = fmod(col->v, 1.0);
    if (col->v < 0)
        col->v += 1.0;
    if (col->section >= 1)
    {
        t_vector_3d planar;

        planar = ft_vec_sub(CP,
            ft_vec_mult_scal(cy->axis,
                ft_vector_dot_product(CP, cy->axis)));

        double x = ft_vector_dot_product(planar, col->dir_u);
        double y = ft_vector_dot_product(planar, col->dir_v);

        double angle = atan2(y, x);
        double radius = sqrt(x * x + y * y);

        col->u = 0.5 + angle / (2 * M_PI);
        col->v = radius / cy->radius;
    }
}

void ft_calc_u_v_cn(t_colision *col)
{
    t_vector_3d CP;
    t_cone *cn;
    double h;
    t_vector_3d proj;
    t_vector_3d R;
    
    cn = col->polyhedron.specs;
    CP = ft_sub_point(col->colision_point, cn->vertex);
    h = ft_vector_dot_product(CP, cn->axis);
    proj = ft_vec_mult_scal(cn->axis, h);
    R = ft_vec_norm(ft_vec_sub(CP, proj));
    col->u = 0.5 + atan2(R.z, R.x) / (2 * M_PI);
    col->v = h / cn->height;
    col->v = fmod(col->v, 1.0);
}