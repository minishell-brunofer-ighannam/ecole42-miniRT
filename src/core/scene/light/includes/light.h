/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:47:50 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 17:41:02 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H

#include "light_internal.h"
#include "math_rt.h"


typedef struct s_light t_light;
typedef struct s_ambient t_ambient;

struct s_light
{
    t_point_3d coord;
    double intensity;
    t_vector_3d color;
};

struct s_ambient
{
    double intensity;
    t_vector_3d color;    
};


#endif