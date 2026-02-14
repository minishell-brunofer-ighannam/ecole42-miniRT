/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/14 15:15:44 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "pattern_internal.h"

static void ft_calc_dir_u_v(t_colision *col);
void ft_calc_u_v_circle(t_colision *col, t_vector_3d CP, t_vector_3d axis, double radius);

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
    col->u_norm = fmod(col->u, 1.0);
    col->v_norm = fmod(col->v, 1.0);
    if (col->u_norm < 0) col->u_norm += 1.0;
    if (col->v_norm < 0) col->v_norm += 1.0;
}

void ft_calc_u_v_sp(t_colision *col)
{
    col->u = 0.5 + atan2(col->normal.z, col->normal.x) / (2 * M_PI);
    col->v = 0.5 - asin(col->normal.y) / M_PI;
    col->u_norm = fmod(col->u, 1.0);
    col->v_norm = fmod(col->v, 1.0);
    if (col->u_norm < 0) col->u_norm += 1.0;
    if (col->v_norm < 0) col->v_norm += 1.0;
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
    col->dir_u = ft_vec_norm(ft_cross(A, N));
    col->dir_v = ft_vec_norm(ft_cross(N, col->dir_u));
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
    h = ft_vec_dot(CP, cy->axis);
    proj = ft_vec_mult(cy->axis, h);
    R = ft_vec_norm(ft_vec_sub(CP, proj));
    col->u = 0.5 + atan2(ft_vec_dot(R, col->dir_u), ft_vec_dot(R, col->dir_v)) / (2 * M_PI);
    col->v = (h + cy->height / 2.0) / cy->height;;
    col->v = fmod(col->v, 1.0);
    if (col->v < 0)
        col->v += 1.0;
    col->u_norm = fmod(col->u, 1.0);
    col->v_norm = fmod(col->v, 1.0);
    if (col->u_norm < 0) col->u_norm += 1.0;
    if (col->v_norm < 0) col->v_norm += 1.0;
    if (col->section >= 1)
        ft_calc_u_v_circle(col, CP, cy->axis, cy->radius);
}

void ft_calc_u_v_circle(t_colision *col, t_vector_3d CP, t_vector_3d axis, double radius)
{
    t_vector_3d planar;
    double angle;
    double radius_pt;
    double x;
    double y;

    planar = ft_vec_sub(CP,ft_vec_mult(axis, ft_vec_dot(CP, axis)));
    x = ft_vec_dot(planar, col->dir_u);
    y = ft_vec_dot(planar, col->dir_v);
    angle = atan2(y, x);
    radius_pt = sqrt(x * x + y * y);
    col->u = 0.5 + angle / (2 * M_PI);
    col->v = radius_pt / radius;
    col->u_norm = fmod(col->u, 1.0);
    col->v_norm = fmod(col->v, 1.0);
    if (col->u_norm < 0) col->u_norm += 1.0;
    if (col->v_norm < 0) col->v_norm += 1.0;
}

void ft_calc_u_v_cn(t_colision *col)
{
    t_vector_3d CP;
    t_cone *cn;
    double h;
    t_vector_3d proj;
    t_vector_3d R;

    cn = col->polyhedron.specs;
    CP = ft_sub_point(col->colision_point, cn->base.point);
    h = ft_vec_dot(CP, cn->axis);
    proj = ft_vec_mult(cn->axis, h);
    R = ft_vec_norm(ft_vec_sub(CP, proj));
    col->u = 0.5 + atan2(ft_vec_dot(R, col->dir_u), ft_vec_dot(R, col->dir_v)) / (2 * M_PI);
    col->v = (h + cn->height / 2.0) / cn->height;;
    col->v = fmod(col->v, 1.0);
    if (col->v < 0)
        col->v += 1.0;
    col->u_norm = fmod(col->u, 1.0);
    col->v_norm = fmod(col->v, 1.0);
    if (col->u_norm < 0) col->u_norm += 1.0;
    if (col->v_norm < 0) col->v_norm += 1.0;
    // if (col->section >= 1)
    //     ft_calc_u_v_circle(col, CP, cn->axis, cn->radius);
}
