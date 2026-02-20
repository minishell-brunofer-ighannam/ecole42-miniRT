/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 18:15:29 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# define AA 1

# include "ray.h"
# include "scene.h"
# include "colision.h"
# include "context.h"
# include "threads_bonus.h"
# include "math_rt.h"
# include "light.h"
# include <pthread.h>

int			ft_vector_to_int_color(t_vector_3d color);
t_colision	ft_trace_ray(t_context *context, int x, int y);
void		*ft_camera_ray_loop(t_context *context, int start, int end);

#endif
