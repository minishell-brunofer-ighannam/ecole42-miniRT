/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rt_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:49:11 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 18:52:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_RT_INTERNAL_H
# define MATH_RT_INTERNAL_H

#include "math_rt.h"

double		ft_vector_dot_product(t_vector_3d *self, t_vector_3d *other);
double		ft_vector_module(t_vector_3d *self);
double		ft_vector_module_squared(t_vector_3d *self);
double		ft_vector_cos_teta(t_vector_3d *self, t_vector_3d *other);
t_vector_3d	ft_vector_sub_vect(t_point_3d *self, t_vector_3d *other);
t_vector_3d	ft_vector_add_vect(t_point_3d *self, t_vector_3d *other);
t_vector_3d	ft_vector_mult_scalar(t_vector_3d *self, double scalar);
t_vector_3d	ft_vector_mult_scalar(t_vector_3d *self, double scalar);
t_vector_3d	ft_vector_div_scalar(t_vector_3d *self, double scalar);
t_vector_3d	ft_vector_normalize(t_vector_3d *self);

#endif