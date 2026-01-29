/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:49:07 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 18:48:39 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_RT_H
# define MATH_RT_H

# include <stdbool.h>
# include <stdio.h>

typedef struct s_point_3d			t_point_3d;
typedef struct s_vector_3d_methods	t_vector_3d_methods;
typedef struct s_vector_3d			t_vector_3d;

struct								s_point_3d
{
	double							x;
	double							y;
	double							z;
	t_vector_3d						(*sub_point)(t_point_3d *self,
								t_point_3d *other);
};

struct								s_vector_3d_methods
{
	double							(*dot_product)(t_vector_3d *self,
									t_vector_3d *other);
	double							(*module)(t_vector_3d *self);
	double							(*module_squared)(t_vector_3d *self);
	double							(*cos_teta)(t_vector_3d *self,
									t_vector_3d *other);
	t_vector_3d						(*sub_vect)(t_point_3d *self,
								t_vector_3d *other);
	t_vector_3d						(*add_vect)(t_point_3d *self,
								t_vector_3d *other);
	t_vector_3d						(*mult_scalar)(t_vector_3d *self,
								double scalar);
	t_vector_3d						(*div_scalar)(t_vector_3d *self,
								double scalar);
	t_vector_3d						(*normalize)(t_vector_3d *self);
};

struct								s_vector_3d
{
	double							x;
	double							y;
	double							z;
	double							module;
	double							module_squared;
	double							dot_prod_self;
	t_vector_3d_methods				m;
};

t_point_3d							ft_new_point(double x, double y, double z);
t_vector_3d_methods					ft_vector_3d_methods(void);
t_vector_3d							ft_new_vector_3d(double x, double y,
										double z);
bool								ft_is_between_int(int ref_one, int ref_two,
										int eval);
bool								ft_is_between_double(double ref_one,
										double ref_two, double eval,
										double eps);
double								ft_sqtr_newton(double n, double eps);
bool								ft_is_normalized_3d_vector(double x,
										double y, double z, double eps);

#endif