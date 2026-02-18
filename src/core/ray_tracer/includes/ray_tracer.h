/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:22:20 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 15:02:18 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "camera_ray.h"
# include "colision.h"
# include "libft.h"
# include "math_rt.h"
# include "ray.h"
# include "scene.h"

t_point_3d	ft_ray_at(t_ray *restrict ray, double t);

#endif
