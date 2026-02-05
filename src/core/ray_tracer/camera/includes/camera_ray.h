/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 11:35:38 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
#define CAMERA_RAY_H

#include "ray.h"
#include "scene.h"
#include "colision.h"
#include "context.h"
#include "threads_bonus.h"
#include "math_rt.h"
#include <pthread.h>


void	*ft_camera_ray_loop(t_context *context, int start, int end);

#endif