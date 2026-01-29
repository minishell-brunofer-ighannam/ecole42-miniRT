/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/01/29 18:39:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "math_rt.h"

typedef struct s_camera t_camera;

struct s_camera
{
    t_point_3d position;
    t_vector_3d orientation;
    double horizontal_fov;
};


#endif
