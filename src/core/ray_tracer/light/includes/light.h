/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:47:50 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 18:14:13 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "colision.h"
# include "context.h"
# include "light_internal.h"
# include "math_rt.h"
# include "polyhedron.h"
# include "scene.h"

typedef struct s_polyhedron	t_polyhedron;

t_vector_3d					ft_ambient_light(t_context *context,
								t_polyhedron *polyhedron);
t_vector_3d					ft_difuse_light(t_context *context,
								t_colision *col);
t_vector_3d					ft_specular_light(t_context *context,
								t_colision *col);

#endif