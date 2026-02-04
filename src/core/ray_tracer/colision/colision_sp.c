/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:31:43 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/03 15:32:13 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

double ft_colision_sp(t_polyhedron *polyhedron, t_ray ray)
{
    t_sphere *sp;
    t_vector_3d oc;
    double half_b;
    double c;

    sp = polyhedron->specs;
    oc = ft_sub_point(ray.point, sp->center);
    half_b = ft_vector_dot_product(ray.vector, oc);
    c = ft_vector_dot_product(oc, oc) - sp->radius * sp->radius;
    return (ft_solve_quadratic_normalized(half_b, c));
}

double ft_solve_quadratic_normalized(double half_b, double c)
{
    double delta;
    double t;

    delta = half_b * half_b - c;
    if (delta < 0.0)
        return (INFINITY);
    delta = ft_sqtr_newton(delta, 1e-6);
    t = (-half_b - delta);
    if (t < EPS)
    {
        t = (-half_b + delta);
        if (t < EPS)
            return (INFINITY);
    }
    return (t);
}