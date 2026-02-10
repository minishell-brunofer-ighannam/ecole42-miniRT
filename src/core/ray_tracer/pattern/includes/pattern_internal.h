/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:02:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/10 10:56:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_INTERNAL_H
#define PATTERN_INTERNAL_H

#include "pattern.h"
#include "colision.h"
#include "math_rt.h"



void ft_calc_u_v_pl(t_colision *col);
void ft_calc_u_v_sp(t_colision *col);
void ft_calc_u_v_cy(t_colision *col);
void ft_calc_u_v_cn(t_colision *col);

#endif