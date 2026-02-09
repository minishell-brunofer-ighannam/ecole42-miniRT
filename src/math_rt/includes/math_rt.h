/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:49:07 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 11:28:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_RT_H
# define MATH_RT_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define EPS 1e-6

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_point_3d	t_point_3d;
typedef struct s_vector_3d	t_vector_3d;

struct						s_point_3d
{
	double					x;
	double					y;
	double					z;
};

struct						s_vector_3d
{
	double					x;
	double					y;
	double					z;
};

double						ft_vector_dot_product(t_vector_3d self,
								t_vector_3d other);
double						ft_vec_mod(t_vector_3d self);
double						ft_vec_mod_squared(t_vector_3d self);
double						ft_vector_cos_teta(t_vector_3d self,
								t_vector_3d other);
t_vector_3d					ft_vec_sub(t_vector_3d self,
								t_vector_3d other);
t_vector_3d					ft_vec_add(t_vector_3d self,
								t_vector_3d other);
t_vector_3d					ft_vec_mult_scal(t_vector_3d self,
								double scalar);
t_vector_3d					ft_vec_mult_scal(t_vector_3d self,
								double scalar);
t_vector_3d					ft_vector_div_scalar(t_vector_3d self,
								double scalar);
t_vector_3d					ft_vec_norm(t_vector_3d self);
t_point_3d					ft_new_point(double x, double y, double z);
t_vector_3d					ft_sub_point(t_point_3d self, t_point_3d other);
t_vector_3d					ft_new_vector_3d(double x, double y, double z);
bool						ft_is_between_int(int ref_one, int ref_two,
								int eval);
bool						ft_is_between_double(double ref_one, double ref_two,
								double eval, double eps);
bool						ft_is_normalized_3d_vector(double x, double y,
								double z, double eps);
t_point_3d					ft_point_add_vect(t_point_3d p, t_vector_3d v);
bool						ft_double_is_equal(double a, double b, double eps);
bool						ft_point_is_equal(t_point_3d a, t_point_3d b,
								double eps);
t_vector_3d					ft_cross_product(t_vector_3d v1, t_vector_3d v2);
t_vector_3d					ft_component_wise_product(t_vector_3d v1,
								t_vector_3d v2);
int							clamp_int(int i);

#endif