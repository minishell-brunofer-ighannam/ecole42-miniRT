/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:41:47 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/04 08:42:20 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "math_rt.h"

typedef struct s_ray t_ray;

struct s_ray
{
    t_point_3d  point;
    t_vector_3d vector;
};


#endif