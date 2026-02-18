/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:37:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 14:59:40 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# include "colision.h"
# include "context.h"
# include "light.h"
# include "math_rt.h"
# include "ray.h"
# include "scene.h"
# include "threads_bonus.h"
# include <pthread.h>

void	*ft_camera_ray_loop(t_context *context, int start, int end);

#endif