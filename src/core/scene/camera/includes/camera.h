/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 15:12:03 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "context.h"
# include "math_rt.h"
# include "scene.h"

typedef struct s_camera		t_camera;
typedef struct s_context	t_context;

void						ft_camera_init(t_camera *camera,
								t_context *context);

#endif
