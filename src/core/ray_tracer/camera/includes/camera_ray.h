/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/15 11:56:37 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# include "ray.h"
# include "scene.h"
# include "colision.h"
# include "context.h"
# include "threads_bonus.h"
# include "math_rt.h"
# include <pthread.h>

t_colision	ft_trace_ray(t_scene *scene, t_mlx *mlx, int x, int y);
void		*ft_camera_ray_loop(t_context *context, int start, int end);

#endif
