/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:38:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/15 11:44:44 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_INTERNAL_H
# define CAMERA_RAY_INTERNAL_H

# include "camera_ray.h"

t_ray	ft_camera_ray(t_mlx *restrict mlx,
			t_camera *restrict camera, int x, int y);

#endif
