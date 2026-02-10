/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:34:55 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/09 17:35:10 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

t_point_3d ft_new_point_str(char **splited)
{
	return (ft_new_point(ft_atod(splited[0]), ft_atod(splited[1]), ft_atod(splited[2])));
}

t_vector_3d ft_new_vec_str(char **splited)
{
	return (ft_new_vector_3d(ft_atod(splited[0]), ft_atod(splited[1]), ft_atod(splited[2])));
}
