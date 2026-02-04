/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:22:20 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/04 08:42:48 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "math_rt.h"
# include "libft.h"
#include "scene.h"
#include "colision.h"
#include "camera_ray.h"
#include "ray.h"

t_point_3d ft_ray_at(t_ray ray, double t);


#endif