/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:29 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/03 17:35:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"


t_point_3d ft_ray_at(t_ray ray, double t)
{
    t_point_3d point;
    t_vector_3d scaled;

    scaled = ft_vector_mult_scalar(ray.vector, t);
    point = ft_point_add_vect(ray.point, scaled);
    return (point);
}
