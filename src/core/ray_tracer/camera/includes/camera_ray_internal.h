/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:38:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 15:39:15 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_INTERNAL_H
# define CAMERA_RAY_INTERNAL_H

# include "camera_ray.h"

t_vector_3d	ft_antialiasing(t_context *context, int x, int y);
int			ft_vector_to_int_color(t_vector_3d color);
t_vector_3d	ft_reflexion(t_context *context, int depth, t_ray ray);
t_ray		ft_camera_ray(t_context *context, int x, int y, double aa);
bool		color_pixel(t_context *context, int x, int y, int color);

#endif
