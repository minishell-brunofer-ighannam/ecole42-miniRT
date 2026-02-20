/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 15:55:05 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# define AA 1

# include "colision.h"
# include "context.h"
# include "light.h"
# include "math_rt.h"
# include "ray.h"
# include "scene.h"
# include "threads_bonus.h"
# include <pthread.h>

int			ft_vector_to_int_color(t_vector_3d color);
t_colision	ft_trace_ray(t_context *context, int x, int y);
void		*ft_camera_ray_loop(t_context *context, int start, int end);

#endif
