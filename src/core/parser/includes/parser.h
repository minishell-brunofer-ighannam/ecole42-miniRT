/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/07 09:35:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

# define KA 0.1
# define KD 0.7
# define KS 0.2
# define N 32
# define KR 0.0
# define BACK_COLOR 0.0, 0.0, 0.0

typedef struct s_scene		t_scene;
typedef struct s_material	t_material;

t_scene						*ft_parser(char *file);

#endif
