/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 06:06:18 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/18 12:57:25 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "context.h"

# define KA 0.2
# define KD 0.7
# define KS 0.2
# define N 32
# define KR 0.0
# define BACK_COLOR 2633020

typedef struct s_scene		t_scene;
typedef struct s_material	t_material;

t_scene						*ft_parser(char *file, t_context *context);

#endif
