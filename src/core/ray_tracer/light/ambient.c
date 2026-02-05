/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:46:48 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 17:22:41 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vector_3d	ft_ambient_light(t_context *context, t_polyhedron *polyhedron)
{
	t_vector_3d color;

	color = ft_vector_mult_scalar(context->scene->ambient.norm_color,
			context->scene->ambient.intensity);
    color = ft_vector_mult_scalar(color, polyhedron->material.ka);
    return (color);
}
